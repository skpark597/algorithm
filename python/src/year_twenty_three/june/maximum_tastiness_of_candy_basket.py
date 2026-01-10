"""
2517. Maximum Tastiness of Candy Basket
You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.
The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute
difference of the prices of any two candies in the basket.
Return the maximum tastiness of a candy basket.

Example 1:
Input: price = [13,5,1,8,21,2], k = 3
Output: 8
Explanation: Choose the candies with the prices [13,5,21].
The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8.
It can be proven that 8 is the maximum tastiness that can be achieved.

Example 2:
Input: price = [1,3,1], k = 2
Output: 2
Explanation: Choose the candies with the prices [1,3].
The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
It can be proven that 2 is the maximum tastiness that can be achieved.

Example 3:
Input: price = [7,7,7,7], k = 2
Output: 0
Explanation: Choosing any two distinct candies from the candies we have will result in a tastiness of 0.

Constraints:
2 <= k <= price.length <= 10^5
1 <= price[i] <= 10^9
"""


from math import floor
from typing import List


class Solution:
    def maximum_tastiness(self, price: List[int], k: int) -> int:
        prices_sorted, diffs = sorted(price), []

        for i in range(len(prices_sorted) - 1):
            diffs.append(prices_sorted[i + 1] - prices_sorted[i])

        left, right = 0, prices_sorted[len(prices_sorted) - 1] - prices_sorted[0]

        while left <= right:
            middle = left + floor((right - left) / 2)
            sum, count = 0, 0

            for num in diffs:
                sum += num

                if sum >= middle:
                    sum = 0
                    count += 1

            if count >= k - 1:
                left = middle + 1
            else:
                right = middle - 1

        return right
