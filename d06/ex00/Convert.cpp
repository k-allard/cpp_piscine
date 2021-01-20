#include "Convert.hpp"
#include <string>
#include <sstream>
#include <iostream>


/*************/
/* COPLIENS' */
/*************/
Convert::Convert(const char *str) : _str(str) {
	this->_type = getArgumentType();
	switch (_type) {
		case intT:
			asInt();
			break;
		case floatT:
			asFloat();
			break;
		case doubleT:
			asDouble();
			break;
		case charT:
			asChar();
			break;
		default:
			break;
	}
}

Convert::argumentType	Convert::getArgumentType() {
	int strLen = _str.length();
	if (strLen == 1 && !std::isdigit(_str[0]))
		return charT;
	for (int i = 0; i < strLen; i++) {
		if (!std::strchr("+-.f", _str[i]) && !std::isdigit(_str[0]))
			return invalidT;
	}
	int i = 0;
	if(_str[i] == '+' || _str[i] == '-')
		i++;
	if(!std::isdigit(_str[i]))
		return invalidT;
	while (i < strLen && std::isdigit(_str[i]))
		i++;
	if (_str[i] == '.') {
		i++;
		_type = floatT;
	}
	while (i < strLen && std::isdigit(_str[i]))
	i++;

		
}


Convert::Convert( Convert const & src ) {}

Convert & Convert::operator=( Convert const & rhs ) {}

Convert::~Convert() {}

std::string const Convert::asChar() const {
}

std::string const Convert::asInt() const {

}
std::string const Convert::asFloat() const {
		try {
			floatV = std::stof()
		}
}
std::string const Convert::asDouble() const {

}

