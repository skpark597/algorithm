"""
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put

"""


class Node:
    key: int
    value: int
    prev: "Node"
    next: "Node"

    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:
    capacity: int
    mapping: dict[int, Node]
    head: Node | None
    tail: Node | None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.mapping = {}
        self.head = None
        self.tail = None

    def _move_to_head(self, node: Node):
        if node.prev is None:
            return

        if node.prev:
            node.prev.next = node.next

        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev

        node.prev = None
        node.next = self.head
        self.head.prev = node
        self.head = node

    def _cut_tail(self):
        tail = self.tail
        prev_tail = self.tail.prev

        if prev_tail:
            prev_tail.next = None

        tail.prev = None
        self.tail = prev_tail

        del self.mapping[tail.key]

    def _append(self, node: Node):
        if self.tail:
            self.tail.next = node
            node.prev = self.tail
            node.next = None
            self.tail = node
        else:
            self.head = node
            self.tail = node

        self.mapping[node.key] = node

    def get(self, key: int) -> int:
        if key not in self.mapping:
            return -1

        self._move_to_head(self.mapping[key])
        return self.head.value

    def put(self, key: int, value: int):
        if key in self.mapping:
            self.mapping[key].value = value
            self._move_to_head(self.mapping[key])
            return

        new_node = Node(key, value)

        if len(self.mapping) == self.capacity:
            self._cut_tail()

        self._append(new_node)
        self._move_to_head(new_node)
