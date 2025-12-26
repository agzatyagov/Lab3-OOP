#include <gtest/gtest.h>
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "array.h"

TEST(RectangleTest, AreaAndCenter)
{
    Point a(0.0, 0.0);
    Point b(4.0, 0.0);
    Point c(4.0, 2.0);
    Point d(0.0, 2.0);

    Rectangle r(a, b, c, d);

    double s = (double)r;
    Point central_tochka = r.center();

    EXPECT_NEAR(s, 8.0, 1e-9);
    EXPECT_NEAR(central_tochka.x, 2.0, 1e-9);
    EXPECT_NEAR(central_tochka.y, 1.0, 1e-9);
}

TEST(TrapezoidTest, AreaAndCenter)
{
    Point a(0.0, 0.0);
    Point b(4.0, 0.0);
    Point c(3.0, 2.0);
    Point d(1.0, 2.0);

    Trapezoid t(a, b, c, d);

    double s = (double)t;
    Point central_tochka = t.center();

    EXPECT_NEAR(s, 6.0, 1e-9);
    EXPECT_NEAR(central_tochka.x, 2.0, 1e-9);
    EXPECT_NEAR(central_tochka.y, 8.0 / 9.0, 1e-9);
}

TEST(RhombusTest, AreaAndCenter)
{
    Point a(0.0, 0.0);
    Point b(2.0, 1.0);
    Point c(4.0, 0.0);
    Point d(2.0, -1.0);

    Rhombus r(a, b, c, d);

    double s = (double)r;
    Point central_tochka = r.center();

    EXPECT_NEAR(s, 4.0, 1e-9);
    EXPECT_NEAR(central_tochka.x, 2.0, 1e-9);
    EXPECT_NEAR(central_tochka.y, 0.0, 1e-9);
}

TEST(ArrayTest, TotalAreaAndRemove)
{
    Array arr;

    {
        Point a(0.0, 0.0);
        Point b(4.0, 0.0);
        Point c(4.0, 2.0);
        Point d(0.0, 2.0);

        Figure* f = new Rectangle(a, b, c, d);
        arr.push_back(f);
    }

    {
        Point a(0.0, 0.0);
        Point b(2.0, 1.0);
        Point c(4.0, 0.0);
        Point d(2.0, -1.0);

        Figure* f = new Rhombus(a, b, c, d);
        arr.push_back(f);
    }

    double total = arr.total_area();
    EXPECT_NEAR(total, 12.0, 1e-9);

    bool ok = arr.remove(0);
    EXPECT_TRUE(ok);

    double total2 = arr.total_area();
    EXPECT_NEAR(total2, 4.0, 1e-9);

    EXPECT_EQ(arr.size(), (std::size_t)1);
}