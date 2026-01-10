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

type Point = [number, number];

function getDistance(p1: Point, p2: Point) {
  return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
}

function distanceToNearestLand(start: Point, lands: Point[]) {
  let nearest = Number.MAX_SAFE_INTEGER;

  for (const land of lands) {
    const distance = getDistance(start, land);
    nearest = Math.min(nearest, distance);
  }

  return nearest;
}

function maxDistance(grid: number[][]): number {
  const length = grid.length;
  const lands: Point[] = [];
  let maximum = 0;

  for (let row = 0; row < length; ++row) {
    for (let column = 0; column < length; ++column) {
      if (grid[row][column] === 1) lands.push([row, column]);
    }
  }

  if (lands.length === 0 || lands.length === length * length) return -1;

  for (let row = 0; row < length; ++row) {
    for (let column = 0; column < length; ++column) {
      if (grid[row][column] === 0) {
        const distance = distanceToNearestLand([row, column], lands);
        maximum = Math.max(maximum, distance);
      }
    }
  }

  return maximum;
}

export { maxDistance };
