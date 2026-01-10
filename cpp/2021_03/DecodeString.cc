/* 394. Decode String */
/** Given an encoded string, return its decoded string.
 *  The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
 *  is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *  You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *  Furthermore, you may assume that the original data does not contain any digits and that digits 
 *  are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 * 
 *  Example 1:
 *  Input: s = "3[a]2[bc]"
 *  Output: "aaabcbc"
 * 
 *  Example 2:
 *  Input: s = "3[a2[c]]"
 *  Output: "accaccacc"
 * 
 *  Example 3:
 *  Input: s = "2[abc]3[cd]ef"
 *  Output: "abcabccdcdcdef"
 * 
 *  Example 4:
 *  Input: s = "abc3[cd]xyz"
 *  Output: "abccdcdcdxyz"
 * 
 *  Constraints:
 *  1 <= s.length <= 30
 *  s consists of lowercase English letters, digits, and square brackets '[]'.
 *  s is guaranteed to be a valid input.
 *  All the integers in s are in the range [1, 300]. **/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string decodeBracket(string s, int digit, int &index) {
    string result;
    string expansion;
    string newDigit;

    while (s[index] != ']') {
        if (s[index] >= '0' and s[index] <= '9') {
            newDigit += s[index++];
        } else if (s[index] == '[') {
            if (newDigit.empty()) newDigit = "1";
            expansion += decodeBracket(s, stoi(newDigit), ++index);
            newDigit.clear();
        } else if (s[index] != ']') {
            expansion += s[index++];
        }
    }

    for (int i = 0; i < digit; ++i) {
        result += expansion;
    }

    index++;
    return result;
}

string decodeString(string s) {
    string answer;
    string digit;
    int i = 0;

    while (i < s.length()) {
        if (s[i] >= '0' and s[i] <= '9') {
            digit += s[i++];
        } else if (s[i] == '[') {
            if (digit.empty()) digit = "1";
            answer += decodeBracket(s, stoi(digit), ++i);
            digit.clear();
        } else if (s[i] != ']') {
            answer += s[i++];
        }
    }

    return answer;
}

int main() {
    string s0 = "3[a]2[bc]";
    string s1 = "3[a2[c]]";
    string s2 =  "2[abc]3[cd]ef";
    string s3 = "abc3[cd]xyz";

    string ans0 = decodeString(s0);
    string ans1 = decodeString(s1);
    string ans2 = decodeString(s2);
    string ans3 = decodeString(s3);

    cout << ans0 << endl; // "aaabcbc"
    cout << ans1 << endl; // "accaccacc"
    cout << ans2 << endl; // "abcabccdcdcdef"
    cout << ans3 << endl; // "abccdcdcdxyz"

    return 0;
}

