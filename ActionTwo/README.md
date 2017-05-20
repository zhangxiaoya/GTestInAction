# 练习更多的断言

这个项目学习使用**Google Test**中的多种断言。在单元测试框架中，断言是一种基本的检验手段，也是最常用的方法，需要记住常用的几个断言。

**Google Test**断言是类似于函数的宏，可以用这些断言来验证一个类或者函数的行为，如果验证失败，断言会给出出错的代码的行数，还有出错的基本信息，另外，用户也可以自定义错误信息，来辅助定位错误类型，以及错误地址。

## 两种断言形式

Google Test中有两种断言形式：
1. 第一种是以**ASSERT_**开头的，这种断言是 **fatal** 断言，如果这样的断言失败，那么当前测试就会停止（但是其他的测试不会受到影响）；
2. 另外这一种断言是以**EXPECT_**开头，这种断言是 **nonfatal** 断言，如果一个测试失败，对其他任何测试都不会有影响。

## 基本的断言
基本的断言就是判断 **TRUE** 或者 **FALSE** 。
对于**fatal**断言，`ASSERT_TRUE(condition)` 和 `ASSERT_FALSE(condition)`;
对于**nonfatal**断言，`EXPECT_TRUE(condition)`和`EXPECT_FALSE(condition)`;

比如我们在一个判断输入参数是奇数的函数定义如下：
```
bool Util::IsOdd(int value)
{
	if (value <= 0)
		return false;
	return value % 2 == 1;
}
```
在测试的时候，我们选择下面的测试。

```
TEST(UtilOddTest, zeroTest)
{
	EXPECT_FALSE(Util::IsOdd(0));
}

TEST(UtilOddTest, normalTest)
{
	EXPECT_TRUE(Util::IsOdd(1));
	EXPECT_FALSE(Util::IsOdd(2));
}
```

## 二值比较断言

除了基本的判断真假的断言，还有更为常用的二值比较断言，这些断言用来比较函数的返回值，与期待的值是否相等，或者其他的大于或者小于的关系。

对于fatal断言来说，有下面的断言。
```
ASSERT_EQ(val1,val2);	val1 == val2
ASSERT_NE(val1,val2);	val1 != val2
ASSERT_LT(val1,val2);   val1 < val2
ASSERT_LE(val1,val2);	val1 <= val2
ASSERT_GT(val1,val2);	val1 > val2
ASSERT_GE(val1,val2);	val1 >= val2
```

对于nonfatal断言来说，有下面的断言。
```
EXPECT_EQ(val1,val2);	val1 == val2
EXPECT_NE(val1,val2);	val1 != val2
EXPECT_LT(val1,val2);	val1 < val2
EXPECT_LE(val1,val2);	val1 <= val2
EXPECT_GT(val1,val2);	val1 > val2
EXPECT_GE(val1,val2);	val1 >= val2
```

这些断言是最长用的，比如在ActionOne中采用的例子，都是比较Equal。这里就不再重复的举例子了。


## 关于字符串断言

在程序中，字符串是一个比较另类的东西，比较起来比较麻烦，出问题最多，若用上面的断言测试字符串，那么只能测试指向字符串的地址，不能实际测试到字符串的内容，Google Test提供了对于字符串的断言，主要有下面的四种。

对于**fatal**断言。
```
ASSERT_STREQ(str1,str2);     the two C strings have the same content
ASSERT_STRNE(str1,str2);     the two C strings have different content
ASSERT_STRCASEEQ(str1,str2); the two C strings have the same content, ignoring case
ASSERT_STRCASENE(str1,str2); the two C strings have different content, ignoring case
```

对于**nonfatal**断言来。
```
EXPECT_STREQ(str1,_str_2);     the two C strings have the same content
EXPECT_STRNE(str1,str2);       the two C strings have different content
EXPECT_STRCASEEQ(str1,str2);   the two C strings have the same content, ignoring case
EXPECT_STRCASENE(str1,str2);   the two C strings have different content, ignoring case
```

下面是一个简单使用的例子，定义一个连接字符串的程序，给定两个字符串输入，将两个字符串连接在一起返回。

```
std::string Util::MergeStr(const std::string& first_str, const std::string& second_str)
{
	return  first_str + second_str;
}
```

在测试程序中这样写：
```
TEST(UtilStringTest, firstTest)
{
	string firstStr = "Hello";
	string secondStr = "Google";
	EXPECT_STREQ("HelloGoogle", Util::MergeStr(firstStr,secondStr).c_str());
}
```

**这里需要注意的是，不支持标准库中的string比较，因为标准库中的string是类，这里只支持标准C语言的字符串。**

下面是测试执行结果。

![结果](https://github.com/zhangxiaoya/GTestInAction/blob/master/ActionTwo/testResult.PNG)