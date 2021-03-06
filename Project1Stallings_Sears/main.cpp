// Project1Stallings_Sears.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Frequency.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {

	ifstream infile(argv[1]); //open the file

	if (infile.is_open() && infile.good()) {
		string s = "";
		getline(infile, s); //collects the entire cipherText into s
		double length = s.length(); // used to count the total amount of a character
		frequencyAnalysis(s, length);
	}
	else {
		cout << "Failed to open file.." << endl;
	}

	return 0;
}

