/* 344. Reverse String */
/** Write a function that reverses a string. The input string is given as an array of characters s.
 * 
 *  Example 1:
 *  Input: s = ["h","e","l","l","o"]
 *  Output: ["o","l","l","e","h"]
 * 
 *  Example 2:
 *  Input: s = ["H","a","n","n","a","h"]
 *  Output: ["h","a","n","n","a","H"]
 * 
 *  Constraints:
 *  1 <= s.length <= 105
 *  s[i] is a printable ascii character.
 *  Follow up: Do not allocate extra space for another array. 
 *  You must do this by modifying the input array in-place with O(1) extra memory. **/

#include <vector>
#include <iostream>

using namespace std;

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size()-1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    vector<char> s0 {'h','e','l','l','o'};
    vector<char> s1 {'H','a','n','n','a','h'};

    reverseString(s0);
    reverseString(s1);

    for (char iter : s0) {
        cout << iter << " ";
    } cout << endl;

    for (char iter : s1) {
        cout << iter << " ";
    }

    return 0;
}