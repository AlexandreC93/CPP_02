#include "Fixed.hpp"

int main ( void ) {
    Fixed        a;
    Fixed        c;
    Fixed const  b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a.toInt() << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}