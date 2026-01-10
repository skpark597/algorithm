/** 109. Convert Sorted List to Binary Search Tree */
/** Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *  For this problem, a height-balanced binary tree is defined as a binary tree in which the 
 *  depth of the two subtrees of every node never differ by more than 1.
 * 
 *  Example 1:
 *  Input: head = [-10,-3,0,5,9]
 *  Output: [0,-3,9,-10,null,5]
 *  Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 * 
 *  Example 2:
 *  Input: head = []
 *  Output: []
 * 
 *  Example 3:
 *  Input: head = [0]
 *  Output: [0]
 * 
 *  Example 4:
 *  Input: head = [1,3]
 *  Output: [3,1]
 * 
 *  Constraints:
 *  The number of nodes in head is in the range [0, 2 * 10^4].
 *  -10^5 <= Node.val <= 10^5 **/

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end) {
    if (start > end) return nullptr;

    int middle = (start + end) / 2;
    TreeNode *newNode = new TreeNode(nums[middle]);

    newNode->left = sortedArrayToBST(nums, start, middle - 1);
    newNode->right = sortedArrayToBST(nums, middle + 1, end);

    return newNode;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    ListNode *iter = head;

    while (iter != nullptr) {
        nums.push_back(iter->val);
        iter = iter->next;
    }

    return sortedArrayToBST(nums, 0, nums.size()-1);
}

int main() {


    return 0;
}