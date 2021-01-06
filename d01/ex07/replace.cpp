/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:17:03 by kallard           #+#    #+#             */
/*   Updated: 2021/01/06 14:45:28 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "*** ERROR: Program takes a filename and two strings arguments" << std::endl;
		exit(1);
	}
	if (std::string(argv[1]).length() == 0 || 
		std::string(argv[2]).length() == 0 ||
		std::string(argv[3]).length() == 0) {
		std::cerr << "*** ERROR: Program takes a filename and two strings arguments, that are NOT empty" << std::endl;
		exit(2);
	}
	std::string str;
	std::string filename = std::string(argv[1]);
	std::string filenameOut = filename + ".replace";
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	std::ifstream fileStreamInput(filename);
	std::ofstream fileStreamOutput(filenameOut);
	if (fileStreamInput.fail()) {
		std::cerr << "*** ERROR: Cannot open input file with filename " << filename << std::endl;
		exit(3);
	}
	if (fileStreamOutput.fail()) {
		std::cerr << "*** ERROR: Cannot open output file with filename " << filenameOut << std::endl;
		exit(4);
	}
	while (!fileStreamInput.eof() && !fileStreamInput.fail() && !fileStreamOutput.fail()) {	
		std::getline(fileStreamInput, str);
		while (str.find(s1) != std::string::npos) {
			str = str.replace(str.find(s1), s1.length(), s2);
		}
		fileStreamOutput << str;
		if(!fileStreamInput.eof())
			fileStreamOutput << std::endl;
	}
	if (!fileStreamInput.eof() && fileStreamInput.fail()) {
		std::cerr << "*** ERROR: Cannot read from input file with filename " << filename << std::endl;
		exit(5);
	}
	if (fileStreamOutput.fail()) {
		std::cerr << "*** ERROR: Cannot write to output file with filename " << filenameOut << std::endl;
		exit(6);
	}
	fileStreamInput.close();
	fileStreamOutput.close();	
}
