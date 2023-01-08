## Preface
 This file is aiming to save my debug experience in pearl house. It will been write by xmind or xmind.


## base algorithm
1. 整体流程： 首先需要掌握的就是如何使用cmake. camke 可以通过层级管理文件和c++代码的编译。 整个项目的C++部分是如何管理呢？ 首先我在根目录下的cmake指定了头文件、编译方式， 并将这个base_algorithm 添加进来， 然后我开始去编译库和样例。 对于库来说， 我在src目录下添加本地代码的头文件， 然后使用生成库的命令。  对于example来说， 我在该目录下去添加头文件和依赖库， 做了一个简单的调用。
### 问题
1. 申明的时候vector等内容都是std的， 需要给std命名空间。 
3. TODO 判断是否在头文件里面添加命名空间， 防止污染。 
4. head file 中头文件中如果声明了构造等， 就必须在cpp里面实现， 系统不会自动创建。






 ## deep learning 
1. 首先需要确定版本， 版本问题真的是非常麻烦，  tensorflow和keras版本经常冲突。 这里我先确定好所有运行版本


2. 

