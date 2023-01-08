
@[TOC] 
# background 
 
最近刚入职熟悉了两周的代码， 我发现了一个比较大的问题，那就是工作给人带来的成长真的有限。 尤其是在大公司更为明显， 往往一个项目和需求给公司要带来的是上亿的额外收入， 这种任务一次性可能需要很多人参与， 在参与的过程中， 可能你很多时间都在与别人沟通和商量， 你以为的一个项目是coding-->简单说一下怎么用就可以结束了，但其实是自己写代码的时间是非常少的。 此外大部分工作如果你做熟悉了，其实基本功都会忘掉， 因为大部分时间都在改业务，很多基本功如果你工作中用不了就会慢慢会忘记。最后还有一个重要的原因就是我的基础不够扎实， 现在去看一些复杂的C++用法还是比较非常困难的，  但是其实这些复杂的用法还是以基础知识 + 时间的沉淀堆积而成的。 因此在面对复杂问题解决不了的时候， 一定不要像个无头苍蝇乱撞， 要慢下来去打好基础， 一步步的去解决。 就像你搬运一个很重的行李走几千米， 可能刚拿到这个任务你就想放弃， 即使试一试但是一想到你要搬运那么多远就想放弃， 但是如果你以小目标和能走好50米不累人的基本功 作为策略， 就会发现几千米也是小case， 1W米都不在话下。 因此我想乘着这个机会， 好好的把基础打一下， 把自己的pearl_hourse代码完善一下。


# content

pearl_house 主要分为三个点 ： 一个是算法点， 一个是基础C++库， 一个是业务库， 。 需要注意几个点， 一个就是算法题用C++做， 然后做好笔记， 基础C++ 代码库封装一些常用的功能 并且体现自己的C++ 水平， 业务库至少一个功能的实现， 这个不限制语言最好有成套的功能组合成为的项目库。 好了就这些， 注意在写的过程中切记先做再优化，避免一开始就戴着脚铐行走。 应该先随便跑，跑的过程中意识到大盘方向没错， 后期感觉到困难的时候再进行结构优化。前期随便跑也要大盘做详细点， 后期优化就可以直接减了。

## 编程经验

###  整体注意事项
1. 空格多一点
2.  文件名全部大写， 类名大写， 函数_ , 参数先看看， 成员暂定。 



### 头文件书写注意事项
架构规范：

2. 包含成员定义实现的头文件可以写成hpp
3. 一个头文件最好放一个类的定义， 名字也和类相同， 方便别人能够看懂， 多个头文件可以放到一个命名空间中。  
4. 可以将自己的公用头文件放到一个头文件中： 可以，但是如果是频繁变化的业务头文件最好别这样， 因为每次修改之前的cpp文件都会重新连接。 
5. 一般把类的定义放在头文件中，而把函数成员的实现代码放在一个.cpp文件中。不过，还有另一种办法。那就是直接把函数成员的实现代码也写进类定义里面。

书写排版规范：
6. 一般“”“ ” 和<> 分开排版
7. 需要有注释， 例如命名空间注释， 头文件的说明信息等。
8. 命名空间不用空格缩进。 


细节： 

7.解决重复include : 
-  写一些ifdef避免重复include 一个头文件， 比如你包含了a.h, b.h ,但是b.h 中有a.h , 就可以用如下的方式解决。 
>#ifndef __a_h__
#define __a_h__
-  program once也行
9. #include和命名空间在自己的头文件中如何使用， 和cpp文件中声明冲突重复怎么办
-  一般就两种写法， 要么写在头文件中， 要么写在cpp文件中。**一般都是写在头文件中**， 所以头文件命名和头文件引用先考虑自己， cpp文件引一下你就行了， 即使它用了vector也不会重复的， 公用库有检测。 如果是自己写的头文件记得加上#ifndef， 避免这种问题。 | 如果不写在头文件中需要指定命名空间std：：vector ， 不然void fast_sort(vector<int>& arr);这种识别不了。
-  一般你如果在头文件定义了成员变量包含了其他内容， 就不得不#include别的头文件进到你的头文件了去先做个申明了 （ 当然你可以在cpp文件中写， 注意你的定义成员函数头文件之前要把用到的头文件下展开， 但是这样太麻烦了， 可以忽略。  ） | 但是你可能会担心这样可能会重复包括vector等， 放心人家里面有program once, 比你想的深。 
- demo ： 可以看到我们设计了层层嵌套的命名空间， 
```C
#include <string>
#include <vector>

using namespace std;
namespace pearl {
namespace algorithm {
namespace array_and_string {

class arr_sort {
 public:
  void fast_sort(vector<int>& arr);
  void choose_sort(vector<int>& arr);
};

}  // namespace array_and_string

}  // namespace algorithm

}  // namespace pearl
```
-  参照： 
- - https://blog.csdn.net/Fourier_Legend/article/details/82225279
- - https://blog.csdn.net/cherishinging/article/details/73810785
10. 对于不是通用的头文件， 完全可以h和cpp放到一个目录下。 
11. 可以在头文件中使用宏定义日志
>#define LOG(str)                                                            \
  std::cout << __FILE__ << ":" << __LINE__ << " " << __TIMESTAMP__ << " : " \
            << str << std::endl;

