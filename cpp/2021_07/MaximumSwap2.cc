/** 670. Maximum Swap */
/** You are given an integer num. You can swap two digits at most once to get the maximum valued number.
 *  Return the maximum valued number you can get.
 * 
 *  Example 1:
 *  Input: num = 2736
 *  Output: 7236
 *  Explanation: Swap the number 2 and the number 7.
 * 
 *  Example 2:
 *  Input: num = 9973
 *  Output: 9973
 *  Explanation: No swap.
 *  
 *  Constraints: 0 <= num <= 10^8 */

#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

// Discussion을 보고 다시 구현해본 풀이. 내가 한 것 보다 간단하네..

int maximumSwap(int num) {
    string numStr = to_string(num);
    int greatest = INT_MIN;
    int greatestIndex = numStr.length()-1;
    vector<int> greatestRight(numStr.length());
    vector<int> greatestIndices (numStr.length());

    for (int i = numStr.length()-1; i >= 0; --i) {
        if (greatest < numStr[i] - '0') {
            greatest = numStr[i] -'0';
            greatestIndex = i;
        }

        greatestRight[i] = greatest;
        greatestIndices[i] = greatestIndex;
    }

    for (int i = 0; i < numStr.length(); ++i) {
        if (numStr[i] - '0' < greatestRight[i]) {
            char temp = numStr[i];
            numStr[i] = greatestRight[i] + '0';
            numStr[greatestIndices[i]] = temp;
            break;
        }
    }

    return stoi(numStr);
}

int main() {
    int ans0 = maximumSwap(2736);
    int ans1 = maximumSwap(9973);
    int ans2 = maximumSwap(98368);

    cout << ans0 << endl; // 7236
    cout << ans1 << endl; // 9973
    cout << ans2 << endl; // 98863

    return 0;
}
