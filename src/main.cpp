/*
 ============================================================================
 Name        : main.cpp
 Author      : InfinitePain
 Version     : 0.1.0
 License     : Apache License 2.0
 Description : Digital Logic Circuit Simulator Main Program
 ============================================================================
 */

#include "halbaddierer.h"
#include "volladdierer.h"
#include "utilities.h"

void test(Baustein* b) {
	short input_values[] = { Schnittstelle::LOW, Schnittstelle::HIGH, Schnittstelle::UNDEFINED };
	int input_count = b->eingaenge.size();
	int num_combinations = 1;
	for (int i = 0; i < input_count; i++) {
		num_combinations *= 3;
	}

	for (int combination = 0; combination < num_combinations; combination++) {
		int temp_combination = combination;

		for (int input_idx = 0; input_idx < input_count; input_idx++) {
			int value_idx = temp_combination % 3;
			b->eingaenge.at(input_idx)->setPegel(input_values[value_idx]);
			temp_combination /= 3;
		}

		b->update();
		b->print();
	}
}

int main(int argc, char* argv[]) {
	bool run_tests = false;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "test") == 0) {
			run_tests = true;
			break;
		}
	}

	if (run_tests) {

		int Anzahl_Schnittstellen = 5;
		std::vector<Schnittstelle*> Schnittstellen;
		for (int i = 0; i < Anzahl_Schnittstellen; i++) {
			Schnittstellen.push_back(new Schnittstelle());
		}

		Oder2* o2 = new Oder2(Schnittstellen.at(0), Schnittstellen.at(1), Schnittstellen.at(2));
		test(o2);

		Halbaddierer* ha = new Halbaddierer(Schnittstellen.at(0), Schnittstellen.at(1), Schnittstellen.at(2), Schnittstellen.at(3));
		test(ha);

		Volladdierer* va = new Volladdierer(Schnittstellen.at(0), Schnittstellen.at(1), Schnittstellen.at(2), Schnittstellen.at(3), Schnittstellen.at(4));
		test(va);

		for (int i = 0; i < Anzahl_Schnittstellen; i++) {
			delete Schnittstellen.at(i);
		}

		delete ha;
		delete va;

		return 0;
	}
	else {
		std::cout << "Welcome to the 8-bit adder!" << std::endl;
		std::cout << "Enter two numbers: combine binary (4-8 digits) and decimal (0-255) as needed." << std::endl;
		while (true) {
			std::string number1 = get_number_from_user();
			std::string number2 = get_number_from_user();
			adder_8bit(number1, number2);
			std::cout << "Press 'q' to quit or any other key to continue." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (std::cin.peek() == 'q') {
				break;
			}
			else {
				std::cin.get();
			}
		}
		return 0;
	}
}
