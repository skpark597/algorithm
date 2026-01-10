/* 17. Letter Combinations of a Phone Number */
/** Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
 *  Return the answer in any order.
 *  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 *  Example 1:
 *  Input: digits = "23"
 *  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 *  Example 2:
 *  Input: digits = ""
 *  Output: []
 * 
 *  Example 3:
 *  Input: digits = "2"
 *  Output: ["a","b","c"]
 * 
 *  Constraints:
 *  0 <= digits.length <= 4
 *  digits[i] is a digit in the range ['2', '9']. **/

#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

string table[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void addAlphabets (queue<string> &queue, string str, char digit) {
    string possible = table[digit-'2'];

    for (int i = 0; i < possible.length(); ++i) {
        queue.push(str + possible[i]);
    }
}

void queueToVector (queue<string> &queue, vector<string> &vec) {
    int count = queue.size();
    vec.resize(count);

    for (int i = 0; i < count; ++i) {
        vec[i] = queue.front();
        queue.pop();
    }
}

vector<string> letterCombinations(string digits) {
    int count = 0;
    int pushed = 0;
    queue<string> queue;
    vector<string> answer;

    if (digits.empty()) return vector<string>();

    addAlphabets(queue, "", digits[0]);

    for (int i = 1; i < digits.length(); ++i) {
        count = queue.size();
        for (int j = 0 ; j < count; ++j) {
            addAlphabets(queue, queue.front(), digits[i]);
            queue.pop();
        }
    }

    queueToVector(queue, answer);

    return answer;
}

int main() {
    string digit0 = "23";
    vector<string> ans0 = letterCombinations(digit0);

    string digit1 = "298";
    vector<string> ans1 = letterCombinations(digit1);

    for (string iter : ans0) {
        cout << iter << " ";
    }
    cout << endl;

    for (string iter : ans1) {
        cout << iter << " ";
    }
    cout << endl;

    return 0;
}

