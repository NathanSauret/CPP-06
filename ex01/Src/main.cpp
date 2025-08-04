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
	title("DATA");
	sub_title("Create Data");
	Data	data;
	data.name = "Bob";
	data.months_at_42 = 12;
	std::cout << "\t        data.name: " << data.name << std::endl;
	std::cout << "\tdata.months_at_42: " << data.months_at_42 << std::endl;
	std::cout << std::endl;

	title("SERIALIZE AND DESERIALIZE");
	// sub_title("Create Serialize");
	// Serialize	serialize;
	// std::cout << std::endl;

	sub_title("Serialize");
	uintptr_t ptr = Serialize::serialize(&data);
	std::cout << std::endl;

	sub_title("Deserialize");
	Data *new_data = Serialize::deserialize(ptr);
	std::cout << std::endl;

	sub_title("Display data after serialization");
	std::cout << "\t        new_data.name: " << new_data->name << std::endl;
	std::cout << "\tnew_data.months_at_42: " << new_data->months_at_42 << std::endl;
	std::cout << std::endl;

	sub_title("Destructor");
	return (0);
}
