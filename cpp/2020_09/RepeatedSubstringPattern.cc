/** 459. Repeated Substring Pattern */
/**  Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
 *  You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 * 
 *  Example 1:
 *  Input: "abab"
 *  Output: True
 *  Explanation: It's the substring "ab" twice
 *  
 *  Example 2
 *  Input: "aba:
 *  Output: False
 *  
 *  Example 3
 *  Input: "abcabcabcabc"
 *  Output: True
 *  Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.) **/

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool repeatedSubstringPattern(string s) {
    if (s.empty() || s.length() ==1 ) return false;

    char first = s[0];
    int start, strLength;
    string str, cmp;
    bool isMatched;
    vector<char> indices;

    for (int i=1; i < s.length(); ++i) {
        if (s[i] == first) indices.push_back(i);
    }

    for (int i=0; i< indices.size(); ++i) {
        start = indices[i];
        strLength = indices[i];
        isMatched = true;
        str = s.substr(0, indices[i]);
        
        while (start < s.length()) {
            cmp = s.substr(start, strLength);
            if (str.compare(cmp) != 0) {
                isMatched = false;
                break;
            }
            start += strLength;
        }

        if (isMatched) return true;
    }

    return false;
}

int main() {
    string input = "abcaabca";
    bool answer = repeatedSubstringPattern(input);

    cout << answer << endl;

    return 0;
}








