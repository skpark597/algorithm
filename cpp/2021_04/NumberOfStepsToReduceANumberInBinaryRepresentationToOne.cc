/* 1404. Number of Steps to Reduce a Number in Binary Representation to One */
/** Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:
 *  If the current number is even, you have to divide it by 2.
 *  If the current number is odd, you have to add 1 to it.
 *  It's guaranteed that you can always reach to one for all testcases.
 *  
 *  Example 1:
 *  Input: s = "1101"
 *  Output: 6
 *  Explanation: "1101" corressponds to number 13 in their decimal representation.
 *  Step 1) 13 is odd, add 1 and obtain 14. 
 *  Step 2) 14 is even, divide by 2 and obtain 7.
 *  Step 3) 7 is odd, add 1 and obtain 8.
 *  Step 4) 8 is even, divide by 2 and obtain 4.  
 *  Step 5) 4 is even, divide by 2 and obtain 2. 
 *  Step 6) 2 is even, divide by 2 and obtain 1.  
 * 
 *  Example 2:
 *  Input: s = "10"
 *  Output: 1
 *  Explanation: "10" corressponds to number 2 in their decimal representation.
 *  Step 1) 2 is even, divide by 2 and obtain 1.  
 * 
 *  Example 3:
 *  Input: s = "1"
 *  Output: 0
 * 
 *  Constraints:
 *  1 <= s.length <= 500
 *  s consists of characters '0' or '1'
 *  s[0] == '1' **/

#include <string>
#include <iostream>

using namespace std;

int numSteps(string s) {
    int count = 0;
    int i = 0;

    while (s.size() > 1) {
        count++;
        if (s.back() == '0') {
            s.pop_back();
            continue;
        }

        for (i = s.length()-1 ; i >= 0; --i) {
            if (s[i] == '0') {
                s[i] = '1';
                break;
            } 

            s[i] = '0';
        }

        if (i == -1) s = '1' + s;
    }

    return count;
}

int main() {
    string s0 = "1101";
    string s1 = "10";
    string s2 = "1";

    int ans0 = numSteps(s0);
    int ans1 = numSteps(s1);
    int ans2 = numSteps(s2);

    cout << ans0 << endl; // 6
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // 0

    return 0;
}