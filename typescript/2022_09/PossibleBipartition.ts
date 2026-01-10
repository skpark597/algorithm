/** 886. Possible Bipartition */
/** We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people,
 *  and they should not go into the same group.
 *  Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled
 *  ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
 *
 *  Example 1:
 *  Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
 *  Output: true
 *  Explanation: group1 [1,4] and group2 [2,3].
 *
 *  Example 2:
 *  Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
 *  Output: false
 *
 *  Example 3:
 *  Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 *  Output: false
 *
 *  Constraints:
 *  1 <= n <= 2000
 *  0 <= dislikes.length <= 10^4
 *  dislikes[i].length == 2
 *  1 <= dislikes[i][j] <= n
 *  ai < bi
 *  All the pairs of dislikes are unique. */

function getAdjacentList(n: number, edges: number[][]) {
  const adjacentList: number[][] = new Array(n + 1)
    .fill(null)
    .map(() => new Array(0));

  for (const edge of edges) {
    adjacentList[edge[0]].push(edge[1]);
    adjacentList[edge[1]].push(edge[0]);
  }

  return adjacentList;
}

function possibleBipartition(n: number, dislikes: number[][]): boolean {
  const adjacentList = getAdjacentList(n, dislikes);
  const colors = new Array(n + 1).fill(-1);
  const queue: number[] = [];

  for (let vertex = 1; vertex <= n; ++vertex) {
    if (colors[vertex] !== -1) continue;

    colors[vertex] = 0;
    queue.push(vertex);

    while (queue.length > 0) {
      const current = queue.shift() as number;

      for (const neighbor of adjacentList[current]) {
        if (colors[neighbor] === colors[current]) return false;
        if (colors[neighbor] === -1) {
          colors[neighbor] = 1 - colors[current];
          queue.push(neighbor);
        }
      }
    }
  }

  return true;
}

export { possibleBipartition };
