# 基于Visual Studio 2015使用Google Test

本项目作为练习使用Google Test，用项目的形式使用Google Test的不同特征。

更多的内容参考Google Test的Github主页的Primer。

## Google Test 简介
Google Test是一个C++的测试框架，基于标准C++，可以在Linux、Mac、Windows上使用。

Google Test由以下几个优势：
- Tests should be independent and repeatable.
- Tests should be well organized and reflect the structure of the tested code. 
- Tests should be portable and reusable.
- When tests fail, they should provide as much information about the problem as possible.
- The testing framework should liberate test writers from housekeeping chores and let them focus on the test content.
- Tests should be fast. 

Google Test是基于xUnit架构，如果熟悉Junit或者pyUnit，那么就会发现很快就能熟练的使用Google Test。

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

到目前为止，Google Test测试框架就编译构建完成了。