/** 173. Binary Search Tree Iterator
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the
constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST. boolean
hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the
smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order
traversal when next() is called.

Example 1:
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:
* The number of nodes in the tree is in the range [1, 10^5].
* 0 <= Node.val <= 10^6
* At most 10^5 calls will be made to hasNext, and next.

Follow up:
Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the
tree? */

#include <TreeNode.h>

#include <cassert>
#include <stack>

using namespace std;
using namespace util;

class BSTIterator {
 private:
  stack<TreeNode*> nodes;

  void traverseLeft(TreeNode* node) {
    for (; node; node = node->left) nodes.push(node);
  }

 public:
  BSTIterator(TreeNode* root) { traverseLeft(root); }

  bool hasNext() { return !nodes.empty(); }

  int next() {
    TreeNode* cur = nodes.top();
    nodes.pop();

    traverseLeft(cur->right);
    return cur->val;
  }
};

int main() {
  TreeNode* root = makeTree(vector<int>{7, 3, 15, NONE, NONE, 9, 20});
  BSTIterator iter(root);

  int ret0 = iter.next();      // return 3
  int ret1 = iter.next();      // return 7
  bool ret2 = iter.hasNext();  // return True
  int ret3 = iter.next();      // return 9
  bool ret4 = iter.hasNext();  // return True
  int ret5 = iter.next();      // return 15
  bool ret6 = iter.hasNext();  // return True
  int ret7 = iter.next();      // return 20
  bool ret8 = iter.hasNext();  // return False

  delete root;

  assert(ret0 == 3);
  assert(ret1 == 7);
  assert(ret2);
  assert(ret3 == 9);
  assert(ret4);
  assert(ret5 == 15);
  assert(ret6);
  assert(ret7 == 20);
  assert(!ret8);

  return 0;
}