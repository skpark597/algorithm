/* 49. Group Anagrams */
/** Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 *  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 *  typically using all the original letters exactly once.
 * 
 *  Example 1:
 *  Input: strs = ["eat","tea","tan","ate","nat","bat"]
 *  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 *  Example 2:
 *  Input: strs = [""]
 *  Output: [[""]]
 * 
 *  Example 3:
 *  Input: strs = ["a"]
 *  Output: [["a"]]
 * 
 *  Constraints:
 *  1 <= strs.length <= 10^4
 *  0 <= strs[i].length <= 100
 *  strs[i] consists of lower-case English letters. **/

#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> groups;

    if (strs.empty()) return vector<vector<string>>();

    for (int i = 0; i < strs.size(); ++i) {
        string str;
        vector<int> count (26, 0);

        for (int j = 0; j < strs[i].length(); ++j) {
            count[strs[i][j]-'a']++;
        }

        for (int j = 0; j < 26; ++j) {
            str += '#';
            str += to_string(count[j]);
        }

        if (groups.count(str)) {
            groups[str].push_back(strs[i]);
        } else {
            groups[str] = vector<string>{strs[i]};
        }
    }

    for (auto iter : groups) {
        answer.push_back(iter.second);
    }

    return answer;
}

int main() {
    vector<string> strs0 {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans0 = groupAnagrams(strs0);

    vector<string> strs1 {""};
    vector<vector<string>> ans1 = groupAnagrams(strs1);

    vector<string> strs2 {"a"};
    vector<vector<string>> ans2 = groupAnagrams(strs2);

    vector<string> strs3 {"bdddddddddd", "bbbbbbbbbbc"};
    vector<vector<string>> ans3 = groupAnagrams(strs3);
    
    for (int i = 0; i < ans0.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans0[i].size(); ++j) {
            if (j == ans0[i].size()-1) {
                cout << ans0[i][j] << "]";
            } else {
                cout << ans0[i][j] << ", ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < ans1.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans1[i].size(); ++j) {
            if (j == ans1[i].size()-1) {
                cout << ans1[i][j] << "]";
            } else {
                cout << ans1[i][j] << ", ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < ans2.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans2[i].size(); ++j) {
            if (j == ans2[i].size()-1) {
                cout << ans2[i][j] << "]";
            } else {
                cout << ans2[i][j] << ", ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < ans3.size(); ++i) {
        cout << "[";
        for (int j = 0; j < ans3[i].size(); ++j) {
            if (j == ans3[i].size()-1) {
                cout << ans3[i][j] << "]";
            } else {
                cout << ans3[i][j] << ", ";
            }
        }
    }
    cout << endl;

    return 0;
}



