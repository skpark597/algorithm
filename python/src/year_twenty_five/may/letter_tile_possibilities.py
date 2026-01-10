"""
1079. Letter Tile Possibilities
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.


Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188

Example 3:
Input: tiles = "V"
Output: 1


Constraints:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.
"""


class Solution:
    def backtracking(self, tiles: str) -> set:
        if not tiles:
            return {""}

        result = set()
        for i, tile in enumerate(tiles):
            for suffix in self.backtracking(tiles[:i] + tiles[i + 1 :]):
                result.add(suffix)
                result.add(tile + suffix)

        return result

    def num_tile_possibilities(self, tiles: str) -> int:
        return len(self.backtracking(tiles)) - 1
