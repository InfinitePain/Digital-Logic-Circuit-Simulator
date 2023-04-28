/*
 ============================================================================
 Name        : halbaddierer.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Half Adder Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#ifndef HALBADDIERER_H_
#define HALBADDIERER_H_

#include "schaltung.h"
#include "xor2.h"
#include "und2.h"

class Halbaddierer: public Schaltung {
public:
	Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1) {
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		addAusgang(a1);

		Xor2* xor2 = new Xor2(e0, e1, a0);
		Und2* und2 = new Und2(e0, e1, a1);

		bausteine.push_back(xor2);
		bausteine.push_back(und2);

		name = "Halbaddierer";
	}

	void update() {
		for (Baustein* b : bausteine) {
			b->update();
		}
	}
};

#endif /*HALBADDIERER_H_*/
