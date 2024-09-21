#include <iostream>
#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	Data	*retDe;
	uintptr_t	retSe;

	for (int i = 0; i < 9; i++)
		data.str[i] = 'a';
	data.str[9] = 0;
	retSe = Serializer::serialize(&data);
	retDe = Serializer::deserialize(retSe);

	std::cout << "Adress of original data:   " << &data << "\n";
	// std::cout << "Content of original data:  " << data.content <<
	std::cout << "Serialized value of data:  " << retSe << "\n";
	std::cout << "Adress of serialized data: " << retDe << std::endl;
	return (0);
}
