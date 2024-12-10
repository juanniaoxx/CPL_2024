# Natcn

## 项目❓介绍

- CPL 2024-5-function-不计分练习 T3 原始代码仓库

- Git 的配置请参考教程视频

- 你可以自由探索了，Feel Free to Ask Us in 蒙民伟楼 604

## 项目❓结构

`include` 目录存放头文件，其中的 `natcn.h` 进行了三个函数的声明，它们具体的参数、返回值、行为逻辑等信息你可以参考其中的注释

`src` 目录存放源文件，其中的 `natcn.c` 进行了上述三个函数的实现，你需要按照头文件中的注释实现对应的函数

`main.c` 为主函数入口，它会调用 `src` 目录下的所有函数以完成程序的功能

推荐源码阅读顺序：

- 先阅读 `include/natcn.h` 大致了解需要实现哪些函数，分别有怎样的要求
- 然后阅读 `main.c` 了解主函数对这些函数的调用方式，进一步把握应该如何实现这些函数
- 最后在 `src/natcn.c` 的注释引导下完成这些函数的实现

## 运行方式

如果你是 CLion 用户，你可以直接运行 CMakeLists 中的 `natcn` 目标

如果你是 Linux 或 MacOS 用户，你可以使用 Makefile 来编译和运行程序：

```shell
make run
```

否则，（或者你想自己在终端中完成编译）请切换到 `main.c` 所在的目录，使用下面的命令编译和运行程序：

```shell
gcc -g -std=c17 -O2 -Iinclude src/natcn.c main.c -o natcn
# Windows
./natcn.exe
# Linux or MacOS
./natcn
```

## 提交方式

你可以最朴实无华地使用 GUI 提交压缩包。

如果你有 Linux 环境，你可以使用 Makefile 来编译，运行和提交程序，在 submit 目标下定义变量如下即可（亦可按照 Online Judge 的说明操作）：
    
```makefile
    $(eval TOKEN := ${your token})
```

你也可以使用 Online Judge 说明第二条的 curl，但在 Windows 上需要使用 `curl.exe`