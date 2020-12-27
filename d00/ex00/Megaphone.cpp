#include "Megaphone.hpp"

void Megaphone::uppercaser(char *arg)
{
	while(*arg)
	{
		if (*arg >= 'a' && *arg <= 'z')
			*arg -= 'a' - 'A';
		arg++;
	}
}
