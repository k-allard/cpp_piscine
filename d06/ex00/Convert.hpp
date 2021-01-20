#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>

class Convert {
	protected: 
		typedef enum argumentTypeEnum
		{
			intT,
			doubleT,
			floatT,
			charT,
			invalidT
		}	argumentType;

		std::string		_str;
		argumentType	_type;
		int				intV;
		double			doubleV;
		float			floatV;
		char			charV;
		int				ifSpecial;
		int				outOfRange;

		void			checkInputString();
		argumentType	getArgumentType();


	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Convert();
		Convert(const char *str); 
		Convert( Convert const & src );
		Convert & operator=( Convert const & rhs );
		~Convert();
		

		/*************/
		/* INTERFACE */
		/*************/
		
		std::string const asChar() const;
		std::string const asInt() const;
		std::string const asFloat() const;
		std::string const asDouble() const;
		void convertInput();
		
		/***********/
		/* GETTERS */
		/***********/

		/**************/
		/* EXCEPTIONS */
		/**************/
	
};

std::ostream & operator<<( std::ostream & o, Convert const & rhs);

#endif
