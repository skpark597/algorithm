/**380. Insert Delete GetRandom O(1)
Implement the RandomizedSet class:
RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns
true if the item was not present, false otherwise. bool remove(int val) Removes
an item val from the set if present. Returns true if the item was present, false
otherwise. int getRandom() Returns a random element from the current set of
elements (it's guaranteed that at least one element exists when this method is
called). Each element must have the same probability of being returned. You must
implement the functions of the class such that each function works in average
O(1) time complexity.



Example 1:
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert",
"getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output [null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted
successfully. randomizedSet.remove(2); // Returns false as 2 does not exist in
the set. randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now
contains [1,2]. randomizedSet.getRandom(); // getRandom() should return either 1
or 2 randomly. randomizedSet.remove(1); // Removes 1 from the set, returns true.
Set now contains [2]. randomizedSet.insert(2); // 2 was already in the set, so
return false. randomizedSet.getRandom(); // Since 2 is the only number in the
set, getRandom() will always return 2.


Constraints:
-2^31 <= val <= 2^31 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is
called. */

#include <algorithm>
#include <cassert>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
 public:
  vector<int> vals;
  unordered_map<int, int> idxs;

  mt19937 gen;

  RandomizedSet() : gen(random_device{}()) { vals.reserve(10000); }

  bool insert(int val) {
    if (idxs.count(val)) return false;

    vals.push_back(val);
    idxs[val] = vals.size() - 1;

    return true;
  }

  bool remove(int val) {
    if (!idxs.count(val)) return false;

    int idx = idxs[val];
    int last = vals.back();

    vals[idx] = last;
    idxs[last] = idx;

    vals.pop_back();
    idxs.erase(val);

    return true;
  }

  int getRandom() {
    uniform_int_distribution<int> dist(0, idxs.size() - 1);
    return vals[dist(gen)];
  }
};

int main() {
  RandomizedSet* set = new RandomizedSet();

  bool ret0 = set->insert(1);
  bool ret1 = set->remove(2);
  bool ret2 = set->insert(2);
  int ret3 = set->getRandom();

  bool ret4 = set->remove(1);
  bool ret5 = set->insert(2);

  int ret6 = set->getRandom();

  assert(ret0 == true);
  assert(ret1 == false);
  assert(ret2 == true);
  assert(ret3 == 1 || ret3 == 2);
  assert(ret4 == true);
  assert(ret5 == false);
  assert(ret6 == 2);
}