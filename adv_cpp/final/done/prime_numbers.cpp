/*
Liczby pierwsze
Napisać program który:
na wejściu dostaje N liczb (czytane z pliku)  (liczby są nie większe niż  9223372036854775807
        implementuje 3 algorytmy sprawdzanie czy liczba jest pierwsza
        sprawdza N liczb każdym algorytmem i podaje na wyjściu czas wykonania dla każdego algorytmy (std::chrono)
        Program ma używać wielu wątków do sprawdzania, ale nie więcej niż ilość rdzeni na używanej maszynie (jeżeli N == 4 to odpalamy 4 wątki, jeżeli N == 100, to odpalamy nproc i dzielimy zbiór liczba na odpowiednie podzbiory)
        Przykładowo: nproc =2 && N = 17. Mamy tylko dwa wątki, tak więc dzielimy zbiór na dwa podzbiory - jeden o wielkości
        algorytmy to:
        Trial division (https://en.wikipedia.org/wiki/Primality_test#Simple_methods)
        Miller–Rabin
        mpz_probab_prime_p (https://gmplib.org/manual/Prime-Testing-Algorithm.html)
        sudo apt-get install libgmp5-dev
        gmp.h: the header files for the declarations exported from the library,
        libgmp.[a,so,dyl]: the library compiled either statically or dynamically.
        https://gmplib.org/manual/Number-Theoretic-Functions.html

*/

#include <iostream>
#include <gtest/gtest.h>
#include <numeric>
#include <thread>
#include <cmath>
#include <memory>
#include <gmp.h>

class PNumbers
{
    public:
        PNumbers() : _v(1000000)
        {
            setUp();
            createThreads();
        }

        ~PNumbers(){
/*            for(auto& t: _t){
                t->join();
            }
*/        }

        bool empty()
        {
            return _v.empty();
        }

        unsigned numOfThreadSupported()
        {
            return _threadNo;
        }
    private:

        std::vector<unsigned long int> _v;
        std::size_t _threadNo = 0;
        std::vector<std::pair<std::size_t, std::size_t>> _partitions;
        std::vector<std::unique_ptr<std::thread>> _t;

        bool setUp(){
            /*std::ifstream ifs(f);
            unsigned long int num = 0;
            while(ifs >> num)
            {
                _v.push_back(num);
            }
            */
            //std::cout << "No of loaded nums: " << _v.size() << std::endl;

            std::iota(std::begin(_v), std::end(_v), 0);
            std::cout << "Size: " << _v.size() << "Element 99999" << _v[99999] << std::endl;
            _threadNo = std::thread::hardware_concurrency();

            return true;
        }

        void createPartitions(){
            if(_threadNo == 0)
            {
                throw std::runtime_error("No hardware_concurrency!");
            }

            if(_threadNo == 1)
            {
                _partitions.push_back(std::make_pair(0, _v.size()));
            } else
            {
                std::size_t partLen = _v.size() / _threadNo;
                std::size_t left = _v.size() % _threadNo;
                std::size_t i = 0;

                while(i < _v.size()){
                    std::size_t end = i + partLen + left;
                    _partitions.push_back(std::make_pair(i, end));

                    if(left > 0) --left;
                    i  = end;
                }
            }
/*
            for(const auto& a : _partitions)
            {
                std::cout << a.first << ", " << a.second << std::endl;
            }

*/
        }


        bool trialDivisionIsPrime(unsigned long int n)
        {
            //1 & even > 2 are out
            if( n < 2 || (n % 2 == 0 && n >2)) return false;

            for(int i = 2; std::pow(i, i) <= n; ++i)
            {
                if(n%i == 0) return false;
            }

            return true;

            }
        // Utility function to do modular exponentiation.
        // It returns (x^y) % p
        int power(int x, unsigned int y, int p)
        {
            int res = 1;      // Initialize result
            x = x % p;  // Update x if it is more than or
                        // equal to p
            while (y > 0)
            {
                // If y is odd, multiply x with result
                if (y & 1)
                    res = (res*x) % p;

                // y must be even now
                y = y>>1; // y = y/2
                x = (x*x) % p;
            }
            return res;
        }

