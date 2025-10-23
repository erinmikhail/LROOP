#include <gtest/gtest.h>
#include "six.h"

TEST(SixTest, DefaultConstructor) {
    Six num;
    EXPECT_EQ(num.getSize(), 1);
    
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0");
}

TEST(SixTest, StringConstructor) {
    Six num("12345");
    EXPECT_EQ(num.getSize(), 5);
    
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "12345");
}

TEST(SixTest, InitializerListConstructor) {
    Six num({1, 2, 3});
    EXPECT_EQ(num.getSize(), 3);
    
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "123");
}

TEST(SixTest, SizeValueConstructor) {
    Six num(4, 5);
    EXPECT_EQ(num.getSize(), 4);
    
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5555");
}

TEST(SixTest, CopyConstructor) {
    Six num1("123");
    Six num2(num1);
    
    EXPECT_TRUE(num1.equals(num2));
    EXPECT_EQ(num1.getSize(), num2.getSize());
}

TEST(SixTest, Addition) {
    Six num1("12");
    Six num2("34");
    
    Six result = num1.add(num2);
    
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "50");
}

TEST(SixTest, Subtraction) {
    Six num1("50");
    Six num2("12");
    
    Six result = num1.subtract(num2);
    
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "34");
}

TEST(SixTest, SubtractionThrowsWhenLarger) {
    Six num1("12");
    Six num2("50");
    
    EXPECT_THROW(num1.subtract(num2), const char*);
}

TEST(SixTest, Equality) {
    Six num1("123");
    Six num2("123");
    Six num3("124");
    
    EXPECT_TRUE(num1.equals(num2));
    EXPECT_FALSE(num1.equals(num3));
}

TEST(SixTest, Comparison) {
    Six num1("123");
    Six num2("124");
    Six num3("122");
    
    EXPECT_TRUE(num2.greater(num1));
    EXPECT_TRUE(num3.less(num1));
    EXPECT_FALSE(num1.greater(num2));
}

TEST(SixTest, AddAssign) {
    Six num1("12");
    Six num2("34");
    
    num1.addAssign(num2);
    
    testing::internal::CaptureStdout();
    num1.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "50");
}

TEST(SixTest, CopyMethod) {
    Six num1("12345");
    Six num2 = num1.copy();
    
    EXPECT_TRUE(num1.equals(num2));
}

TEST(SixTest, InvalidDigitThrows) {
    EXPECT_THROW(Six num("126"), const char*);
    EXPECT_THROW(Six num("12a"), const char*);
}

TEST(SixTest, RemoveLeadingZeros) {
    Six num("000123");
    
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "123");
}