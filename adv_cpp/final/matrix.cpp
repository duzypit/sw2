/*
Matrix<M,N,T>
Napisać implementację:
posiada operatory:
dodawania macierzy (+)
    mnożenia macierzy (+)
    dodawania skalara do macierzy (+)
    mnożenia macierzy przez skalar (+)
    dostarcza konstruktory:
    domyślny
    kopiujący (+)
    przesuwający*

    Zadanie dodatkowe: gdzie występuje (+) implementacja ma działać dla typu T1 który jest konwertowalny do typu T
*/
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

template<std::size_t N, std::size_t M, typename T>
class Matrix{
public:
	//default ctor
	Matrix() : _data(N*M) {}

	//copy ctor
/*  template<int N1, int M1, typename T1>
	Matrix(const Matrix<N1,M1,T1>&) {}b
*/
    //move ctor

    //add op
    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix<N,M,T> operator+(const Matrix<N1,M1,T1>& rhs){
        if(!std::is_convertible<T, T1>::value){
            throw std::runtime_error("Martix add: type of second matrix is not convertiblel");
        }

        if(N != N1 || M != M1){
            throw std::runtime_error("Matrix add: size mismatch");
        }

        Matrix<N, M, T> tmp;

        std::size_t row = 0;
        std::size_t col = 0;
        for(const auto& v : _data){

            tmp(row, col) = v + rhs(row,col);
            ++col;
            if(col >= M){
                col = 0;
                ++row;
            }

        }

        return tmp;
    };

    //multiply op
    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix<M1,N,T> operator*(const Matrix<N1,M1,T1>& rhs) {
        if(!std::is_convertible<T, T1>::value){
            throw std::runtime_error("Martix multiply: type of second matrix is not convertiblel");
        }

        if(N != M1){
            throw std::runtime_error("Matrix multiply: size mismatch");
        }

        Matrix<M1, N, T> tmp;
        std::size_t row;
        std::size_t col;
        std::size_t inner;
        for(row = 0; row != N; ++row){
            for(col = 0; col != M1; ++col){
                T sum = 0;
                for(inner = 0; inner != M1; ++inner){
                    //std::cout<< row << "," << inner << " += " << row << "," << inner << " * " << inner << "," << row << std::endl;
                    //std::cout << "Multi: " << this->_data[this->_cols * row + inner] << " * " << rhs(inner, col) << std::endl;
                    std::cout << "row " << row << ", col " << col << ", inner " << inner << ", m1 val " << (*this)(row, inner) << ", m2 val " << rhs(inner,col) << std::endl;
                    sum += ((*this)(row,inner) * rhs(inner,col));
                }
                tmp(row,col) = sum;
            }
        }

        return tmp;

    }


    //scalar add op


    //scalar multiply op


    T operator[](int index) const{
        return this->_data[index];
    }

	T& operator[](int index){
        return this->_data[index];
    }

    T operator() (std::size_t row, std::size_t col) const{
        if(row <= this->_rows && col <= this->_cols){
            return this->_data[this->_cols *row + col];
        }

        throw std::runtime_error("wrong boundaries");

    }

    T& operator() (const std::size_t row, const std::size_t col){
       if(row <= this->_rows && col <= this->_cols){
            return this->_data[this->_cols *row + col];
        } else {
            throw std::runtime_error("wrong boundaries");
        }
    }

	friend std::ostream& operator<<(std::ostream& os, const Matrix<N,M,T>& mat){
            std::size_t currentCol = 0;
            //tutaj wyłącznie for(;;) nie range loop
            for(auto v : mat._data){
                currentCol++;
                if(currentCol > mat._cols){
                    currentCol = 0;
                    os << std::endl;
                }
                os << "  " << v <<  "  ";
            }

        return os;
	}


    void fill(T val){
        std::fill(this->_data.begin(), this->_data.begin()+(N*M), val);
    }

    void printData(){
        for(auto v : this->_data){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

private:
    std::size_t _rows = N;
    std::size_t _cols = M;
    std::vector<T> _data;
};

template<std::size_t N, std:: size_t M>
class Matrix<N, M, bool>{
public:
	Matrix() {
		static_assert(true, "Bool type is not supported!");
        std::cout << "Bool type is not supported!" << std::endl;

	}
};

template<typename T>
class Matrix<0,0, T>{
public:
	Matrix(){
		static_assert(true, "Matrix for N = 0 && M = 0 cannot be created!");
        std::cout << "Matrix for N = 0 && M =0 cannot be created!" << std::endl;
	}
};
/*
int main(){
    /*
    //spec for 0,0
    Matrix <0,0,int> intz;
    //spec for bool - error, spec don't work
    Matrix<1, 1, bool> boolz;

    Matrix<2,3, int> proper;
    //indirect use of operator[]
    proper(0,0) = 1;
    proper(0,1) = 5;
    proper(0,2) = 0;
    proper(1,0) = 2;
    proper(1,1) = -3;
    proper(1,2) = 1;

    //operator<<
//    std::cout << proper << std::endl;


    Matrix<3,2, int> m1;
    m1(0,0) = 0;
    m1(0,1) = -2;
    m1(1,0) = 1;
    m1(1,1) = 1;
    m1(2,0) = 3;
    m1(2,1) = 4;

    auto m2 = m1 * proper;
    std::cout << m2 << std::endl;
    return 0;


}*/

TEST(Matrix, M2MMultiply){
    Matrix<2,3, int> m1;
    m1(0,0) = 1;
    m1(0,1) = 1;
    m1(0,2) = 1;
    m1(1,0) = 1;
    m1(1,1) = 1;
    m1(1,2) = 1;


    Matrix<3,2, float> m2;
    m2(0,0) = 1.0;
    m2(0,1) = 1.0;
    m2(1,0) = 1.0;
    m2(1,1) = 1.0;
    m2(2,0) = 1.0;
    m2(2,1) = 1.0;

    auto m3 = m1 * m2;
    std::cout<< m3 << std::endl;
    //EXPECT_EQ(m3(0,0), 1);
    //EXPECT_EQ(m3(0,0), 1);*/
}

/*
TEST(Matrix, M2MAdd){
    Matrix<2,3, int> m1;
    m1(0,0) = 0;
    m1(0,1) = -2;
    m1(1,0) = 1;
    m1(1,1) = 1;
    m1(2,0) = 3;
    m1(2,1) = 4;


    Matrix<2,3, float> m2;
    m2(0,0) = 1.0;
    m2(0,1) = 5.0;
    m2(0,2) = 0.0;
    m2(1,0) = 2.0;
    m2(1,1) = -3.0;
    m2(1,2) = 1.0;

    auto m3 = m1 + m2;
    std::cout<< m3 << std::endl;
    //EXPECT_EQ(1, 1);
    EXPECT_EQ(m3(0,0), 1);
}
*/


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