编写内容与理解： 
12. 定义和声明的区别：
- 一般头文件是声明，开发完源码打包封闭， 头文件直接给别人， 这样别人就能用， 但是不知道你的具体实现， 如果你不在乎可以就在头文件中写好定义， 公开代码最好别这样， 而且非常冗余。
一般自己添加命名空间


### cpp文件

#### 单线程

函数级别：

类级别：

1. 有些资源类一定要注意析构函数释放资源， 默认释放不了， 例如文件和数据库连接句柄。

#### 多线程
类级别： 
2. 有些类成员函数里面可以通过绑定器开启多线程，因此一个类函数就可以调用3个线程对自身的数据进行操作， 例如数据库连接池代码中的例子。 
3. 多线程中如果对同一个类成员操作， 如果是std容器一定要记得加锁， 如果是原子操作可以不用考虑。 而且锁必须是你对象的那一把。

## 编译与常遇问题

### 基本命令
1. 生成动态库 ： gcc -fPIC -shared arrsort.cpp  -o libarrsort.so  & cp libarrsort.so  /usr/lib
2. C++ 开启11和gdb调试 ： g++ main.cpp  -std=c++11  -g    -larrsort -o a 
3. 添加库文件的搜索路径：export LD_LIBRARY_PATH=/mypath${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
4. 链接动态库 g++ main.cpp  -std=c++11  -g    -larrsort -o a 


#### 常用脚本
 gcc -fPIC -shared arrsort.cpp  -o libarrsort.so  & cp libarrsort.so  /usr/lib

g++ main.cpp  -std=c++11  -g    -larrsort -o a 

./a

### 问题排查

2. 执行 g++ main.cpp -o  test | main.cpp:(.text+0x50): undefined reference to `pearl::algorithm::array_and_string::ArrSort::choose_sort(std::vector<int, std::allocator<int> >&)'
collect2: error: ld returned 1 exit status  | 这个主要你只包含头文件， 但是具体实现他不知道， 因此你要先去编译成一个库让mian去链接。 
3. 执行 g++ main.cpp  -std=c++11  -g   -L -larrsort -o a  | 
/tmp/ccW4F3AC.o: In function `main':
/root/pearl/pearl_houses/kernel/algorithm/src/main.cpp:10: undefined reference to `pearl::algorithm::array_and_string::ArrSort::choose_sort(std::vector<int, std::allocator<int> >&)'
collect2: error: ld returned 1 exit status  | 这个就是你库找不到， 而且很多错误你具有概念性问题， 首先你要通过LD_LIBRARY_PATH=/mypath${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH} 添加自己的搜索路径， 很多云服务器这个环境变量是空的 ， 而且-L没有具体内容就不要写了| 

4. 编译项目发现cout找不到 | arrsort.cpp:(.text+0x16): undefined reference to `std::cout'  |  这是因为你用gcc编译了，尝试更改成g++或者gcc加-lstdc++。 
5. g++版本过老 |  main.cpp:8:51: error: in C++98 ‘arr’ must be initialized by constructor, not by ‘{...}’  |  添加-std=c++11 
6. 函数默认值无法添加| arrsort.h:13:8: error: after previous specification in ‘bool pearl::algorithm::array_and_string::ArrSort::bubble_sort(std::vector<int>&, bool)’ [-fpermissive]  | 这种就是你头文件申明的时候要去掉默认值， 就在函数具体定义时候从右到做就行了 | 
7. using namespace 了但是cout 还是找不到   | 没有加iostrem


### 基本认知
1. 库文件没有main函数， 就是一堆类和函数的打包， 因此要注意命名空间的设置。 

## 算法库
这部分参照自己之前的leetcode代码库进行重新搭建。 
### 数组和字符串类
 



## 后端库
### 数据库
这部分添加了C++数据库链接 | 添加了数据库连接池






# version 

##  添加了一个基本的编译和提交运行版本， 2022年7月17日22:15:09

##  添加了启动的脚本 ： 2022年7月17日22:15:28

##  添加了数据库的链接： 2022年7月19日00:40:52

##  添加了数据库连接池，但是还没调试和压测：2022年7月20日00:59:17

##  代码解决了g++编译版本问题 ， 提交了日志模块。  2022年8月3日00:51:11

1. 参照https://blog.51cto.com/u_15080022/4375675  和https://blog.51cto.com/u_15080022/4375675

2. bazel启动脚本bazel build //common_tools:base

##    添加gtest到bazel中。

1. 重启了版本， 安装了bazel 参照https://blog.csdn.net/xavier_muse/article/details/93203093?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-93203093-blog-112696943.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-93203093-blog-112696943.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=1   （不需要去弄环境变量， 是弄好的）

2. 新的centos8  not have g++ , I used  yum install gcc-c++.x86_64 to install.

3. bazel is success. add arry test case.