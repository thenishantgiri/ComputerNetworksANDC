#include <iostream>
using namespace std;

string calcXor(string a, string b) {
    string result = "";
    int len = a.length();
    // if bits are same, XOR is 0, else 1
    for (int i = 1; i < len; i++) {
        if (a[i] == b[i]) {
            result += "0";
        } else {
            result += "1";
        }
    }
    return result;
}

string mod2div(string divident, string divisor) {
    int pick = divisor.length();
    int n = divident.length();
    string tmp = divident.substr(0, pick);
    string zeroDivisor = string(pick, '0');

    while (pick < n) {
        if (tmp[0] == '1') {
            tmp = calcXor(divisor, tmp) + divident[pick];
        } else {
            tmp = calcXor(zeroDivisor, tmp) + divident[pick];
        }
        pick++;
    }

    if (tmp[0] == '1') {
        tmp = calcXor(divisor, tmp);
    } else {
        tmp = calcXor(zeroDivisor, tmp);
    }
    return tmp;
}

void encodeData(string data, string key) {
    int zerosToAppend = key.length() - 1;
    string appendedData = data;
    for (int i = 0; i < zerosToAppend; i++) {
        appendedData += "0";
    }

    string remainder = mod2div(appendedData, key);
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << "\n";
    cout << "Codeword: " << codeword << "\n";
}

int main() {
    string data = "100100";
    string key = "1101";
    encodeData(data, key);
    return 0;
}