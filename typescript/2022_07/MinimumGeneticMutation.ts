/** 433. Minimum Genetic Mutation */
/** A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
 *  Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is
 *  defined as one single character changed in the gene string.
 *
 *  For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
 *  There is also a gene bank bank that records all the valid gene mutations.
 *  A gene must be in bank to make it a valid gene string.
 *
 *  Given the two gene strings start and end and the gene bank bank, return the minimum number of
 *  mutations needed to mutate from start to end. If there is no such a mutation, return -1.
 *  Note that the starting point is assumed to be valid, so it might not be included in the bank.
 *
 *  Example 1:
 *  Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 *  Output: 1
 *
 *  Example 2:
 *  Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
 *  Output: 2
 *
 *  Example 3:
 *  Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
 *  Output: 3
 *
 *  Constraints:
 *  start.length == 8
 *  end.length == 8
 *  0 <= bank.length <= 10
 *  bank[i].length == 8
 *  start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T']. */

function mutateOnce(start: string, end: string) {
  let diff = 0;

  for (let i = 0; i < start.length; ++i) {
    if (start.charAt(i) !== end.charAt(i)) diff++;
    if (diff > 1) return false;
  }

  return diff === 1;
}

function getEdges(vertices: string[]) {
  const edges: number[][] = new Array(vertices.length).fill(0).map(() => []);

  for (let i = 0; i < vertices.length; ++i) {
    for (let j = i + 1; j < vertices.length; ++j) {
      if (mutateOnce(vertices[i], vertices[j])) {
        edges[i].push(j);
        edges[j].push(i);
      }
    }
  }

  return edges;
}

function bfs(vertices: string[], edges: number[][], end: string) {
  const discovered = new Array<boolean>(vertices.length).fill(false);
  const queue = [0];
  let distance = 0;

  discovered[0] = true;

  while (queue.length > 0) {
    const length = queue.length;

    for (let i = 0; i < length; ++i) {
      const current = queue.shift() as number;
      if (vertices[current] === end) return distance;

      const neighbors = edges[current as number];

      for (const neighbor of neighbors) {
        if (!discovered[neighbor]) {
          queue.push(neighbor);
          discovered[neighbor] = true;
        }
      }
    }

    distance++;
  }

  return -1;
}

function minMutation(start: string, end: string, bank: string[]): number {
  const vertices = [start, ...bank];
  const edges = getEdges(vertices);
  const distance = bfs(vertices, edges, end);

  return distance;
}

export { minMutation };
