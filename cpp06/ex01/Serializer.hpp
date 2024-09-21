#ifndef _SERIALIZER_HPP_
# define _SERIALIZER_HPP_

# include <string>

# define uintptr_t	unsigned long long
struct	Data
{
	char	str[10];
};

class Serializer
{
	//OCCF
	private:
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
	public:
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