        bool millerTest(int d, int n)
        {
            // Pick a random number in [2..n-2]
            // Corner cases make sure that n > 4
            int a = 2 + rand() % (n - 4);

            // Compute a^d % n
            int x = power(a, d, n);

            if (x == 1  || x == n-1)
               return true;

            // Keep squaring x while one of the following doesn't
            // happen
            // (i)   d does not reach n-1
            // (ii)  (x^2) % n is not 1
            // (iii) (x^2) % n is not n-1
            while (d != n-1)
            {
                x = (x * x) % n;
                d *= 2;

                if (x == 1)      return false;
                if (x == n-1)    return true;
            }

            // Return composite
            return false;
        }

        // It returns false if n is composite andzA returns true if n
        // is probably prime.  k is an input parameter that determines
        // accuracy level. Higher value of k indicates more accuracy.

        bool MillerRabinIsPrime(int n, int k = 15)
        {
            // Corner cases
            if (n <= 1 || n == 4)  return false;
            if (n <= 3) return true;

            // Find r such that n = 2^d * r + 1 for some r >= 1
            int d = n - 1;
            while (d % 2 == 0)
                d /= 2;

            // Iterate given nber of 'k' times
            for (int i = 0; i < k; i++)
                 if (millerTest(d, n) == false)
                      return false;

            return true;
        }

        void process(std::pair<std::size_t, std::size_t> const& boundaries)
        {
            //trial division method

            std::size_t noOfPrime = 0;
            auto start = std::chrono::system_clock::now();
            for(std::size_t i = boundaries.first; i < boundaries.second; ++i)
            {
                if(trialDivisionIsPrime(_v[i])) ++noOfPrime;
            }
            auto end = std::chrono::system_clock::now();

            std::chrono::duration<double> elapsed_seconds = end-start;

            std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;

            std::cout << "Trial division method, no of primes: " << noOfPrime << std::endl;
            std::cout << "eta: " << elapsed_seconds.count() << "s\n";

            //Miller - Rabin method

            noOfPrime = 0;
            start = std::chrono::system_clock::now();
            for(std::size_t i = boundaries.first; i < boundaries.second; ++i)
            {
                if(MillerRabinIsPrime(_v[i])) ++noOfPrime;
            }
            end = std::chrono::system_clock::now();

            elapsed_seconds = end-start;

            std::cout << "Miller-Rabin method, no of primes: " << noOfPrime << std::endl;
            std::cout << "eta: " << elapsed_seconds.count() << "s\n";

            //mpz_probab_prime
            std::size_t definietely = 0;
            std::size_t probably = 0;
            std::size_t notPrime = 0;
            int result = 0;

            start = std::chrono::system_clock::now();

            for(std::size_t i = boundaries.first; i < boundaries.second; ++i)
            {
                mpz_t n;
                mpz_init(n);
                mpz_set_ui(n, _v[i]);
                result = mpz_probab_prime_p(n, 20);
                switch(result) {
                    case 2:
                        //definitely prime
                        definietely += 1;
                        break;
                    case 1:
                        //probably prime
                        probably += 1;
                        break;
                    default:
                        //definitely non-prime
                        notPrime +=1 ;
                        break;
                }
                mpz_clear(n);
            }

            end = std::chrono::system_clock::now();
            elapsed_seconds = end-start;

            std::cout << "Mpz_probab_prime_p method, no of primes: deinitely: " << definietely << ", probably: " << probably << " not prime: " << notPrime  << std::endl;

            std::cout << "eta: " << elapsed_seconds.count() << "s\n";

        }

        void createThreads()
        {
            //ile wątków, juz jest
            createPartitions();
            //podział na grupy w zaleznosci od watkow
            for(const auto& b : _partitions){
                _t.push_back(std::unique_ptr<std::thread>(new std::thread(&PNumbers::process, this, b)));

            }

            for(auto& t : _t)
            {
                t->join();
            }
            //utworzenie watków, watki badają

        }
};


int main(int argc, char **argv) {
    PNumbers p;
}

