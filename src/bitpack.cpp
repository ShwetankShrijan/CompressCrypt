#include "../include/bitpack.h"
#include <vector>
#include <string>
using namespace std;

vector<unsigned char> packBits(const string& bits){
    vector<unsigned char> packed;
    unsigned char current = 0;
    int count = 0;
    for(char bit : bits){
        current <<= 1;
        if(bit == '1') current |= 1;
        count++;
        if(count == 8){
            packed.push_back(current);
            current = 0;
            count = 0;
        }
    }

    if(count != 0){
        current <<= (8 - count);
        packed.push_back(current);
    }
    return packed;
}

string unpackBits(const vector<unsigned char>& bytes, int originalBitCount){
    string bits;
    for(unsigned char byte : bytes){
        for(int i = 7; i >= 0; i--){
            bits += ((byte >> i) & 1) ? '1' : '0';
        }
    }
    bits.resize(originalBitCount);
    return bits;
}