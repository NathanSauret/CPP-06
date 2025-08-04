#include "../Include/casts.hpp"

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



int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Must have one parameter <element>" << RESET << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}
