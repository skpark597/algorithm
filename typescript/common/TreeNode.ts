export class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;

  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }

  // array를 tree로 만드는 함수. LeetCode TreeVisualizer가 array를 Tree로 만드는 방식과 동일.
  static make(numbers: (number | null)[]): TreeNode | null {
    if (numbers.length === 0 || numbers[0] === null) return null;

    const root = new TreeNode(numbers[0]);
    const queue: TreeNode[] = [root];
    const length = numbers.length;
    let index = 0;

    while (queue.length > 0) {
      const node = queue.shift() as TreeNode;
      const leftNumber = index < length - 1 ? numbers[++index] : null;
      const rightNumber = index < length - 1 ? numbers[++index] : null;
      const left = leftNumber !== null ? new TreeNode(leftNumber) : null;
      const right = rightNumber !== null ? new TreeNode(rightNumber) : null;

      node.left = left;
      node.right = right;

      if (left) queue.push(left);
      if (right) queue.push(right);
    }

    return root;
  }

  static isSame(tree0: TreeNode | null, tree1: TreeNode | null): boolean {
    if (tree0 === null || tree1 === null) {
      if (tree0 === null && tree1 === null) return true;
      return false;
    }

    if (tree0.val !== tree1.val) return false;

    const isLeftSubTreeSame = this.isSame(tree0.left, tree1.left);
    const isRightSubTreeSame = this.isSame(tree0.right, tree1.right);

    return isLeftSubTreeSame && isRightSubTreeSame;
  }

  static compare(a: TreeNode | null, b: TreeNode | null) {
    if (a === null && b === null) return 0;
    if (a === null && b !== null) return -1;
    if (a !== null && b === null) return 1;

    // eslint-disable-next-line @typescript-eslint/ban-ts-comment
    // @ts-ignore
    return a.val - b.val;
  }

  static isSameListIgnoringOrder(list0: (TreeNode | null)[], list1: (TreeNode | null)[]) {
    if (list0.length !== list1.length) return false;

    const sorted0 = list0.sort(this.compare);
    const sorted1 = list1.sort(this.compare);

    sorted0.forEach((tree0) => {
      sorted1.forEach((tree1) => {
        if (!this.isSame(tree0, tree1)) return false;
      });
    });

    return true;
  }
}
