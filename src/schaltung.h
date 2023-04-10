/*
 ============================================================================
 Name        : schaltung.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Circuit Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#pragma once

#include "schnittstelle.h"
#include "baustein.h"
#include <vector>

class Schaltung: public Baustein {
protected:
	std::vector<Baustein*> bausteine;
	std::vector<Schnittstelle*> intern;
public:
	virtual ~Schaltung() {
		for (Baustein* b : bausteine) {
			delete b;
		}
		for (Schnittstelle* s : intern) {
			delete s;
		}
	}
};
