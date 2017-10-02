# 独立的测试工程

在生产环境中，会将测试代码放在一个单独的project中，测试代码与实际的代码在不同的工程中，在项目发布版本的时候，只需要将实际的代码工程发布，测试代码不会混在一起；在CI环境中，可以写独立的脚本运行特定的工程。

## 创建模拟动态链接库工程
这里，我创建一个单独的工程，名字叫做SampleDynamicLibrary，用来模拟实现一个动态链接库，添加一个头文件和一个源文件，实现一个全局int类型数据的加法操作。
代码如下：

```C++
// DynamicSample.h
#pragma once

__declspec(dllexport) int GlobalAdd(int a, int b);
```

```C++
#include "../Headers/DynamicSample.h"

int GlobalAdd(int a, int b)
{
    return a + b;
}
```
然后，修改项目属性，将General-> Congifuration Type修改成Dynamic Library，默认是Application。

模拟项目就完成了。

## 创建测试工程

测试工程的创建与前面几个工程类似，首先创建一个空的C++工程，然后添加Google Test的属性表，添加一个包含main函数的文件，简单起见，我们直接在这一个文件中完成测试。
源文件代码如下：

```c++
#include <gtest/gtest.h>
#include "../SampleDynamicLibrary/Headers/DynamicSample.h"

TEST(DynamicTes, test)
{
	EXPECT_EQ(2,GlobalAdd(1, 1));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```

在当前的测试工程，添加reference，把刚刚的创建的模拟工程添加到reference。

然后就可以运行了。