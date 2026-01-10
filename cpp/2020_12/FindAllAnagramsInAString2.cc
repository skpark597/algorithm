/* 438. Find All Anagrams in a String */
/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
   Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20100.
   The order of output does not matter.
   
   Example 1:
   Input: s: "cbaebabacd" p: "abc"
   Output: [0, 6]
   
   Explanation:
   The substring with start index = 0 is "cba", which is an anagram of "abc".
   The substring with start index = 6 is "bac", which is an anagram of "abc".
   
   Example 2:
   Input: s: "abab" p: "ab"
   Output: [0, 1, 2]
   
   Explanation:
   The substring with start index = 0 is "ab", which is an anagram of "ab".
   The substring with start index = 1 is "ba", which is an anagram of "ab".
   The substring with start index = 2 is "ab", which is an anagram of "ab". **/

/* Discussion을 보고 구현한 풀이 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> answer;
    vector<int> sCounts (26, 0);
    vector<int> pCounts (26, 0);
    int s_size = s.length();
    int p_size = p.length();

    if (s_size == 0 || s_size < p_size) return answer;

    for (int i = 0; i < p_size; ++i) {
        sCounts[s[i]-'a']++;
    }

    for (int i = 0; i < p_size; ++i) {
        pCounts[p[i]-'a']++;
    }

    for (int i = 0; i < s_size-p_size; ++i) {
        if (sCounts == pCounts) {
            answer.push_back(i);
        }

        sCounts[s[i]-'a']--;
        sCounts[s[i+p_size]-'a']++;
    }

    if (sCounts == pCounts) answer.push_back(s_size-p_size);

    return answer;
}

int main() {
    string s0 = "cbaebabacd";
    string p0 = "abc";

    string s1 = "abab";
    string p1 = "ab";

    string s2 = "aa";
    string p2 = "bb";

    string s3 = "abacbabc";
    string p3 = "abc";

    string s4 = "abaacbabc";
    string p4 = "abc";

    string s5 = "cbaebabacd";
    string p5 = "abc";

    vector<int> answer0 = findAnagrams(s0, p0); // 0 6
    vector<int> answer1 = findAnagrams(s1, p1); // 0 1 2
    vector<int> answer2 = findAnagrams(s2, p2); // 
    vector<int> answer3 = findAnagrams(s3, p3); // 1 2 3 5
    vector<int> answer4 = findAnagrams(s4, p4); // 3 4 6
    vector<int> answer5 = findAnagrams(s5, p5); // 0 6

    for (int i = 0; i < answer0.size(); ++i) {
        cout << answer0[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < answer1.size(); ++i) {
        cout << answer1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < answer2.size(); ++i) {
        cout << answer2[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < answer3.size(); ++i) {
        cout << answer3[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < answer4.size(); ++i) {
        cout << answer4[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < answer5.size(); ++i) {
        cout << answer5[i] << " ";
    }

    return 0;
}