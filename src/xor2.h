/*
 ============================================================================
 Name        : xor2.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : XOR Gate Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#pragma once

#include "baustein.h"
#include <vector>

class Xor2: public Baustein {
public:
	Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0) {
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		name = "Xor2";
	}

	void update() {
		short e0Pegel = eingaenge.at(0)->getPegel();
		short e1Pegel = eingaenge.at(1)->getPegel();

		if (e0Pegel == Schnittstelle::UNDEFINED || e1Pegel == Schnittstelle::UNDEFINED) {
			ausgaenge.at(0)->setPegel(Schnittstelle::UNDEFINED);
		}
		else if (e0Pegel == e1Pegel) {
			ausgaenge.at(0)->setPegel(Schnittstelle::LOW);
		}
		else {
			ausgaenge.at(0)->setPegel(Schnittstelle::HIGH);
		}
	}
};
