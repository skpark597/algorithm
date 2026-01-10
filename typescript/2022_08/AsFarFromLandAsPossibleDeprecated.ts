/** 1162. As Far from Land as Possible */
/** Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land,
 *  find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
 *  If no land or water exists in the grid, return -1.
 *
 *  The distance used in this problem is the Manhattan distance:
 *  the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 *
 *  Example 1:
 *  Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
 *  Output: 2
 *  Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
 *
 *  Example 2:
 *  Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
 *  Output: 4
 *  Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 *
 *  Constraints:
 *  n == grid.length
 *  n == grid[i].length
 *  1 <= n <= 100
 *  grid[i][j] is 0 or 1 */

// up, right, down, left
const dr = [-1, 0, 1, 0];
const dc = [0, 1, 0, -1];
const directionCount = dr.length;

function isAllWaterOrLand(grid: number[][]) {
  const length = grid.length;
  const value = grid[0][0];

  for (let row = 0; row < grid.length; ++row) {
    for (let column = 0; column < grid[0].length; ++column) {
      if (grid[row][column] !== value) return false;
    }
  }

  return true;
}

function isNextDestination(
  row: number,
  column: number,
  grid: number[][],
  discovered: boolean[][]
) {
  const length = grid.length;

  if (row < 0 || row >= length || column < 0 || column >= length) return false;
  if (discovered[row][column]) return false;

  return true;
}

function distanceToNearestLand(row: number, column: number, grid: number[][]) {
  const queue: number[][] = [[row, column]];
  const length = grid.length;
  const discovered = new Array(length)
    .fill(false)
    .map(() => new Array(length).fill(false));
  let arrivedLand = false;
  let distance = 0;

  discovered[row][column] = true;

  while (queue.length > 0) {
    const count = queue.length;

    for (let i = 0; i < count; ++i) {
      const coordinate = queue.shift() as number[];
      const row = coordinate[0];
      const column = coordinate[1];

      if (grid[row][column] === 1) {
        arrivedLand = true;
        break;
      }

      for (let j = 0; j < directionCount; ++j) {
        const nextRow = row + dr[j];
        const nextColumn = column + dc[j];

        if (isNextDestination(nextRow, nextColumn, grid, discovered)) {
          discovered[nextRow][nextColumn] = true;
          queue.push([nextRow, nextColumn]);
        }
      }
    }

    if (arrivedLand) break;
    distance++;
  }

  return distance;
}

function maxDistanceDeprecated(grid: number[][]): number {
  let maximum = 0;

  if (isAllWaterOrLand(grid)) return -1;

  for (let row = 0; row < grid.length; ++row) {
    for (let column = 0; column < grid[0].length; ++column) {
      const distance = distanceToNearestLand(row, column, grid);
      maximum = Math.max(maximum, distance);
    }
  }

  return maximum;
}

export { maxDistanceDeprecated };
