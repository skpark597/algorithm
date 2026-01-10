import { TreeNode } from "../common/TreeNode";
import { ListNode } from "../common/ListNode";

const treeExample0 = () => {
  const node5 = new TreeNode(5);
  const node2 = new TreeNode(2);
  const node3 = new TreeNode(3, node5);
  const node1 = new TreeNode(1, node3, node2); // root

  return node1;
};

const treeExample1 = () => {
  const node4 = new TreeNode(4);
  const node7 = new TreeNode(7);
  const node1 = new TreeNode(1, null, node4);
  const node3 = new TreeNode(3, null, node7);
  const node2 = new TreeNode(2, node1, node3);

  return node2;
};

// 1 -> 2 -> 3 -> null
const listExample0 = () => {
  const node1 = new ListNode(3);
  const node0 = new ListNode(2, node1);
  return new ListNode(1, node0);
};

// 1 -> 2 -> 3 -> 4 -> null
const listExample1 = () => {
  const node3 = new ListNode(4);
  const node2 = new ListNode(3, node3);
  const node1 = new ListNode(2, node2);
  return new ListNode(1, node1);
};

// 2 -> 3 -> 4 -> null
const listExample2 = () => {
  const node1 = new ListNode(4);
  const node0 = new ListNode(3, node1);
  return new ListNode(2, node0);
};

// 1 -> 2 -> 3 -> 4, 4가 다시 2를 refrence
const circularListExample0 = () => {
  const node3 = new ListNode(4);
  const node2 = new ListNode(3, node3);
  const node1 = new ListNode(2, node2);
  const node0 = new ListNode(1, node1);
  node3.next = node1;

  return node0;
};

// 1 -> 2 -> 3 -> 4, 4가 다시 3를 refrence
const circularListExample1 = () => {
  const node3 = new ListNode(4);
  const node2 = new ListNode(3, node3);
  const node1 = new ListNode(2, node2);
  const node0 = new ListNode(1, node1);
  node3.next = node2;

  return node0;
};

// 2 -> 3 -> 4 -> null
const circularListExample2 = () => {
  const node1 = new ListNode(4);
  const node0 = new ListNode(3, node1);
  return new ListNode(2, node0);
};

describe("common utility test", () => {
  it("check if two trees are same", () => {
    const tree0 = treeExample0();
    const tree1 = treeExample1();

    const ans0 = TreeNode.isSame(tree0, tree0);
    const ans1 = TreeNode.isSame(tree1, tree1);
    const ans2 = TreeNode.isSame(tree0, tree1);

    expect(ans0).toEqual(true);
    expect(ans1).toEqual(true);
    expect(ans2).toEqual(false);
  });

  it("make a tree from array", () => {
    const arr0 = [1, 3, 2, 5];
    const arr1 = [2, 1, 3, null, 4, null, 7];

    const ret0 = TreeNode.make(arr0);
    const ret1 = TreeNode.make(arr1);

    const ans0 = treeExample0();
    const ans1 = treeExample1();

    const compare0 = TreeNode.isSame(ret0, ans0);
    const compare1 = TreeNode.isSame(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("check if two linked lists are same", () => {
    const list0 = listExample0();
    const list1 = listExample1();
    const list2 = listExample2();

    const compare0 = ListNode.isSameList(list0, list0);
    const compare1 = ListNode.isSameList(list0, list1);
    const compare2 = ListNode.isSameList(list0, list2);
    const compare3 = ListNode.isSameList(list1, list1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(false);
    expect(compare2).toEqual(false);
    expect(compare3).toEqual(true);
  });

  it("make a linked list from array ", () => {
    const arr0 = [1, 2, 3];
    const arr1 = [1, 2, 3, 4];

    const ret0 = ListNode.makeList(arr0);
    const ret1 = ListNode.makeList(arr1);

    const ans0 = listExample0();
    const ans1 = listExample1();

    const compare0 = ListNode.isSameList(ret0, ans0);
    const compare1 = ListNode.isSameList(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("split linked list", () => {
    const list0 = listExample0();
    const list1 = listExample1();

    const ret0 = ListNode.splitList(list0, 1, 2);
    const ret1 = ListNode.splitList(list1, 1, 3);

    const compare0 = ListNode.isSameList(ret0, list0.next);
    const compare1 = ListNode.isSameList(ret1, list1.next);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("check if two circular linked list are same", () => {
    const list0 = circularListExample0();
    const list1 = circularListExample1();
    const list2 = circularListExample2();
    const list3 = circularListExample0();
    const list4 = circularListExample1();
    const list5 = circularListExample2();

    const compare0 = ListNode.isSameCircularList(list0, list0);
    const compare1 = ListNode.isSameCircularList(list1, list1);
    const compare2 = ListNode.isSameCircularList(list2, list2);
    const compare3 = ListNode.isSameCircularList(list3, list4);
    const compare4 = ListNode.isSameCircularList(list3, list5);
    const compare5 = ListNode.isSameCircularList(list4, list5);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
    expect(compare3).toEqual(false);
    expect(compare4).toEqual(false);
    expect(compare5).toEqual(false);
  });

  it("make a circular linked list from array", () => {
    const arr0: [number[], number] = [[1, 2, 3, 4], 1];
    const arr1: [number[], number] = [[1, 2, 3, 4], 2];
    const arr2: [number[], number] = [[2, 3, 4], -1];

    const list0 = ListNode.makeCircularList(arr0);
    const list1 = ListNode.makeCircularList(arr1);
    const list2 = ListNode.makeCircularList(arr2);
    const list3 = null;

    const ans0 = circularListExample0();
    const ans1 = circularListExample1();
    const ans2 = circularListExample2();
    const ans3 = null;

    const compare0 = ListNode.isSameCircularList(list0, ans0);
    const compare1 = ListNode.isSameCircularList(list1, ans1);
    const compare2 = ListNode.isSameCircularList(list2, ans2);
    const compare3 = ListNode.isSameCircularList(list3, ans3);
    const compare4 = ListNode.isSameCircularList(list3, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
    expect(compare3).toEqual(true);
    expect(compare4).toEqual(false);
  });
});
