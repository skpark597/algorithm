/** 107. Binary Tree Level Order Traversal II */
/** Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
 *  (i.e., from left to right, level by level from leaf to root).
 * 
 *  Example 1:
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: [[15,7],[9,20],[3]]
 * 
 *  Example 2:
 *  Input: root = [1]
 *  Output: [[1]]
 * 
 *  Example 3:
 *  Input: root = []
 *  Output: []
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 2000].
 *  -1000 <= Node.val <= 1000 **/

#include <vector>
#include <stack>
#include <queue>
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

void bfs(TreeNode *root, stack<int> &st, stack<int> &counts) {
    queue<TreeNode *> queue;

    queue.push(root);
    st.push(root->val);
    counts.push(1);

    while (!queue.empty()) {
        int size = queue.size();
        int count = 0;

        for (int i = 0; i < size; ++i) {
            TreeNode *cur = queue.front();
            queue.pop();

            if (cur->right != nullptr) {
                queue.push(cur->right);
                st.push(cur->right->val);
                count++;
            }

            if (cur->left != nullptr) {
                queue.push(cur->left);
                st.push(cur->left->val);
                count++;
            }
        }

        if (count > 0) counts.push(count);
    }
}

vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> answer;
    stack<int> st;
    stack<int> counts;

    if (root == nullptr) return answer;

    bfs(root, st, counts);

    while (!counts.empty()) {
        vector<int> level;
        int count = counts.top();
        counts.pop();

        for (int i = 0; i < count; ++i) {
            int value = st.top();
            st.pop();
            level.push_back(value);
        }

        answer.push_back(level);
    }

    return answer;
}

int main() {
    TreeNode *node0_7 = new TreeNode(7);
    TreeNode *node0_15 = new TreeNode(15);
    TreeNode *node0_20 = new TreeNode(20, node0_15, node0_7);
    TreeNode *node0_9 = new TreeNode(9);
    TreeNode *node0_3 = new TreeNode(3, node0_9, node0_20);

    TreeNode *node1_1 = new TreeNode(1);

    vector<vector<int>> ans0 = levelOrderBottom(node0_3);
    vector<vector<int>> ans1 = levelOrderBottom(node1_1);

    for (vector<int> iter0 : ans0) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << " ] ";
    } cout << endl;

    for (vector<int> iter0 : ans1) {
        cout << "[ ";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << " ] ";
    } cout << endl;

    return 0;
}
