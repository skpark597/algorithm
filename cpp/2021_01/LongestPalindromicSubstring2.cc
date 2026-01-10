/* 5. Longest Palindromic Substring */
/** Given a string s, return the longest palindromic substring in s.
 * 
 *  Example 1:
 *  Input: s = "babad"
 *  Output: "bab"
 *  Note: "aba" is also a valid answer.
 * 
 *  Example 2:
 *  Input: s = "cbbd"
 *  Output: "bb"
 * 
 *  Example 3:
 *  Input: s = "a"
 *  Output: "a"
 * 
 *  Example 4:
 *  Input: s = "ac"
 *  Output: "a"
 * 
 *  Constraints:
 *  1 <= s.length <= 1000
 *  s consist of only digits and English letters (lower-case and/or upper-case). **/

/* 처음 떠올린 풀이.. 통과는 했으나 느리다.. */

#include <string>
#include <list>
#include <cstring>
#include <iostream>

using namespace std;

list<int> cache[1000];

void init() {
    for (int i = 0; i < 1000; ++i) {
        cache[i].clear();
    }
}

string longestPalindrome(string s) {
    int max = 0;
    string answer;
    init();

    if (s.empty()) return "";
    if (s.length() == 1) return s;

    cache[s.length()-1].push_back(s.length()-1);
    answer = s.back();

    for (int i = s.length()-2; i >= 0; --i) {
        list<int> &cur = cache[i];
        list<int> &prev = cache[i+1];

        cur.push_back(i);
        if (s[i] == s[i+1]) {
            cur.push_back(i+1);
            if (max < 2) {
                max = 2;
                answer = s.substr(i, 2);
            }
        }

        for (int iter : prev) {
            if (iter < s.length() && s[iter+1] == s[i]) {
                cur.push_back(iter+1);
                if (iter+2-i > max) {
                    max = iter+2-i;
                    answer = s.substr(i, max);
                }
            }
        }
    }

    return answer;
}

int main() {
    string s0 = "babad";
    string ans0 = longestPalindrome(s0);

    string s1 = "cbbd";
    string ans1 = longestPalindrome(s1);

    string s2 = "a";
    string ans2 = longestPalindrome(s2);

    string s3 = "ac";
    string ans3 = longestPalindrome(s3);

    cout << ans0 << endl; // aba
    cout << ans1 << endl; // bb
    cout << ans2 << endl; // a
    cout << ans3 << endl; // c

    return 0;
}

