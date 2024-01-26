
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _fixedPointValue( n << _fractionalBits ) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _fixedPointValue( roundf( n * ( 1 << _fractionalBits ) ) ) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy ) {
    // std::cout << "Copy constructor called" << std::endl;
    // this->setRawBits(copy.getRawBits());
    *this = copy;
}

Fixed& Fixed::operator=( const Fixed &copy ) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &copy )
        this->_fixedPointValue = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _fractionalBits );
}

int     Fixed::toInt( void ) const {
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &copy ) const {
    return this->getRawBits() > copy.getRawBits();
}

bool    Fixed::operator<( const Fixed &copy ) const {
    return this->getRawBits() < copy.getRawBits();
}

bool    Fixed::operator>=( const Fixed &copy ) const {
    return this->getRawBits() >= copy.getRawBits();
}

bool   Fixed::operator<=( const Fixed &copy ) const {
    return this->getRawBits() <= copy.getRawBits();
}

bool  Fixed::operator==( const Fixed &copy ) const {
    return this->getRawBits() == copy.getRawBits();
}

bool    Fixed::operator!=( const Fixed &copy ) const {
    return this->getRawBits() != copy.getRawBits();
}

//------------------ Arithmetic operators ------------------//

Fixed   Fixed::operator+( const Fixed &copy ) const {
    return Fixed( this->toFloat() + copy.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &copy ) const {
    return Fixed( this->toFloat() - copy.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &copy ) const {
    return Fixed( this->toFloat() * copy.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &copy ) const {
    return Fixed( this->toFloat() / copy.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void ) {
    ++this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue--;
    return tmp;
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}