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
void MonoDigrams::setMono(string letters, int count, double freq) {
	MonoOrDi = letters;
	numberAppearance = count;
	frequency = freq;
}
void MonoDigrams::PrintMonograms() {
	cout << setprecision(3);
	cout << (MonoOrDi) << "\t\t" << frequency*100 << "%" << endl;
	cout << setprecision(0);
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
	//int i = 65;
	string ascii;
	int stop;
	int key = 0;
	int counter;
	double IC = 0;
	vector<MonoDigrams> monograms;
	monograms.resize(26);
	monograms.size();
	for (int i = 65; i <= 90; i++) {
		ascii = i;
		int characterCount = count(cipher.begin(), cipher.end(), i);
		double currentFrequency = characterCount / length;
		monograms[i-65].setMono(ascii, characterCount, currentFrequency);
		monograms[i-65].PrintMonograms();
	}
	cout << endl << endl << endl;

	vector<MonoDigrams> digrams;
	string stringOne, stringTwo;

	for (int j = 0; j < (cipher.size() - 1); j++) {
		stringOne = cipher.at(j);
		stringOne += cipher.at(j + 1);
		counter = 0;
		stop = 0;

		for (int i = 0; i < digrams.size(); i++) {
			if (stringOne == digrams.at(i).getLetters()) {
				stop = 1;
			}
		}

		if (stop) {

		}
		else {
			for (int x = j; x < (cipher.size() - 1); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				if (stringOne == stringTwo) {
					counter += 1;
				}
			}
			MonoDigrams toAdd;
			toAdd.setMono(stringOne, counter, (counter / (length - 1)));
			digrams.push_back(toAdd);
			//toAdd.PrintMonograms();
			
		}
		if (digrams.size() == 0) {
			for (int x = j; x < (cipher.size() - 1); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				if (stringOne == stringTwo) {
					counter += 1;
				}
			}
			MonoDigrams toAdd;
			toAdd.setMono(stringOne, counter, (counter / (length - 1)));
			digrams.push_back(toAdd);
		}
	}
	for (int x = 0; x < digrams.size(); x++) {
		if (digrams[x].getFrequency() > .01) {
			digrams[x].PrintMonograms();
		}
	}



	//trigrams



	vector<MonoDigrams> trigrams;


	for (int j = 0; j < (cipher.size() - 2); j++) {
		stringOne = cipher.at(j);
		stringOne += cipher.at(j + 1);
		stringOne += cipher.at(j + 2);
		counter = 0;
		stop = 0;

		for (int i = 0; i < trigrams.size(); i++) {
			if (stringOne == trigrams.at(i).getLetters()) {
				stop = 1;
			}
		}

		if (stop) {
		}
		else {
			for (int x = j; x < (cipher.size() - 2); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				stringTwo += cipher.at(x + 2);
				if (stringOne == stringTwo) {
					counter += 1;
				}
			}
			MonoDigrams toAddTri;
			toAddTri.setMono(stringOne, counter, (counter / (length - 2)));
			trigrams.push_back(toAddTri);
		}
		if (trigrams.size() == 0) {
			for (int x = j; x < (cipher.size() - 2); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				stringTwo += cipher.at(x + 2);
				if (stringOne == stringTwo) {
					counter += 1;
				}
			}
			MonoDigrams toAddTri;
			toAddTri.setMono(stringOne, counter, (counter / (length - 2)));
			trigrams.push_back(toAddTri);
		}
	}
	for (int x = 0; x < trigrams.size(); x++) {
		if (trigrams[x].getFrequency() > .004) {
			trigrams[x].PrintMonograms();
		}
	}


}