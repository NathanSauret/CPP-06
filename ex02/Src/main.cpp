#include "../Include/casts.hpp"

#include "functions.cpp"

void	title(const std::string str)
{
	std::string	title;

	if (str.length() + 2 >= 42)
		return ;

	title.append(" " + str + " ");
	while (title.length() < 42)
		title.append("~");
	
	std::cout << YELLOW << title << RESET << std::endl;
}

void	sub_title(const std::string str)
{
	std::string	title;

	title.append("        ~~~ " + str + " ");
	while (title.length() < 42)
		title.append("~");
	
	std::cout << CYAN << title << RESET << std::endl;
}



int main(void)
{
	srand(time(NULL));
	title("TESTING WITH FIVE RANDOM BASES");
	for (int i=0; i<5; i++)
	{
		std::cout << GREEN << "\ti = " << i << RESET << std::endl;
		sub_title("Generate base");
		Base	*base = generate();

		sub_title("identify(Base* p)");
		identify(base);

		sub_title("identify(Base& p)");
		identify(*base);

		sub_title("Delete base");
		delete(base);
		std::cout << std::endl;
	}

	return (0);
}
