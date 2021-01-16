#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void execute(Bureaucrat const &) const;
};

#endif