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

/* Solution을 보고 DP로 다시 구현한 문제 */

#include <string>
#include <list>
#include <cstring>
#include <iostream>

using namespace std;

bool cache[1000][1000];

string longestPalindrome(string s) {
    int size = s.length();
    string answer;
    int start = -1;
    int end = -1;

    memset(cache, false, sizeof(cache));

    if (s.empty()) return "";
    answer = s.back();

    for (int i = 0; i < size; ++i) {
        cache[i][i] = true;
    }

    for (int i = 0; i < size-1; ++i) {
        cache[i][i+1] = s[i] == s[i+1];
        if (cache[i][i+1]) start = i;
    }

    if (start != -1) answer = s.substr(start, 2);

    for (int i = 2; i < size; ++i) {
        for (int j = 0; j < size-i; ++j) {
            cache[j][j+i] = (s[j] == s[j+i]) && cache[j+1][j+i-1];
            if (cache[j][j+i]) {
                start = j;
                end = j+i;
            }
        }
    }

    if (end != -1) answer = s.substr(start, end-start+1);

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
