/* 902. Numbers At Most N Given Digit Set */
/** Given an array of digits, you can write numbers using each digits[i] as many times as we want.  
 *  For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
 *  Return the number of positive integers that can be generated that are less than or equal to a given integer n.
 *  
 *  Example 1:
 *  Input: digits = ["1","3","5","7"], n = 100
 *  Output: 20
 *  Explanation: 
 *  The 20 numbers that can be written are:
 *  1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
 * 
 *  Example 2:
 *  Input: digits = ["1","4","9"], n = 1000000000
 *  Output: 29523
 *  Explanation: 
 *  We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
 *  81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
 *  2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
 *  In total, this is 29523 integers that can be written using the digits array.
 * 
 *  Example 3:
 *  Input: digits = ["7"], n = 8
 *  Output: 1
 *  
 *  Constraints:
 *  1 <= digits.length <= 9
 *  digits[i].length == 1
 *  digits[i] is a digit from '1' to '9'.
 *  All the values in digits are unique.
 *  1 <= n <= 10^9  **/

/* 아래는 내가 처음 생각한 풀이 - 잘했다고 생각했는데 시간,공간 복잡도가 둘 다 더 효율적인 방법이 있었다 ㅜㅠ
   아니다 생각해보니 1121_2.cc 의 풀이랑 거의 똑같구나*/

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

// n_digits에는 n의 각 자리수가 역순으로 들어있음 (n=123 이면 n_digits ={3,2,1})
// n이 m 자리 수라고 할 때, digits을 이용하여 만들 수 있는 m자리 수 중 n 이하인 것의 개수를 리턴
int countLessThan(vector<string>& digits, vector<int> &n_digits) {
    int answer = 0;
    int lessCount = 0;
    int sameCount = 0;

    for (int i = 0; i < digits.size(); ++i) {
        if (stoi(digits[i]) < n_digits.back()) {
            lessCount++;
        } else if (stoi(digits[i]) == n_digits.back()) {
            sameCount++;
        }
    }

    if (n_digits.size() == 1) return lessCount+sameCount;

    answer = lessCount * pow(digits.size(), n_digits.size()-1);
    if (sameCount > 0) {
        n_digits.pop_back();
        answer += countLessThan(digits, n_digits);
    }

    return answer;
}

int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int answer = 0;
    int length = digits.size();
    int m = -1;
    vector<int> n_digits;

    while (n > 0) {
        n_digits.push_back(n % 10);
        m++;
        n /= 10;
    }

    // digits을 이용하여 만들 수 있는 m자리 이하의 수의 개수를 먼저 answer에 세팅
    answer = length == 1 ? m : (pow(length, m+1) - length) / (length - 1);

    // digits을 이용하여 만들 수 있는 m+1자리 수의 개수를 더한다.
    answer += countLessThan(digits, n_digits);

    return answer;
}

int main() {
    int n = 100;
    vector<string> digits {"1","3","5","7"};
    //vector<string> digits {"1","4","9"};
    //vector<string> digits {"7"};

    int answer = atMostNGivenDigitSet(digits, n);
    cout << answer << endl;

    return 0;
}









