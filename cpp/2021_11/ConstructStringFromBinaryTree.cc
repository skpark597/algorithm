/** 606. Construct String from Binary Tree */
/** Given the root of a binary tree, construct a string consisting of parenthesis and integers from 
 *  a binary tree with the preorder traversal way, and return it.
 *  Omit all the empty parenthesis pairs that do not affect the one-to-one mapping 
 *  relationship between the string and the original binary tree.
 * 
 *  Example 1:
 *  Input: root = [1,2,3,4]
 *  Output: "1(2(4))(3)"
 *  Explanation: Originally, it needs to be "1(2(4)())(3()())",
 *  but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
 * 
 *  Example 2:
 *  Input: root = [1,2,3,null,4]
 *  Output: "1(2()(4))(3)"
 *  Explanation: Almost the same as the first example, except we cannot 
 *  omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  -1000 <= Node.val <= 1000 **/

#include <vector>
#include <string>
#include <iostream>
#include <TreeNode.h>
#include <limits.h>

using namespace std;

string tree2str(TreeNode *root)
{
    string result = "";
    string leftChild, rightChild;

    if (!root)
        return result;

    leftChild = tree2str(root->left);
    rightChild = tree2str(root->right);

    result.append(to_string(root->val));

    if (rightChild.empty() && !leftChild.empty())
    {
        result.append("(" + leftChild + ")");
    }
    else if (!rightChild.empty())
    {
        result.append("(" + leftChild + ")");
        result.append("(" + rightChild + ")");
    }

    return result;
}

int main()
{
    vector<int> nums0{1, 2, 3, 4};
    TreeNode *case0 = util::makeTree(nums0);

    vector<int> nums1{1, 2, 3, NONE, 4};
    TreeNode *case1 = util::makeTree(nums1);

    string ans0 = tree2str(case0);
    string ans1 = tree2str(case1);

    cout << ans0 << endl; // "1(2(4))(3)"
    cout << ans1 << endl; // "1(2()(4))(3)"

    return 0;
}
