#include "../Include/casts.hpp"



// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\tScalarConverter default constructor called" << std::endl;

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
	return (*this);
}




// Checks
int	check_input_nan_inf( const std::string& src )
{
	if (src.compare("nan") == 0 
		|| src.compare("+inf") == 0
		|| src.compare("-inf") == 0
		|| src.compare("+inff") == 0
		|| src.compare("-inff") == 0)
	{
		return (NAN_INF);
	}
	return (0);
}

int	check_input_char( const std::string& src )
{
	if (src.length() == 1 
		&& (src[0] == '+' 
		|| src[0] == '-' 
		|| src[0] == 'f' 
		|| src[0] == '.'))
	{
		return (CHAR);
	}
	return (0);
}

int	check_input_int( const std::string& src )
{
	if (src.find_first_of("+-") != src.find_last_of("+-"))
		return (ERROR);
	if (src.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	return (0);
}

int	check_input_double( const std::string& src )
{
	if (src.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (src.find_first_of(".") != src.find_last_of(".")
			|| isdigit(src[src.find_first_of(".") + 1]) == 0
			|| src.find_first_of(".") == 0)
		{
			return (ERROR);
		}
		else
			return (DOUBLE);
	}
	return (0);
}

int	check_input_float( const std::string& src )
{
	if (src.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (src.find_first_of("f") != src.find_last_of("f")
			|| src.find_first_of(".") != src.find_last_of(".")
			|| src.find_first_of("f") - src.find_first_of(".") == 1
			|| src.find_first_of(".") == 0
			|| src[src.find_first_of("f") + 1] != '\0')
		{
			return (ERROR);
		}
		else
			return (FLOAT);
	}
	return (0);
}

// Get input type
int	get_input_type( const std::string& src )
{
	int	type = 0;

	if (src.empty() == true)
		type = ERROR;

	type = check_input_nan_inf(src);
	if (type != 0)
		return(type);
	type = check_input_char(src);
	if (type != 0)
		return(type);
	type = check_input_int(src);
	if (type != 0)
		return(type);
	type = check_input_double(src);
	if (type != 0)
		return(type);
	type = check_input_float(src);
	if (type != 0)
		return(type);
	
	if ((src.length() == 1 && std::isprint(src[0]))
		|| (src.length() == 1 && std::isalpha(src[0])))
	{
		type = CHAR;
	}
	else
		type = ERROR;
	return(type);
}



// Display types functions
void	display_char( int type, double double_type, char char_type )
{
	if (type != NAN_INF
		&& double_type <= UCHAR_MAX
		&& double_type >= 0)
	{
		if (isprint(char_type))
			std::cout << "'" << char_type << "'";
		else
			std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
}

void	display_int( int type, double double_type, int int_type )
{
	if (type != NAN_INF
		&& double_type >= std::numeric_limits<int>::min()
		&& double_type <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << int_type;
	}
	else
		std::cout << "int: impossible";
}

void	display_float( const std::string& str, int type, double float_type, int int_type )
{
	if (type != NAN_INF)
	{
		std::cout << "float: " << float_type;
		if (float_type - int_type == 0)
			std::cout << ".0f";
		else
			std::cout << "f";
	}
	else
	{
		if (str == "nan" || str == "nanf")
			std::cout << "float: nanf";
		else if (str[0] == '+')
			std::cout << "float: +inff";
		else
			std::cout << "float: -inff";
	}
}

void	display_double( const std::string& str, int type, double double_type, int int_type )
{
	if (type != NAN_INF)
	{
		std::cout << "double: " << double_type;
		if (double_type < std::numeric_limits<int>::min()
			|| double_type > std::numeric_limits<int>::max()
			|| double_type - int_type == 0)
		{
			std::cout << ".0";
		}
	}
	else
	{
		if (str == "nan" || str == "nanf")
			std::cout << "double: nan";
		else if (str[0] == '+')
			std::cout << "double: +inf";
		else
			std::cout << "double: -inf";
	}
}



// Display all types
void	display_conversions( const std::string& str, int type, char char_type, int int_type, float float_type, double double_type )
{
	std::cout << "\tchar: ";
	display_char(type, double_type, char_type);
	std::cout << std::endl;

	std::cout << "\tint: ";
	display_int(type, double_type, int_type);
	std::cout << std::endl;

	std::cout << "\tfloat: ";
	display_float(str, type, float_type, int_type);
	std::cout << std::endl;

	std::cout << "\tdouble: ";
	display_double(str, type, double_type, int_type);
	std::cout << std::endl;
}



void	ScalarConverter::convert( const std::string& str )
{
	int		type;
	char	char_type;
	int		int_type;
	float	float_type;
	double	double_type;

	// Set double in first
	double_type = atof(str.c_str());

	// Check if NAN_INF
	type = get_input_type(str);

	// Get all types
	switch (type)
	{
		case (CHAR):
		{
			char_type = static_cast<unsigned char>(str[0]);
			int_type = static_cast<int>(char_type);
			float_type = static_cast<float>(char_type);
			double_type = static_cast<double>(char_type);
			break;
		}
		case (INT):
		{
			int_type = static_cast<int>(double_type);
			char_type = static_cast<unsigned char>(int_type);
			float_type = static_cast<float>(double_type);
			break;
		}
		case (FLOAT):
		{
			float_type = static_cast<float>(double_type);
			char_type = static_cast<char>(float_type);
			int_type = static_cast<int>(float_type);
			break;
		}
		case (DOUBLE):
		{
			char_type = static_cast<char>(double_type);
			int_type = static_cast<int>(double_type);
			float_type = static_cast<float>(double_type);
			break;
		}
		case (ERROR):
		{
			std::cerr << RED << "\tError: Impossible to print or input not convertable" << RESET << std::endl;
			return ;
		}
	}

	// Display types
	display_conversions(str, type, char_type, int_type, float_type, double_type);
}