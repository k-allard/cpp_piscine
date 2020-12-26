#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
	int		contacts_count;
	int		contacts_count_max;
	Contact	contacts[8];
	void	print_list();



public:
	Phonebook();
	void add_contact();
	void search();
};

#endif