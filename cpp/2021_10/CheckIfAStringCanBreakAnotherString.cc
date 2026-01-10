/* 1433. Check If a String Can Break Another String */
/** Given two strings: s1 and s2 with the same size, 
 *  check if some permutation of string s1 can break some permutation of string s2 or vice-versa. 
 *  In other words s2 can break s1 or vice-versa.
 *  A string x can break string y (both of size n) if x[i] >= y[i] 
 *  (in alphabetical order) for all i between 0 and n-1.
 * 
 * Example 1:
 * Input: s1 = "abc", s2 = "xya"
 * Output: true
 * Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
 * 
 * Example 2:
 * Input: s1 = "abe", s2 = "acd"
 * Output: false 
 * Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all 
 * permutation for s2 = "acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". 
 * However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
 * 
 * Example 3:
 * Input: s1 = "leetcodee", s2 = "interview"
 * Output: true
 * 
 * Constraints:
 * s1.length == n
 * s2.length == n
 * 1 <= n <= 10^5
 * All strings consist of lowercase English letters.**/

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<char> makeWordVector(string s)
{
    vector<char> ans;
    for (char word : s)
        ans.push_back(word);

    return ans;
}

// word1 and word2 must be sorted
bool canBreak(vector<char> words1, vector<char> words2)
{
    int status = 0;
    for (int i = 0; i < words1.size(); ++i)
    {
        int diff = words1[i] - words2[i];

        if (diff == 0)
            continue;

        if (status == 0)
            status = diff;
        else if (status * diff < 0)
            return false;
    }

    return true;
}

bool checkIfCanBreak(string s1, string s2)
{
    vector<char> words1 = makeWordVector(s1);
    vector<char> words2 = makeWordVector(s2);

    sort(words1.begin(), words1.end());
    sort(words2.begin(), words2.end());

    return canBreak(words1, words2);
}

int main()
{
    string s0_0 = "abc";
    string s0_1 = "xya";
    string s1_0 = "abe";
    string s1_1 = "acd";
    string s2_0 = "leetcodee";
    string s2_1 = "interview";
    string s3_0 = "lsrgqnpl";
    string s3_1 = "nlarrtzt";

    bool ans0 = checkIfCanBreak(s0_0, s0_1);
    bool ans1 = checkIfCanBreak(s1_0, s1_1);
    bool ans2 = checkIfCanBreak(s2_0, s2_1);
    bool ans3 = checkIfCanBreak(s3_0, s3_1);

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false
    cout << ans2 << endl; // true
    cout << ans3 << endl; // false
}
