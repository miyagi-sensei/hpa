#include <iostream>
#include <math.h>
using namespace std;
#define DIGIT2CHAR(d) char(d + ZERO)
#define ZERO '0'

string add(string x, string y) {
    int digit, carry = 0, i;
    int len_diff = abs(int(x.length() - y.length()));
    string zeros(len_diff, ZERO);
    if (x.length() < y.length()) {
        x = zeros + x;
    } else {
        y = zeros + y;
    }
    for (i = x.length() - 1; i >= 0; i--){
        digit = int(x[i] - ZERO) + int(y[i] - ZERO) + carry;
        carry = digit / 10;
        digit = digit % 10;
        x[i] = char(digit + ZERO);
    }
    if (carry == 1){
        return '1' + x;
    }
    else{
        return x;
    }
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << add(x, y) << endl;
}

