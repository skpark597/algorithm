/* 11. Container With Most Water */
/** Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 *  n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
 *  Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
 *  Notice that you may not slant the container.
 * 
 *  Example 1:
 *  Input: height = [1,8,6,2,5,4,8,3,7]
 *  Output: 49
 *  Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
 *  In this case, the max area of water (blue section) the container can contain is 49.
 * 
 *  Example 2:
 *  Input: height = [1,1]
 *  Output: 1
 * 
 *  Example 3:
 *  Input: height = [4,3,2,1,4]
 *  Output: 16
 * 
 *  Example 4:
 *  Input: height = [1,2,1]
 *  Output: 2
 * 
 *  Constraints:
 *  n == height.length
 *  2 <= n <= 3 * 10^4
 *  0 <= height[i] <= 3 * 10^4 **/

/* Solution을 보고 구현 풀이. Two Pointer 이용 */

#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size()-1;
    int area = 0;
    int smallerHeight;
    int width;

    while (left < right) {
        width = right-left;
        if (height[left] <= height[right]) {
            smallerHeight = height[left];
            left++;
        } else {
            smallerHeight = height[right];
            right--;
        }

        area = max(area, width * smallerHeight);
    }

    return area;
}

int main() {
    vector<int> height0 {1,8,6,2,5,4,8,3,7};
    vector<int> height1 {1,1};
    vector<int> height2 {4,3,2,1,4};
    vector<int> height3 {1,2,1};

    int ans0 = maxArea(height0);
    int ans1 = maxArea(height1);
    int ans2 = maxArea(height2);
    int ans3 = maxArea(height3);

    cout << ans0 << endl; // 49
    cout << ans1 << endl; // 1
    cout << ans2 << endl; // 16
    cout << ans3 << endl; // 2

    return 0;
}

