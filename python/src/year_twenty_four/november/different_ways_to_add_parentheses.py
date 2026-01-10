"""
241. Different Ways to Add Parentheses
Given a string expression of numbers and operators, return all possible results from computing all the different
possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and
the number of different results does not exceed 104.

Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10


Constraints:
1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
"""


class Solution:
    def calculate(self, a: int, b: int, op: str) -> int:
        if op == "+":
            return a + b
        elif op == "-":
            return a - b
        elif op == "*":
            return a * b

    def diff_ways_to_compute(self, exp: str) -> list[int]:
        if exp.isdigit():
            return [int(exp)]

        result = []

        for i, c in enumerate(exp):
            if c not in "+-*":
                continue

            left_vals = self.diff_ways_to_compute(exp[:i])
            right_vals = self.diff_ways_to_compute(exp[i + 1 :])

            for left_val in left_vals:
                for right_val in right_vals:
                    result.append(self.calculate(left_val, right_val, c))

        return result
