#include "Frequency.h"
#include "stdafx.h"
#include <iostream> 
#include <string>
#include <sstream>
using namespace std;

void frequencyAnalysis(string cipher, double length) {
	int i = 65;
	int key = 0;
	int temp = 0;
	string plaintext = "";
	double frequency1 = 0;
	double frequency2 = 0;
	int whatLetter1 = 0;
	int whatLetter2 = 0;
	for (int i = 65; i <= 90; i++) {
		double characterCount = count(cipher.begin(), cipher.end(), i);
		double currentFrequency = characterCount / length;
		if (currentFrequency > frequency1) {
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
	cout << whatLetter1 << endl;
	cout << frequency2 << endl;
	cout << whatLetter2 << endl;
	key = whatLetter1 - 69;
	cout << key << endl;

}