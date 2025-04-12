#include "headern.h"


int32_t* ProizvodnayaMain(int32_t* deg, int32_t& d, int32_t NMAX) {
	EnterOfArray(deg, d, NMAX);
	Proizvodnaya(deg, d);
	PrintOfArray(deg, d);
	return deg;
}

int32_t* Proizvodnaya(int32_t* deg, int32_t d) {
	for (int32_t i{ d }; i > 0; i--) {
		deg[i] *= i;
	}
	for (int32_t i{ 0 }; i <= d; i++) {
		deg[i] = deg[i + 1];
	}
	deg[d] = 0;
	return deg;
}

void PrintOfArray(int32_t* deg, int32_t d) {
	std::cout << "Your array is :\n";
	for (int32_t i{ d }; i >= 0; --i) {
		std::cout << "Coeficent with degree " << i << " is " << deg[i] << "\n";
	}
}

int32_t* EnterOfArray(int32_t* deg, int32_t& d,int32_t NMAX) {
	std::cout << "Enter max deg < " << NMAX << "\n";
	std::cin >> d;
	while (CheckSize(d, NMAX) == false) {
		std::cout << "Invalid value. Please try again: ";
		std::cin >> d;
	}
	std::cout << " Enter coeficent \n";
	for (int32_t i{ d }; i >= 0; --i) {
		std::cout << " coef " << i << " :";
		std::cin >> deg[i];
		std::cout << "\n";
	}
	return deg;
}

bool CheckSize(int32_t d,int32_t NMAX) {
	if ((d > NMAX-1)||(d<0)){
		return false;
	}
	else {
		return true;
	}
}