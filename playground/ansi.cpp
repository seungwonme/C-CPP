#include <iostream>
using namespace std;

int	main(void)
{
	cout << "Regular Colors\n";
	cout << "\033[0;30m\\033[0;30m Black\033[0m\n";
	cout << "\033[0;31m\\033[0;31m Red\033[0m\n";
	cout << "\033[0;32m\\033[0;32m Green\033[0m\n";
	cout << "\033[0;33m\\033[0;33m Yellow\033[0m\n";
	cout << "\033[0;34m\\033[0;34m Blue\033[0m\n";
	cout << "\033[0;35m\\033[0;35m Purple\033[0m\n";
	cout << "\033[0;36m\\033[0;36m Cyan\033[0m\n";
	cout << "\033[0;37m\\033[0;37m White\033[0m\n";
	cout << "\033[0;39m\\033[0;39m Default\033[0m\n\n";

	cout << "Bold\n";
	cout << "\033[1;30m\\033[1;30m Black\033[0m\n";
	cout << "\033[1;31m\\033[1;31m Red\033[0m\n";
	cout << "\033[1;32m\\033[1;32m Green\033[0m\n";
	cout << "\033[1;33m\\033[1;33m Yellow\033[0m\n";
	cout << "\033[1;34m\\033[1;34m Blue\033[0m\n";
	cout << "\033[1;35m\\033[1;35m Purple\033[0m\n";
	cout << "\033[1;36m\\033[1;36m Cyan\033[0m\n";
	cout << "\033[1;37m\\033[1;37m White\033[0m\n";
	cout << "\033[1;39m\\033[1;39m Default\033[0m\n\n";

	cout << "Underline\n";
	cout << "\033[4;30m\\033[4;30m Black\033[0m\n";
	cout << "\033[4;31m\\033[4;31m Red\033[0m\n";
	cout << "\033[4;32m\\033[4;32m Green\033[0m\n";
	cout << "\033[4;33m\\033[4;33m Yellow\033[0m\n";
	cout << "\033[4;34m\\033[4;34m Blue\033[0m\n";
	cout << "\033[4;35m\\033[4;35m Purple\033[0m\n";
	cout << "\033[4;36m\\033[4;36m Cyan\033[0m\n";
	cout << "\033[4;37m\\033[4;37m White\033[0m\n";
	cout << "\033[4;39m\\033[4;39m Default\033[0m\n\n";

	cout << "Background\n";
	cout << "\033[40m\\033[40m Black\033[0m\n";
	cout << "\033[41m\\033[41m Red\033[0m\n";
	cout << "\033[42m\\033[42m Green\033[0m\n";
	cout << "\033[43m\\033[43m Yellow\033[0m\n";
	cout << "\033[44m\\033[44m Blue\033[0m\n";
	cout << "\033[45m\\033[45m Purple\033[0m\n";
	cout << "\033[46m\\033[46m Cyan\033[0m\n";
	cout << "\033[47m\\033[47m White\033[0m\n";
	cout << "\033[49m\\033[49m Default\033[0m\n\n";

	cout << "High Intensity\n";
	cout << "\033[0;90m\\033[0;90m Black\033[0m\n";
	cout << "\033[0;91m\\033[0;91m Red\033[0m\n";
	cout << "\033[0;92m\\033[0;92m Green\033[0m\n";
	cout << "\033[0;93m\\033[0;93m Yellow\033[0m\n";
	cout << "\033[0;94m\\033[0;94m Blue\033[0m\n";
	cout << "\033[0;95m\\033[0;95m Purple\033[0m\n";
	cout << "\033[0;96m\\033[0;96m Cyan\033[0m\n";
	cout << "\033[0;97m\\033[0;97m White\033[0m\n\n";

	cout << "Bold High Intensity\n";
	cout << "\033[1;90m\\033[1;90m Black\033[0m\n";
	cout << "\033[1;91m\\033[1;91m Red\033[0m\n";
	cout << "\033[1;92m\\033[1;92m Green\033[0m\n";
	cout << "\033[1;93m\\033[1;93m Yellow\033[0m\n";
	cout << "\033[1;94m\\033[1;94m Blue\033[0m\n";
	cout << "\033[1;95m\\033[1;95m Purple\033[0m\n";
	cout << "\033[1;96m\\033[1;96m Cyan\033[0m\n";
	cout << "\033[1;97m\\033[1;97m White\033[0m\n\n";

	cout << "High Intensity backgrounds\n";
	cout << "\033[0;100m\\033[0;100m Black\033[0m\n";
	cout << "\033[0;101m\\033[0;101m Red\033[0m\n";
	cout << "\033[0;102m\\033[0;102m Green\033[0m\n";
	cout << "\033[0;103m\\033[0;103m Yellow\033[0m\n";
	cout << "\033[0;104m\\033[0;104m Blue\033[0m\n";
	cout << "\033[0;105m\\033[0;105m Purple\033[0m\n";
	cout << "\033[0;106m\\033[0;106m Cyan\033[0m\n";
	cout << "\033[0;107m\\033[0;107m White\033[0m\n";
	cout << "\033[0;109m\\033[0;109m Default\033[0m\n\n";

	cout << "Reset\n";
	cout << "\033[0m\\033[0m\n\n";

	cout << "\\x1b and \\e are also used instead of \\033\n\n";
	cout << "More escape sequences:\n";
	cout << "\\033[2J\\033[1;1H Clear screen\n";

	return 0;
}
