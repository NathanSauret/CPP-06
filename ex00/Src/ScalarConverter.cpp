#include "../Include/casts.hpp"



// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\tScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( const std::string input ) : _input(input)
{
	std::cout << "\tScalarConverter constructor with input " << input << " called" << std::endl;

}

ScalarConverter::ScalarConverter( const ScalarConverter &src )
{
	std::cout << "\tScalarConverter copy constructor called" << std::endl;
	*this = src;
}



// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\tScalarConverter destructor called" << std::endl;
}



// Operator overload
ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &src )
{
	std::cout << "\tScalarConverter assignation operator called" << std::endl;
	this->_input = src._input;
	this->_type = src._type;
	this->_char = src._char;
	this->_int = src._int;
	this->_float = src._float;
	this->_double = src._double;
	return (*this);
}



// Get
std::string	ScalarConverter::getInput( void ) const
{
	return (this->_input);
}

int	ScalarConverter::getType( void ) const
{
	return (this->_type);
}

char	ScalarConverter::getChar( void ) const
{
	return (this->_char);
}

int	ScalarConverter::getInt( void ) const
{
	return (this->_int);
}

float	ScalarConverter::getFloat( void ) const
{
	return (this->_float);
}

double	ScalarConverter::getDouble( void ) const
{
	return (this->_double);
}



// Private member functions
int	ScalarConverter::getInputType( void )
{
	return (-1);
}



// Public member functions
void	ScalarConverter::displayChar( void ) const
{
	std::cout << "";
}

void	ScalarConverter::displayInt( void ) const
{
	std::cout << "";
}

void	ScalarConverter::displayFloat( void ) const
{
	std::cout << "";
}

void	ScalarConverter::displayDouble( void ) const
{
	std::cout << "";
}



// Exceptions
const char	*ScalarConverter::ErrorException::what(void) const throw()
{
	return ("Error: Impossible to print or input not convertable");
};