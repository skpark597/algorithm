/** 988. Smallest String Starting From Leaf */
/** You are given the root of a binary tree where each node has a value 
 *  in the range [0, 25] representing the letters 'a' to 'z'.
 *  Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
 * 
 *  As a reminder, any shorter prefix of a string is lexicographically smaller.
 *  For example, "ab" is lexicographically smaller than "aba".
 *  A leaf of a node is a node that has no children.
 * 
 *  Example 1:
 *  Input: root = [0,1,2,3,4,3,4]
 *  Output: "dba"
 * 
 *  Example 2:
 *  Input: root = [25,1,3,1,3,0,2]
 *  Output: "adz"
 *  
 *  Example 3:
 *  Input: root = [2,2,1,null,1,0,null,0]
 *  Output: "abc"
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 8500].
 *  0 <= Node.val <= 25 **/

#include <vector>
#include <string>
#include <iostream>
#include <TreeNode.h>

using namespace std;

void pushTreeVal(vector<string> &result, vector<string> &strings, int value)
{
    for (string iter : strings)
        result.push_back(iter + (char)(value + 'a'));
}

vector<string> getStrings(TreeNode *root)
{
    vector<string> result;

    if (root->left == nullptr && root->right == nullptr)
        return vector<string>{string(1, (char)(root->val + 'a'))};

    if (root->left != nullptr)
    {
        vector<string> left = getStrings(root->left);
        pushTreeVal(result, left, root->val);
    }

    if (root->right != nullptr)
    {
        vector<string> right = getStrings(root->right);
        pushTreeVal(result, right, root->val);
    }

    return result;
}

string smallestFromLeaf(TreeNode *root)
{
    vector<string> allStrings = getStrings(root);
    string result = allStrings[0];

    for (string iter : allStrings)
    {
        if (iter < result)
            result = iter;
    }

    return result;
}

int main()
{
    vector<int> nums0{0, 1, 2, 3, 4, 3, 4};
    TreeNode *root0 = util::makeTree(nums0);

    vector<int> nums1{25, 1, 3, 1, 3, 0, 2};
    TreeNode *root1 = util::makeTree(nums1);

    vector<int> nums2{2, 2, 1, NONE, 1, 0, NONE, 0};
    TreeNode *root2 = util::makeTree(nums2);

    vector<int> nums3{0, NONE, 1};
    TreeNode *root3 = util::makeTree(nums3);

    vector<int> nums4{25, 1, NONE, 0, 0, 1, NONE, NONE, NONE, 0};
    TreeNode *root4 = util::makeTree(nums4);

    string ans0 = smallestFromLeaf(root0);
    string ans1 = smallestFromLeaf(root1);
    string ans2 = smallestFromLeaf(root2);
    string ans3 = smallestFromLeaf(root3);
    string ans4 = smallestFromLeaf(root4);

    cout << ans0 << endl; // "dba"
    cout << ans1 << endl; // "adz"
    cout << ans2 << endl; // "abc"
    cout << ans3 << endl; // "ba"
    cout << ans4 << endl; // "ababz"

    return 0;
}