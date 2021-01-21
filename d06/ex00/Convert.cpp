/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 04:03:18 by kallard           #+#    #+#             */
/*   Updated: 2021/01/21 04:19:27 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*************/
/* COPLIENS' */
/*************/
Convert::Convert(const char *str) : _str(str), _type(invalidT), 
				intV(0), doubleV(0.0), floatV(0.0f), 
				charV(0), ifSpecial(0), exceptionFlag(0) {
	this->_type = getArgumentType();
}

Convert::Convert(Convert & src) { *this = src; }

Convert & Convert::operator=( Convert & rhs ) {
	_str = rhs.get_str();
	_type =	rhs.get_type();
	intV = rhs.get_intV();
	doubleV = rhs.get_doubleV();
	floatV = rhs.get_floatV();
	charV =	 rhs.get_charV();
	ifSpecial =	rhs.get_ifSpecial();
	exceptionFlag = rhs.get_exceptionFlag();
	return (*this);
}

Convert::~Convert() {}

/*************/
/* INTERFACE */
/*************/
void Convert::convertInput() {
	switch (_type) {
		case intT:
			asInt();
			break;
		case doubleT:
			asFloat();
			break;
		case floatT:
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
	if (_str == "inf" || _str == "+inf" || _str == "-inf" 
		|| _str == "inff" || _str == "+inff" || _str == "-inff") {
		floatV = _str[0] == '-' ? -1.0 / 0.0 : 1.0 / 0;
		ifSpecial = 1;
		return floatT;
	}
	if (_str == "nan" || _str == "nanf") {
		floatV = 0.0 / 0.0;
		ifSpecial = 1;
		return floatT;
	}
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
	if (i != strLen - 1 && i != strLen)
		return invalidT;
	if (_str[i] == 0) {
		if (_type == floatT)
			return doubleT;
		return intT;
	}
	if (_str[i] == 'f' && _type == floatT)
		return floatT;
	return invalidT;
}

void Convert::asChar() {
	charV = _str[0];
	doubleV = static_cast<double>(charV);
	floatV = static_cast<float>(charV);
	intV = static_cast<int>(charV);
}

void Convert::asInt() {
	try {
		intV = std::stoi(_str);
		doubleV = static_cast<double>(intV);
		floatV = static_cast<float>(intV);
		charV = static_cast<char>(intV);
	}
	catch (const std::exception &e) {
		exceptionFlag = 1;
	}
}

void Convert::asFloat() {
	try {
		floatV = std::stof(_str);
		doubleV = static_cast<double>(floatV);
		intV = static_cast<int>(floatV);
		charV = static_cast<char>(floatV);
		if (floatV > std::numeric_limits<int>::max() || floatV < std::numeric_limits<int>::min())
			ifSpecial = 1;
	}
	catch (const std::exception &e) {
		exceptionFlag = 1;
	}
}

void Convert::asDouble() {
	try {
		doubleV = std::stod(_str);
		floatV = static_cast<float>(doubleV);
		intV = static_cast<int>(doubleV);
		charV = static_cast<char>(doubleV);
		if (doubleV > std::numeric_limits<int>::max() || doubleV < std::numeric_limits<int>::min())
			ifSpecial = 1;
	}
	catch (const std::exception &e) {
		exceptionFlag = 1;
	}
}

/***********/
/* GETTERS */
/***********/
std::string				Convert::get_str() { return _str; }
Convert::argumentType	Convert::get_type() { return _type; }
int						Convert::get_intV() { return intV; }
double					Convert::get_doubleV() { return doubleV; }
float					Convert::get_floatV() { return floatV; }
char					Convert::get_charV() { return charV; }
int						Convert::get_ifSpecial() { return ifSpecial; }
int						Convert::get_exceptionFlag(){ return exceptionFlag; }

/***************/
/* << OVERLOAD */
/***************/
std::ostream & operator<<( std::ostream & o, Convert & rhs) {
	if (rhs.get_type() == 4 || rhs.get_exceptionFlag()) {
		o << "Invalid input!" << std::endl;
		return o;
	}
	std::ostringstream out;
	o << "char: ";
	if (rhs.get_ifSpecial() || rhs.get_intV() < 0 || rhs.get_intV() > 127)
		o << "impossible" << std::endl;
	else if ((rhs.get_intV() >= 0 && rhs.get_intV() < 32) || rhs.get_intV() == 127)
		o << "Non displayable" << std::endl;
	else
		o << "\'" << rhs.get_charV() << "\'" << std::endl;

	o << "int: ";
	if (rhs.get_ifSpecial())
		o << "impossible" << std::endl;
	else
		o << rhs.get_intV() << std::endl;

	o << "float: " << rhs.get_floatV();
	out << rhs.get_floatV();
	if (!std::strchr(out.str().c_str(), '.') && !rhs.get_ifSpecial())
			o << ".0";
	o << "f" << std::endl;

	o << "double: " << rhs.get_doubleV();
	if (!std::strchr(out.str().c_str(), '.') && !rhs.get_ifSpecial())
			o << ".0";
	o << std::endl;

	return (o);
}
