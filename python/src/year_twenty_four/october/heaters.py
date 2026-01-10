"""
475. Heaters
Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
Every house can be warmed, as long as the house is within the heater's warm radius range.
Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
Notice that all the heaters follow your radius standard, and the warm radius will the same.


Example 1:
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.

Example 3:
Input: houses = [1,5], heaters = [2]
Output: 3

Constraints:
1 <= houses.length, heaters.length <= 3 * 10^4
1 <= houses[i], heaters[i] <= 10^9
"""


class Solution:
    def is_covered(self, houses: list[int], heaters: list[int], radius: int) -> bool:
        i = k = 0

        while i < len(houses):
            if houses[i] < heaters[k] - radius:
                return False

            if houses[i] > heaters[k] + radius:
                k += 1

                if k == len(heaters):
                    return False

            else:
                i += 1

        return True

    def find_radius(self, houses: list[int], heaters: list[int]) -> int:
        left, right = 0, int(1e9)

        houses.sort()
        heaters.sort()

        while left <= right:
            radius = (left + right) // 2

            if self.is_covered(houses, heaters, radius):
                right = radius - 1
            else:
                left = radius + 1

        return left
