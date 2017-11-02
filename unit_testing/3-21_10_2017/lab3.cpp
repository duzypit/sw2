// #include <gtest/gtest.h>
// #include "gmock/gmock.h"

// #include <gmock/gmock-matchers.h>
// #include "../../../src/Picture.hpp"
// #include "../../../src/Rectangle.hpp"
// #include "../../../src/IShape.hpp"

#include <iostream>


#include "gmock/gmock.h"

#include "gtest/gtest.h"

#include "Picture.hpp"
#include "Rectangle.hpp"
#include "IShape.hpp"

using namespace testing;

class Mock_Shape : public IShape
{
    public:
        MOCK_METHOD0(getArea, double());
};

class LabTestClass : public Test
{
public:
    Pic

    virtual void SetUp()
    {

    }
    virtual void TearDown()
    {

    }
};

TEST_F(LabTestClass, TestNOK)
{
    Rectangle rec1(2,4);
    myPicture.addShape(&rec1);
    int ret = myPicture.getTotalArea();

    EXPECT_EQ(ret, 8);
}

TEST_F(LabTestClass, TestShape)
{
    Mock_Shape myMock;
    EXPECT_CALL(myMock, getArea())
            //.WillOnce(Return(10))
            .WillOnce(Return(20));
    myPicture.addShape(&myMock);

    EXPECT_EQ(20, myPicture.getTotalArea());
    //EXPECT_EQ(10, myPicture.getTotalArea());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
