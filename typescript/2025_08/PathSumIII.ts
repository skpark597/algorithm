/** 437. Path Sum III
 *  Given the root of a binary tree and an integer targetSum, return the number of paths
 *  where the sum of the values along the path equals targetSum.
 *  The path does not need to start or end at the root or a leaf, but it must go downwards
 *  (i.e., traveling only from parent nodes to child nodes).
 *
 *  Example 1:
 *  Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 *  Output: 3
 *  Explanation: The paths that sum to 8 are shown.
 *
 *  Example 2:
 *  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 *  Output: 3
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 1000].
 *  -10^9 <= Node.val <= 10^9
 *  -1000 <= targetSum <= 1000 */

import { TreeNode } from "../common/TreeNode";

/**
 * Returns an array of length 2:
 * 0: number of paths **not containing the root** where sum equals `target`
 * 1: dict of number of paths **including the root** where key is in `sums`
 */

function dfs(root: TreeNode | null, target: number, sums: Set<number>): [number, Record<number, number>] {
  if (!root) return [0, {}];

  const next = new Set<number>([target]);
  sums.forEach((sum) => next.add(sum - root.val));

  const [nl, fl] = dfs(root.left, target, next);
  const [nr, fr] = dfs(root.right, target, next);

  const count = nl + nr + (fl[target] ?? 0) + (fr[target] ?? 0);
  const freq: Record<number, number> = {};

  for (const sum of sums) {
    freq[sum] = (fl[sum - root.val] ?? 0) + (fr[sum - root.val] ?? 0);
    if (sum === root.val) freq[sum]++;
  }

  return [count, freq];
}

function pathSumOld(root: TreeNode | null, targetSum: number): number {
  const [cnt, freq] = dfs(root, targetSum, new Set<number>([targetSum]));
  return cnt + (freq[targetSum] ?? 0);
}

let count = 0;

function preOrder(node: TreeNode | null, k: number, curSum: number, freq: Record<number, number>) {
  if (node === null) return;

  curSum += node.val;

  if (curSum === k) count++;
  count += freq[curSum - k] ?? 0;

  freq[curSum] = (freq[curSum] ?? 0) + 1;

  preOrder(node.left, k, curSum, freq);
  preOrder(node.right, k, curSum, freq);

  freq[curSum]--;
  curSum -= node.val;
}

function pathSum(root: TreeNode | null, targetSum: number): number {
  count = 0;
  preOrder(root, targetSum, 0, {});
  return count;
}

export { pathSum };
