#include <stdio.h>
#include <iostream>

int main(int argc, char **argv)
{
	int nCelsius;
	std::cout << "Enter temperature in Celsius: ";
	std::cin >> nCelsius;

	int nNFactor;
	nNFactor = 212 - 32;

	int nFahrenheit;
	nFahrenheit = nNFactor * nCelsius/100 + 32;
	std::cout << "It is ";
	std::cout << nFahrenheit;
	std::cout << " degrees Fahrenheit." << std::endl;
	return (0);
}