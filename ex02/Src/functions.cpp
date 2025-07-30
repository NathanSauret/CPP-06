#include "../Include/casts.hpp"

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
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
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &Test)
{
	while (i < 3)
	{
		try
		{
			if (i == 0)
				Base &unused = dynamic_cast<A &>(Test);
			else if (i == 1)
				Base &unused = dynamic_cast<B &>(Test);
			else if (i == 2)
				Base &unused = dynamic_cast<C &>(Test);
		}
		catch (std::exception &e)
		{
			i++;
			identify(Test);
			return;
		}
		std::cout << "\tbase is ";
		switch (i)
		{
			case (0):
			{
				std::cout << "A";
				break;
			}
			case (1):
			{
				std::cout << "B";
				break;
			}
			case (2):
			{
				std::cout << "C";
				break;
			}
		}
		std::cout << std::endl;
		i = 0;
		break;
	}
}

// static void identify(Base &Test)
// {
// 	bool	found = 0;
// 	int		i = 0;

// 	while (i < 3)
// 	{
// 		void *foo = NULL; // only to initialize the unused var
// 		Base &unused = (Base &)foo; // only to prevent the -Werror from triggering for unused value of the casts
// 		try
// 		{
// 			if (i == 0)
// 			{
// 				unused = dynamic_cast<A &>(Test);
// 				found = 1;
// 			}
// 			else if (i == 1)
// 			{
// 				unused = dynamic_cast<B &>(Test);
// 				found = 1;
// 			}
// 			else if (i == 2)
// 			{
// 				unused = dynamic_cast<C &>(Test);
// 				found = 1;
// 			}
// 			(void)unused;
// 		}
// 		catch (std::exception &e)
// 		{
// 			i++;
// 			identify(Test);
// 		}
// 		if (found)
// 		{
// 			switch (i)
// 			{
// 				case (0):
// 					std::cout << "\tA";
// 				case (1):
// 					std::cout << "\tB";
// 				case (2):
// 					std::cout << "\tC";
// 			}
// 			std::cout << " is the identified type" << std::endl;
// 			break;
// 		}
// 	}
// }
