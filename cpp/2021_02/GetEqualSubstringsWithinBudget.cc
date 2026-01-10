/** 1208. Get Equal Substrings Within Budget */
/** You are given two strings s and t of the same length. You want to change s to t. 
 *  Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, 
 *  the absolute difference between the ASCII values of the characters.
 *  You are also given an integer maxCost.
 *  Return the maximum length of a substring of s that can be changed to be the same as 
 *  the corresponding substring of twith a cost less than or equal to maxCost.
 *  If there is no substring from s that can be changed to its corresponding substring from t, return 0.
 * 
 *  Example 1:
 *  Input: s = "abcd", t = "bcdf", maxCost = 3
 *  Output: 3
 *  Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.
 * 
 *  Example 2:
 *  Input: s = "abcd", t = "cdef", maxCost = 3
 *  Output: 1
 *  Explanation: Each character in s costs 2 to change to charactor in t, so the maximum length is 1.
 * 
 *  Example 3:
 *  Input: s = "abcd", t = "acde", maxCost = 0
 *  Output: 1
 *  Explanation: You can't make any change, so the maximum length is 1.
 * 
 *  Constraints:
 *  1 <= s.length, t.length <= 10^5
 *  0 <= maxCost <= 10^6
 *  s and t only contain lower case English letters. **/

#include <string>
#include <iostream>

using namespace std;

int equalSubstring(string s, string t, int maxCost) {
    int start = 0;
    int end = 0;
    int cost = 0;
    int answer = 0;

    while (end < s.length()) {
        int nextCost = cost + abs(s[end]-t[end]);

        if (nextCost > maxCost) {
            cost -= abs(s[start]-t[start]);
            start++;
        } else {
            cost = nextCost;
            end++;
            answer = max(answer, end-start);
        }
    }

    return answer;
}

int main() {
    string s0 = "abcd";
    string t0 = "bcdf";
    int ans0 = equalSubstring(s0, t0, 3);

    string s1 = "abcd";
    string t1 = "cdef";
    int ans1 = equalSubstring(s1, t1, 3);

    string s2 = "abcd";
    string t2 = "acde";
    int ans2 = equalSubstring(s2, t2, 0);

    cout << ans0 << endl; // 3
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // 1

    return 0;
}

