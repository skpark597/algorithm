/* 567. Permutation in String */
/** Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
 *  In other words, one of the first string's permutations is the substring of the second string.
 * 
 *  Example 1:
 *  Input: s1 = "ab" s2 = "eidbaooo"
 *  Output: True
 *  Explanation: s2 contains one permutation of s1 ("ba").
 * 
 *  Example 2:
 *  Input:s1= "ab" s2 = "eidboaoo"
 *  Output: False
 * 
 *  Constraints:
 *  The input strings only contain lower case letters.
 *  The length of both given strings is in range [1, 10,000]. **/

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int s1_count[26];
int cur_count[26];

bool checkInclusion(string s1, string s2) {
    int start = 0;
    int end = 0;

    memset(s1_count, 0, sizeof(s1_count));
    memset(cur_count, 0, sizeof(cur_count));

    for (int i = 0; i < s1.length(); ++i) s1_count[s1[i]-'a']++;

    while (end < s2.length()) {
        if (s1_count[s2[end]-'a'] > cur_count[s2[end]-'a']) {
            cur_count[s2[end]-'a']++;
            end++;
        } else if (end-start != s1.length()) {
            cur_count[s2[start]-'a']--;
            start++;
        } else {
            return true;
        }
    }

    return end-start == s1.length();
}

int main() {
    string s01 = "ab";
    string s02 = "eidbaooo";

    string s11 = "ab";
    string s12 = "eidboaoo";

    string s21 = "adc";
    string s22 = "dcda";

    bool ans0 = checkInclusion(s01, s02);
    bool ans1 = checkInclusion(s11, s12);
    bool ans2 = checkInclusion(s21, s22);

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false
    cout << ans2 << endl; // true

    return 0;
}

