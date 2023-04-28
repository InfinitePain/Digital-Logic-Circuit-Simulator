/*
 ============================================================================
 Name        : utilities.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Utility Functions Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "cstring"
#include <limits>
#include "halbaddierer.h"
#include "volladdierer.h"

std::string decimal_to_binary(int decimal, int length = 8) {
	std::string binary = "";
	for (int i = 0; i < length; i++) {
		if (decimal % 2 == 0) {
			binary = std::to_string(0) + binary;
		}
		else {
			binary = std::to_string(1) + binary;
		}
		decimal /= 2;
	}
	return binary;
}

int binary_to_decimal(std::string binary) {
	int decimal = 0;
	int length = binary.length();
	for (int i = 0; i < length; i++) {
		if (binary.at(i) == '1') {
			int pow_temp = 1;
			for (int j = 0; j <= length - i - 2; j++) {
				pow_temp *= 2;
			}
			decimal += pow_temp;
		}
	}
	return decimal;
}

short get_binary_value(std::string binary, int pos) {
	int correct_pos = binary.length() - pos - 1;
	if (binary.at(correct_pos) == '1') {
		return Schnittstelle::HIGH;
	}
	else {
		return Schnittstelle::LOW;
	}
}

void adder_8bit(const std::string& number1, const std::string& number2) {
	Schnittstelle* input1[8];
	Schnittstelle* input2[8];
	Schnittstelle* carry[8];
	Schnittstelle* output[8];
	Halbaddierer* half_adder;
	Volladdierer* full_adder[7];
	std::string binary_result;

	for (int i = 0; i < 8; i++) {
		input1[i] = new Schnittstelle();
		input2[i] = new Schnittstelle();
		carry[i] = new Schnittstelle();
		output[i] = new Schnittstelle();
	}

	for (int i = 0; i < 8; i++) {
		input1[i]->setPegel(get_binary_value(number1, i) ? Schnittstelle::HIGH : Schnittstelle::LOW);
		input2[i]->setPegel(get_binary_value(number2, i) ? Schnittstelle::HIGH : Schnittstelle::LOW);
	}

	half_adder = new Halbaddierer(input1[0], input2[0], output[0], carry[0]);

	for (int i = 1; i < 8; i++) {
		full_adder[i - 1] = new Volladdierer(input1[i], input2[i], carry[i - 1], output[i], carry[i]);
	}

	half_adder->update();

	for (int i = 0; i < 7; i++) {
		full_adder[i]->update();
	}

	for (int i = 0; i < 8; i++) {
		binary_result += std::to_string(output[7 - i]->getPegel());
	}

	std::cout << "Result in binary: " << binary_result << std::endl;
	std::cout << "Result in decimal: " << binary_to_decimal(binary_result) << std::endl;

	for (int i = 0; i < 8; i++) {
		delete input1[i];
		delete input2[i];
		delete carry[i];
		delete output[i];
	}

	delete half_adder;

	for (int i = 0; i < 7; i++) {
		delete full_adder[i];
	}
}

bool is_binary(const std::string& str) {
	if (str.length() == 0 || str.length() > 8) {
		return false;
	}
	for (char c : str) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

bool is_only_digits(const std::string& str) {
	if (str.length() == 0 || str.length() > 8) {
		return false;
	}
	for (char c : str) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}

bool is_valid_number(const std::string& str) {
	if(is_binary(str)) {
		return true;
	}
	else if (is_only_digits(str)) {
		int number = std::stoi(str);
		if (number >= 0 && number <= 255) {
			return true;
		}
	}
	return false;
}

std::string get_number_from_user() {
	std::string input;
	std::cout << "Number to add: ";
	std::cin >> input;
	while (std::cin.bad() || !is_valid_number(input)) {
		std::cout << "Invalid input. Please enter a number between 0 and 255 or a binary number with a maximum length of 8." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Number to add: ";
		std::cin >> input;
	}
	if (is_binary(input)) {
		if (input.length() < 8) {
			input.insert(0, 8 - input.length(), '0');
		}
		return input;
	}
	else {
		return decimal_to_binary(std::stoi(input));
	}
}

#endif /*UTILITIES_H_*/
