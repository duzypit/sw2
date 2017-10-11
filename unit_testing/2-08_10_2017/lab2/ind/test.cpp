d//https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
//https://larry-price.com/blog/2013/10/13/installing-gtest-and-gmock-libs-in-ubuntu-13-dot-04/
//http://www.bogotobogo.com/cplusplus/google_unit_test_gtest.php


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

//oryginalny plik main txt
/*
   Picture myPicture;
   myPicture.addShape(new Rectangle(2,4));
   myPicture.addShape(new Rectangle(4,4));
   myPicture.addShape(new Triangle(2,4));
   myPicture.addShape(new Triangle(4,4));
   std::cout << "Total area size = " << myPicture.getTotalArea() << std::endl;    
*/
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
