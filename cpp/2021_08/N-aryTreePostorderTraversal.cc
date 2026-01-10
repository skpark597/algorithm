/** 590. N-ary Tree Postorder Traversal */
/** Given the root of an n-ary tree, return the postorder traversal of its nodes' values.
 *  Nary-Tree input serialization is represented in their level order traversal. 
 *  Each group of children is separated by the null value (See examples)
 * 
 *  Example 1:
 *  Input: root = [1,null,3,2,4,null,5,6]
 *  Output: [5,6,3,2,4,1]
 * 
 *  Example 2:
 *  Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 *  Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 10^4].
 *  0 <= Node.val <= 10^4
 *  The height of the n-ary tree is less than or equal to 1000. **/

#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void traversal(Node *node, vector<int> &answer) {
    vector<Node *> children = node->children;

    for (Node *iter : children) {
        if (iter == nullptr) continue;
        traversal(iter, answer);
    }

    answer.push_back(node->val);
}

vector<int> postorder(Node* root) {
    vector<int> answer;
    if (root == nullptr) return answer;
    traversal(root, answer);
    return answer;
}

int main() {
    Node *node05 = new Node(5);
    Node *node06 = new Node(6);
    vector<Node *> children0 {node05, node06};
    Node *node03 = new Node(3, children0);
    Node *node02 = new Node(2);
    Node *node04 = new Node(4);
    vector<Node *> children1 {node03, node02, node04};
    Node *node01 = new Node(1, children1);

    vector<int> ans0 = postorder(node01);

    for (int iter : ans0) cout << iter << " ";

}


