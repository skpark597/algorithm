"""
Alice and Bob have a different total number of candies.
You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i]
is the number of candies of the ith box of candy that Alice has and bobSizes[j]
is the number of candies of the jth box of candy that Bob has.

Since they are friends, they would like to exchange one candy box
each so that after the exchange, they both have the same total amount of candy.
The total amount of candy a person has is the sum of the number of candies in each box they have.
Return an integer array answer where answer[0] is the number of candies in the box
that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange.
If there are multiple answers, you may return any one of them.
It is guaranteed that at least one answer exists.


Example 1:
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]

Example 2:
Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]

Example 3:
Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]

Constraints:
1 <= aliceSizes.length, bobSizes.length <= 10^4
1 <= aliceSizes[i], bobSizes[j] <= 10^5
Alice and Bob have a different total number of candies.
There will be at least one valid answer for the given input.
"""

from math import floor
from typing import List


class Solution:
    def fair_candy_swap(
        self, alice_sizes: List[int], bob_sizes: List[int]
    ) -> List[int]:
        answer = []
        bob_sorted = sorted(bob_sizes)
        bob_total, alice_total = sum(bob_sizes), sum(alice_sizes)
        desired_size = int((alice_total + bob_total) / 2)

        for alice_sent in alice_sizes:
            alice_received = desired_size - alice_total + alice_sent
            left, right, found = 0, len(bob_sorted) - 1, False

            while left <= right:
                middle = left + floor((right - left) / 2)
                candies = bob_sorted[middle]

                if candies > alice_received:
                    right = middle - 1
                elif candies < alice_received:
                    left = middle + 1
                elif candies == alice_received:
                    found = True
                    break

            if found:
                answer = [alice_sent, alice_received]
                break

        return answer
