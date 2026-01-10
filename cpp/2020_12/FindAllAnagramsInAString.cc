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

/* 문제를 보고 처음 내가 생각해낸 풀이 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int current = 0;
    int startIndex = 0;
    vector<int> pCount;
    vector<int> counts;
    vector<int> answer;

    if (s.empty()) return answer;

    pCount.resize(26, -1);

    for (int i = 0; i < p.length(); ++i) {
        if (pCount[p[i]-'a'] == -1) {
            pCount[p[i]-'a'] = 1;
        } else {
            pCount[p[i]-'a']++;
        }
    }

    counts = pCount;

    for (int i = 0; i < s.length(); ++i) {
        if (counts[s[i]-'a'] == -1) {
            startIndex = i+1;
            if (current > 0) {
                counts = pCount;
                current = 0;
            }
        } else if (counts[s[i]-'a'] > 0) {
            current++;
            counts[s[i]-'a']--;
            if (current == p.length()) {
                answer.push_back(startIndex);
                counts[s[startIndex]-'a']++;
                startIndex++;
                current--;
            }
        } else if (counts[s[i]-'a'] == 0) {
            current++;
            counts[s[i]-'a']--;
            for (int j = startIndex; j < i; ++j) {
                counts[s[j]-'a']++;
                startIndex++;
                current--;
                if (s[j] == s[i]) break;
            }
        }
    }

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

    vector<int> answer0 = findAnagrams(s0, p0); // 0 6
    vector<int> answer1 = findAnagrams(s1, p1); // 0 1 2
    vector<int> answer2 = findAnagrams(s2, p2); // 
    vector<int> answer3 = findAnagrams(s3, p3); // 1 2 3 5
    vector<int> answer4 = findAnagrams(s4, p4); // 3 4 6

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

    return 0;
}


