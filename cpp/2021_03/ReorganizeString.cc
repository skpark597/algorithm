/* 767. Reorganize String */
/** Given a string S, check if the letters can be rearranged so that 
 *  two characters that are adjacent to each other are not the same.
 * 
 *  If possible, output any possible result.  If not possible, return the empty string.
 *  Example 1:
 *  Input: S = "aab"
 *  Output: "aba"
 * 
 *  Example 2:
 *  Input: S = "aaab"
 *  Output: ""
 *  
 *  Note: S will consist of lowercase letters and have length in range [1, 500]. **/

#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 처음에 떠올린 풀이. 온라인 채점 통과하고 맞는 풀이이지만 뭔가 더 쉬운 방법이 없을까?

struct compare {
    bool operator() (const pair<char, int> &lhs, const pair<char,int> &rhs) {
        if (lhs.second != rhs.second) return lhs.second < rhs.second;
        return lhs.first <= rhs.first;
    }
};

string reorganizeString(string S) {
    string answer;
    int count[26];
    priority_queue<pair<char,int>, vector<pair<char,int>>, compare> pq;
 
    memset(count, 0, sizeof(count));

    for (char iter : S) count[iter-'a']++;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) pq.push(make_pair('a'+i, count[i]));
    }

    while (!pq.empty()) {
        pair<char, int> top = pq.top();
        pq.pop();

        if (answer.back() == top.first) {
            if (pq.empty()) return "";
            pair<char,int> nextTop = pq.top();
            pq.pop();
            answer += nextTop.first;
            nextTop.second--;
            pq.push(top);
            if (nextTop.second > 0) pq.push(nextTop);
        } else {
            answer += top.first;
            top.second--;
            if (top.second > 0) pq.push(top);
        }
    }

    return answer;
}

int main() {
    string S0 = "aab";
    string S1 = "aaab";

    string ans0 = reorganizeString(S0);
    string ans1 = reorganizeString(S1);

    cout << ans0 << endl;
    cout << ans1 << endl;

    return 0;
}