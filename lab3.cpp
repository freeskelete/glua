#include <iostream>

int main() {

	// Пункт 1
	int A, B, C;
	std::cout << "Input 3 natural numbers" << std::endl;
	std::cin >> A >> B >> C;
	if (A > 0 && B > 0 && C > 0) {
		if (A > B && B > C) {
			std::cout << A - B - C << " A > B & B > C" << std::endl;
		}
		else if (B > A && B % C == 0) {
			std::cout << B / C + B - A << " B > A & B % C" << std::endl;
		}
		else {
			std::cout << A + B + C << " A + B + C " << std::endl;
		}
	}
	else {
		std::cout << " Error with input " << std::endl;
	}
	// Пункт 2
	int n;
	std::cout << "Vvedit cifru N: " << std::endl;
	std::cin >> n;

	switch (n) {
	case 0:
		std::cout << "null";
		break;
	case 1:
		std::cout << "odin";
		break;
	case 2:
		std::cout << "dva";
		break;
	case 3:
		std::cout << "tri";
		break;
	case 4:
		std::cout << "chetire";
		break;
	case 5:
		std::cout << "pyat'";
		break;
	case 6:
		std::cout << "shest'";
		break;
	case 7:
		std::cout << "siem'";
		break;
	case 8:
		std::cout << "vosiem";
		break;
	case 9:
		std::cout << "dievet";
		break;
	default:
		std::cout << "invalid cifra";
		break;
	}
	// Доп
	int x = 0; // initialize x to 0

	std::cout << "Enter a number -1 or 1: " << std::endl;
	std::cin >> x;

	if (x == -1) {
		std::cout << "Negative number" << std::endl;
	}
	else if (x == 1) {
		std::cout << "Positive number" << std::endl;
	}
	else {
		std::cout << "Invalid input" << std::endl;
	}
}
