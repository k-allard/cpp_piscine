#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
class Bureaucrat;

class AForm {
	private: 
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_ifSigned;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExecute); 
		AForm( AForm const & src );
		AForm & operator=( AForm const & rhs );
		~AForm();

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
		virtual void beSigned(Bureaucrat const &);
		virtual void execute(Bureaucrat const & executor) const = 0;
	
		/**************/
		/* EXCEPTIONS */
		/**************/
		class GradeTooHighException : public std::exception { };
		class GradeTooLowException : public std::exception { };
		class NotSignedForExecutionException : public std::exception { };
};

std::ostream & operator<<( std::ostream & o, AForm const & rhs);

#endif