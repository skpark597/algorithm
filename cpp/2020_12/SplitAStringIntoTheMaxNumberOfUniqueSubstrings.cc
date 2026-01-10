/* 1593. Split a String Into the Max Number of Unique Substrings */
/** Given a string s, return the maximum number of unique substrings that the given string can be split into.
 *  You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. 
 *  However, you must split the substrings such that all of them are unique.
 *  A substring is a contiguous sequence of characters within a string.
 *  
 *  Example 1:
 *  Input: s = "ababccc"
 *  Output: 5
 *  Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
 *  Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
 * 
 *  Example 2:
 *  Input: s = "aba"
 *  Output: 2
 *  Explanation: One way to split maximally is ['a', 'ba'].
 * 
 *  Example 3:
 *  Input: s = "aa"
 *  Output: 1
 *  Explanation: It is impossible to split the string any further.
 * 
 *  Constraints:
 *  1 <= s.length <= 16
 *  s contains only lower case English letters. **/

#include <set>
#include <string>
#include <iostream>

using namespace std;

set<string> appeared;

int backTracking(const string &s, int start) {
    int ret = 0;
    string word;

    if (start == s.length()-1) {
        word = s.substr(s.length()-1, 1);
        return appeared.count(word) > 0 ? 0 : 1;
    }

    for (int i = start; i < s.length()-1; ++i) {
        word = s.substr(start, i-start+1);
        if (appeared.count(word)) continue;
        appeared.insert(word);
        ret = max(ret, backTracking(s, i+1));
        appeared.erase(word);
    }

    return ret+1;
}

int maxUniqueSplit(string s) {
    appeared.clear();
    if (s.empty()) return 0;

    return backTracking(s, 0);
}

int main() {
    string s0 = "ababccc";
    int ans0 = maxUniqueSplit(s0);

    string s1 = "aba";
    int ans1 = maxUniqueSplit(s1);

    string s2 = "aa";
    int ans2 = maxUniqueSplit(s2);

    cout << ans0 << endl; // 5
    cout << ans1 << endl; // 2
    cout << ans2 << endl; // 1

}

