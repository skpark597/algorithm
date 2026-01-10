/* 229. Majority Element II */
/** Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 *  Note: The algorithm should run in linear time and in O(1) space.
 * 
 *  Example 1:
 *  Input: [3,2,3]
 *  Output: [3]
 *  
 *  Example 2:
 *  Input: [1,1,1,3,3,2,2,2]
 *  Output: [1,2] **/

#include <vector>
#include <iostream>
#include <math.h>
#include <set>

using namespace std;

void increase (long &state, int index, int size) {
    int temp = pow (2, size)-1;
    int temp2 = state & (temp << (index*size));
    temp2 = temp2 >> index *size;
    if (temp2 != temp) temp2++;
    state = (state & ~(temp << (index *size))) | (temp2 << index * size);
}

int getCount (long &state, int index, int size) {
    int temp = pow (2,size) -1;
    int result = (state >> index * size) & temp;
    state = state & ~(temp << (index *size));
    return result;
}

vector<int> majorityElement(vector<int>& nums) {
    if (nums.empty()) return vector<int>();

    vector<int> answer;
    int frequency = nums.size()/3+1;
    int size = 0;
    int abss = abs(nums[0]);
    int minimum = nums[0];
    long state;
    int count;

    for (int i=0; i < nums.size(); ++i) {
        abss = max (abss, abs(nums[i]));
        minimum = min (minimum, nums[i]);
    }

    if (minimum < 0) {
        abss -= minimum;
        for (int i=0; i< nums.size(); ++i) {
            nums[i] -= minimum;
        }
    }

    while (frequency > 0) {
        size++;
        frequency = frequency / 2;
    }

    state = 1 << size * (abss+1);

    for (int i=0; i< nums.size(); ++i) {
        increase (state, nums[i], size);
    }

    for (int i=0; i< nums.size(); ++i) {
        count = getCount(state, nums[i], size);
        if (count > nums.size()/3) answer.push_back(nums[i]+minimum);
    }


    return answer;
}


int main() {
    //vector<int> nums {1,1,1,3,3,2,2,2};
    //vector<int> nums {1};
    //vector<int> nums {2,2};
    vector<int> nums {0,-1,2,-1};
    vector<int> answer = majorityElement(nums);

    for (int &iter : answer) {
        cout << iter << " ";
    }

    return 0;
}







