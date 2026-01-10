/* 113. Path Sum II */
/** Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *  Note: A leaf is a node with no children.
 * 
 *  Example:
 *  Given the below binary tree and sum = 22
 * 
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
    
 *  Return: [[5,4,11,2],[5,8,4,5]] * **/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> answer;
int target_sum;

void findPath(TreeNode *root, vector<int> path, int cur_sum) {
    int val = root->val;
    path.push_back(val);

    if (root->left == nullptr && root->right == nullptr) {
        if (cur_sum + val == target_sum) {
            answer.push_back(path);
        }
        return;
    }

    if (root->left != nullptr) {
        findPath(root->left, path, cur_sum+val);
    } 

    if (root->right != nullptr) {
        findPath(root->right, path, cur_sum+val);
    }

}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> path;

    if (root == nullptr) return vector<vector<int>>();
    target_sum = sum;
    findPath(root, path, 0);
    return answer;
}

int main() {
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node13 = new TreeNode(13);
    TreeNode *node11 = new TreeNode(11, node7, node2);
    TreeNode *node4 = new TreeNode(4, node5, node1);
    TreeNode *node4_2 = new TreeNode(4, node11, nullptr);
    TreeNode *node8 = new TreeNode(8, node13, node4);
    TreeNode *node5_2 = new TreeNode(5, node4_2, node8);

    vector<vector<int>> answer = pathSum(node5_2, 22);

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            cout << answer[i][j] <<" ";
        }
        cout << endl;
    }


    return 0;
}



