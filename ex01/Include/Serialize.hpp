#ifndef	SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serialize
{
	private:
		// Constructors
		Serialize();
		Serialize( const Serialize &src );

		// Destructor
		~Serialize();

		// Operators overload
		Serialize	&operator=( const Serialize &src );

	public:
		// Class functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif