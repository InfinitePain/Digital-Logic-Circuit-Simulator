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

void test(Baustein* b) {
	int numInputs = b->eingaenge.size();
	int numCombinations = 1 << numInputs;

	for (int i = 0; i < numCombinations; i++) {
		for (int j = 0; j < numInputs; j++) {
			int pegel = (i & (1 << j)) ? Schnittstelle::HIGH : Schnittstelle::LOW;
			b->eingaenge.at(j)->setPegel(pegel);
		}

		b->update();
		b->print();
		std::cout << std::endl;
	}
}

int main() {
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
