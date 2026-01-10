/** 1254. Number of Closed Islands */
/** Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island
 *  totally (all left, top, right, bottom) surrounded by 1s.
 *
 *  Return the number of closed islands.
 *
 *  Example 1:
 *  Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 *  Output: 2
 *  Explanation:
 *  Islands in gray are closed because they are completely surrounded by water (group of 1s).
 *
 *  Example 2:
 *  Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 *  Output: 1
 *
 *  Example 3:
 *  Input: grid = [[1,1,1,1,1,1,1],
 *                 [1,0,0,0,0,0,1],
 *                 [1,0,1,1,1,0,1],
 *                 [1,0,1,0,1,0,1],
 *                 [1,0,1,1,1,0,1],
 *                 [1,0,0,0,0,0,1],
 *                 [1,1,1,1,1,1,1]]
 *  Output: 2
 *  Constraints:
 *  1 <= grid.length, grid[0].length <= 100
 *  0 <= grid[i][j] <=1 */

// up, right, down, left
const dc = [0, 1, 0, -1];
const dr = [-1, 0, 1, 0];
const directionCount = dc.length;

function isCorner(row: number, column: number, grid: number[][]) {
  const height = grid.length;
  const width = grid[0].length;

  return (
    row === 0 || row === height - 1 || column === 0 || column === width - 1
  );
}

function isOutOfBoundary(row: number, column: number, grid: number[][]) {
  const height = grid.length;
  const width = grid[0].length;

  return row < 0 || row >= height || column < 0 || column >= width;
}

function visitConnectedLands(
  row: number,
  column: number,
  grid: number[][],
  visited: boolean[][]
): number {
  if (grid[row][column] === 1 || visited[row][column]) return 0;

  visited[row][column] = true;

  for (let i = 0; i < directionCount; ++i) {
    const nextRow = row + dr[i];
    const nextColumn = column + dc[i];

    if (isOutOfBoundary(nextRow, nextColumn, grid)) continue;
    visitConnectedLands(nextRow, nextColumn, grid, visited);
  }

  return 1;
}

function countOfCornerLands(grid: number[][], visited: boolean[][]) {
  const height = grid.length;
  const width = grid[0].length;
  let count = 0;

  for (let row = 0; row < height; ++row) {
    count += visitConnectedLands(row, 0, grid, visited);
    count += visitConnectedLands(row, width - 1, grid, visited);
  }

  for (let column = 0; column < width; ++column) {
    count += visitConnectedLands(0, column, grid, visited);
    count += visitConnectedLands(height - 1, column, grid, visited);
  }

  return count;
}

function countOfInnerLands(grid: number[][], visited: boolean[][]) {
  const height = grid.length;
  const width = grid[0].length;
  let count = 0;

  for (let row = 0; row < height; ++row) {
    for (let column = 0; column < width; ++column) {
      if (isCorner(row, column, grid)) continue;
      count += visitConnectedLands(row, column, grid, visited);
    }
  }

  return count;
}

function closedIsland(grid: number[][]): number {
  const height = grid.length;
  const width = grid[0].length;
  const visited: boolean[][] = new Array(height)
    .fill(false)
    .map(() => new Array(width).fill(false));

  countOfCornerLands(grid, visited);
  return countOfInnerLands(grid, visited);
}

export { closedIsland };
