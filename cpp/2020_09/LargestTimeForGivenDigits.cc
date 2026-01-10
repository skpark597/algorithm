/* 949. Largest Time for Given Digits */
/** Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
 *  24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. 
 *  The earliest 24-hour time is 00:00, and the latest is 23:59.
 *  Return the latest 24-hour time in "HH:MM" format.  If no valid time can be made, return an empty string.
 * 
 *  Example 1:
 *  Input: A = [1,2,3,4]
 *  Output: "23:41"
 *  Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", 
 *  "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
 * 
 *  Example 2:
 *  Input: A = [5,5,5,5]
 *  Output: ""
 *  Explanation: There are no valid 24-hour times as "55:55" is not valid.
 * 
 *  Example 3:
 *  Input: A = [0,0,0,0]
 *  Output: "00:00"
 * 
 *  Example 4:
 *  Input: A = [0,0,1,0]
 *  Output: "10:00"
 * 
 *  Constraints:
 *  arr.length == 4
 *  0 <= arr[i] <= 9 **/

#include <vector>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;
vector<bool> used (4, false);

int findMaxLessThan (vector<int> &A, int bound = INT_MAX) {
    int index = -1;
    int max = -1;

    for (int i=0; i < A.size(); ++i) {
        if (A[i] < bound && A[i] > max && used[i] == false) {
            max = A[i];
            index = i;
        }
    }
    
    if (index != -1) used[index] = true;
    return max;
}

string largestTimeFromDigits(vector<int>& A) {
    string answer;
    int first, second, third, fourth;

    // first number setting
    first = findMaxLessThan(A, 3);
    if (first == -1) return answer;

    // second number setting
    if (first == 2) {
        second = findMaxLessThan (A, 4);
    } else {
        second = findMaxLessThan(A, 10);
    }   
    if (second == -1) return answer;    

    // third number setting
    third = findMaxLessThan(A, 6);
    if (third == -1 && (first < 2 || (first == 2 && second >1))) return answer;
    else if (third == -1 && (first==2 && second <=1)) {
        used.clear(); 
        used.resize(4,false);
        first = findMaxLessThan (A, 2);
        second = findMaxLessThan (A, 10);
        third = findMaxLessThan (A, 6);
        if (third == -1) return answer;
    }

    // fourth number setting
    fourth = findMaxLessThan(A, 10);

    answer.append(to_string(first));
    answer.append(to_string(second));
    answer.append(":");
    answer.append(to_string(third));
    answer.append(to_string(fourth));

    return answer;
}

int main() {
    //vector<int> input {2,0,6,6};
    //vector<int> input {5,5,5,5};
    vector<int> input {0,4,0,0};
    string answer = largestTimeFromDigits(input);

    cout << answer << endl;

    return 0;
}




