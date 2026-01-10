/* 119. Pascal's Triangle II */
/** Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 *  In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 *  Example 1:
 *  Input: rowIndex = 3
 *  Output: [1,3,3,1]
 * 
 *  Example 2:
 *  Input: rowIndex = 0
 *  Output: [1]
 * 
 *  Example 3:
 *  Input: rowIndex = 1
 *  Output: [1,1]
 * 
 *  Constraints: 0 <= rowIndex <= 33
 *  Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space? **/

#include <vector>
using namespace std;


vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) return vector<int> {1};

    vector<int> answer {1};
    vector<int> prevRow = getRow(rowIndex-1);

    for (int i=0; i< rowIndex-1; ++i) {
        answer.push_back(prevRow[i]+prevRow[i+1]);
    }

    answer.push_back(1);
    return answer;
}


int main() {
    vector<int> answer1 = getRow(0);
    vector<int> answer2 = getRow(1);
    vector<int> answer3 = getRow(3);
    vector<int> answer4 = getRow(4);
    return 0;
}