#include "./Bigint.hpp"

int main(void)
{
    const Bigint a(42);
    Bigint b(21), c, d(1337), e(d);

    std::cout << "\033[1;36m [PRINT ALL VARS] \033[0m" << std::endl;
    std::cout << "a " << a << std::endl; // operator<<
    std::cout << "b " << b << std::endl; // operator<<
    std::cout << "c " << c << std::endl; // operator<<
    std::cout << "d " << d << std::endl; // operator<<
    std::cout << "e " << e << std::endl; // operator<<
    
    std::cout << "\033[1;36m [TEST OVERRIDES] \033[0m" << std::endl;
    std::cout << "(a + b) = " << a + b << " | (63)" << std::endl; // operator+
    std::cout << "(c += a) = " << (c += a) << " | (42)" << std::endl; // operator+=
    
    
    std::cout << "\033[1;36m [TEST INC DEC] \033[0m" << std::endl;
    std::cout << b++ << " | print (21) is (22)" << std::endl; // operator++(int)  (post-increment)
    std::cout << ++b << " | print (23) is (23)" << std::endl; // operator++()     (pre-increment)
    
    
    std::cout << "\033[1;36m [TEST DIGIT SHIFTING] \033[0m" << std::endl;
    std::cout << "((b << 10) + 42) = " << (b << 10) + 42 << " | (230000000042)" << std::endl; // operator<< (shift), operator+
    //std::cout << "((b >> 10) = " << (d >> 2) << " | (23)" << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << " | (13370000)" << std::endl; // operator<<=
    std::cout << "(d >>= (const bigint)2) = " << (d >>= (const Bigint)2) << " | (133700)" << std::endl; // operator>>=
    
    
    std::cout << "\033[1;36m [TEST UBERSCHLAG] \033[0m" << std::endl;
    b = 99; // operator=
    c = 10; // operator=
    std::cout << "b " << b << std::endl; // operator<<
    std::cout << "c " << c << std::endl; // operator<<
    std::cout << "(b + c) = " << (b + c) << " | (109)" << std::endl; // operator+
    
    
    std::cout << "\033[1;36m [TEST COMPARISON] \033[0m" << std::endl;
    std::cout << "d " << d << std::endl; // operator<<
    std::cout << "a " << a << std::endl; // operator<<
    if (d < a)
        std::cout << "(d < a) true" << std::endl; // operator<
    else
        std::cout << "(d < a) false" << std::endl;

    if (d > a)
        std::cout << "(d > a) true" << std::endl; // operator>
    else
        std::cout << "(d > a) false" << std::endl;

    if (d == a)
        std::cout << "(d == a) true" << std::endl; // operator==
    else
        std::cout << "(d == a) false" << std::endl;

    if (d != a)
        std::cout << "(d != a) true" << std::endl; // operator!=
    else
        std::cout << "(d != a) false" << std::endl;

    if (d <= a)
        std::cout << "(d <= a) true" << std::endl; // operator<=
    else
        std::cout << "(d <= a) false" << std::endl;

    if (d >= a)
        std::cout << "(d >= a) true" << std::endl; // operator>=
    else
        std::cout << "(d >= a) false" << std::endl;
    
    std::string zero = "0110";
    std::string one = "111";
    if (zero < one) {
        std::cout << zero << " < " << one << std::endl;
    } else {
        std::cout << zero << " > " << one << std::endl;
    }
    return(0);
}
