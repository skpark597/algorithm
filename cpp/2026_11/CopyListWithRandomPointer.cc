/** 138. Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any
node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has
its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should
point to new nodes in the copied list such that the pointers in the original list and copied list represent the same
list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two
nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val,
random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not
point to any node. Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Constraints:
* 0 <= n <= 1000
* -10^4 <= Node.val <= 10^4
* Node.random is null or is pointing to some node in the linked list. */

#include <cassert>
#include <unordered_map>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

Node* copyRandomList(Node* head) {
  unordered_map<Node*, Node*> node_map;
  Node *prev = nullptr, *cur = nullptr;

  Node dummy(0);
  dummy.next = head;

  for (cur = &dummy; cur; prev = cur, cur = cur->next) {
    Node* new_node = new Node(cur->val);

    node_map[cur] = new_node;
    if (prev) node_map[prev]->next = new_node;
  }

  for (cur = head; cur; cur = cur->next) {
    if (cur->random) node_map[cur]->random = node_map[cur->random];
  }

  return node_map[&dummy]->next;
}

Node* test_case0() {
  Node* node4 = new Node(1);
  Node* node3 = new Node(10);
  Node* node2 = new Node(11);
  Node* node1 = new Node(13);
  Node* node0 = new Node(7);

  node0->next = node1;
  node1->next = node2;
  node1->random = node0;
  node2->next = node3;
  node2->random = node4;
  node3->next = node4;
  node3->random = node2;
  node4->next = nullptr;
  node4->random = node0;

  return node0;
}

Node* test_case1() {
  Node* node0 = new Node(1);
  Node* node1 = new Node(2);

  node0->next = node1;
  node0->random = node1;
  node1->random = node1;

  return node0;
}

Node* test_case2() {
  Node* node0 = new Node(3);
  Node* node1 = new Node(3);
  Node* node2 = new Node(3);

  node0->next = node1;
  node1->next = node2;
  node1->random = node0;

  return node0;
}

bool isDeepCopy(const Node* org, const Node* copy) {
  const Node *fst = org, *snd = copy;
  unordered_map<const Node*, const Node*> node_map;

  for (; fst; fst = fst->next, snd = snd->next) {
    if (!snd || fst == snd || fst->val != snd->val) return false;
    node_map[fst] = snd;
  }

  if (snd) return false;

  for (fst = org, snd = copy; fst; fst = fst->next, snd = snd->next) {
    if (node_map[fst->random] != snd->random) return false;
  }

  return true;
}

int main() {
  Node* org0 = test_case0();
  Node* org1 = test_case1();
  Node* org2 = test_case2();

  Node* copy0 = copyRandomList(org0);
  Node* copy1 = copyRandomList(org1);
  Node* copy2 = copyRandomList(org2);

  assert(isDeepCopy(org0, copy0));
  assert(isDeepCopy(org1, copy1));
  assert(isDeepCopy(org2, copy2));

  return 0;
}
