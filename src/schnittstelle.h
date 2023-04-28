/*
 ============================================================================
 Name        : schnittstelle.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Interface Class Header for Digital Logic Circuit Simulator
 ============================================================================
 */

#ifndef SCHNITTSTELLE_H_
#define SCHNITTSTELLE_H_

class Schnittstelle {
private:
	short pegel; // HIGH, LOW, UNDEFINED
public:
	static const short HIGH = 1;
    static const short LOW = 0;
	static const short UNDEFINED = -1;

	Schnittstelle(): pegel(LOW) {}
	
	short getPegel() {
		return pegel;
	}

	bool setPegel(short pegel) {
		if (pegel == HIGH || pegel == LOW) {
			this->pegel = pegel;
			return true;
		}
		this->pegel = UNDEFINED;
		return false;
	}
};

#endif /*SCHNITTSTELLE_H_*/
