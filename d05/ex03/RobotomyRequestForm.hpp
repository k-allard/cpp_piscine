#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		/*************/
		/* COPLIENS' */
		/*************/
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

		/*************/
		/* INTERFACE */
		/*************/
		virtual void execute(Bureaucrat const &) const;
};

#endif