#ifndef BITPACK_H
#define BITPACK_H

#include <vector>
#include <string>

using namespace std;

vector<unsigned char> packBits(const string& bits);
string unpackBits(const vector<unsigned char>& bytes, int originalBitCount);

#endif