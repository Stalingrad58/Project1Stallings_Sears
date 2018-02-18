#pragma once
#ifndef CIPHERS_H_
#define CIPHERS_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "Frequency.h"

void shiftCipher(MonoDigrams mostFrequent, string cipher); //will attempt to decode cipher using shift cipher
void substitutionCipher(); //will attempt to decode cipher using substitution cipher
void vignereCipher(); //will attempt to decode cipher using substitution cipher
#endif