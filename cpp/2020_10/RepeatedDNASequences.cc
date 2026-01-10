/* 187. Repeated DNA Sequences */
/** All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', 
 *  for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated 
 *  sequences within the DNA.
 * 
 *  Write a function to find all the 10-letter-long sequences (substrings) that occur more than 
 *  once in a DNA molecule.
 * 
 *  Example 1:
 *  Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *  Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * 
 *  Example 2:
 *  Input: s = "AAAAAAAAAAAAA"
 *  Output: ["AAAAAAAAAA"]
 *  
 *  Constraints:
 *  0 <= s.length <= 105
 *  s[i] is 'A', 'C', 'G', or 'T'. **/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> substrToCount;
    vector<string> answer;
    
    if (s.length() < 10) return answer;

    for (int i = 0; i < s.length()-9; ++i) {
        string substr = s.substr(i,10);
        if (substrToCount.count(substr) && substrToCount[substr] == 1) {
            substrToCount[substr]++;
            answer.push_back(substr);
        } else if (substrToCount.count(substr) == 0) {
            substrToCount[substr] = 1;
        }
    }

    return answer;
}

int main() {
    //string s = "AAAAAAAAAAAAA";
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> answer = findRepeatedDnaSequences(s);

    for (string iter : answer) {
        cout << iter << endl;
    }

    return 0;
}



