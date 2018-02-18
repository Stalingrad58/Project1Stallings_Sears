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
	cout << (MonoOrDi) << "\t\t" << frequency * 100 << "%" << endl;
	return;
}
void MonoDigrams::PrintTrigrams() {

	cout << (MonoOrDi) << "\t\t" << frequency * 100 << "%\t\t";
	for (unsigned int i = 0; i < (locations.size() - 1); i++) {
		
		cout << (locations.at(i + 1) - locations.at(i)) << "  ";
	}
	cout << endl;
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

void MonoDigrams::setLocation(vector<unsigned int> loca) {
	for (unsigned int i = 0; i < loca.size(); i++) {
		locations.push_back(loca.at(i));
	}
}
int MonoDigrams::getLocation(int i) {
	return locations.at(i);
}

vector<MonoDigrams> monoFrequencyAnalysis(string cipher, double length) {
	//int i = 65;
	string ascii;
	int key = 0;
	double IC = 0;
	vector<MonoDigrams> monograms;
	monograms.resize(26);
	monograms.size();
	for (int i = 65; i <= 90; i++) {
		ascii = i;
		int characterCount = count(cipher.begin(), cipher.end(), i);
		double currentFrequency = characterCount / length;
		monograms[i - 65].setMono(ascii, characterCount, currentFrequency);
		monograms[i - 65].PrintMonograms();
		IC += currentFrequency * currentFrequency;
	}
	cout << endl << endl << endl;
	return monograms;
}
	//digrams
vector<MonoDigrams> diFrequencyAnalysis(string cipher, double length) {
	int stop;
	int counter;
	vector<MonoDigrams> digrams;
	string stringOne, stringTwo;

	for (unsigned int j = 0; j < (cipher.size() - 1); j++) {
		stringOne = cipher.at(j);
		stringOne += cipher.at(j + 1);
		counter = 0;
		stop = 0;

		for (unsigned int i = 0; i < digrams.size(); i++) {
			if (stringOne == digrams.at(i).getLetters()) {
				stop = 1;
				break;
			}
		}

		if (stop) {
		}
		else {
			for (unsigned int x = j; x < (cipher.size() - 1); x++) {
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
			for (unsigned int x = j; x < (cipher.size() - 1); x++) {
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
	for (unsigned int x = 0; x < digrams.size(); x++) {
		if (digrams[x].getFrequency() > .01) {
			digrams[x].PrintMonograms();
		}
	}
	return digrams;
}

	//trigrams

vector<MonoDigrams> triFrequencyAnalysis(string cipher, double length){
	int stop, counter;
	vector<MonoDigrams> trigrams;
	vector<unsigned int> locations;
	string stringOne, stringTwo;

	for (unsigned int j = 0; j < (cipher.size() - 2); j++) {
		stringOne = cipher.at(j);
		stringOne += cipher.at(j + 1);
		stringOne += cipher.at(j + 2);
		counter = 0;
		stop = 0;
		locations.clear();
		locations.push_back(j);
		

		for (unsigned int i = 0; i < trigrams.size(); i++) {
			if (stringOne == trigrams.at(i).getLetters()) {
				stop = 1;
				break;
			}
		}

		if (stop) {

		}
		else {
			for (unsigned int x = (j + 1); x < (cipher.size() - 2); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				stringTwo += cipher.at(x + 2);
				if (stringOne == stringTwo) {
					counter += 1;
					locations.push_back(x);
				}
			}
			MonoDigrams toAddTri;
			toAddTri.setMono(stringOne, counter, (counter / (length - 2)));
			toAddTri.setLocation(locations);
			trigrams.push_back(toAddTri);

		}
		if (trigrams.size() == 0) {
			for (unsigned int x = (j + 1); x < (cipher.size() - 2); x++) {
				stringTwo = cipher.at(x);
				stringTwo += cipher.at(x + 1);
				stringTwo += cipher.at(x + 2);
				if (stringOne == stringTwo) {
					counter += 1;
					locations.push_back(x);
				}
			}
			MonoDigrams toAddTri;
			toAddTri.setMono(stringOne, counter, (counter / length - 2));
			toAddTri.setLocation(locations);
			trigrams.push_back(toAddTri);
		}
	}
	cout << setprecision(3);
	for (unsigned int x = 0; x < trigrams.size(); x++) {
		if (trigrams[x].getFrequency() > .0004) {
			trigrams[x].PrintTrigrams();
		}
	}
	cout << setprecision(6);
	return trigrams;
}

double IC(vector<MonoDigrams> monograms) {
	double IC = 0;
	for (unsigned int i = 0; i < monograms.size(); i++) {
		IC += monograms[i].getFrequency() * monograms[i].getFrequency();
	}
	return IC;
}