"""
826. Most Profit Assigning Work
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker
(i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3.
If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.


Example 1:
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.

Example 2:
Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0

Constraints:
n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 10^4
1 <= difficulty[i], profit[i], worker[i] <= 10^5
"""


class Solution:
    def max_profit_assignment(self, difficulties: list[int], profits: list[int], workers: list[int]) -> int:
        profit_table, max_profit = {}, 0

        for difficulty, profit in sorted(zip(difficulties, profits)):
            max_profit = max(max_profit, profit)
            profit_table[difficulty] = max_profit

        difficulties.sort()
        workers.sort()

        left, right, result = 0, 0, 0

        for worker in workers:
            left, right = max(0, right), len(difficulties) - 1
            first_left = left

            while left <= right:
                middle = left + int((right - left) / 2)

                if difficulties[middle] <= worker:
                    left = middle + 1
                else:
                    right = middle - 1

            if right >= first_left:
                result += profit_table[difficulties[right]]

        return result
