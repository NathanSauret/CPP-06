#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define ERROR -2
#define NAN_INF -1
#define	CHAR 1
#define	INT 2
#define FLOAT 3
#define DOUBLE 4


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
		void	setInputType( void );
		int		checkInputNanInf( void ) const;
		int		checkInputChar( void ) const;
		int		checkInputInt( void ) const;
		int		checkInputDouble( void ) const;
		int		checkInputFloat( void ) const;

		void	convertAndReplaceTypes( void );

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
		void	displayType( void ) const;
		void	displayConversions( void ) const;
	
	// Exceptions
	class ErrorException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif