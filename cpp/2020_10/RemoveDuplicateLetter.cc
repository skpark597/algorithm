/* 316. Remove Duplicate Letter */
/** Given a string s, remove duplicate letters so that every letter appears once and only once. 
 *  You must make sure your result is the smallest in lexicographical order among all possible results.
 *  Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *  
 *  Example 1:
 *  Input: s = "bcabc"
 *  Output: "abc"
 *  
 *  Example 2
 *  Input: s = "cbacdcbc"
 *  Output: "acdb"
 *  
 *  Constraints:
 *  1 <= s.length <= 10^4
 *  s consists of lowercase English letters. **/

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string removeDuplicateLetters(string s) {
    string answer;
    vector<int> freq (26, 0);
    vector<bool> visited (26, false);
    stack<char> st;

    for (int i = 0; i < s.length(); ++i) {
        freq[s[i]-'a']++;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (visited[s[i]-'a']) {
            freq[s[i]-'a']--;
            continue;
        }
        
        visited[s[i]-'a'] = true;

        while (!st.empty() && st.top() > s[i] && freq[st.top()-'a'] > 0) {
            visited[st.top()-'a'] = false;
            st.pop();
        }
        
        st.push(s[i]);
        freq[s[i]-'a']--;
    }

    while (!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }

    return answer;
}

int main() {
    string s = "bbcaac";
    string answer = removeDuplicateLetters(s);

    cout << answer << endl;
    return 0;
}




