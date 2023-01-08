


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <pthread.h>


#define DNS_SVR				"114.114.114.114"


#define DNS_HOST			0x01
#define DNS_CNAME			0x05



struct dns_header {
	unsigned short id;
	unsigned short flags;
	unsigned short qdcount;
	unsigned short ancount;
	unsigned short nscount;
	unsigned short arcount;
};

struct dns_question {
	int length;
	unsigned short qtype;
	unsigned short qclass;
	char *qname;
};

struct dns_item {
	char *domain;
	char *ip;
};




int dns_client_commit(const char *domain) {

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("create socket failed\n");
		exit(-1);
	}

	printf("url:%s\n", domain);

	struct sockaddr_in dest;
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(53);
	dest.sin_addr.s_addr = inet_addr(DNS_SVR);
	
	int ret = connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));
	printf("connect :%d\n", ret);

	struct dns_header header = {0};
	dns_create_header(&header);

	struct dns_question question = {0};
	dns_create_question(&question, domain);

	char request[1024] = {0};
	int req_len = dns_build_request(&header, &question, request);
	int slen = sendto(sockfd, request, req_len, 0, (struct sockaddr*)&dest, sizeof(struct sockaddr));

	char buffer[1024] = {0};
	struct sockaddr_in addr;
	size_t addr_len = sizeof(struct sockaddr_in);
		
	int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, (socklen_t*)&addr_len);
		
	printf("recvfrom n : %d\n", n);
	struct dns_item *domains = NULL;
	dns_parse_response(buffer, &domains);

	return 0;
}

char *domain[] = {
	"www.ntytcp.com",
	"bojing.wang",
	"www.baidu.com",
	"tieba.baidu.com",
	"news.baidu.com",
	"zhidao.baidu.com",
	"music.baidu.com",
	"image.baidu.com",
	"v.baidu.com",
	"map.baidu.com",
	"baijiahao.baidu.com",
	"xueshu.baidu.com",
	"cloud.baidu.com",
	"www.163.com",
	"open.163.com",
	"auto.163.com",
	"gov.163.com",
	"money.163.com",
	"sports.163.com",
	"tech.163.com",
	"edu.163.com",
	"www.taobao.com",
	"q.taobao.com",
	"sf.taobao.com",
	"yun.taobao.com",
	"baoxian.taobao.com",
	"www.tmall.com",
	"suning.tmall.com",
	"www.tencent.com",
	"www.qq.com",
	"www.aliyun.com",
	"www.ctrip.com",
	"hotels.ctrip.com",
	"hotels.ctrip.com",
	"vacations.ctrip.com",
	"flights.ctrip.com",
	"trains.ctrip.com",
	"bus.ctrip.com",
	"car.ctrip.com",
	"piao.ctrip.com",
	"tuan.ctrip.com",
	"you.ctrip.com",
	"g.ctrip.com",
	"lipin.ctrip.com",
	"ct.ctrip.com"
};

struct async_context {

	int epfd;
	pthread_t thid;

};


typedef void (*async_result_cb)(void *arg, int count);


struct epoll_arg {
	async_result_cb cb;
	int fd;
};

#define ASYNC_CLIENT_NUM	1024

void dns_async_free_domain(struct dns_item *domains, int count) {

	int i = 0;
	for (i = 0;i < count;i ++) {
		free(domains[i].domain);
		free(domains[i].ip);
	}
	free(domains);
}


