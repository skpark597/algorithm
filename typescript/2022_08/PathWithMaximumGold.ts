/** 1219. Path with Maximum Gold */
/** In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell,
 *  0 if it is empty.
 *
 *  Return the maximum amount of gold you can collect under the conditions:
 *
 *  Every time you are located in a cell you will collect all the gold in that cell.
 *  From your position, you can walk one step to the left, right, up, or down.
 *  You can't visit the same cell more than once.
 *  Never visit a cell with 0 gold.
 *  You can start and stop collecting gold from any position in the grid that has some gold.
 *
 *  Example 1:
 *  Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
 *  Output: 24
 *  Explanation:
 *  [[0,6,0],
 *   [5,8,7],
 *   [0,9,0]]
 *  Path to get the maximum gold, 9 -> 8 -> 7.
 *
 *  Example 2:
 *  Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
 *  Output: 28
 *  Explanation:
 *  [[1,0,7],
 *   [2,0,6],
 *   [3,4,5],
 *   [0,3,0],
 *   [9,0,20]]
 *  Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 *
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 15
 *  0 <= grid[i][j] <= 100
 *  There are at most 25 cells containing gold. */

// up, right, down, left
const dc = [1, 0, -1, 0];
const dr = [0, 1, 0, -1];
const directionCount = dc.length;

function canVisit(
  r: number,
  c: number,
  grid: number[][],
  visited: boolean[][]
) {
  const rowLength = visited.length;
  const columnLength = visited[0].length;

  if (r < 0 || r >= rowLength || c < 0 || c >= columnLength) return false;
  if (grid[r][c] === 0 || visited[r][c]) return false;

  return true;
}

function backtracking(
  grid: number[][],
  row: number,
  column: number,
  visited: boolean[][],
  previoudGold: number
) {
  const currentGold = previoudGold + grid[row][column];
  let maxGold = currentGold;
  visited[row][column] = true;

  for (let i = 0; i < directionCount; ++i) {
    const newRow = row + dr[i];
    const newColumn = column + dc[i];

    if (canVisit(newRow, newColumn, grid, visited)) {
      const nextGold = backtracking(
        grid,
        newRow,
        newColumn,
        visited,
        currentGold
      );

      maxGold = Math.max(maxGold, nextGold);
    }
  }

  visited[row][column] = false;
  return maxGold;
}

function getMaximumGold(grid: number[][]): number {
  const rowLength = grid.length;
  const columnLength = grid[0].length;
  const visited = new Array(rowLength)
    .fill(false)
    .map(() => new Array(columnLength).fill(false));
  let maxGold = 0;

  for (let row = 0; row < rowLength; ++row) {
    for (let column = 0; column < columnLength; ++column) {
      if (grid[row][column] === 0) continue;
      const gold = backtracking(grid, row, column, visited, 0);

      maxGold = Math.max(maxGold, gold);
    }
  }

  return maxGold;
}

export { getMaximumGold };
