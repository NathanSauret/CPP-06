#include "../Include/casts.hpp"



// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\tScalarConverter default constructor called" << std::endl;

}

ScalarConverter::ScalarConverter( const std::string input ) : _input(input)
{
	std::cout << "\tScalarConverter constructor with input '" << input << "' called" << std::endl;
	this->_double = atof(this->getInput().c_str());
	setInputType();
	convertAndReplaceTypes();
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
	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
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
void	ScalarConverter::setInputType( void )
{
	this->_type = 0;

	if (this->_input.empty() == true)
		this->_type = ERROR;

	this->_type = checkInputNanInf();
	if (this->_type != 0)
		return ;
	this->_type = checkInputChar();
	if (this->_type != 0)
		return ;
	this->_type = checkInputInt();
	if (this->_type != 0)
		return ;
	this->_type = checkInputDouble();
	if (this->_type != 0)
		return ;
	this->_type = checkInputFloat();
	if (this->_type != 0)
		return ;
	
	if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0]))
		|| (this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
	{
		this->_type = CHAR;
	}
	else
		this->_type = ERROR;
}

int	ScalarConverter::checkInputNanInf( void ) const
{
	if (this->getInput().compare("nan") == 0 
		|| this->getInput().compare("+inf") == 0
		|| this->getInput().compare("-inf") == 0
		|| this->getInput().compare("+inff") == 0
		|| this->getInput().compare("-inff") == 0)
	{
		return (NAN_INF);
	}
	return (0);
}

int	ScalarConverter::checkInputChar( void ) const
{
	if (this->getInput().length() == 1 
		&& (this->getInput()[0] == '+' 
		|| this->getInput()[0] == '-' 
		|| this->getInput()[0] == 'f' 
		|| this->getInput()[0] == '.'))
	{
		return (CHAR);
	}
	return (0);
}

int	ScalarConverter::checkInputInt( void ) const
{
	if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
		return (ERROR);
	if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	return (0);
}

int	ScalarConverter::checkInputDouble( void ) const
{
	if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".")
			|| isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == 0
			|| this->getInput().find_first_of(".") == 0)
		{
			return (ERROR);
		}
		else
			return (DOUBLE);
	}
	return (0);
}

int	ScalarConverter::checkInputFloat( void ) const
{
	if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f")
			|| this->getInput().find_first_of(".") != this->getInput().find_last_of(".")
			|| this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1
			|| this->getInput().find_first_of(".") == 0
			|| this->getInput()[this->getInput().find_first_of("f") + 1] != '\0')
		{
			return (ERROR);
		}
		else
			return (FLOAT);
	}
	return (0);
}

void	ScalarConverter::convertAndReplaceTypes()
{
	if (this->_type == NAN_INF)
		return ;

	switch (this->_type)
	{
		case (CHAR):
		{
			this->_char = static_cast<unsigned char>(this->getInput()[0]);
			this->_int = static_cast<int>(this->getChar());
			this->_float = static_cast<float>(this->getChar());
			this->_double = static_cast<double>(this->getChar());
			break;
		}

		case (INT):
		{
			this->_int = static_cast<int>(this->getDouble());
			this->_char = static_cast<unsigned char>(this->getInt());
			this->_float = static_cast<float>(this->getDouble());
			break;
		}

		case (FLOAT):
		{
			this->_float = static_cast<float>(this->getDouble());
			this->_char = static_cast<char>(this->getFloat());
			this->_int = static_cast<int>(this->getFloat());
			break;
		}

		case (DOUBLE):
		{
			this->_char = static_cast<char>(this->getDouble());
			this->_int = static_cast<int>(this->getDouble());
			this->_float = static_cast<float>(this->getDouble());
			break;
		}
		
		case (ERROR):
		{
			throw ScalarConverter::ErrorException();
			break;
		}
	}
}


// Public member functions
void	ScalarConverter::displayChar( void ) const
{
	if (this->_type != NAN_INF
		&& this->getDouble() <= UCHAR_MAX
		&& this->getDouble() >= 0)
	{
		if (isprint(this->getChar()))
			std::cout << "'" << this->getChar() << "'";
		else
			std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
}

void	ScalarConverter::displayInt( void ) const
{
	if (this->_type != NAN_INF
		&& this->getDouble() >= std::numeric_limits<int>::min()
		&& this->getDouble() <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << this->getInt();
	}
	else
		std::cout << "int: impossible";
}

void	ScalarConverter::displayFloat( void ) const
{
	if (this->_type != NAN_INF)
	{
		std::cout << "float: " << this->getFloat();
		if (this->getFloat() - this->getInt() == 0)
			std::cout << ".0f";
		else
			std::cout << "f";
	}
	else
	{
		if (this->_input == "nan" || this->_input == "nanf")
			std::cout << "float: nanf";
		else if (this->_input[0] == '+')
			std::cout << "float: +inff";
		else
			std::cout << "float: -inff";
	}
}

void	ScalarConverter::displayDouble( void ) const
{
	if (this->_type != NAN_INF)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < std::numeric_limits<int>::min()
			|| this->getDouble() > std::numeric_limits<int>::max()
			|| this->getDouble() - this->getInt() == 0)
		{
			std::cout << ".0";
		}
	}
	else
	{
		if (this->_input == "nan" || this->_input == "nanf")
			std::cout << "double: nan";
		else if (this->_input[0] == '+')
			std::cout << "double: +inf";
		else
			std::cout << "double: -inf";
	}
}

void	ScalarConverter::displayType( void ) const
{
	switch (this->_type)
	{
		case (-2):
		{
			std::cout << "ERROR" << std::endl;
			break ;
		}
		case (-1):
		{
			std::cout << "NAN_INF" << std::endl;
			break ;
		}
		case (0):
		{
			std::cout << "NONE" << std::endl;
			break ;
		}
		case (1):
		{
			std::cout << "CHAR" << std::endl;
			break ;
		}
		case (2):
		{
			std::cout << "INT" << std::endl;
			break ;
		}
		case (3):
		{
			std::cout << "FLOAT" << std::endl;
			break ;
		}
		case (4):
		{
			std::cout << "DOUBLE" << std::endl;
			break ;
		}
	}
}

void	ScalarConverter::displayConversions( void ) const
{
	std::cout << "\tchar: ";
	this->displayChar();
	std::cout << std::endl;

	std::cout << "\tint: ";
	this->displayInt();
	std::cout << std::endl;

	std::cout << "\tfloat: ";
	this->displayFloat();
	std::cout << std::endl;

	std::cout << "\tdouble: ";
	this->displayDouble();
	std::cout << std::endl;
}



// Exceptions
const char	*ScalarConverter::ErrorException::what(void) const throw()
{
	return ("\tError: Impossible to print or input not convertable");
};