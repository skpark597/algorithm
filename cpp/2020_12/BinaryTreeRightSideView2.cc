/* 199. Binary Tree Right Side View */
/** Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 * 
 *  Example:
 *  Input: [1,2,3,null,5,null,4]
 *  Output: [1, 3, 4]
 *  Explanation:

       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <--- **/

/* 처음 생각한 풀이. queue를 2개 쓰는게 오류의 발생을 높일 수 있다 */

#include <vector>
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

vector<int> rightSideView(TreeNode *root) {
    int cur_depth;
    vector<int> answer;
    queue<TreeNode *> tree_q;
    queue<int> depths;

    if (root == nullptr) return vector<int>();

    tree_q.push(root);
    depths.push(1);
    cur_depth = 0;

    while (!tree_q.empty()) {
        TreeNode *node = tree_q.front();
        int depth = depths.front();
        tree_q.pop();
        depths.pop();

        if (depth > cur_depth) {
            answer.push_back(node->val);
            cur_depth = depth;
        }

        if (node->right != nullptr) {
            tree_q.push(node->right);
            depths.push(depth+1);
        }
        
        if (node->left != nullptr) {
            tree_q.push(node->left);
            depths.push(depth+1);
        }
    }

    return answer;
}

int main() {
    TreeNode *node04 = new TreeNode(4);
    TreeNode *node05 = new TreeNode(5);
    TreeNode *node03 = new TreeNode(3, nullptr, node04);
    TreeNode *node02 = new TreeNode(2, nullptr, node05);
    TreeNode *node01 = new TreeNode(1, node02, node03);

    vector<int> ans0 = rightSideView(node01);

    TreeNode *node15 = new TreeNode(5);
    TreeNode *node13 = new TreeNode(3, nullptr, nullptr);
    TreeNode *node12 = new TreeNode(2, nullptr, node15);
    TreeNode *node11 = new TreeNode(1, node12, node13);

    vector<int> ans1 = rightSideView(node11);

    for (int iter : ans0) {
        cout << iter << " ";
    }
    cout << endl;


    for (int iter : ans1) {
        cout << iter << " ";
    }
    cout << endl;

    return 0;
}

