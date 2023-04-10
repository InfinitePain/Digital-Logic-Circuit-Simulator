/*
 ============================================================================
 Name        : volladdierer.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Full Adder Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#pragma once

#include "schaltung.h"
#include "oder2.h"

class Volladdierer: public Schaltung {
public:
	Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1) {
		addEingang(e0);
		addEingang(e1);
		addEingang(e2);
		addAusgang(a0);
		addAusgang(a1);

		Schnittstelle* intern0 = new Schnittstelle();
		Schnittstelle* intern1 = new Schnittstelle();
		Schnittstelle* intern2 = new Schnittstelle();

		intern.push_back(intern0);
		intern.push_back(intern1);
		intern.push_back(intern2);

		Halbaddierer* ha0 = new Halbaddierer(e0, e1, intern1, intern0);
		Halbaddierer* ha1 = new Halbaddierer(intern1, e2, a0, intern2);
		Oder2* oder2 = new Oder2(intern0, intern2, a1);

		bausteine.push_back(ha0);
		bausteine.push_back(ha1);
		bausteine.push_back(oder2);

		name = "Volladdierer";
	}

	void update() {
		bausteine.at(0)->update();
		bausteine.at(1)->update();
		bausteine.at(2)->update();
	}
};
