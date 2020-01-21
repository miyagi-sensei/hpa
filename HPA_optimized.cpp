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

string mult(string x, string y) {
    int sign_x = 1, sign_y = 1, i, j;
    if (x == "0" || y == "0") return "0";
    if (x[0] == '-') {
        x.erase(0, 1);      // inefficient but good enough for this problem
        sign_x = -1;
    }
    if (y[0] == '-') {
        y.erase(0, 1);      // inefficient but good enough for this problem
        sign_y = -1;
    }
    int temp, carry, dy;
    string answer = "", zeros = "", prod(x.length(), '0');
    for (j = y.length() - 1; j >= 0; j--) {
        dy = y[j] - ZERO;
        if (dy == 1) {
            answer = add(answer, x + zeros);
        } else if (dy) {
            carry = 0;
            for (i = x.length() - 1; i >= 0; i--){
                temp = int(x[i] - ZERO) * dy + carry;
                carry = temp / 10;
                temp = temp % 10;
                prod[i] = char(temp + ZERO);
            }
            if (carry > 0){
                answer = add(answer, char(carry + ZERO) + prod + zeros);
            } else {
                answer = add(answer, prod + zeros);
            }
        }
        zeros += ZERO;
    }
    return ((sign_x * sign_y)) == 1 ? answer : '-' + answer;
}

string factorial(int n) {
    string fact_str = "1";
    for (int i=2; i<=n; i++) {
        fact_str = mult(fact_str, to_string(i));
    }
    return fact_str;
}

int main()
{
    int N;
    cin >> N;
    cout << factorial(N) << endl;
    return 0;
}

