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
#include <algorithm>

template <std::size_t N, std::size_t M, typename T>
class Matrix {
   public:
    // default ctor
    Matrix() : _data() {}
    // Trochę bardziej czytelne
    ~Matrix() = default;

    // add op
    template <std::size_t N1, std::size_t M1, typename T1>
    Matrix<N, M, T> operator+(Matrix<N1, M1, T1>& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        if constexpr (!std::is_convertible<T, T1>::value) {
            static_assert(std::is_convertible<T, T1>::value, "Martix add: type of second matrix is not convertible");
        }

        // To powinien być błąd na etapie kompilacji, nie runtime
        if (N != N1 || M != M1) {
            static_assert("Matrix add: size mismatch");
        }

        // Da się zastosować jakiś algorytm STL'a?
        Matrix<N,M,T> tmp;
        std::transform(_data.begin(), _data.end(), rhs.begin(), tmp.begin(), [](T f, T1 s) -> T {return f+s;});

        return tmp;
    }

    // multiply op
    template <std::size_t N1, std::size_t M1, typename T1>
    Matrix<N, M, T> operator*(const Matrix<N1, M1, T1>& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        if constexpr (!std::is_convertible<T, T1>::value) {
            static_assert(std::is_convertible<T, T1>::value, "Martix multiply: type of second matrix is not convertible");
        }


        // To powinien być błąd na etapie kompilacji, nie runtime
        if (N != M1) {
            static_assert("Matrix multiply: size mismatch");
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
    // rozumiem, że chodziło o sytuację A+b*I? Jeśi tak, poniżej kod
    // scalar add op
    template <typename T1>
    Matrix<N, M, T> operator+(const T1& scalar) {

        Matrix<N, M, T> tmp;
        tmp.fill(0);

        std::size_t diagCounter = 0;
        if(N > M) {
            diagCounter = N;
        } else {
            diagCounter = M;
        }

        for(std::size_t x = 0; x < diagCounter; ++x){
            tmp(x,x) = 1;
        }

        Matrix<N,M,T> scalarMultipliedByIdentity = tmp * scalar;

        std::cout << scalarMultipliedByIdentity << std::endl;

        return scalarMultipliedByIdentity;
    }

    // scalar multiply op
    template <typename T1>
    auto operator*(const T1& rhs) {
        // To powinien być błąd na etapie kompilacji, nie runtime
        if constexpr (!std::is_convertible<T, T1>::value) {
            static_assert(std::is_convertible<T, T1>::value, "Martix multiply: type of second matrix is not convertible");
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
    T operator[](const int& index) const { return _data[index]; }

    T& operator[](int index) { return _data[index]; }

    // Sygnatura funkcji nie do końca prawidłowa
    T operator()(const std::size_t& row, const std::size_t& col) const {
        if (row <= N && col <= M) {
            return _data[M * row + col];
        }
        throw std::out_of_range("operator(): target id out of range");
    }

    T& operator()(const std::size_t row, const std::size_t col) {
        if (row <= N && col <= M) {
            return _data[M * row + col];
        }
        throw std::out_of_range("operator(): target id out of range");
    }

    auto begin(){
        return _data.begin();
    }

    auto end(){
        return _data.end();
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
        std::fill(_data.begin(), _data.begin() + (N * M), val);
    }

    template <typename T1>
    void fill (T1 val){
        if constexpr (!std::is_convertible<T, T1>::value) {
            static_assert("Martix fill: type of second var is not convertible");
        } else {
            T compTypeVal = reinterpret_cast<T>(val);
            std::fill(_data.begin(), _data.begin() +(N*M), compTypeVal);
        }

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
TEST(Matrix, Matrix_add_scalar){
    Matrix<2,2,float> m;
    m.fill(0);
    auto m2 = m + 2.0;
    EXPECT_EQ(m2(1,1), 2.0);
}

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
/*
TEST(Matrix, Matrix_add_scalar) {
    Matrix<2, 2, int> m;
    int scalar = 5;
    EXPECT_ANY_THROW(m + scalar);
}
*/
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

