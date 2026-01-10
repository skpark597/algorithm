/** 1869. Longer Contiguous Segments of Ones than Zeros */
/** Given a binary string s, return true if the longest contiguous segment of 1s is strictly longer than 
 *  the longest contiguous segment of 0s in s. Return false otherwise.
 *  For example, in s = "110100010" the longest contiguous segment of 1s has length 2, 
 *  and the longest contiguous segment of 0s has length 3.
 *  Note that if there are no 0s, then the longest contiguous segment of 0s is considered to have length 0. 
 *  The same applies if there are no 1s.
 * 
 *  Example 1:
 *  Input: s = "1101"
 *  Output: true
 *  Explanation:
 *  The longest contiguous segment of 1s has length 2: "1101"
 *  The longest contiguous segment of 0s has length 1: "1101"
 *  The segment of 1s is longer, so return true.
 * 
 *  Example 2:
 *  Input: s = "111000"
 *  Output: false
 *  Explanation:
 *  The longest contiguous segment of 1s has length 3: "111000"
 *  The longest contiguous segment of 0s has length 3: "111000"
 *  The segment of 1s is not longer, so return false.
 * 
 *  Example 3:
 *  Input: s = "110100010"
 *  Output: false
 *  Explanation:
 *  The longest contiguous segment of 1s has length 2: "110100010"
 *  The longest contiguous segment of 0s has length 3: "110100010"
 *  The segment of 1s is not longer, so return false.
 * 
 *  Constraints:
 *  1 <= s.length <= 100
 *  s[i] is either '0' or '1'. **/

#include <string>
#include <iostream>

using namespace std;

int getLength(string &s, char num) {
    int length = 0;
    int start = 0;
    int end = 0;

    for (end = 0; end < s.length(); ++end) {
        if (s[end] != num) {
            length = max(length, end-start);
            start = end+1;
        }
    }

    return max(length, end-start);
}

bool checkZeroOnes(string s) {
    int length0 = getLength(s, '0');
    int length1 = getLength(s, '1');

    return length1 > length0;
}

int main() {
    string s0 = "1101";
    string s1 = "111000";
    string s2 = "110100010";

    bool ans0 = checkZeroOnes(s0);
    bool ans1 = checkZeroOnes(s1);
    bool ans2 = checkZeroOnes(s2);

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false
    cout << ans2 << endl; // false

    return 0;
}
