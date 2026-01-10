/** 59. Spiral Matrix II */
/** Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 *
 *  Example 1:
 *  Input: n = 3
 *  Output: [[1,2,3],[8,9,4],[7,6,5]]
 *
 *  Example 2:
 *  Input: n = 1
 *  Output: [[1]]
 *
 *  Constraints:
 *  1 <= n <= 20 */

// right, down, left, up
const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];

function isOutOfBoundary(row: number, col: number, matrix: number[][]) {
  return (
    row < 0 ||
    row > matrix.length - 1 ||
    col < 0 ||
    col > matrix[0].length - 1 ||
    matrix[row][col] !== -1
  );
}

function generateMatrix(n: number): number[][] {
  const matrix = new Array(n).fill(-1).map(() => new Array(n).fill(-1));
  let current = 1;
  let direction = 0;
  let row = 0;
  let col = 0;

  while (current <= n * n) {
    let nextRow = row + dr[direction];
    let nextCol = col + dc[direction];

    matrix[row][col] = current;

    if (isOutOfBoundary(nextRow, nextCol, matrix)) {
      direction = (direction + 1) % 4;
      nextRow = row + dr[direction];
      nextCol = col + dc[direction];
    }

    row = nextRow;
    col = nextCol;
    current++;
  }

  return matrix;
}

export { generateMatrix };
