/** 621. Task Scheduler */
/** Given a characters array tasks, representing the tasks a CPU needs to do, where each letter 
 *  represents a different task. Tasks could be done in any order. 
 *  Each task is done in one unit of time. 
 *  For each unit of time, the CPU could complete either one task or just be idle.
 *  However, there is a non-negative integer n that represents the cooldown period between two same tasks 
 *  (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
 *  
 *  Return the least number of units of times that the CPU will take to finish all the given tasks.
 * 
 *  Example 1:
 *  Input: tasks = ["A","A","A","B","B","B"], n = 2
 *  Output: 8
 *  Explanation: 
 *  A -> B -> idle -> A -> B -> idle -> A -> B
 *  There is at least 2 units of time between any two same tasks.
 * 
 *  Example 2:
 *  Input: tasks = ["A","A","A","B","B","B"], n = 0
 *  Output: 6
 *  Explanation: On this case any permutation of size 6 would work since n = 0.
 *  ["A","A","A","B","B","B"]
 *  ["A","B","A","B","A","B"]
 *  ["B","B","B","A","A","A"]
 *  ...
 *  And so on.
 * 
 *  Example 3:
 *  Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 *  Output: 16
 *  Explanation: 
 *  One possible solution is
 *  A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 *  
 *  Constraints:
 *  1 <= task.length <= 10^4
 *  tasks[i] is upper-case English letter.
 *  The integer n is in the range [0, 100]. **/

#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int count[26];

int leastInterval(vector<char> &tasks, int n) {
    int answer = 0;
    priority_queue<int> pq;
    vector<int> pickedTask;

    memset(count, 0, sizeof(count));
    pickedTask.reserve(26);
    
    for (int i = 0; i < tasks.size(); ++i) {
        count[tasks[i]-'A']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) pq.push(count[i]);
    }

    while (!pq.empty()) {
        pickedTask.clear();

        for (int i = 0; i < n+1; ++i) {
            if (!pq.empty()) {
                pickedTask.push_back(pq.top());
                pq.pop();
            }
        }

        for (int t : pickedTask) {
            if (t > 1) pq.push(t-1);
        }

        answer += n+1;
    }

    answer -= (n+1-pickedTask.size());
    return answer;
}

int main() {
    vector<char> tasks0 {'A','A','A','B','B','B'};
    vector<char> tasks1 {'A','A','A','B','B','B'};
    vector<char> tasks2 {'A','A','A','A','A','A','B','C','D','E','F','G'};

    int ans0 = leastInterval(tasks0, 2);
    int ans1 = leastInterval(tasks1, 0);
    int ans2 = leastInterval(tasks2, 2);

    cout << ans0 << endl; // 8
    cout << ans1 << endl; // 6
    cout << ans2 << endl; // 16

    return 0;
}



