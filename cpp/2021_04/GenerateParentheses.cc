/* 22. Generate Parentheses */
/** Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *  
 *  Example 1:
 *  Input: n = 3
 *  Output: ["((()))","(()())","(())()","()(())","()()()"]
 * 
 *  Example 2:
 *  Input: n = 1
 *  Output: ["()"]
 *  
 *  Constraints: 1 <= n <= 8 **/

#include <vector>
#include <iostream>

#define NUMBER_OF_CACHE 9

using namespace std;

vector<string> cache[NUMBER_OF_CACHE];

vector<string> generateInternal(int n) {
    if (n == 0) return vector<string> {""}; 
    if (cache[n].size() > 0) return cache[n];

    vector<string> &result = cache[n];

    for (int i = 0; i < n; ++i) {
        vector<string> first = generateInternal(i);
        vector<string> second = generateInternal(n-i-1);

        for (string fst : first) {
            string str = "(" + fst + ")";
            for (string snd : second) {
                result.push_back(str + snd);
            }
        }
    }

    return result;
}

vector<string> generateParenthesis(int n) {
    for (int i = 0; i < NUMBER_OF_CACHE; ++i) {
        cache[i].clear();
    }

    return generateInternal(n);
}

int main() {
    vector<string> ans0 = generateParenthesis(3);
    vector<string> ans1 = generateParenthesis(1);

    for (string iter : ans0) {
        cout << iter << " ";
    } cout << endl;

     for (string iter : ans1) {
        cout << iter << " ";
    } cout << endl;

    int test = 0;
    cout << (test-1)/2 << endl;

    return 0;
}
