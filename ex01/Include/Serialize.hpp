#ifndef	SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serialize
{
	private:

	public:
		// Constructors
		Serialize();
		Serialize( const Serialize &src );

		// Destructor
		~Serialize();

		// Operators overload
		Serialize	&operator=( const Serialize &src );

		// Class functions
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif