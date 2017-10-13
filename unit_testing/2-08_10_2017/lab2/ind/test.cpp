#include <iostream>
#include "/home/test/sw2/unit_testing/2-08_10_2017/lab2/gtest/googlemock/include/gmock/gmock.h"

#include "Picture.hpp"
#include "Rectangle.hpp"
using namespace testing;

TEST(LabTest, TestOK)
{
    Picture myPicture;
    Rectangle rec1(2,4);
    myPicture.addShape(&rec1);
    ASSERT_THAT(myPicture.getTotalArea(), 8);
}
TEST(LabTest, TestNOK)
{
    Picture myPicture;
    Rectangle rec1(2,4);
    myPicture.addShape(&rec1);
    ASSERT_THAT(myPicture.getTotalArea(), 9);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
