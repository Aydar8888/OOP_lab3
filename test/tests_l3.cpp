#include <gtest/gtest.h>
#include "../include/array.h"
#include "../include/figure.h"
#include "../include/point.h"
#include "../include/rectangle.h"
#include "../include/rhomb.h"
#include "../include/trapezoid.h"

TEST(RectangleTest, Area) {
    Rectangle r1(0, 0, 4, 5);
    EXPECT_DOUBLE_EQ(r1.area(), 20.0);

    Rectangle r2(0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(r2.area(), 0.0);

    Rectangle r3(-1, -1, 1, 1);
    EXPECT_DOUBLE_EQ(r3.area(), 1.0);

    Rectangle r4(-1, 1, 0.5, 0.5);
    EXPECT_DOUBLE_EQ(r4.area(), 0.25);

    Rectangle r5(-10, -10, 4, 6);
    EXPECT_DOUBLE_EQ(r5.area(), 24.0);

    Rectangle r6(-100, 50, 10, 20);
    EXPECT_DOUBLE_EQ(r6.area(), 200.0);

    Rectangle r7(1.5, 2.5, 2.5, 3.5);
    EXPECT_DOUBLE_EQ(r7.area(), 8.75);

    Rectangle r8(-2.25, -1.75, 0.5, 1.25);
    EXPECT_DOUBLE_EQ(r8.area(), 0.625);

    Rectangle r9(0, 0, 1000, 2000);
    EXPECT_DOUBLE_EQ(r9.area(), 2000000.0);

    EXPECT_THROW(Rectangle r10(1, 1, -1, 2), std::invalid_argument);
}

TEST(RectangleTest, Center) {
    Rectangle r1(0, 0, 4, 6);
    Point c1 = r1.center();
    EXPECT_DOUBLE_EQ(c1.get_x(), 2.0);
    EXPECT_DOUBLE_EQ(c1.get_y(), 3.0);

    Rectangle r2(1, 1, 4, 6);
    Point c2 = r2.center();
    EXPECT_DOUBLE_EQ(c2.get_x(), 3.0);
    EXPECT_DOUBLE_EQ(c2.get_y(), 4.0);

    Rectangle r3(-2, -3, 4, 6);
    Point c3 = r3.center();
    EXPECT_DOUBLE_EQ(c3.get_x(), 0.0);
    EXPECT_DOUBLE_EQ(c3.get_y(), 0.0);

    Rectangle r4(5, 5, 0, 0);
    Point c4 = r4.center();
    EXPECT_DOUBLE_EQ(c4.get_x(), 5.0);
    EXPECT_DOUBLE_EQ(c4.get_y(), 5.0);

    Rectangle r5(-5, -5, 0, 0);
    Point c5 = r5.center();
    EXPECT_DOUBLE_EQ(c5.get_x(), -5.0);
    EXPECT_DOUBLE_EQ(c5.get_y(), -5.0);

    Rectangle r6(-10, -10, 4, 6);
    Point c6 = r6.center();
    EXPECT_DOUBLE_EQ(c6.get_x(), -8.0);
    EXPECT_DOUBLE_EQ(c6.get_y(), -7.0);

    Rectangle r7(-4, 2, 8, 4);
    Point c7 = r7.center();
    EXPECT_DOUBLE_EQ(c7.get_x(), 0.0);
    EXPECT_DOUBLE_EQ(c7.get_y(), 4.0);

    Rectangle r8(0.5, 1.5, 3.0, 4.0);
    Point c8 = r8.center();
    EXPECT_DOUBLE_EQ(c8.get_x(), 2.0);
    EXPECT_DOUBLE_EQ(c8.get_y(), 3.5);

    Rectangle r9(-1.5, -2.5, 2.0, 2.0);
    Point c9 = r9.center();
    EXPECT_DOUBLE_EQ(c9.get_x(), -0.5);
    EXPECT_DOUBLE_EQ(c9.get_y(), -1.5);

    Rectangle r10(-1000000, -1000000, 200000, 300000);
    Point c10 = r10.center();
    EXPECT_DOUBLE_EQ(c10.get_x(), -900000.0);
    EXPECT_DOUBLE_EQ(c10.get_y(), -850000.0);
}

TEST(RectangleTest, Equality) {
    Rectangle r1(0, 0, 4, 5);
    Rectangle r2(0, 0, 4, 5);
    EXPECT_TRUE(r1 == r2);

    Rectangle r3(1, 0, 4, 5);
    EXPECT_FALSE(r1 == r3);

    Rectangle r4(0, 0, 3.9, 5);
    EXPECT_FALSE(r1 == r4);

    Rectangle r5(0, 0, 4, 6);
    EXPECT_FALSE(r1 == r5);

    Rectangle r6(2, 2, 10, 10);
    EXPECT_FALSE(r1 == r6);

    Rectangle r7(0, 0, 0, 0);
    Rectangle r8(0, 0, 0, 0);
    EXPECT_TRUE(r7 == r8);

    Rectangle r9(-5, -5, 2, 3);
    Rectangle r10(-5, -5, 2, 3);
    EXPECT_TRUE(r9 == r10);

    Rectangle r11(-5, -4.9, 2, 3);
    EXPECT_FALSE(r9 == r11);
}

TEST(RectangleTest, Print) {
    Rectangle r1(0, 0, 4, 3);
    std::ostringstream os1;
    r1.print(os1);
    EXPECT_EQ(os1.str(), "Прямоугольник: (0, 0), (0, 3), (4, 3), (4, 0)");

    Rectangle r2(2, 1, 3, 2);
    std::ostringstream os2;
    r2.print(os2);
    EXPECT_EQ(os2.str(), "Прямоугольник: (2, 1), (2, 3), (5, 3), (5, 1)");

    Rectangle r3(-2, -3, 4, 6);
    std::ostringstream os3;
    r3.print(os3);
    EXPECT_EQ(os3.str(), "Прямоугольник: (-2, -3), (-2, 3), (2, 3), (2, -3)");

    Rectangle r4(1.5, 2.5, 2.0, 1.0);
    std::ostringstream os4;
    r4.print(os4);
    EXPECT_EQ(os4.str(), "Прямоугольник: (1.5, 2.5), (1.5, 3.5), (3.5, 3.5), (3.5, 2.5)");

    Rectangle r5(5, 5, 0, 0);
    std::ostringstream os5;
    r5.print(os5);
    EXPECT_EQ(os5.str(), "Прямоугольник: (5, 5), (5, 5), (5, 5), (5, 5)");

    std::ostringstream os6;
    os6 << r1;
    EXPECT_EQ(os6.str(), "Прямоугольник: (0, 0), (0, 3), (4, 3), (4, 0)");
}

TEST(RectangleTest, CopyConstructor) {
    Rectangle original(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(double(original), 12.0);  

    Rectangle copy(original);

    EXPECT_TRUE(copy == original);

    Point orig_center = original.center();
    Point copy_center = copy.center();
    EXPECT_DOUBLE_EQ(orig_center.get_x(), copy_center.get_x());
    EXPECT_DOUBLE_EQ(orig_center.get_y(), copy_center.get_y());
    EXPECT_DOUBLE_EQ(double(copy), double(original));
}

TEST(RectangleTest, Operator1) {
    Rectangle r1(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(double(r1), 12.0);

   
    Rectangle r2(10.0, 20.0, 5.0, 6.0);
    EXPECT_DOUBLE_EQ(double(r2), 30.0);
    r1 = r2;
    EXPECT_TRUE(r1 == r2);
}

TEST(RectangleTest, DoubleConversionOperator) {
    Rectangle r1(0, 0, 4, 5);
    EXPECT_DOUBLE_EQ(double(r1), 20.0);

    Rectangle r2(0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(double(r2), 0.0);

    Rectangle r3(0, 0, 1, 1);
    EXPECT_DOUBLE_EQ(double(r3), 1.0);

    Rectangle r4(0, 0, 2.5, 3.5);
    EXPECT_DOUBLE_EQ(double(r4), 8.75);

    Rectangle r5(-2, -3, 4, 5);
    EXPECT_DOUBLE_EQ(double(r5), 20.0);

    Rectangle r8(10, 10, 10, 10);
    EXPECT_DOUBLE_EQ(double(r8), 100.0);

    Rectangle r9(1, 1, 3, 4);
    Rectangle r10(std::move(r9));
    EXPECT_DOUBLE_EQ(double(r10), 12.0);
}


// ========================================================

TEST(RhombTest, Area) {
    Rhomb r1(0, 0, 4, 6);
    EXPECT_DOUBLE_EQ(r1.area(), 12.0);

    Rhomb r2(0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(r2.area(), 0.0);

    Rhomb r3(-1, -1, 2, 2);
    EXPECT_DOUBLE_EQ(r3.area(), 2.0);

    Rhomb r4(0, 0, 0.5, 1.25);
    EXPECT_DOUBLE_EQ(r4.area(), 0.3125);

    Rhomb r5(-10, -10, 4, 6);
    EXPECT_DOUBLE_EQ(r5.area(), 12.0);

    Rhomb r6(-100, 50, 10, 20);
    EXPECT_DOUBLE_EQ(r6.area(), 100.0);

    Rhomb r7(1.5, 2.5, 2.5, 3.5);
    EXPECT_DOUBLE_EQ(r7.area(), 4.375);

    EXPECT_THROW(Rhomb r8(0, 0, -1, 2), std::invalid_argument);
    EXPECT_THROW(Rhomb r9(0, 0, 2, -3), std::invalid_argument);
}

TEST(RhombTest, Center) {
    Rhomb r1(0, 0, 4, 6);
    Point c1 = r1.center();
    EXPECT_DOUBLE_EQ(c1.get_x(), 2.0);
    EXPECT_DOUBLE_EQ(c1.get_y(), 0.0);

    Rhomb r2(1, 1, 4, 6);
    Point c2 = r2.center();
    EXPECT_DOUBLE_EQ(c2.get_x(), 3.0);
    EXPECT_DOUBLE_EQ(c2.get_y(), 1.0);

    Rhomb r3(-2, -3, 4, 6);
    Point c3 = r3.center();
    EXPECT_DOUBLE_EQ(c3.get_x(), 0.0);
    EXPECT_DOUBLE_EQ(c3.get_y(), -3.0);

    Rhomb r4(5, 5, 0, 0);
    Point c4 = r4.center();
    EXPECT_DOUBLE_EQ(c4.get_x(), 5.0);
    EXPECT_DOUBLE_EQ(c4.get_y(), 5.0);
}

TEST(RhombTest, Equality) {
    Rhomb r1(0, 0, 4, 5);
    Rhomb r2(0, 0, 4, 5);
    EXPECT_TRUE(r1 == r2);

    Rhomb r3(1, 0, 4, 5);
    EXPECT_FALSE(r1 == r3);

    Rhomb r4(0, 0, 3.9, 5);
    EXPECT_FALSE(r1 == r4);

    Rhomb r5(0, 0, 4, 6);
    EXPECT_FALSE(r1 == r5);

    Rhomb r6(2, 2, 10, 10);
    EXPECT_FALSE(r1 == r6);
}

TEST(RhombTest, Print) {
    Rhomb r1(0, 0, 4, 6);
    std::ostringstream os1;
    r1.print(os1);
    EXPECT_EQ(os1.str(), "Ромб: (0, 0), (0, 3), (4, 0), (2, -3)");

    Rhomb r2(2, 1, 3, 2);
    std::ostringstream os2;
    r2.print(os2);
    EXPECT_EQ(os2.str(), "Ромб: (2, 1), (2, 2), (5, 1), (3.5, 0)");

    std::ostringstream os3;
    os3 << r1;
    EXPECT_EQ(os3.str(), "Ромб: (0, 0), (0, 3), (4, 0), (2, -3)");
}

TEST(RhombTest, CopyConstructor) {
    Rhomb original(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(double(original), 6.0);  

    Rhomb copy(original);

    EXPECT_TRUE(copy == original);

    Point orig_center = original.center();
    Point copy_center = copy.center();
    EXPECT_DOUBLE_EQ(orig_center.get_x(), copy_center.get_x());
    EXPECT_DOUBLE_EQ(orig_center.get_y(), copy_center.get_y());
    EXPECT_DOUBLE_EQ(double(copy), double(original));
}

TEST(RhombTest, Operator1) {
    Rhomb r1(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(double(r1), 6.0);

    Rhomb r2(10.0, 20.0, 5.0, 6.0);
    EXPECT_DOUBLE_EQ(double(r2), 15.0);
    r1 = r2;
    EXPECT_TRUE(r1 == r2);
}

TEST(RhombTest, DoubleConversionOperator) {
    Rhomb r1(0, 0, 4, 5);
    EXPECT_DOUBLE_EQ(double(r1), 10.0);

    Rhomb r2(0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(double(r2), 0.0);

    Rhomb r3(0, 0, 1, 1);
    EXPECT_DOUBLE_EQ(double(r3), 0.5);

    Rhomb r4(0, 0, 2.5, 3.5);
    EXPECT_DOUBLE_EQ(double(r4), 4.375);

    Rhomb r5(-2, -3, 4, 5);
    EXPECT_DOUBLE_EQ(double(r5), 10.0);

    Rhomb r8(10, 10, 10, 10);
    EXPECT_DOUBLE_EQ(double(r8), 50.0);

    Rhomb r9(1, 1, 3, 4);
    Rhomb r10(std::move(r9));
    EXPECT_DOUBLE_EQ(double(r10), 6.0);
}

// ==========================================

TEST(TrapezoidTest, Area) {
    Trapezoid t1(0, 0, 4, 6, 5);
    EXPECT_DOUBLE_EQ(t1.area(), 25.0);

    Trapezoid t2(0, 0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(t2.area(), 0.0);

    Trapezoid t3(-1, -1, 2, 2, 2);
    EXPECT_DOUBLE_EQ(t3.area(), 4.0);

    Trapezoid t4(0, 0, 0.5, 1.25, 1.0);
    EXPECT_DOUBLE_EQ(t4.area(), 0.875);

    Trapezoid t5(-10, -10, 4, 6, 3);
    EXPECT_DOUBLE_EQ(t5.area(), 15.0);

    Trapezoid t6(-100, 50, 10, 20, 5);
    EXPECT_DOUBLE_EQ(t6.area(), 75.0);

    EXPECT_THROW(Trapezoid t7(0, 0, -1, 2, 3), std::invalid_argument);
    EXPECT_THROW(Trapezoid t8(0, 0, 2, -3, 3), std::invalid_argument);
    EXPECT_THROW(Trapezoid t9(0, 0, 2, 3, -1), std::invalid_argument);
}

TEST(TrapezoidTest, Center) {
    Trapezoid t1(0, 0, 4, 6, 3);
    Point c1 = t1.center();
    double y1 = (3.0 * (4 + 2*6)) / (3*(4+6)); 
    EXPECT_DOUBLE_EQ(c1.get_x(), 2.0);
    EXPECT_DOUBLE_EQ(c1.get_y(), y1);

    Trapezoid t2(1, 1, 4, 6, 3);
    Point c2 = t2.center();
    double y2 = 1.0 + (3.0 * (4 + 2*6)) / (3*(4+6));
    EXPECT_DOUBLE_EQ(c2.get_x(), 3.0);
    EXPECT_DOUBLE_EQ(c2.get_y(), y2);

    Trapezoid t3(-2, -3, 4, 6, 3);
    Point c3 = t3.center();
    double y3 = -3.0 + (3.0 * (4 + 2*6)) / (3*(4+6));
    EXPECT_DOUBLE_EQ(c3.get_x(), 0.0);
    EXPECT_DOUBLE_EQ(c3.get_y(), y3);
}

TEST(TrapezoidTest, Equality) {
    Trapezoid t1(0, 0, 4, 5, 3);
    Trapezoid t2(0, 0, 4, 5, 3);
    EXPECT_TRUE(t1 == t2);

    Trapezoid t3(1, 0, 4, 5, 3);
    EXPECT_FALSE(t1 == t3);

    Trapezoid t4(0, 0, 3.9, 5, 3);
    EXPECT_FALSE(t1 == t4);

    Trapezoid t5(0, 0, 4, 6, 3);
    EXPECT_FALSE(t1 == t5);

    Trapezoid t6(0, 0, 4, 5, 2);
    EXPECT_FALSE(t1 == t6);
}

TEST(TrapezoidTest, Print) {
    Trapezoid t1(0, 0, 4, 6, 3);
    std::ostringstream os1;
    t1.print(os1);
    EXPECT_EQ(os1.str(), "Трапеция: (0, 0), (-1, 3), (5, 3), (4, 0)"); 

    Trapezoid t2(2, 1, 3, 2, 2);
    std::ostringstream os2;
    t2.print(os2);
    EXPECT_EQ(os2.str(), "Трапеция: (2, 1), (2.5, 3), (4.5, 3), (5, 1)"); 

    std::ostringstream os3;
    os3 << t1;
    EXPECT_EQ(os3.str(), "Трапеция: (0, 0), (-1, 3), (5, 3), (4, 0)");
}

TEST(TrapezoidTest, CopyConstructor) {
    Trapezoid original(1.0, 2.0, 3.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(double(original), 17.5);  

    Trapezoid copy(original);
    EXPECT_TRUE(copy == original);

    Point orig_center = original.center();
    Point copy_center = copy.center();
    EXPECT_DOUBLE_EQ(orig_center.get_x(), copy_center.get_x());
    EXPECT_DOUBLE_EQ(orig_center.get_y(), copy_center.get_y());
    EXPECT_DOUBLE_EQ(double(copy), double(original));
}

TEST(TrapezoidTest, Operator1) {
    Trapezoid t1(1.0, 2.0, 3.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(double(t1), 17.5);

    Trapezoid t2(10.0, 20.0, 5.0, 6.0, 2.0);
    EXPECT_DOUBLE_EQ(double(t2), 11.0);
    t1 = t2;
    EXPECT_TRUE(t1 == t2);
}

TEST(TrapezoidTest, DoubleConversionOperator) {
    Trapezoid t1(0, 0, 4, 5, 3);
    EXPECT_DOUBLE_EQ(double(t1), 13.5);

    Trapezoid t2(0, 0, 0, 0, 0);
    EXPECT_DOUBLE_EQ(double(t2), 0.0);

    Trapezoid t3(0, 0, 1, 1, 1);
    EXPECT_DOUBLE_EQ(double(t3), 1.0);

    Trapezoid t4(0, 0, 2.5, 3.5, 1.0);
    EXPECT_DOUBLE_EQ(double(t4), 3.0);

    Trapezoid t5(-2, -3, 4, 5, 6);
    EXPECT_DOUBLE_EQ(double(t5), 27.0);

    Trapezoid t8(10, 10, 10, 10, 10);
    EXPECT_DOUBLE_EQ(double(t8), 100.0);

    Trapezoid t9(1, 1, 3, 4, 5);
    Trapezoid t10(std::move(t9));
    EXPECT_DOUBLE_EQ(double(t10), 17.5);
}

// ==============================================

TEST(ArrayTest, AddAndSize) {
    Array arr;
    EXPECT_EQ(arr.size(), 0);

    arr.add(new Rectangle(0, 0, 4, 5));
    EXPECT_EQ(arr.size(), 1);

    arr.add(new Rhomb(0, 0, 4, 6));
    EXPECT_EQ(arr.size(), 2);

    arr.add(new Trapezoid(0, 0, 4, 6, 5));
    EXPECT_EQ(arr.size(), 3);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.add(new Rectangle(0, 0, 4, 5));   // 20
    arr.add(new Rhomb(0, 0, 4, 6));       // 12
    arr.add(new Trapezoid(0, 0, 4, 6, 5));// 25
    EXPECT_DOUBLE_EQ(arr.totalArea(), 57.0);
}

TEST(ArrayTest, Remove) {
    Array arr;
    arr.add(new Rectangle(0, 0, 4, 5));   
    arr.add(new Rhomb(0, 0, 4, 6));       
    arr.add(new Trapezoid(0, 0, 4, 6, 5));

    arr.remove(1); 
    EXPECT_EQ(arr.size(), 2);
    EXPECT_DOUBLE_EQ(arr.totalArea(), 45.0);

    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

TEST(ArrayTest, OperatorIndex) {
    Array arr;
    arr.add(new Rectangle(0, 0, 4, 5));
    arr.add(new Rhomb(0, 0, 4, 6));

    const Figure& f0 = arr[0];
    EXPECT_DOUBLE_EQ(double(f0), 20.0);

    const Figure& f1 = arr[1];
    EXPECT_DOUBLE_EQ(double(f1), 12.0);

    EXPECT_THROW(arr[5], std::out_of_range);
}

TEST(ArrayTest, AddNullptr) {
    Array arr;
    arr.add(nullptr); 
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, Resize) {
    Array arr(2); 
    arr.add(new Rectangle(0,0,1,1));
    arr.add(new Rhomb(0,0,1,1));
    arr.add(new Trapezoid(0,0,1,1,1)); 

    EXPECT_EQ(arr.size(), 3);
    EXPECT_DOUBLE_EQ(arr.totalArea(), 0.5 + 1 + 1.0); 
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}