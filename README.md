# 基于Visual Studio 2015使用Google Test

本项目用作练习使用[Google C++ Test](https://github.com/google/googletest)，用Github项目的方式练逐步练习使用Google C++ 单元测试框架。
项目是基于Visual Studio 2015构建测试结局方案，整个Solution中，每个项目作为一个学习节点。主要内容参考Google Test的Github主页的[Primer](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md)。

## Google Test 简介
Google C++ Test，简称Google Test，或者简称gtest，是一个C++的单元测试框架，基于标准C++，可以在Linux、Mac、Windows三种平台上使用，方便开发者在这三个平台上使用C++语言开发项目时候，同时进行单元测试。

**Google Test由以下几个优势：**
1. **Tests should be independent and repeatable** -- 测试之间相互独立，互不影响，允许单个运行测试，方便进行Debug，并且测试可以多次运行，每次的结果也互不影响。
2. **Tests should be well organized and reflect the structure of the tested code** -- 测试逻辑结构组织清晰，公用数据或者子例程的时候，测试用例名字是一样的，方便一个项目新人快速上手。
3. **Tests should be portable and reusable** -- Google Test是与平台无关的，也就是跨平台，在跨平台项目上使用也没问题。
4. **When tests fail, they should provide as much information about the problem as possible** -- GoogleTest是用户友好的，当测试用例挂了，提供详细的输出信息，方便调试。
5. **The testing framework should liberate test writers from housekeeping chores and let them focus on the test content** -- Google Test框架不是很琐碎，可以很方便的使用，让程序员关注于程序，而不是花费大量的时间研究测试怎么写。
6. **Tests should be fast** -- Google Test运行很快，不用每次运行测试都要等。

Google Test是基于xUnit架构，如果熟悉Junit或者pyUnit，那么就会发现很快就能熟练的使用Google Test，我之前在公司使用过NUnit测试框架，所以看起比较简单。

## 编译Google Test

在使用Google Test框架之前，必须先编译Google Test，生成静态链接库，在使用的时候链接就可以了；另外，由于Google Test本身并不是很大，完全可以把Google Test集成到项目中。

在Window上有两种方式来构建编译Google Test。
- 在Google Test根目录中，有一个msvc的子目录，里面提供了gtest的解决方案，直接使用Visual Studio 2015打开，构建就可以了。
- 使用CMake构建，具体步骤如下(假设Google Test的根目录是 GTESTROOT)。

```
cd GTESTROOT
mkdir build
cd build
cmake GTEST-BUILD-SAMPLES=ON ..  # 参数表示要编译样例代码
```

在build目录下会产生一个，gtest的解决方案，使用Visual Studio 2015打开，构建整个项目，若是Debug模式，在当前目录的Debug目录下会产生需要的lib，还有其他例子的可执行文件。

在Applications目录下创建一个叫做gtest目录，然后在这里创建两个目录include和lib。将GTESTROOT目录下的include里面的内容拷贝到这个include目录下，将gtest.lib文件拷贝到lib目录。

到目前为止，Google Test测试框架就编译构建完成了，在Windows上使用Google Test需要注意的是，由于Gtest构建的时候是使用 MTd 模式，因此在使用项目的时候也把项目改成这个模式，或者在构建gtest的时候使用其他的构建模式。

## 练习使用Google Test Step by Step

1. [初步使用gtest](https://github.com/zhangxiaoya/GTestInAction/tree/master/GTestInAction)