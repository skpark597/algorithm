/** 222. Count Complete Tree Nodes */
/** Given the root of a complete binary tree, return the number of the nodes in the tree.
 *  According to Wikipedia, every level, except possibly the last, is completely filled in a 
 *  complete binary tree, and all nodes in the last level are as far left as possible. 
 *  It can have between 1 and 2h nodes inclusive at the last level h.
 * 
 *  Design an algorithm that runs in less than O(n) time complexity.
 * 
 *  Example 1:
 *  Input: root = [1,2,3,4,5,6]
 *  Output: 6
 * 
 *  Example 2:
 *  Input: root = []
 *  Output: 0
 * 
 *  Example 3:
 *  Input: root = [1]
 *  Output: 1
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 5 * 10^4].
 *  0 <= Node.val <= 5 * 10^4
 *  The tree is guaranteed to be complete. **/

#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <math.h>

int getHeight(TreeNode *root) {
        TreeNode *iter = root;
        int height = -1;
        
        while (iter != nullptr) {
            iter = iter->left;
            height++;
        }
        
        return height;
}
    
void setAboveLeafs(vector<TreeNode *> &aboveLeafs, int height, TreeNode *root) {
    queue<TreeNode *> queue;
    int size = 0;
    queue.push(root);
    
    for (int i = 0; i < height-1; ++i) {
        int size = queue.size();
        
        for (int j = 0; j < size; ++j) {
            TreeNode *node = queue.front();
            queue.pop();
            
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
        }
    }
    
    size = queue.size();
    for (int i = 0; i < size; ++i) {
        aboveLeafs[i] = queue.front();
        queue.pop();
    }
}

int binarySearch(int height, vector<TreeNode *> &aboveLeafs) {
    int left = 0;
    int right = aboveLeafs.size()-1;
    int index = 0;
    int middle;
    int answer = pow(2, height)-1;
    
    while (left <= right) {
        middle = left + (right - left) / 2;
        
        if (aboveLeafs[middle]->left == nullptr) {
            right = middle - 1;
        } else if (aboveLeafs[middle]->right != nullptr) {
            left = middle + 1;
        } else {
            right = middle;
            break;
        }
    }
    
    if (aboveLeafs[right]->right == nullptr) {
        answer += 2 * right + 1;
    } else {
        answer += 2 * right + 2;
    }

    return answer;
}

int countNodes(TreeNode* root) {
    int height = 0;
    vector<TreeNode *> aboveLeafs;
    
    if (root == nullptr) return 0;
    height = getHeight(root);
    if (height == 0) return 1;
    aboveLeafs.resize(pow(2, height-1));
    
    setAboveLeafs(aboveLeafs, height, root);
    return binarySearch(height, aboveLeafs);
}

int main() {
    TreeNode *root0 = util::makeTree({1,2,3,4,5,6});
    TreeNode *root1 = util::makeTree({});
    TreeNode *root2 = util::makeTree({1});

    int ans0 = countNodes(root0);
    int ans1 = countNodes(root1);
    int ans2 = countNodes(root2);

    cout << ans0 << endl; // 6
    cout << ans1 << endl; // 0
    cout << ans2 << endl; // 1

    return 0;
}
