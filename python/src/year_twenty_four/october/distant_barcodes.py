"""
1054. Distant Barcodes
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal.
You may return any answer, and it is guaranteed an answer exists.

Example 1:
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

Example 2:
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]

Constraints:
1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
"""

import heapq
from collections import Counter


class Solution:
    def rearrange_barcodes(self, barcodes: list[int]) -> list[int]:
        result, freqs = [], Counter(barcodes)
        max_heap = [(-freq, barcode) for barcode, freq in freqs.items()]

        heapq.heapify(max_heap)

        prev_freq = prev_barcode = 0

        while max_heap:
            freq, barcode = heapq.heappop(max_heap)
            result.append(barcode)

            if prev_freq < 0:
                heapq.heappush(max_heap, (prev_freq, prev_barcode))

            prev_freq = freq + 1
            prev_barcode = barcode

        return result
