#include <iostream>
#include "opencv2/core/core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <gtest/gtest.h>

#include "tinyexpr.h"

double calc(std::string expr)
{
    return te_interp(expr.data(), 0);
}


class TestCalc : public ::testing::Test
{
protected:
    std::string str;
    void SetUp()
    {
        str = "5+5";
    }

    void TearDown()
    {
        str = "";
    }
};

TEST_F(TestCalc,test1)
{
    ASSERT_DOUBLE_EQ(calc(str),10);
}

TEST_F(TestCalc, test2)
{
    str = "5*5+5";
    ASSERT_DOUBLE_EQ(calc(str),30);
}

TEST_F(TestCalc,test3)
{
    str = "5*5+1";
    ASSERT_DOUBLE_EQ(calc(str),26);
}

TEST_F(TestCalc, test4)
{
    str = "5+5+5";
    ASSERT_DOUBLE_EQ(calc(str),15);
}

TEST_F(TestCalc,test5)
{
    str = "5*5-5";
    ASSERT_DOUBLE_EQ(calc(str),20);
}

TEST_F(TestCalc, test6)
{
    str = "10/2-3";
    ASSERT_DOUBLE_EQ(calc(str),2);
}

TEST_F(TestCalc,test7)
{
    str = "(10/2)^3";
    ASSERT_DOUBLE_EQ(calc(str),125);
}

TEST_F(TestCalc, test8)
{
    str = "5*5+5";
    ASSERT_DOUBLE_EQ(calc(str),30);
}

TEST_F(TestCalc,test9)
{
    str = "10/2+3";
    ASSERT_DOUBLE_EQ(calc(str),8);
}

TEST_F(TestCalc, test10)
{
    str = "5*5+5";
    ASSERT_DOUBLE_EQ(calc(str),30);
}

TEST_F(TestCalc,test11)
{
    str = "10/2*3";
    ASSERT_DOUBLE_EQ(calc(str),15);
}

TEST_F(TestCalc, test12)
{
    str = "5^3+5";
    ASSERT_DOUBLE_EQ(calc(str),130);
}


int main(int arhc, char * argv[])
{

   ::testing::InitGoogleTest(&arhc, argv);
   return RUN_ALL_TESTS();
}
