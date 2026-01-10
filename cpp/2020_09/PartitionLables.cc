/* 763. Partition Lables */
/* A string S of lowercase English letters is given. 
 * We want to partition this string into as many parts as possible so that each letter appears in at most one part, 
 * and return a list of integers representing the size of these parts.
 * 
 * Example 1
 * Input: S = "ababcbacadefegdehijhklij
 * Output: [9,7,8]
 * Explanation
 * The partition is "ababcbaca", "defegde", "hijhklij"
 * This is a partition so that each letter appears in at most one part
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts
 * 
 * Note
 * S will have length in range [1, 500]
 * S will consist of lowercase English letters ('a' to 'z') only.  */

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> answer;
    map<char, int> lastPosition;
    int maxIndex = 0;
    int start = 0;
    int index;
    
    for (int i=0; i< S.length(); ++i) {
        lastPosition[S[i]] = i;
    }

    while (start < S.length()) {
        for (int i=start; i<= maxIndex; ++i) {
            maxIndex = max (lastPosition[S[i]], maxIndex);
        }
        answer.push_back(maxIndex-start+1);
        start = maxIndex+1;
        maxIndex = start;
    }

    return answer;
}

int main () {
    string S = "ababcbacadefegdehijhklij";
    vector<int> answer = partitionLabels(S);

    for (int i=0; i< answer.size();++i) {
        cout << answer[i] << endl;
    }

    return 0;
}











