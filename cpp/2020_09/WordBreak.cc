/* 139. Word Break */
/** Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
 *  determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *  
 *  Note:
 *  The same word in the dictionary may be reused multiple times in the segmentation.
 *  You may assume the dictionary does not contain duplicate words.
 * 
 *  Example 1:
 *  Input: s = "leetcode", wordDict = ["leet", "code"]
 *  Output: true
 *  Explanation: Return true because "leetcode" can be segmented as "leet code".
 * 
 *  Example 2:
 *  Input: s = "applepenapple", wordDict = ["apple", "pen"]
 *  Output: true
 *  Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *  Note that you are allowed to reuse a dictionary word.
 *  
 *  Example 3:
 *  Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *  Output: false **/

/** 처음에 이렇게 풀었으나 Time Limit Exceeded가 떴음 ㅜㅠ  **/


#include <vector>
#include <string>
#include <iostream>
using namespace std;

string removeMatchedWord (string &s, string &word) {
    if (s.length() < word.length()) return s;
    if (s.compare(0, word.length(), word) ==0) {
        return s.substr(word.length(), s.length()-word.length());
    }
    return s;
}

bool wordBreak(string s, vector<string> &wordDict) {
    if (s.length() == 0) return true;

    for (int i=0; i < wordDict.size(); ++i) {
        string newS = removeMatchedWord (s, wordDict[i]);
        if (newS.length() < s.length()) {
            if (wordBreak(newS, wordDict)) return true;
        }
    }
    
    return false;
}

int main() {
    //string s = "catsandog";
    //vector<string> wordDict {"cats", "dog", "sand", "and", "cat"};
    //string s = "leetcode";
    //vector<string> wordDict {"leet","code"};
    string s = "applepenapple";
    vector<string> wordDict {"apple", "pen"};
    bool answer = wordBreak (s, wordDict);
    
    cout << answer << endl;
    return 0;
}