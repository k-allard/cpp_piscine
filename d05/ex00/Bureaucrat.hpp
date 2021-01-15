#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	protected: 
		const std::string	_name;
		int					_grade;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Bureaucrat();
		Bureaucrat(std::string const name, int grade); 
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat & operator=( Bureaucrat const & rhs );
		~Bureaucrat();

		/***********/
		/* GETTERS */
		/***********/
		std::string const & getName() const;
		int getGrade() const;

		/*************/
		/* INTERFACE */
		/*************/
		void incrementGrade();
		void decrementGrade(); 

		/**************/
		/* EXCEPTIONS */
		/**************/
		class GradeTooHighException : public std::exception { };
		class GradeTooLowException : public std::exception { };
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif