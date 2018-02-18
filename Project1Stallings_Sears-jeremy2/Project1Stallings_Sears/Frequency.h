#pragma once
#ifndef FREQUENCY_H_
#define FREQUENCY_H_

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class MonoDigrams {
private:
	string MonoOrDi;
	int numberAppearance;
	double frequency;
	vector<int> locations;

public:
	MonoDigrams();
	void setMono(string letters, int count, double frequency);
	void PrintMonograms();
	void PrintTrigrams();
	string getLetters();
	int getCount();
	double getFrequency();
	void setLocation(vector<unsigned int> loca);
	int getLocation(int i);
	
};
vector<MonoDigrams> monoFrequencyAnalysis(string cipher, double length);
vector<MonoDigrams> diFrequencyAnalysis(string cipher, double length);
vector<MonoDigrams> triFrequencyAnalysis(string cipher, double length);
double IC(vector<MonoDigrams> monograms);

#endif 
