#ifndef PPF_HPP
# define PPF_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void execute(Bureaucrat const &) const;
};

#endif