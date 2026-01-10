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
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 아래는 내가 최초로 구현한 풀이. 조금 복잡함.

void initialize(int num, vector<int> &digits, vector<int> &indices) {
    unordered_map<int, int> digitToIndex;
    vector<int> sortDigits;

    while (num > 0) {
        digits.push_back(num % 10);
        num = num / 10;
    }

    for (int i = 0; i < digits.size(); ++i) {
        if (digitToIndex.count(digits[i]) == 0) {
            digitToIndex[digits[i]] = digits.size()-i-1;
        }
    }
    
    sortDigits = digits;
    reverse(digits.begin(), digits.end());
    sort(sortDigits.begin(), sortDigits.end());

    for (int i = 0; i < sortDigits.size(); ++i) {
        indices.push_back(digitToIndex[sortDigits[i]]);
    }
}

int maximumSwap(int num) {
    string answer;
    vector<int> digits;
    vector<int> indices;

    initialize(num, digits, indices);

    for (int i = 0; i < digits.size(); ++i) {
        if (i != indices.back() && digits[i] < digits[indices.back()]) {
            int temp = digits[i];
            digits[i] = digits[indices.back()];
            digits[indices.back()] = temp;
            break;
        }

        indices.pop_back();
    }

    for (int i = 0; i < digits.size(); ++i) {
        answer += (char)digits[i] + '0';
    }

    return stoi(answer);
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
