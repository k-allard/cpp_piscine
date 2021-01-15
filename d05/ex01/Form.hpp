#ifndef FORM_HPP
# define FORM_HPP

#include <string>
class Bureaucrat;

class Form {
	private: 
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_ifSigned;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute); 
		Form( Form const & src );
		Form & operator=( Form const & rhs );
		~Form();

		/***********/
		/* GETTERS */
		/***********/
		std::string const & get_name() const;
		int get_gradeToSign() const;
		int get_gradeToExecute() const;
		bool get_ifSigned() const;

		/*************/
		/* INTERFACE */
		/*************/
		void beSigned(const Bureaucrat &);

		/**************/
		/* EXCEPTIONS */
		/**************/
		class GradeTooHighException : public std::exception { };
		class GradeTooLowException : public std::exception { };
};

std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif