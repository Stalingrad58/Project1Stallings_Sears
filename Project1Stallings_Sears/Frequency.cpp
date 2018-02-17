#include "stdafx.h"
#include "Frequency.h"
#include <iostream> 
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

MonoDigrams::MonoDigrams() {

}
MonoDigrams::MonoDigrams(string letters, int count, double freq) {
	MonoOrDi = letters;
	numberAppearance = count;
	frequency = freq;
}
void MonoDigrams::PrintMonograms() {
	cout << MonoOrDi << "\t\t" << frequency << endl;
	return;
}

string MonoDigrams::getLetters() {
	return MonoOrDi;
}

int MonoDigrams::getCount() {
	return numberAppearance;
}
double MonoDigrams::getFrequency() {
	return frequency;
}

void frequencyAnalysis(string cipher, double length) {
	int i = 65;
	int key = 0;
	double IC = 0;
	vector<MonoDigrams> monograms(26);
	for (int i = 65; i <= 90; i++) {
		int characterCount = count(cipher.begin(), cipher.end(), i);
		double currentFrequency = characterCount / length;
//		monograms[i] = MonoDigrams(to_string(i), characterCount, currentFrequency);
//		monograms[i].PrintMonograms();

	}
		/*if (currentFrequency > frequency1) {
			frequency2 = frequency1;
			frequency1 = currentFrequency;
			whatLetter2 = whatLetter1;
			whatLetter1 = i;
		}
		else if (currentFrequency > frequency2) {
			frequency2 = currentFrequency;
			whatLetter2 = i;
		}
	}
	cout << frequency1 << endl;
	cout << char(whatLetter1) << endl;
	cout << frequency2 << endl;
	cout << char(whatLetter2) << endl;
	key = whatLetter1 - 69;
	cout << key << endl;
	*/

}