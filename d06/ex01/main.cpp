/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:27:35 by kallard           #+#    #+#             */
/*   Updated: 2021/01/21 14:18:25 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <time.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void) {
	char *raw = new char[20];
	std::string alphanumBuf = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";
	int alphanumBufLen = alphanumBuf.length();
	for (int i = 0; i < 8; i++)
		raw[i] = alphanumBuf[rand() % alphanumBufLen];
	int randInt = rand();
	*reinterpret_cast<int *>(raw + 8) = randInt;
	for (int i = 0; i < 8; i++)
		raw[i + 12] = alphanumBuf[rand() % alphanumBufLen];
	std::string forOutput(raw, 20);
	std::cout << "\nBefore serialization:\n"
			  << forOutput.substr(0, 8) << "  |  " 
			  << randInt << "  |  " 
			  << forOutput.substr(12, 20) 
			  << std::endl << std::endl;
	return (reinterpret_cast<void *>(raw));
}

Data *deserialize(void *raw) {
	Data *data = new Data;
	data->s1 = std::string(static_cast<char *>(raw), 8);
	data->n = *reinterpret_cast<int *>(static_cast<char *>(raw) + 8);
	data->s2 = std::string(static_cast<char *>(raw) + 12, 8);
	return (data);
}

int main() {
	srand(time(NULL));
	void *raw = serialize();
	std::cout << "Serealized:\n";
	for (int i = 0; i < 20; i++)
		std::cout << reinterpret_cast<char *>(raw)[i];
	std::cout << "\n\n";
	Data *data = deserialize(raw);
	std::cout << "Deserealized:\n"
			  << data->s1 << "  |  " 
			  << data->n << "  |  " 
			  << data->s2 
			  << std::endl << std::endl;
	delete data;
	delete[] reinterpret_cast<char *>(raw);
	return 0;
}
