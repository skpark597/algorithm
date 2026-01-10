/* 633. Sum of Square Numbers */
/** Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
 * 
 *  Example 1:
 *  Input: c = 5
 *  Output: true
 *  Explanation: 1 * 1 + 2 * 2 = 5
 *  
 *  Example 2:
 *  Input: c = 3
 *  Output: false
 *  
 *  Example 3:
 *  Input: c = 4
 *  Output: true
 *  
 *  Example 4:
 *  Input: c = 2
 *  Output: true
 * 
 *  Example 5:
 *  Input: c = 1
 *  Output: true
 * 
 *  Constraints: 0 <= c <= 2^31 - 1 **/

#include <iostream>
#include <math.h>

using namespace std;

// 16진수로 표현할 때 제곱수의 일의 자리 숫자는 0,1,4,9 밖에 안된다.
bool bBase[16] = {true, true, false, false, true, false, false, false, false, true, false, false, false, false, false, false};

/* a^2 + b^2 = c 이고 b <= a를 만족한다고 가정하자 */
bool judgeSquareSum(int c) {
    for (int a = sqrt(c)/sqrt(2); a <= sqrt(c); ++a) {
        int temp = c - a * a;
        if (!bBase[temp & 0x0F]) continue;

        double b = sqrt(temp);
        if ((int)b == b) return true;
    }

    return false;
}

int main() {
    bool answer0 = judgeSquareSum(5); //1
    bool answer1 = judgeSquareSum(3); //0
    bool answer2 = judgeSquareSum(4); //1
    bool answer3 = judgeSquareSum(2); //1
    bool answer4 = judgeSquareSum(1); //1
    bool answer5 = judgeSquareSum(2147483645); //0

    cout << answer0 << endl;
    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;
    cout << answer4 << endl;
    cout << answer5 << endl;

    return 0;
}