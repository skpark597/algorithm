/* 1239. Maximum Length of a Concatenated String with Unique Characters */
/** Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.
 *  Return the maximum possible length of s.
 * 
 *  Example 1:
 *  Input: arr = ["un","iq","ue"]
 *  Output: 4
 *  Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
 *  Maximum length is 4.
 * 
 *  Example 2:
 *  Input: arr = ["cha","r","act","ers"]
 *  Output: 6
 *  Explanation: Possible solutions are "chaers" and "acters".
 * 
 *  Example 3:
 *  Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 *  Output: 26
 * 
 *  Constraints:
 *  1 <= arr.length <= 16
 *  1 <= arr[i].length <= 26
 *  arr[i] contains only lower case English letters. **/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canAppend (string str, string cur) {
    int bit = 1 << 26;

    for (int i = 0; i < cur.length(); ++i) {
        if (bit & (1 << (cur[i]-'a'))) return false;
        bit |= 1 << (cur[i] - 'a');
    }

    for (int i = 0; i < str.length(); ++i) {
        if (bit & (1 << (str[i] - 'a'))) {
            return false;
        }
    }

    return true;
}

int backTracking(vector<string> &arr, string str, int index) {
    string cur;
    int contain;
    int notContain;
    
    if (index >= arr.size()) return str.length();
    cur = arr[index];

    notContain = backTracking(arr, str, index+1);

    if (!canAppend(str, cur)) {
        return notContain;
    }
    
    contain = backTracking(arr, str.append(cur), index+1);

    return max(notContain, contain);
}

int maxLength(vector<string> &arr) {
    return backTracking(arr, "", 0);
}

int main() {
    vector<string> arr0 {"un","iq","ue"};
    vector<string> arr1 {"cha","r","act","ers"};
    vector<string> arr2 {"abcdefghijklmnopqrstuvwxyz"};
    vector<string> arr3 {"yy","bkhwmpbiisbldzknpm"};

    int ans0 = maxLength(arr0);
    int ans1 = maxLength(arr1);
    int ans2 = maxLength(arr2);
    int ans3 = maxLength(arr3);

    cout << ans0 << endl;
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;

    return 0;
}

