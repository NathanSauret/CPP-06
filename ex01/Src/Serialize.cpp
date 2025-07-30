#include "../Include/Serialize.hpp"

// Constructors
Serialize::Serialize( void )
{
	std::cout << "\tSerialize default constructor called" << std::endl;
}

Serialize::Serialize( const Serialize &src )
{
	std::cout << "\tSerialize copy constructor called" << std::endl;
	*this = src;
}



// Destructor
Serialize::~Serialize( void )
{
	std::cout << "\tSerialize default destructor called" << std::endl;
}



// Operators overload
Serialize	&Serialize::operator=( const Serialize &src )
{
	std::cout << "\tSerialize assignation operator called" << std::endl;
	return (*this);
}



// Class functions
uintptr_t	Serialize::serialize(Data* ptr)
{
	std::cout << "\tSerialization..." << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialize::deserialize(uintptr_t raw)
{
	std::cout << "\tDeserialization..." << std::endl;
	return (reinterpret_cast<Data *>(raw));
}