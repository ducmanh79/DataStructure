#include <iostream>
#include "Combination.h"
	Combination::Combination(unsigned int aN, unsigned int aK) {
		fN = aN;
		fK = aK;
	}
	unsigned int Combination::getN() const {
		return fN;
	}

	unsigned int Combination::getK() const {
		return fK;
	}

	unsigned long long Combination::operator()() const {
		unsigned long long result = fN;
		if (fK > fN) return 0;
		if (fK <= fN) {
			for (int i = 2; i <= fK; i++)
			{
				result *= (fN - (i - 1));
				result /= i;
			}
		} 
		return result;
	}