/* 274. H-Index */
/** Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
 *  According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have 
 *  at least h citations each, and the other N − h papers have no more than h citations each."
 * 
 *  Example:
 *  Input: citations = [3,0,6,1,5]
 *  Output: 3 
 *  Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
 *               received 3, 0, 6, 1, 5 citations respectively. 
 *               Since the researcher has 3 papers with at least 3 citations each and the remaining 
 *               two with no more than 3 citations each, her h-index is 3.
 *  Note: If there are several possible values for h, the maximum one is taken as the h-index. **/

#include <vector>
using namespace std;

void swap (int idx1, int idx2, vector<int> &nums) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

void insertionSort (vector<int> &nums) {
    for (int i=0; i< nums.size()-1; ++i) {
        int j=i;
        while (j>=0 && nums[j] > nums[j+1]) {
            swap(j,j+1,nums);
            j--;
        }
    }
}

int hIndex (vector<int> &citations) {
    int h_index = citations.size();
    if (h_index == 0) return 0;

    insertionSort(citations);

    for (int i=0; i< citations.size(); ++i) {
        if (h_index <= citations[i]) break;
        h_index--;
    }

    return h_index;
}

int main() {
    vector<int> citations {3,0,6,1,5};
    int answer = hIndex(citations);

    return 0;
}