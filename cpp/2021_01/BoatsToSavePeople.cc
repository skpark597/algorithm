/* 881. Boats to Save People */
/** You are given an array people where people[i] is the weight of the ith person, 
 *  and an infinite number of boats where each boat can carry a maximum weight of limit. 
 *  Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
 *  Return the minimum number of boats to carry every given person.
 * 
 *  Example 1:
 *  Input: people = [1,2], limit = 3
 *  Output: 1
 *  Explanation: 1 boat (1, 2)
 * 
 *  Example 2:
 *  Input: people = [3,2,2,1], limit = 3
 *  Output: 3
 *  Explanation: 3 boats (1, 2), (2) and (3)
 * 
 *  Example 3:
 *  Input: people = [3,5,3,4], limit = 5
 *  Output: 4
 *  Explanation: 4 boats (3), (3), (4), (5)
 *  
 *  Constraints:
 *  1 <= people.length <= 5 * 10^4
 *  1 <= people[i] <= limit <= 3 * 10^4 **/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
    int start = 0;
    int end = people.size()-1;
    int answer = 0;

    sort(people.begin(), people.end());

    while (start <= end) {
        if (people[start] + people[end] <= limit) start++;
        end--;
        answer++;
    }

    return answer;
}

int main() {
    vector<int> people0 {1,2};
    int limit0 = 3;
    int ans0 = numRescueBoats(people0, limit0);

    vector<int> people1 {3,2,2,1};
    int limit1 = 3;
    int ans1 = numRescueBoats(people1, limit1);

    vector<int> people2 {3,5,3,4};
    int limit2 = 5;
    int ans2 = numRescueBoats(people2, limit2);

    cout << ans0 << endl; // 1
    cout << ans1 << endl; // 3
    cout << ans2 << endl; // 4
    return 0;
}
