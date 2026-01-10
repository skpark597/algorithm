/* 451. Sort Characters By Frequency */
/** Given a string, sort it in decreasing order based on the frequency of characters.
 *  Example 1:
 *  Input: "tree"
 *  Output: "eert"
 *  Explanation:
 *  'e' appears twice while 'r' and 't' both appear once.
 *  So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * 
 *  Example 2:
 *  Input: "cccaaa"
 *  Output: "cccaaa"
 *  Explanation:
 *  Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 *  Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 *  Example 3:
 *  Input: "Aabb"
 *  Output: "bbAa"
 *  Explanation:
 *  "bbaA" is also a valid answer, but "Aabb" is incorrect.
 *  Note that 'A' and 'a' are treated as two different characters. */

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

string frequencySort(string s) {
    int size;
    string answer;
    unordered_map<char,int> freq;
    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < s.length(); ++i) {
        if (freq.count(s[i]) == 0) {
            freq[s[i]] = 1;
        } else {
            freq[s[i]]++;
        }
    }

    for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
        pq.push(make_pair(iter->second, iter->first));
    }

    while (!pq.empty()) {
        for (int j = 0; j < pq.top().first; ++j) {
            answer += pq.top().second;
        }
        pq.pop();
    }

    return answer;
}

int main() {
    string s0 = "tree";
    string ans0 = frequencySort(s0);

    string s1 = "cccaaa";
    string ans1 = frequencySort(s1);

    string s2 = "Aabb";
    string ans2 = frequencySort(s2);

    cout << ans0 << endl; //eert
    cout << ans1 << endl; //cccaaa
    cout << ans2 << endl; //bbAa

    return 0;
}
