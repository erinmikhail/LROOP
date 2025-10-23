#include <gtest/gtest.h>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

TEST(PointTest, Equality) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(3.0, 4.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(SquareTest, DefaultConstructor) {
    Square square;
    Point center = square.center();
    
    EXPECT_DOUBLE_EQ(center.x, 0.5);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
    EXPECT_DOUBLE_EQ(static_cast<double>(square), 1.0);
}

TEST(SquareTest, AreaCalculation) {
    Square square(Point(0,0), Point(2,0), Point(2,2), Point(0,2));
    EXPECT_DOUBLE_EQ(static_cast<double>(square), 4.0);
}

TEST(SquareTest, CenterCalculation) {
    Square square(Point(1,1), Point(3,1), Point(3,3), Point(1,3));
    Point center = square.center();
    
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(SquareTest, CopyConstructor) {
    Square square1(Point(0,0), Point(2,0), Point(2,2), Point(0,2));
    Square square2(square1);
    
    EXPECT_TRUE(square1 == square2);
}

TEST(SquareTest, CopyMethod) {
    Square square(Point(0,0), Point(2,0), Point(2,2), Point(0,2));
    Figure* copy = square.copy();
    
    EXPECT_TRUE(square == *copy);
    EXPECT_DOUBLE_EQ(static_cast<double>(square), static_cast<double>(*copy));
    
    delete copy;
}

TEST(RectangleTest, DefaultConstructor) {
    Rectangle rectangle;
    Point center = rectangle.center();
    
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
    EXPECT_DOUBLE_EQ(static_cast<double>(rectangle), 2.0);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle(Point(0,0), Point(4,0), Point(4,2), Point(0,2));
    EXPECT_DOUBLE_EQ(static_cast<double>(rectangle), 8.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle rectangle(Point(1,1), Point(5,1), Point(5,3), Point(1,3));
    Point center = rectangle.center();
    
    EXPECT_DOUBLE_EQ(center.x, 3.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(RectangleTest, CopyMethod) {
    Rectangle rectangle(Point(0,0), Point(4,0), Point(4,2), Point(0,2));
    Figure* copy = rectangle.copy();
    
    EXPECT_TRUE(rectangle == *copy);
    EXPECT_DOUBLE_EQ(static_cast<double>(rectangle), static_cast<double>(*copy));
    
    delete copy;
}

TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid trapezoid;
    Point center = trapezoid.center();
    
    EXPECT_DOUBLE_EQ(center.x, 1.5);
    EXPECT_DOUBLE_EQ(center.y, 0.5);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    double area = static_cast<double>(trapezoid);
    
    EXPECT_GT(area, 0.0);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    Point center = trapezoid.center();
    
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(TrapezoidTest, CopyMethod) {
    Trapezoid trapezoid(Point(0,0), Point(4,0), Point(3,2), Point(1,2));
    Figure* copy = trapezoid.copy();
    
    EXPECT_TRUE(trapezoid == *copy);
    
    delete copy;
}

TEST(FigureArrayTest, AddAndRemove) {
    FigureArray array;
    
    Square* square = new Square();
    array.addFigure(square);
    
    EXPECT_EQ(array.size(), 1);
    
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray array;
    
    array.addFigure(new Square(Point(0,0), Point(1,0), Point(1,1), Point(0,1)));
    array.addFigure(new Rectangle(Point(0,0), Point(2,0), Point(2,1), Point(0,1)));
    
    double totalArea = array.totalArea();
    EXPECT_DOUBLE_EQ(totalArea, 3.0); // 1 + 2 = 3
    
    array.clear();
}

TEST(FigureArrayTest, Clear) {
    FigureArray array;
    
    array.addFigure(new Square());
    array.addFigure(new Rectangle());
    
    EXPECT_EQ(array.size(), 2);
    
    array.clear();
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, PrintAllEmpty) {
    FigureArray array;
    
    testing::internal::CaptureStdout();
    array.printAll();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("No figures in array"), std::string::npos);
}

TEST(FigureIOTest, SquareOutput) {
    Square square;
    
    testing::internal::CaptureStdout();
    square.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Square vertices"), std::string::npos);
}

TEST(FigureIOTest, RectangleOutput) {
    Rectangle rectangle;
    
    testing::internal::CaptureStdout();
    rectangle.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Rectangle vertices"), std::string::npos);
}

TEST(FigureIOTest, TrapezoidOutput) {
    Trapezoid trapezoid;
    
    testing::internal::CaptureStdout();
    trapezoid.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Trapezoid vertices"), std::string::npos);
}