#include "../Include/casts.hpp"

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "\tCreated type A base" << std::endl;
		return (new A());
	case 1:
		std::cout << "\tCreated type B base" << std::endl;
		return (new B());
	case 2:
		std::cout << "\tCreated type C base" << std::endl;
		return (new C());
	}
	return (NULL);
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
		std::cout << "\tbase is A" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "\tbase is B" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "\tbase is C" << std::endl;
	else
		std::cout << "\tbase is unknown" << std::endl;

}

static void identify(Base &Test)
{
	try
	{
		Base &unused = dynamic_cast<A &>(Test);
		std::cout << "\tbase is A" << std::endl;
		return ;
	}
	catch (std::exception &e){}

	try
	{
		Base &unused = dynamic_cast<B &>(Test);
		std::cout << "\tbase is B" << std::endl;
		return ;
	}
	catch (std::exception &e){}

	try
	{
		Base &unused = dynamic_cast<C &>(Test);
		std::cout << "\tbase is C" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	std::cout << "\tbase is unknown" << std::endl;
}
