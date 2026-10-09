/** 117. Populating Next Right Pointers in Each Node II
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be
set to NULL.

Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its
next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with
'#' signifying the end of each level.

Example 2:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100

Follow-up:
* You may only use constant extra space.
* The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem. */

#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
  bool operator==(const Node& other) const { return is_equal(this, &other); };

 private:
  static bool is_equal(const Node* n1, const Node* n2) {
    if (!n1 && !n2) return true;
    if (!n1 || !n2) return true;

    return n1->val == n2->val && is_equal(n1->left, n2->left) && is_equal(n1->right, n2->right) &&
           is_equal(n1->next, n2->next);
  };
};

void populate(Node* cur) {
  Node* parent = cur;
  Node* child = nullptr;
  Node* firstChild = nullptr;

  while (parent) {
    if (parent->left) {
      if (!firstChild) firstChild = parent->left;
      if (child) child->next = parent->left;
      child = parent->left;
    }

    if (parent->right) {
      if (!firstChild) firstChild = parent->right;
      if (child) child->next = parent->right;
      child = parent->right;
    }

    parent = parent->next;
  }

  if (firstChild) populate(firstChild);
}

Node* connect(Node* root) {
  populate(root);
  return root;
}

int main() {
  // 입력 트리
  Node* n7 = new Node(7);
  Node* n5 = new Node(5);
  Node* n4 = new Node(4);
  Node* n3 = new Node(3, nullptr, n7, nullptr);
  Node* n2 = new Node(2, n4, n5, nullptr);
  Node* root = new Node(1, n2, n3, nullptr);

  Node* result = connect(root);

  // 기대 결과
  Node* e7 = new Node(7);
  Node* e5 = new Node(5);
  Node* e4 = new Node(4, nullptr, nullptr, e5);
  Node* e3 = new Node(3, nullptr, e7, nullptr);
  Node* e2 = new Node(2, e4, e5, e3);
  Node* expected = new Node(1, e2, e3, nullptr);

  assert(*result == *expected);

  return 0;
}
