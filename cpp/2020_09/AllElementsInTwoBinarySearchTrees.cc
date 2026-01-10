/* 1305. All Elements in Two Binary Search Trees */
/** Given two binary search trees root1 and root2.
 *  Return a list containing all the integers from both trees sorted in ascending order.
 *  
 *  Example 1:
 *  Input: root1 = [2,1,4], root2 = [1,0,3]
 *  Output: [0,1,1,2,3,4]
 *  
 *  Example 2:
 *  Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
 *  Output: [-10,0,0,1,2,5,7,10]
 *  
 *  Example 3:
 *  Input: root1 = [], root2 = [5,1,7,0,2]
 *  Output: [0,1,2,5,7]
 *  
 *  Example 4:
 *  Input: root1 = [0,-10,10], root2 = []
 *  Output: [-10,0,10]
 *  
 *  Example 5:
 *  Input: root1 = [1,null,8], root2 = [8,1]
 *  Output: [1,1,8,8]
 *   
 *  Constraints:
 *  Each tree has at most 5000 nodes.
 *  Each node's value is between [-10^5, 10^5] **/

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void sortedVectorFromBST (TreeNode *root, vector<int> &result) {
    if (root == nullptr) return;
    if (root->left != nullptr) {
        sortedVectorFromBST (root->left, result);
    }

    result.push_back(root->val);

    if (root->right != nullptr) {
        sortedVectorFromBST (root->right, result);
    }
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> first, second, result;

    sortedVectorFromBST(root1, first);
    sortedVectorFromBST(root2, second);

    int fst = 0;
    int snd = 0;

    while (fst < first.size() || snd < second.size()) {
        if (fst == first.size() || (snd < second.size() && second[snd] < first[fst])) {
            result.push_back(second[snd]);
            snd++;
        } else {
            result.push_back(first[fst]);
            fst++;
        }
    }
    return result;
}


int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2,node1,node4);

    TreeNode *node0 = new TreeNode(0);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node11 = new TreeNode(1,node0,node3);

    vector<int> answer = getAllElements(node2, node11);

    for (int &iter : answer) {
        cout << iter << " ";
    }

    return 0;
}












