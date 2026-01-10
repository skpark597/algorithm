/* 67. Add Binary */
/** Given two binary strings a and b, return their sum as a binary string.
 *  
 *  Example 1:
 *  Input: a = "11", b = "1"
 *  Output: "100"
 * 
 *  Example 2:
 *  Input: a = "1010", b = "1011"
 *  Output: "10101"
 * 
 *  Constraints:
 *  1 <= a.length, b.length <= 10^4
 *  a and b consist only of '0' or '1' characters.
 *  Each string does not contain leading zeros except for the zero itself. **/

#include <string>
#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    string answer;
    int aIndex = a.length()-1;
    int bIndex = b.length()-1;
    int surplus = 0;

    while (aIndex  >= 0 || bIndex >= 0 || surplus > 0) {
        int curA = aIndex >= 0 ? a[aIndex]-'0' : 0;
        int curB = bIndex >= 0 ? b[bIndex]-'0' : 0;
        int cur = curA + curB + surplus;

        if (cur >= 2) {
            answer = (char)(cur-2+'0') + answer;
            surplus = 1;
        } else {
            answer = (char)(cur+'0') + answer;
            surplus = 0;
        }
        
        aIndex--;
        bIndex--;
    }

    return answer;
}

int main() {
    string a0 = "11";
    string b0 = "1";

    string a1 = "1010";
    string b1 = "1011";

    string a2 = "1111";
    string b2 = "1111";

    string ans0 = addBinary(a0, b0);
    string ans1 = addBinary(a1, b1);
    string ans2 = addBinary(a2, b2);

    cout << ans0 << endl; // 100
    cout << ans1 << endl; // 10101
    cout << ans2 << endl; // 11110

    return 0;
}
