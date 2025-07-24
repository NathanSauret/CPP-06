#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define	CHAR 0
#define	INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter
{
	private:
		std::string	_input;
		int			_type;
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		// Private member functions
		int	getInputType( void );			// todo

	public:
		// Constructors
		ScalarConverter();
		ScalarConverter( const std::string input );
		ScalarConverter( const ScalarConverter &src );

		// Destructor
		~ScalarConverter();

		// Operators overload
		ScalarConverter	&operator=( const ScalarConverter &src );

		// Get
		std::string	getInput( void ) const;
		int			getType( void ) const;
		char		getChar( void ) const;
		int			getInt( void ) const;
		float		getFloat( void ) const;
		double		getDouble( void ) const;

		// Public member functions
		void	displayChar( void ) const;
		void	displayInt( void ) const;
		void	displayFloat( void ) const;
		void	displayDouble( void ) const;
	
	// Exceptions
	class ErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif