/**
 * 694. Number of Distinct Islands
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * An island is considered to be the same as another if and only if one island can be translated
 * (and not rotated or reflected) to equal the other
 *
 * Return the number of distinct islands.
 *
 * Example 1:
 * Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
 * Output: 1
 *
 * Example 2:
 * Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
 * Output: 3
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 **/

// prettier-ignore
// right, down, left, up
const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];

function dfs(
  r_orig: number,
  c_orig: number,
  r: number,
  c: number,
  grid: number[][],
  visited: boolean[][],
  island: number[][]
) {
  visited[r][c] = true;
  island.push([r - r_orig, c - c_orig]);

  for (let i = 0; i < 4; ++i) {
    const next_r = r + directions[i][0];
    const next_c = c + directions[i][1];

    if (next_r < 0 || next_r >= grid.length || next_c < 0 || next_c >= grid[0].length) continue;
    if (visited[next_r][next_c] || !grid[next_r][next_c]) continue;

    dfs(r_orig, c_orig, next_r, next_c, grid, visited, island);
  }

  return island;
}

function numDistinctIslands(grid: number[][]): number {
  const visited: boolean[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(false));
  const islands: Set<string> = new Set();

  for (let r = 0; r < grid.length; ++r) {
    for (let c = 0; c < grid[0].length; ++c) {
      if (visited[r][c] || grid[r][c] === 0) continue;

      const island = dfs(r, c, r, c, grid, visited, []);

      island.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        return a[1] - b[1];
      });

      islands.add(JSON.stringify(island));
    }
  }

  return islands.size;
}

export { numDistinctIslands };
