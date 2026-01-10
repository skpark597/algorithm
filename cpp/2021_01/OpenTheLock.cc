/* 752. Open the Lock */
/** You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
 *  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
 *  The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
 *  Each move consists of turning one wheel one slot.
 *  The lock initially starts at '0000', a string representing the state of the 4 wheels.
 *  You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
 *  the wheels of the lock will stop turning and you will be unable to open it.
 *  Given a target representing the value of the wheels that will unlock the lock, 
 *  return the minimum total number of turns required to open the lock, or -1 if it is impossible.
 * 
 *  Example 1:
 *  Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 *  Output: 6
 *  Explanation:
 *  A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
 *  Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
 *  because the wheels of the lock become stuck after the display becomes the dead end "0102".
 * 
 *  Example 2:
 *  Input: deadends = ["8888"], target = "0009"
 *  Output: 1
 *  Explanation:
 *  We can turn the last wheel in reverse to move from "0000" -> "0009".
 *  
 *  Example 3:
 *  Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
 *  Output: -1
 *  Explanation:
 *  We can't reach the target without getting stuck.
 * 
 *  Example 4:
 *  Input: deadends = ["0000"], target = "8888"
 *  Output: -1
 * 
 *  Constraints:
 *  1 <= deadends.length <= 500
 *  deadends[i].length == 4
 *  target.length == 4
 *  target will not be in the list deadends.
 *  target and deadends[i] consist of digits only. **/

#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <unordered_set>
#include <iostream>

using namespace std;

string neighbor(string cur, int num) {
    int index = num % 4;
    string next = cur;

    if (num < 4) {
        next[index] = next[index] == '9' ? '0' : next[index]+1;
    } else {
        next[index] = next[index] == '0' ? '9' : next[index]-1;
    }

    return next;
}

int openLock(vector<string> &deadends, string target) {
    queue<string> queue;
    unordered_set<string> seen (deadends.begin(), deadends.end());
    int dist = 0;

    if (seen.count("0000")) return -1;

    queue.push("0000");
    while (!queue.empty()) {
        int size = queue.size();

        for (int i = 0; i < size; ++i) {
            string cur = queue.front();
            queue.pop();

            if (cur == target) return dist;

            for (int j = 0; j < 8; ++j) {
                string next = neighbor(cur, j);
                if (!seen.count(next)) {
                    seen.insert(next);
                    queue.push(next);
                }
            }
        }

        dist++;
    }

    return -1;
}

int main() {
    vector<string> deadends0 {"0201","0101","0102","1212","2002"};
    string target0 ="0202";
    int ans0 = openLock(deadends0, target0);

    vector<string> deadends1 {"8888"};
    string target1 ="0009";
    int ans1 = openLock(deadends1, target1);

    vector<string> deadends2 {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target2 ="8888";
    int ans2 = openLock(deadends2, target2);

    vector<string> deadends3 {"0000"};
    string target3 ="8888";
    int ans3 = openLock(deadends3, target3);

    cout << ans0 << endl; // 6
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // -1
    cout << ans3 << endl; // -1

    return 0;
}