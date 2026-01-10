/* 859. Buddy Strings */
/** Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.
 *  Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and 
 *  swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 * 
 *  Example 1:
 *  Input: A = "ab", B = "ba"
 *  Output: true
 *  Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
 * 
 *  Example 2:
 *  Input: A = "ab", B = "ab"
 *  Output: false
 *  Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
 * 
 *  Example 3:
 *  Input: A = "aa", B = "aa"
 *  Output: true
 *  Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
 * 
 *  Example 4:
 *  Input: A = "aaaaaaabc", B = "aaaaaaacb"
 *  Output: true
 * 
 *  Example 5:
 *  Input: A = "", B = "aa"
 *  Output: false
 * 
 *  Constraints:
 *  0 <= A.length <= 20000
 *  0 <= B.length <= 20000
 *  A and B consist of lowercase letters. **/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool buddyStrings(string A, string B) {
    int firstDiff = -1;
    int secondDiff = -1;
    vector<bool> visitied (26, false);
    bool duplicate = false;

    if (A.length() != B.length()) return false;

    for (int i = 0; i < A.length(); ++i) {
        if (A[i] == B[i]) {
            if (visitied[A[i]-'a']) duplicate = true;
            visitied[A[i]-'a'] = true;
            continue;
        }
        
        if (firstDiff == -1) {
            firstDiff = i;
        } else if (secondDiff == -1) {
            secondDiff = i;
        } else {
            return false;
        }
    }

    if (duplicate && A == B) return true;
    if (secondDiff == -1) return false;
    if (A[firstDiff] == B[secondDiff] && A[secondDiff] == B[firstDiff]) return true;

    return false;
}

int main() {
    string A = "abc";
    string B = "acd";

    bool answer = buddyStrings(A,B);

    cout << answer << endl;
    return 0;
}




