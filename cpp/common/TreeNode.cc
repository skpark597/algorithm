#include <iostream>
#include <queue>
#include <string>
#include "TreeNode.h"

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) :
	val(x), left(left), right(right) {}

namespace util {
	// LeetCode Tree Visualizer에 맞추어서 구현함. 디버깅용.
	TreeNode *makeTree(vector<int> nums) {
		if (nums.empty()) return nullptr;

		queue<TreeNode *> queue;
		int index = 1;
		TreeNode *root = new TreeNode(nums[0]);
		queue.push(root);

		while (index < nums.size()) {
			TreeNode *cur = queue.front();
			queue.pop();

			cur->left = nums[index] == NONE ? nullptr : new TreeNode(nums[index]);
			index++;

			if (index < nums.size()) {
				cur->right = nums[index] == NONE ? nullptr : new TreeNode(nums[index]);
				index++;
			}

			if (cur->left != nullptr) queue.push(cur->left);
			if (cur->right != nullptr) queue.push(cur->right);
		}

		return root;
	}

	void printTree(TreeNode *root) {
		if (root == nullptr) {
			cout << "no element" << endl;
			return;
		}
		
		queue<TreeNode *> queue;
		string str = "";
		queue.push(root);

		str += "[";
		if (root->left == nullptr && root->right == nullptr) {
			str += to_string(root->val) + "]";
		} else {
			str += to_string(root->val) + ", ";
		}

		while (!queue.empty()) {
			TreeNode *cur = queue.front();
			TreeNode *left = cur->left;
			TreeNode *right = cur->right;
			string value;
			queue.pop();

			if (left == nullptr && right == nullptr) continue;

			value = left == nullptr ? "NONE" : to_string(left->val);
			str += value + ", ";

			value = right == nullptr ? "NONE" : to_string(right->val);
			str += value + ", ";

			if (left != nullptr) queue.push(left);
			if (right != nullptr) queue.push(right);
		}

		str.pop_back();
		str.pop_back();
		str += "]";
		cout << str << endl;
	}
}



