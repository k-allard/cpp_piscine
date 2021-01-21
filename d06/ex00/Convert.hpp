#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <sstream>
#include <iostream>

class Convert {
	protected: 
		typedef enum	argumentTypeEnum {
			intT,
			doubleT,
			floatT,
			charT,
			invalidT
		}				argumentType;
		argumentType	getArgumentType();

		std::string		_str;
		argumentType	_type;
		int				intV;
		double			doubleV;
		float			floatV;
		char			charV;
		int				ifSpecial;
		int				exceptionFlag;

	public:
		/*************/
		/* COPLIENS' */
		/*************/
		Convert();
		Convert(const char *str); 
		Convert( Convert & src );
		Convert & operator=( Convert & rhs );
		~Convert();
		
		/*************/
		/* INTERFACE */
		/*************/
		void convertInput();
		void asChar();
		void asInt();
		void asFloat();
		void asDouble();
		
		/***********/
		/* GETTERS */
		/***********/
		std::string		get_str();
		argumentType	get_type();
		int				get_intV();
		double			get_doubleV();
		float			get_floatV();
		char			get_charV();
		int				get_ifSpecial();
		int				get_exceptionFlag();
};

/***************/
/* << OVERLOAD */
/***************/
std::ostream & operator<<( std::ostream & o, Convert & rhs);

#endif
