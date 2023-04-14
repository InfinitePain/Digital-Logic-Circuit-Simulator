/*
 ============================================================================
 Name        : oder2.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : OR Gate Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#pragma once

#include "baustein.h"
#include <vector>

class Oder2: public Baustein {
public:
	Oder2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0) {
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		name = "Oder2";
	}

	void update() {
		short e0Pegel = eingaenge.at(0)->getPegel();
		short e1Pegel = eingaenge.at(1)->getPegel();

		if (e0Pegel == Schnittstelle::UNDEFINED || e1Pegel == Schnittstelle::UNDEFINED) {
			ausgaenge.at(0)->setPegel(Schnittstelle::UNDEFINED);
		}
		else if (e0Pegel == Schnittstelle::HIGH || e1Pegel == Schnittstelle::HIGH) {
			ausgaenge.at(0)->setPegel(Schnittstelle::HIGH);
		}
		else {
			ausgaenge.at(0)->setPegel(Schnittstelle::LOW);
		}
	}
};
