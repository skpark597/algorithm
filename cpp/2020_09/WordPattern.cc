/* 190. Word Pattern */
/** Given a pattern and a string str, find if str follows the same pattern.
 *  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *  
 *  Example 1:
 *  Input: pattern = "abba", str = "dog cat cat dog"
 *  Output: true
 * 
 *  Example 2:
 *  Input:pattern = "abba", str = "dog cat cat fish"
 *  Output: false
 * 
 *  Example 3:
 *  Input: pattern = "aaaa", str = "dog cat cat dog"
 *  Output: false
 * 
 *  Example 4:
 *  Input: pattern = "abba", str = "dog dog dog dog"
 *  Output: false
 * 
 *  Notes:
 *  You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.**/

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

string getToken (string &str) {
    int i = 0;
    string token;

    string::iterator iter;

    for (iter = str.begin(); iter != str.end(); iter = str.erase(iter)) {
        if (*iter == ' ') break;
        token += *iter;
    }

    if (iter != str.end()) str.erase(iter);
    return token;
}

bool wordPattern(string pattern, string str) {
    map<char, string> alphabetToWord;
    map<string, char> wordToAlphabet;
        
    for (int i=0; i < pattern.length(); ++i) {
        char alphabet = pattern[i];
        string word = getToken(str);
        
        if (alphabetToWord.count(alphabet)) {
            if (alphabetToWord[alphabet].compare(word) != 0) return false;
        } else if (wordToAlphabet.count(word)) {
            if (wordToAlphabet[word] != alphabet) return false;
        } else {
            alphabetToWord[alphabet] = word;
            wordToAlphabet[word] = alphabet;
        }
    }
    return true;
}

int main() {
    string pattern = "abc";
    string str = "dog ca cat";
    bool result = wordPattern(pattern, str);

    cout << result << endl;

    return 0;
}

















