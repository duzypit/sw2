#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "IShape.hpp"
#include "Rectangle.hpp"
#include "Picture.hpp"

TEST(Picture, TestRectangle) {
    Picture myPicture;
    Rectangle rec1(2,4);
    myPicture.addShape(&rec1);
    int ret = myPicture.getTotalArea();

    EXPECT_EQ(ret, 8);
}

TEST_F(Mock_Shape, TestShape) {
    Mock_Shape myMock;
    EXPECT_CALL(myMock, getArea())
            //.WillOnce(Return(10))
            .WillOnce(Return(20));
    myPicture.addShape(&myMock);

    EXPECT_EQ(20, myPicture.getTotalArea());
    //EXPECT_EQ(10, myPicture.getTotalArea());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();

}
