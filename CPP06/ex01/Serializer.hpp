#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	public:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer &operator=(Serializer const &src);

		static uintptr_t	*serialize(Data *ptr);
		static Data			*deserialize(uintptr_t *raw);
};

#endif
