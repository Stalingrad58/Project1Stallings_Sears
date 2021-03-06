// Project1Stallings_Sears.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Frequency.h"
#include "Ciphers.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {

	ifstream infile(argv[1]); //open the file

	if (infile.is_open() && infile.good()) {
		string s = "";
		double Index = 0;
		MonoDigrams mostFrequent = MonoDigrams();
		getline(infile, s); //collects the entire cipherText into s
		double length = s.length(); // used to count the total amount of a character
		vector<MonoDigrams> monograms = monoFrequencyAnalysis(s, length);//gimme the vector of monograms and their frequencies
		Index = IC(monograms); //gimme the index of coincidence
		cout << "IC = " << Index << endl << endl << endl; //output it
		if (Index > 0.05) {
			for (unsigned int i = 0; i < monograms.size(); i++) {//find the most frequent monogram
				if (monograms[i].getFrequency() > mostFrequent.getFrequency()) {
					mostFrequent = monograms[i];
				}
			}
			shiftCipher(mostFrequent, s);
			substitutionCipher();
		}
		else {
			vector<MonoDigrams> trigrams = triFrequencyAnalysis(s, length);
			vignereCipher(trigrams, s);
		}

		
	}
	else {
		cout << "Failed to open file.." << endl;
	}

	return 0;
}

