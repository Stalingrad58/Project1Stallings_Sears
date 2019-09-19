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

public:
	MonoDigrams();
	void setMono(string letters, int count, double frequency);
	void PrintMonograms();
	string getLetters();
	int getCount();
	double getFrequency();
	
};
vector<MonoDigrams> monoFrequencyAnalysis(string cipher, double length);
void diFrequencyAnalysis(string cipher, double length);
void triFrequencyAnalysis(string cipher, double length);
double IC(vector<MonoDigrams> monograms);

#endif 
