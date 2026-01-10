/* 526. Beautiful Arrangement */
/** Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is 
 *  constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:
 * 
 *  The number at the ith position is divisible by i.
 *  i is divisible by the number at the ith position.
 * 
 *  Now given N, how many beautiful arrangements can you construct?
 * 
 *  Example 1:
 *  Input: 2
 *  Output: 2
 *  Explanation: 
 *  
 *  The first beautiful arrangement is [1, 2]:
 *  Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 *  Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 *  The second beautiful arrangement is [2, 1]:
 *  Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 *  Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 *  
 * Note:
 * N is a positive integer and will not exceed 15. **/

#include <vector>
#include <cstring>
#include <math.h>
#include <iostream>

using namespace std;

const int maxBit = 32768;  //32768 = 2 ^ (15)
int cache[maxBit];
int maxIndex;

// 1 ~ index-1 까지는 array에 모두 채워져 있다고 가정
// 현재까지 사용된 숫자가 usedNums 일 때, index부터 maxIndex까지를 남은 숫자들로 채울 수 있는 경우의 수를 리턴
int fillNumber(int index, int usedNums) {
    int &ret = cache[usedNums];
    int i = 1;

    if (ret != -1) return ret;
    if (index > maxIndex) return 1;

    ret = 0;

    for (int i = 1; i < maxIndex+1; ++i) {
        if (i % index == 0 || index % i == 0){
            int ithBit = 1 << (i-1);
            if ((usedNums & ithBit) == 0) {
                ret += fillNumber(index+1, (usedNums | ithBit));
            }
        }
    }

    return ret;
}

int countArrangement(int N) {
    maxIndex = N;
    memset(cache, -1, sizeof(cache));

    return fillNumber(1, 0);
}

int main() {
    int answer;

    for (int i = 1; i <= 15; ++i) {
        answer = countArrangement(i);
        cout << answer << endl;
    }

    return 0;
}






