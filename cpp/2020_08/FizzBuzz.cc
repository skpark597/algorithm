/* 412. Fizz Buzz */
/** Write a program that outputs the string representation of numbers from 1 to n.
 *  But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
 *  For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 *  Example:
 *  n = 15,
 *  Return:
 *  [
 *   "1",
 *   "2",
 *   "Fizz",
 *   "4",
 *   "Buzz",
 *   "Fizz",
 *   "7",
 *   "8",
 *   "Fizz",
 *   "Buzz",
 *   "11",
 *   "Fizz",
 *   "13",
 *   "14",
 *   "FizzBuzz"] */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> fizzBuzz(int n) {
    bool multipleOfThree = false;
    bool multipleOfFive = false;
    vector<string> answer;
    answer.resize(n);

    for (int i=1; i <= n ; ++i) {
        multipleOfThree = (i%3 == 0);
        multipleOfFive = (i%5 == 0);
        
        if (multipleOfThree && multipleOfFive) {
            answer[i-1] = "FizzBuzz";
        } else if (multipleOfThree){
            answer[i-1] = "Fizz";
        } else if (multipleOfFive) {
            answer[i-1] = "Buzz";
        } else {
            answer[i-1] = to_string(i);
        }
    }

    return answer;
}

int main() {

    vector<string> answer = fizzBuzz(15);

    for (string &iter : answer) {
        cout << iter << endl;
    }

    return 0;
}