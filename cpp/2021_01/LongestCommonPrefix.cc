/* 14. Longest Common Prefix */
/** Write a function to find the longest common prefix string amongst an array of strings.
 *  If there is no common prefix, return an empty string "".
 * 
 *  Example 1:
 *  Input: strs = ["flower","flow","flight"]
 *  Output: "fl"
 * 
 *  Example 2:
 *  Input: strs = ["dog","racecar","car"]
 *  Output: ""
 *  Explanation: There is no common prefix among the input strings.
 * 
 *  Constraints:
 *  0 <= strs.length <= 200
 *  0 <= strs[i].length <= 200
 *  strs[i] consists of only lower-case English letters. **/

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string answer = "";
    int index = 0;
    char cur;
    bool finish = false;
    int len;

    if (strs.empty() || strs[0].empty()) return "";
    if (strs.size() == 1) return strs[0];

    len = strs[0].length();
    cur = strs[0][0];
    for (int i = 1; i < strs.size(); ++i) {
        len = min(len, (int)strs[i].length());
    }

    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (cur != strs[j][index]) {
                finish = true;
                break;
            }
        }

        if (finish) break;
        index++;
        cur = strs[0][index];
    }

    return strs[0].substr(0,index);
}

int main() {
    vector<string> strs0 {"flower", "flow", "flight"};
    string ans0 = longestCommonPrefix(strs0);

    vector<string> strs1 {"dog","racecar","car"};
    string ans1 = longestCommonPrefix(strs1);

    cout << ans0 << endl;
    cout << ans1 << endl;

    return 0;
}
