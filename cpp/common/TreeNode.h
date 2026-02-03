#include <vector>

#include "limits.h"
using namespace std;

const int NONE = INT_MAX;
class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode* left, TreeNode* right);
};

namespace util {
TreeNode* makeTree(vector<int> nums);
bool isSameTree(TreeNode* root0, TreeNode* root1);
void printTree(TreeNode* root);
}  // namespace util
