#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string> 

class	Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string address;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string meal;
	std::string underwear_color;
	std::string secret;

public:
	void		set_first_name(std::string first_name);
	void		set_last_name(std::string last_name);
	void		set_nickname(std::string nickname);
	void		set_login(std::string login);
	void		set_address(std::string address);
	void		set_email(std::string email);
	void		set_phone(std::string phone);
	void		set_birthday(std::string birthday);
	void		set_meal(std::string meal);
	void		set_underwear_color(std::string underwear_color);
	void		set_secret(std::string secret);
	void		print_detail();
	void		print_line();

	Contact();
};

#endif