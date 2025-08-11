#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define ERROR -2
#define NAN_INF -1
#define	CHAR 1
#define	INT 2
#define FLOAT 3
#define DOUBLE 4

#include <string>

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter( const ScalarConverter &src );

		// Destructor
		~ScalarConverter();

		// Operators overload
		ScalarConverter	&operator=( const ScalarConverter &src );

	public:
		// class member functions
		static void	convert(const std::string& str);
};

#endif