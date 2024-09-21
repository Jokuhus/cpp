#include <random>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	Base*	ret;

	std::random_device	rd;
	std::mt19937	gen(rd());
	std::uniform_int_distribution<int>	dis(0,2);

	switch (dis(gen))
	{
		case 0:
			ret = new A();
			break ;
		case 1:
			ret = new B();
			break ;
		default:
			ret = new C();
	}
	return (ret);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This class is type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This class is type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This class is type C" << std::endl;
	else
		std::cout << "This class is unknown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	tmp = dynamic_cast<A&>(p);
		std::cout << "This class is type A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B	tmp = dynamic_cast<B&>(p);
			std::cout << "This class is type B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C	tmp = dynamic_cast<C&>(p);
				std::cout << "This class is type C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "This class is unknown" << std::endl;
			}
		}
	}
}

int	main(void)
{
	for (int i = 0; i < 5; i++)
	{
		Base	*tmp = generate();
		identify(tmp);
		identify(*tmp);
		delete tmp;
	}
	return (0);
}
