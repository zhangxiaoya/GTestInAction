# Action One 简单练习使用Google Test

## 配置gtest

1. 在解决方案中添加一个工程，命名Action One；
2. 在对应的工程下添加一个属性表（Debug或者Release模式，32位还是64位要与编译gtest的选项一致，默认是），命名GoogleTest.props;
3. 修改新的属性表中，添加Include目录和lib目录；
4. 修改运行时链接库为Multi Thread Debug

经过以上几个步骤，项目的GoogleTest基本配置好了。

## 添加目标文件

在工程中添加一个文件simple.hpp，在里面添加一个函数的定义。

```
#pragma once

// Returns the factorial of n
inline int Factorial(int n)
{
	auto result = 1;
	for (auto i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
```

## 简单分析

这个函数的功能是给定一个整数输入，返回它的阶乘。

- 当输入参数小于0，或者等于0的时候，返回1；
- 当输入正常参数的时候，返回它的阶乘。

简单的列举上面两种情况，可以添加两个测试：

1. 非正常值测试，输入边界外的数字，比如负数等；
2. 正常值测试，输入正常数字

## 添加测试文件
为了简单，将测试部分代码都放在了main文件中。

```
#include "Sample1.hpp"
#include <gtest/gtest.h>

using namespace std;

TEST(FactorialTest, outlierTest)
{
	EXPECT_EQ(1, Factorial(-1));
	EXPECT_EQ(1, Factorial(0));
}

TEST(FactorialTest, normalTest)
{
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```

如上面所示，TEST宏里面完成测试，类似与函数的调用。

TEST宏有两个参数，第一个称作是测试用例名称，第二个称作是测试名称，测试用例名称表示对某一个函数或者类的测试，用来标识某种行为的测试；测试名称表示的是一个测试用例下的某一个测试的名称，对应一个测试体。比如，上面对Factorial函数的测试用例，用例名称直接在函数名后面添加了一个Test，表示，这个测试用例是对应这个函数，后面的名字可以根据测试内容设定，比如这里分了两类，一种是正常值测试，一种是非正常值测试。（函数比较简单，所以测试划分比较粗暴）。

在main函数中，有两行代码，第一行是初始化Google Test，第二行是运行所有测试。

下面是上面测试运行结果：
![结果](https://github.com/zhangxiaoya/GTestInAction/blob/master/GTestInAction/sample1Result.JPG)