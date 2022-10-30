## Background
Today, I have a good idea about how to balance Pearl House with Pearl Life. So, what is Pearl? Pearl is a big project about how to guide my whole work. Pearl's Mind includes life, work, health, economics, and communication. I often read books to increase this model. Pearl House consists of some work about my work area. Liking CPP, front development, and end development.
However, It is a big problem how to build Pearl House. I have often made git guidance, python grammar, and CPP grammar. But, it does not work in real work. So, I still need to google questions when I meet some problems in real work. In this article, I will introduce a new work named Pearl Life. It can give our Pearl House a usable place. In the next, I will introduce some work in Pearl Life.

## Content

### What Pearl Life Content?

Pearl Life aims to use Pearl House to develop a system to maintain my life.
Health: pearl life helps me grow healthily. It can make benefit sleep, getting up, exercising, checking the body, and eating healthy food.
Shopping: As we know, there have many things we need to buy, like paper towels, clothes, towels, and shoes. How do a route to decide what I need to buy and when to buy it?
 Economic: It helps me know how to save and organize money and my assets. 
Life flow: It makes a route for daily life. It consists of health shopping, and economics. 
Bonus and random System: Make a bonus and random system to make you can following Peal Life. 




Here is pearl life's essential skill your need to master in this picture. It includes almost all skills in daily work and projects. For example, in development, your need to use docker to employ your server, use Git to organize your project, use Grafana to monitor your server, and use Jenkins to make ci/cd work.   Besides that, we need to use CPP, python, js, java, CSS, and HTML to program. It relies on more than one language because every language has self-advantage. In the middle models part, we use MySQL to save my data,  Nginx to do the proxy server, TensorFlow to make a model for recommend and search,  Redis to make cache data,  Vue to build front interaction,  and so on.
![在这里插入图片描述](https://img-blog.csdnimg.cn/ead78fe716cd4484b82a6bd89758bfdd.png)
           ------------------------------------------------------------------   1-1  basic skills


Basic these skills,  We want to build a system as the following framework. Firstly, we use the front end to send the HTTP command, which includes all kinds of servers. The request pass Nginx proxy to every cluster. As we know, every cluster has a complete server for the front. But， we need to build two clusters for server safe. Next, all requests will receive by server proxy. The server proxy will make a request forwarded to other servers by referring to the zookeeper IP address.   Every professional server function is different.

![在这里插入图片描述](https://img-blog.csdnimg.cn/e3a7e962ae064800b262c61a4019abc1.png)
                      ----------------------------------------------------------------     1-2  pearl life framework

- The shopping server will make SQL requests for all lists your need to buy.
- The notebook server will make your idea save in the database.
- The economic server will make a list of your property， And another CUDR  interface.
- The health server will make your health command and health status.
- The life flow server will make all servers 1-4 requests and combine self-work to give your finally suggest.
Besides that, we will expand other servers, like the bonus server, to make a bonus, a search server to search your note, and  
others. All professional servers will have a self-zookeeper to make a list of real operator databases and actual tasks. That makes your shopping server will not need to worry about many QPS to cause server overload.

Finally, all data will be using MySQL and Hadoop to save. All business servers will save data into MySQL. All logs or notebooks will save in Hadoop for search.

I hope this project, whose name is pearl life, is essential to my daily life's demand and include all kind of knowledge in IT work.

### A implment about login server

Login server is basic server that make your using pearl life.


basic skills: vue + js + html + git + nginx + docker + django + zookeeper + python + redis .
framework:  the framework like this pictures.  we can used web front to create or login a user, the request pass server proxy. After finding server in zookeeper, we know what is usercontroll server, and finllay, we into user node  to do some actual work for login and register.


![在这里插入图片描述](https://img-blog.csdnimg.cn/637f8c7b02d546d7b5f6654dd4ee78c9.png)
task one : init a project.  done 



## Version Log
20221030  add first sersion for whole framework.















# git 

## background
Today, I  will introduce how to use Git.  Git is a tool that we can use it record project logs. When we build a big project, there have many questions in development.  Using Git can do a better job f in a team.  We need to control source quality with Git in the pearl life project.

## Content
### what is Git? Why should we use Git?
Git is an open-source version control system for projects.  If you don't use Git,  you will have many conflicting project versions. 

### Git basic knowledge
- Local Git VS Github: you should know local Git is the same as GitHub, but remote Github is more like a  repository to save and sync other people in the same project.  The real work needs to be done in local Git.
- Git framework:  As we can see in this picture, the workspace is our new project init or clone from another space. We can use add to add coding into the index stage.  And we can use git commit to commit your code as a log in local.  Finally, we can use git to push your coding into the remote workspace.  And you can use pull or fetch to copy other people's push.

 - basic command in daily git:   git add . | git commit -m "xxxx" | git push origin master:remote_branch | git commit -ammend |  git  branch | git checkout -b  dev | git log | git reset log_id  | git reset --hard log_id | git remote add  origin www. |   git merger master  | git pull | git fetch | 

![在这里插入图片描述](https://img-blog.csdnimg.cn/ac68b2d9a195411598dc885b1a96ad25.png)

## workflow

## version 

## reference

1. my xmind: pearl_mind  技术全栈
2. my: note https://editor.csdn.net/md/?articleId=126151184
3. my note:https://editor.csdn.net/md/?articleId=103460445
4.  git workspace stash : https://www.cnblogs.com/qdhxhz/p/9757390.html
5. git merger vs rebase: https://www.jianshu.com/p/f23f72251abc
6. git pull  vs git merger vs git fetch : https://segmentfault.com/q/1010000009076820










