# 本项目旨在解释vscode如何进行C++的调试工作

主要有两种方法：1.设置三个.json文件来进行指导 2.使用CMakeLists.txt构建项目

## 方法一：json文件法
https://blog.csdn.net/qq_45488242/article/details/128414756
https://blog.csdn.net/czpdd/article/details/123748329

VSCODE中提供了tasks.json和launch.json两个文件来分别描述**调试前的准备工作**以及**以指定的参数启动调试器**

### 调试前的准备工作：tasks.json

### 启动调试器：launch.json


## 方法二:CMakeLists.txt法
另一篇解释cmake的文章
https://blog.csdn.net/qq_44886213/article/details/124198574
    由这篇博客可知，如果不使用CMakeLists.txt构建C++项目的话，就要编写.vscode文件夹中的三个json文件。除了麻烦外，还必须依托vscode这个平台，没法单独在shell/cmd编译。下面就要介绍一下，如何在vscode中使用CMakeLists.txt构建C++项目。
    之后可以在没有.vscode的文件夹中试着做一下这个