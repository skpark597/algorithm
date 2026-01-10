/* 106. Construct Binary Tree from Inorder and Postorder Traversal */
/** Given two integer arrays inorder and postorder where inorder is the inorder traversal of a 
 *  binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 * 
 *  Example 1:
 *  Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 *  Output: [3,9,20,null,null,15,7]
 * 
 *  Example 2:
 *  Input: inorder = [-1], postorder = [-1]
 *  Output: [-1]
 * 
 *  Constraints:
 *  1 <= inorder.length <= 3000
 *  postorder.length == inorder.length
 *  -3000 <= inorder[i], postorder[i] <= 3000
 *  inorder and postorder consist of unique values.
 *  Each value of postorder also appears in inorder.
 *  inorder is guaranteed to be the inorder traversal of the tree.
 *  postorder is guaranteed to be the postorder traversal of the tree. **/

#include <vector>
#include "/Users/seungkyun_park/Algorithm/LeetCode/common/TreeNode.h"

using namespace std;

vector<int> in;
vector<int> pos;

TreeNode *buildTreeInternal(int iStart, int iEnd, int pStart, int pEnd) {
    TreeNode *cur = nullptr;
    int leftCount = 0;

    if (iStart > iEnd) return cur;
    cur = new TreeNode(pos[pEnd]);

    for (; leftCount <= iEnd-iStart; ++leftCount) {
        if (pos[pEnd] == in[iStart+leftCount]) break;
    }

    cur->left = buildTreeInternal(iStart, iStart+leftCount-1, pStart, pStart+leftCount-1);
    cur->right = buildTreeInternal(iStart+leftCount+1, iEnd, pStart+leftCount, pEnd-1);

    return cur;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    in.clear();
    pos.clear();
    in = inorder;
    pos = postorder;

    return buildTreeInternal(0, inorder.size()-1, 0, postorder.size()-1);
}

int main() {
    vector<int> inorder0 {9,3,15,20,7};
    vector<int> postorder0 {9,15,7,20,3};

    vector<int> inorder1 {-1};
    vector<int> postorder1 {-1};

    TreeNode *ans0 = buildTree(inorder0, postorder0);
    TreeNode *ans1 = buildTree(inorder1, postorder1);

    return 0;
}
