/*
 ============================================================================
 Name        : baustein.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Building Block Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include "schnittstelle.h"


class Baustein {
protected:
	// Attributes

public:
	void addEingang(Schnittstelle* schnittstelle) {
		// code
	}

	void addAusgang(Schnittstelle* schnittstelle) {
		// code
	}

	virtual void print() {
		// code
	}

	virtual void update() = 0;
	friend void test2(Baustein* b);
};
