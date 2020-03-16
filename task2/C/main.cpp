#include "main.h"

int C_res() {
	return 3;
}

int main() {
	std::cout << A_res() << std::endl;
	std::cout << B_res() << std::endl;
	std::cout << C_res() << std::endl;
	return 0;
}