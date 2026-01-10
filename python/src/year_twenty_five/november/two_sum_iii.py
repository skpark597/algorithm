"""
170. Two Sum III - Data structure design
Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.
Implement the TwoSum class:

TwoSum() Initializes the TwoSum object, with an empty array initially.
void add(int number) Adds number to the data structure.
boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.


Example 1:
Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false


Constraints:
-10^5 <= number <= 10^5
-2^31 <= value <= 2^31 - 1
At most 10^4 calls will be made to add and find.
"""

import bisect
from typing import Counter


class TwoSum0:
    def __init__(self):
        self.nums = []

    def add(self, num: int):
        left, right = 0, len(self.nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if self.nums[mid] <= num:
                left = mid + 1
            else:
                right = mid - 1

        self.nums.insert(right + 1, num)

    def find(self, val: int) -> bool:
        def find_num(num: int, left: int, right: int):
            while left <= right:
                mid = (left + right) // 2

                if self.nums[mid] == num:
                    return True
                elif self.nums[mid] < num:
                    left = mid + 1
                else:
                    right = mid - 1

            return False

        for i, num in enumerate(self.nums):
            if find_num(val - num, i + 1, len(self.nums) - 1):
                return True

        return False


class TwoSum1:
    def __init__(self):
        self.nums = []

    def add(self, num: int):
        bisect.insort(self.nums, num)

    def find(self, val: int) -> bool:
        for i, num in enumerate(self.nums):
            diff = val - num
            idx = bisect.bisect_left(self.nums, diff, i + 1)

            if idx < len(self.nums) and self.nums[idx] == diff:
                return True

        return False


class TwoSum2:
    def __init__(self):
        self.counter = Counter()

    def add(self, num: int):
        self.counter[num] += 1

    def find(self, val: int) -> bool:
        for num in self.counter:
            diff = val - num

            if diff not in self.counter:
                continue

            if diff != num or self.counter[num] > 1:
                return True

        return False
