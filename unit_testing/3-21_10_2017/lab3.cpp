#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "IShape.hpp"
#include "Rectangle.hpp"
#include "Picture.hpp"

using ::testing::Return;

class Mock_Shape : public IShape {
public:
    MOCK_METHOD0(getArea, double());
    MOCK_METHOD0(getCircuit, double());
};

TEST(Picture, TestRectangle) {
    Picture myPicture;
    Rectangle rec1(2,4);
    myPicture.addShape(&rec1);

    EXPECT_EQ(8, myPicture.getTotalArea()) << "GetTotalArea failed";
    EXPECT_EQ(12, rec1.getCircuit()) << "Rectangle getCircuit failed";
}

TEST(Mock_Shape, TestGetArea) {
//Zadanie domowe: dodać dodatkową metodę liczącą obwód wszystkich figur (w klasie Picture) i
//jej przetestownie. Podobnie jak w przypadku getTotalArea metoda ma korzystać z zewnętrznego
//interfejsu IShape. To jest ta zależnosc dla której trzeba napisać atrapę (mock lub stub)

    Mock_Shape myMock;
    Picture myPicture;

    EXPECT_CALL(myMock, getArea())
        .WillRepeatedly(Return(200));

    EXPECT_CALL(myMock, getCircuit())
        .WillRepeatedly(Return(100));
    myPicture.addShape(&myMock);

    EXPECT_EQ(200, myPicture.getTotalArea());
    EXPECT_EQ(100, myPicture.getTotalCircuit());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();

}
