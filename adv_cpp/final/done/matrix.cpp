/*
Matrix<M,N,T>
Napisać implementację:
posiada operatory:
x dodawania macierzy (+)
x mnożenia macierzy (+)
xdodawania skalara do macierzy (+)
xmnożenia macierzy przez skalar (+)
    dostarcza konstruktory:
xdomyślny
xkopiujący (+)
    przesuwający*

    Zadanie dodatkowe: gdzie występuje (+) implementacja ma działać dla typu T1
który jest konwertowalny do typu T
*/
#include <gtest/gtest.h>
#include <iostream>
#include <array>
#include <type_traits>

template <std::size_t N, std::size_t M, typename T>
class Matrix {
   public:
    // default ctor
    Matrix() : _data() {}
    // Trochę bardziej czytelne
    ~Matrix() = default;
    // add op
    template <std::size_t N1, std::size_t M1, typename T1>
    Matrix<N, M, T> operator+(const Matrix<N1, M1, T1>& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        //if (!std::is_convertible<T, T1>::value) {
            static_assert(!std::is_convertible<T, T1>::value,"Martix add: type of second matrix is not convertible");
        //}

        if (N != N1 || M != M1) {
            throw std::runtime_error("Matrix add: size mismatch");
        }

        Matrix<N, M, T> tmp;

        // Da się zastosować jakiś algorytm STL'a?
        std::size_t row = 0;
        std::size_t col = 0;
        for (const auto& v : _data) {
            tmp(row, col) = v + rhs(row, col);
            ++col;
            if (col >= M) {
                col = 0;
                ++row;
            }
        }
        return tmp;
    };

    // multiply op
    template <std::size_t N1, std::size_t M1, typename T1>
    Matrix<N, M, T> operator*(const Matrix<N1, M1, T1>& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        if (!std::is_convertible<T, T1>::value) {
            throw std::runtime_error(
                "Martix multiply: type of second matrix is not convertiblel");
        }

        // To powinien być błąd na etapie kompilacji, nie runtime
        if (N != M1) {
            throw std::runtime_error("Matrix multiply: size mismatch");
        }

        Matrix<N, M, T> tmp;
        std::size_t row;
        std::size_t col;
        std::size_t inner;
        std::size_t innerMax = N1;
        for (row = 0; row < N; ++row) {
            for (col = 0; col < M; ++col) {
                T sum = 0;
                for (inner = 0; inner < innerMax; ++inner) {
                    sum += ((*this)(row, inner) * rhs(inner, row));
                }
                tmp(row, col) = sum;
            }
        }
        return tmp;
    }

    // BATA: ?????? Dlaczego??
    // scalar add op
    template <typename T1>
    Matrix<N, M, T> operator+(const T1&) {
        throw std::runtime_error("Martix + scalar: op is forbidden ;)");
    }

    // scalar multiply op
    template <typename T1>
    auto operator*(const T1& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        if (!std::is_convertible<T, T1>::value) {
            throw std::runtime_error(
                "Martix multiply by scalar: type of scalar is not "
                "convertiblel");
        }

        Matrix<N, M, T> tmp;
        std::size_t row = 0;
        std::size_t col = 0;

        for (auto v : _data) {
            T x = v * rhs;
            tmp(row, col) = x;
            ++col;
            if (col == M) {
                col = 0;
                ++row;
            }
        }
        return tmp;
    }

    // Sygnatura funkcji nie do końca prawidłowa
    T operator[](int index) const { return this->_data[index]; }

    T& operator[](int index) { return this->_data[index]; }

    // Sygnatura funkcji nie do końca prawidłowa
    T operator()(std::size_t row, std::size_t col) const {
        if (row <= N && col <= M) {
            return this->_data[M * row + col];
        }

        throw std::out_of_range("operator(): target id out of range");
    }

    T& operator()(const std::size_t row, const std::size_t col) {
        if (row <= N && col <= M) {
            return this->_data[M * row + col];
        }
        throw std::out_of_range("operator(): target id out of range");
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const Matrix<N, M, T>& mat) {
        std::size_t currentCol = 0;
        for (auto v : mat._data) {
            if (currentCol == M) {
                currentCol = 0;
                os << std::endl;
            }
            currentCol++;
            os << "  " << v << "  ";
        }
        return os;
    }

    // Jeżeli T =float, to nie mogę zrobić T(0)
    void fill(T val) {
        std::fill(this->_data.begin(), this->_data.begin() + (N * M), val);
    }

   private:
    //vector??????, Rozmiar jest znany w czasie kompilacji
    std::array<T, N*M> _data;
};

template <std::size_t N, std::size_t M>
class Matrix<N, M, bool> {
   public:
    Matrix() {
        static_assert(true, "Bool type is not supported!");
        std::cout << "Bool type is not supported!" << std::endl;
    }
};

template <typename T>
class Matrix<0, 0, T> {
   public:
    Matrix() {
        static_assert(true, "Matrix for N = 0 && M = 0 cannot be created!");
        std::cout << "Matrix for N = 0 && M =0 cannot be created!" << std::endl;
    }
};

TEST(Matrix, M2M_add) {
    Matrix<2, 2, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 1;

    Matrix<2, 2, float> m2;
    m2(0, 0) = 2.0;
    m2(0, 1) = 2.0;
    m2(1, 0) = 2.0;
    m2(1, 1) = 2.0;

    auto m3 = m1 + m2;

    EXPECT_EQ(m3(1, 1), 3);
}

TEST(Matrix, M2M_Multiply_same_size) {
    Matrix<2, 2, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 1;

    Matrix<2, 2, float> m2;
    m2(0, 0) = 1.0;
    m2(0, 1) = 1.0;
    m2(1, 0) = 1.0;
    m2(1, 1) = 1.0;

    auto m3 = m1 * m2;
    EXPECT_EQ(m3(1, 1), 2);
}

TEST(Matrix, M2M_Multiply_dif_size) {
    Matrix<2, 3, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(0, 2) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 1;
    m1(1, 2) = 1;

    Matrix<3, 2, float> m2;
    m2(0, 0) = 1.0;
    m2(0, 1) = 1.0;
    m2(1, 0) = 1.0;
    m2(1, 1) = 1.0;
    m2(2, 0) = 1.0;
    m2(2, 1) = 1.0;

    auto m3 = m1 * m2;
    EXPECT_EQ(m3(1, 2), 3);
}

TEST(Matrix, Matrix_multiplication_by_scalar) {
    Matrix<2, 2, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 1;

    float scalar = 5;

    auto m2 = m1 * scalar;
    EXPECT_EQ(m2(1, 1), 5);
}

TEST(Matrix, Matrix_add_scalar) {
    Matrix<2, 2, int> m;
    int scalar = 5;
    EXPECT_ANY_THROW(m + scalar);
}

TEST(Matrix, Copy_ctor) {
    Matrix<2, 2, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 4;

    auto m2(m1);

    EXPECT_EQ(m2(1, 1), 4);
}

TEST(Matrix, Move_ctor) {
    Matrix<2, 2, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 1;
    m1(1, 0) = 1;
    m1(1, 1) = 5;

    auto m2(std::move(m1));

    EXPECT_EQ(m2(1, 1), 5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

