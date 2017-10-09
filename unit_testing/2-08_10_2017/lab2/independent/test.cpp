//https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
//https://larry-price.com/blog/2013/10/13/installing-gtest-and-gmock-libs-in-ubuntu-13-dot-04/
#include <gtest/gtest.h>
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
