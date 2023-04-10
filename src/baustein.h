/*
 ============================================================================
 Name        : baustein.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Building Block Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#pragma once

#include "schnittstelle.h"
#include <iostream>
#include <string>
#include <vector>

class Baustein {
protected:
	std::string name;
	std::vector<Schnittstelle*> eingaenge;
	std::vector<Schnittstelle*> ausgaenge;

public:
	void addEingang(Schnittstelle* schnittstelle) {
		eingaenge.push_back(schnittstelle);
	}

	void addAusgang(Schnittstelle* schnittstelle) {
		ausgaenge.push_back(schnittstelle);
	}

	virtual void print() {
		std::cout << "Baustein: " << name << std::endl;
		for (int i = 0; i < eingaenge.size(); i++) {
			std::cout << "Eingang " << i << ": " << "Pegel = " << eingaenge.at(i)->getPegel() << std::endl;
		}
		for (int i = 0; i < ausgaenge.size(); i++) {
			std::cout << "Ausgang " << i << ": " << "Pegel = " << ausgaenge.at(i)->getPegel() << std::endl;
		}
	}

	virtual void update() = 0;
	friend void test(Baustein* b);
};
