# 使用Google Test Fixture功能

为什么在测试使用Fixture这个名字，Fixture的中文有固定物的意思，因为我们在需要用一些预设的信息来进行测试，这个功能有点预先设定好固定物的意思。

什么情况下采用到Fixture功能呢？

等到真正用到这个功能的时候就会发现，其实很多时候都在使用这个功能，因为月是复杂的场景中，很多测试都是使用同样的数据，不是每次新建一个测试就添加一些数据。
比如测试一个类，但是通常不会直接测试类，而是测试类的行为。多个成员函数可能会使用相同的类数据成员，那就在一开始准备好这样的测试数据，每个接口的测试，都用这个提前准备好的测试数据。

使用Fixture实际上是我们定义一个Fixture类，这个类继承了::testing::Test，然后在这个类中准备好数据，测试的时候，测试框架会使用这个类里面的数据。

基类中有两个虚函数，一个SetUp，一个是TearDown，前者是完成初始化工作，类似于构造函数，后者是完成清理工作，类似于析构函数，这两个函数需要重载，我们在SetUp中准备好测试数据，在TearDown里面清理数据（有时候不需要不写）。

举一个简单的例子，有一个SimpleString类，定义如下：

```
#pragma once
#include <vector>

class SimpleString
{
public:
	SimpleString();

	void Append(const char val);

	size_t Length() const;

	void Dispose();

private:
	std::vector<char> data;
};
```

类的定义如下：
```
#include "SimpleString.h"

SimpleString::SimpleString() : data()
{
	this->data.resize(0);
}

void SimpleString::Append(const char val)
{
	this->data.push_back(val);
}

size_t SimpleString::Length() const
{
	return this->data.size();
}

void SimpleString::Dispose()
{
	this->data.clear();
}

```


## 使用Fixture

我想测试这个类的Length函数，那么就定义Fixture如下：

```
#pragma once
#include <gtest/gtest.h>
#include "SimpleString.h"

class SimpleStringTest: public ::testing::Test
{
protected:
	void SetUp() override;

	void TearDown() override;

protected:
	SimpleString simpleString;
};
```

函数定义如下：
```
#include "SimpleStringTest.h"

void SimpleStringTest::SetUp()
{
	this->simpleString.Append('a');
	this->simpleString.Append('b');
}

void SimpleStringTest::TearDown()
{
	this->simpleString.Dispose();
}
```

在使用Fixture的时候，与简单的断言有些不同，这里使用的是TEST_F宏，而不是TEST宏。这里主要是C++的宏不允许重载，所以才这样设计，两个红的第一个参数不一样。
- TEST宏的第一个参数是测试用例名字，是程序员自己写的的，只要有意义就行
- TEST_F宏的第一个参数，必须是上面定义的Fixture的名字，否则不能使用Fixture。

我们在Main函数中使用一下试试。
```
#include <iostream>

#include <gtest/gtest.h>
#include "SimpleStringTest.h"

using namespace std;

TEST_F(SimpleStringTest, firstTest)
{
	EXPECT_EQ(2, simpleString.Length());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}
```

## 关于出发测试运行

有过其他测试经验的同学可能会发现，Google Test中的每个测试用例不需要注册就能运行，在很多测试框架中，要求每个测试被注册一下，然后系统才能运行它，Google Test实际上是隐式注册，在TEST宏和TEST_F宏中隐式帮我们注册了测试用例。

使用`RUN_ALL_TESTS()`运行所有的测试，如果所有的测试都通过，那么返回0，否则，返回1。这个返回值不能忽略，测试框架需要根据这个返回值知道测试是否通过，所以需要在main函数中返回这个返回值，不然会提示错误。

下面是测试执行结果。

![结果](https://github.com/zhangxiaoya/GTestInAction/blob/master/ActionThree/testResult.PNG)