// 
void *dns_async_callback(void *arg) {

	/*
	 * while (1) {
 	 *    epoll_wait();
 	 *    recv();
 	 *      parser();
 	 *      fd --> epoll delete
	 * }
	 */

	struct async_context *ctx = (struct async_context *)arg;
	
 	while (1) {

		struct epoll_event events[ASYNC_CLIENT_NUM] = {0};
		
		// yield --> label --> resume
		int nready = epoll_wait(ctx->epfd, events, ASYNC_CLIENT_NUM, 0);
		if (nready < 0) continue;

		int i = 0;
		for (i = 0;i < nready;i ++) {

			struct epoll_arg *data = events[i].data.ptr;
			int sockfd = data->fd;

			char buffer[1024] = {0};
			struct sockaddr_in addr;
			size_t addr_len = sizeof(struct sockaddr_in);
				
			int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, (socklen_t*)&addr_len);
				
			printf("recvfrom n : %d\n", n);
			// 为什么要定义成为结构体呢， 因为返回的数据可能有很多类型， 每种类型的处理不一样。 
			struct dns_item *domains = NULL;
			int count = dns_parse_response(buffer, &domains);

			data->cb(domains, count);

			//
			epoll_ctl(ctx->epfd, EPOLL_CTL_DEL, sockfd, NULL);

			close(sockfd);
			

			dns_async_free_domain(domains);
			free(data);

		}

	}


}


int  dns_async_context_init(struct async_context  *ctx) {

	if (ctx == NULL) return -1;

	//1 epoll_create

	int epfd = epoll_create(1);
	if (epfd < 0) return -1;

	ctx->epfd = epfd;
	

	//1 pthread_create

	int ret = pthread_create(&ctx->thid, NULL, dns_async_callback, ctx);
	if (ret) {
		close(epfd);
		return -1;
	}

	return 0;
}


int dns_async_context_destroy() {

	//1 close(epfd)
	

	//1 pthread_cancel(thid)
	

	free();
}


//  多次提交过去
int dns_async_client_commit(struct async_context *ctx, async_result_cb cb) {
	//1 socket
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("create socket failed\n");
		exit(-1);
	}

	printf("url:%s\n", domain);

	struct sockaddr_in dest;
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(53);
	dest.sin_addr.s_addr = inet_addr(DNS_SVR);
	//1 connect server
	
	int ret = connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));
	printf("connect :%d\n", ret);

	//1 encode protocol
	struct dns_header header = {0};
	dns_create_header(&header);

	struct dns_question question = {0};
	dns_create_question(&question, domain);

	char request[1024] = {0};
	int req_len = dns_build_request(&header, &question, request);

	//1 send ， 发送过去绑定epoll， 有响应epoll就会搞过来
	int slen = sendto(sockfd, request, req_len, 0, (struct sockaddr*)&dest, sizeof(struct sockaddr));
#if 0
	char buffer[1024] = {0};
	struct sockaddr_in addr;
	size_t addr_len = sizeof(struct sockaddr_in);
		
	int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, (socklen_t*)&addr_len);
		
	printf("recvfrom n : %d\n", n);
	struct dns_item *domains = NULL;
	dns_parse_response(buffer, &domains);
#else

	struct epoll_arg  *eparg = (struct epoll_arg  *)calloc(1, sizeof(struct epoll_arg));
	if (eparg == NULL) return -1;

	eparg->fd = sockfd;
	eparg->cb = cb;
		

	struct epoll_event ev;
	ev.data.ptr = eparg;
	ev.events = EPOLLIN;
	epoll_ctl(ctx->epfd, EPOLL_CTL_ADD, sockfd, &ev);

#endif
	return 0;
}




int main(int argc, char *argv[]) {

	int count = sizeof(domain) / sizeof(domain[0]);
	int i = 0;
#if 0
	for (i = 0;i < count;i ++) {
		dns_client_commit(domain[i]);
	}
#else

	for (i = 0;i < 50;i ++) {
		dns_async_client_commit(ctx, domain[i]);
		yield();
	}


#endif

	getchar();

#if 0  //异步的
	struct async_context  * ctx = dns_async_context_init();
	dns_async_context_destroy(ctx);
	
	
	struct async_context  * ctx = malloc();
	dns_async_context_init(ctx);

	dns_async_context_destroy(ctx);

	free(ctx);
#endif

}







