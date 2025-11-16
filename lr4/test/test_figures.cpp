#include <gtest/gtest.h>
#include <cmath>
#include "Point.h"
#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Array.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(PointTest, CreationAndOperations) {
    Point<int> p1(1, 2);
    Point<int> p2(1, 2);
    Point<int> p3(3, 4);
    
    EXPECT_EQ(p1.getX(), 1);
    EXPECT_EQ(p1.getY(), 2);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    
    Point<int> sum = p1 + p3;
    EXPECT_EQ(sum.getX(), 4);
    EXPECT_EQ(sum.getY(), 6);
    
    Point<int> div = p1 / 2;
    EXPECT_EQ(div.getX(), 0);
    EXPECT_EQ(div.getY(), 1);
}

TEST(RhombusTest, CreationAndArea) {
    Rhombus<double> rhombus(4.0, 6.0);
    
    EXPECT_DOUBLE_EQ(rhombus.area(), 12.0);
    
    Point<double> center = rhombus.geometricCenter();
    EXPECT_DOUBLE_EQ(center.getX(), 0.0);
    EXPECT_DOUBLE_EQ(center.getY(), 0.0);
    
    EXPECT_EQ(rhombus.getName(), "Rhombus");
}

TEST(PentagonTest, CreationAndArea) {
    Pentagon<double> pentagon(1.0);
    double area = pentagon.area();
    
    double expected_area = (5.0 / 2.0) * 1.0 * 1.0 * std::sin(2 * M_PI / 5);
    EXPECT_NEAR(area, expected_area, 1e-10);
    
    Point<double> center = pentagon.geometricCenter();
    EXPECT_DOUBLE_EQ(center.getX(), 0.0);
    EXPECT_DOUBLE_EQ(center.getY(), 0.0);
    
    EXPECT_EQ(pentagon.getName(), "Pentagon");
}

TEST(HexagonTest, CreationAndArea) {
    Hexagon<double> hexagon(1.0);
    double area = hexagon.area();
    
    double expected_area = (3 * std::sqrt(3) / 2) * 1.0 * 1.0;
    EXPECT_NEAR(area, expected_area, 1e-10);
    
    Point<double> center = hexagon.geometricCenter();
    EXPECT_DOUBLE_EQ(center.getX(), 0.0);
    EXPECT_DOUBLE_EQ(center.getY(), 0.0);
    
    EXPECT_EQ(hexagon.getName(), "Hexagon");
}

TEST(FigureTest, DoubleConversion) {
    Rhombus<double> rhombus(3.0, 4.0);
    double area = static_cast<double>(rhombus);
    EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST(ArrayTest, BasicOperations) {
    Array<std::shared_ptr<Figure<int>>> array;
    
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 10);
    
    array.push_back(std::make_shared<Rhombus<int>>(2, 3));
    array.push_back(std::make_shared<Pentagon<int>>(4));
    
    EXPECT_EQ(array.getSize(), 2);
    
    EXPECT_EQ(array[0]->getName(), "Rhombus");
    EXPECT_EQ(array[1]->getName(), "Pentagon");
    
    array.remove(0);
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_EQ(array[0]->getName(), "Pentagon");
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    array.push_back(std::make_shared<Rhombus<double>>(2.0, 3.0));
    array.push_back(std::make_shared<Rhombus<double>>(4.0, 5.0));
    
    double total_area = array.totalArea();
    EXPECT_DOUBLE_EQ(total_area, 13.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}