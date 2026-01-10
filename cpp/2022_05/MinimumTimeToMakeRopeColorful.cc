/** 1578. Minimum Time to Make Rope Colorful */
/** Alice has n balloons arranged on a rope. You are given a 0-indexed string
colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons
to be of the same color, so she asks Bob for help. Bob can remove some balloons
from the rope to make it colorful. You are given a 0-indexed integer array
neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove
the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

Example 1:
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.

Example 2:
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any
balloons from the rope.

Example 3:
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1
second to remove. There are no longer two consecutive balloons of the same
color. Total time = 1 + 1 = 2.

Constraints:
n == colors.length == neededTime.length
1 <= n <= 10^5
1 <= neededTime[i] <= 10^4
colors contains only lowercase English letters.*/

#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int minCost(string colors, vector<int> &neededTime) {
  int cost = 0;
  char current = colors[0];
  int consecutiveSum = neededTime[0];
  int consecutiveMax = neededTime[0];

  for (int i = 1; i < colors.length(); ++i) {
    if (current != colors[i]) {
      cost += (consecutiveSum - consecutiveMax);
      current = colors[i];
      consecutiveSum = neededTime[i];
      consecutiveMax = neededTime[i];
    } else {
      consecutiveSum += neededTime[i];
      consecutiveMax = max(neededTime[i], consecutiveMax);
    }
  }

  cost += (consecutiveSum - consecutiveMax);
  return cost;
}

int main() {
  string colors0 = "abaac";
  vector<int> neededTime0{1, 2, 3, 4, 5};

  string colors1 = "abc";
  vector<int> neededTime1{1, 2, 3};

  string colors2 = "aabaa";
  vector<int> neededTime2{1, 2, 3, 4, 1};

  string colors3 = "bbbaaa";
  vector<int> neededTime3{4, 9, 3, 8, 8, 9};

  int ans0 = minCost(colors0, neededTime0);
  int ans1 = minCost(colors1, neededTime1);
  int ans2 = minCost(colors2, neededTime2);
  int ans3 = minCost(colors3, neededTime3);

  cout << ans0 << endl; // 3
  cout << ans1 << endl; // 0
  cout << ans2 << endl; // 2
  cout << ans3 << endl; // 23

  return 0;
}
