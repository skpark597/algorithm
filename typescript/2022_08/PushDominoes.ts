/** 838. Push Dominoes */
/** There are n dominoes in a line, and we place each domino vertically upright.
 *  In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
 *  After each second, each domino that is falling to the left pushes the adjacent domino on the left.
 *  Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
 *  When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of
 *  the forces.
 *  For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
 *  You are given a string dominoes representing the initial state where:
 *  dominoes[i] = 'L', if the ith domino has been pushed to the left,
 *  dominoes[i] = 'R', if the ith domino has been pushed to the right, and
 *  dominoes[i] = '.', if the ith domino has not been pushed.
 *
 *  Return a string representing the final state.
 *
 *  Example 1:
 *  Input: dominoes = "RR.L"
 *  Output: "RR.L"
 *  Explanation: The first domino expends no additional force on the second domino.
 *
 *  Example 2:
 *  Input: dominoes = ".L.R...LR..L.."
 *  Output: "LL.RR.LLRRLL.."
 *
 *  Constraints:
 *  n == dominoes.length
 *  1 <= n <= 10^5
 *  dominoes[i] is either 'L', 'R', or '.'.  */

function replaceDominoes(
  dominoes: string,
  start: number,
  end: number,
  letter: string
) {
  if (start > end) return dominoes;

  let letters = "";

  for (let i = start; i < end; ++i) {
    letters += letter;
  }

  return dominoes.substring(0, start) + letters + dominoes.substring(end);
}

function pushDominoes(dominoes: string): string {
  if (dominoes.length === 0) return "";

  let start = 0;
  let result = dominoes;

  for (let end = 0; end <= dominoes.length; ++end) {
    const startLetter = dominoes.charAt(start);
    const currentLetter =
      end < dominoes.length ? dominoes.charAt(end) : undefined;

    if (startLetter === "L" || (startLetter === "." && currentLetter === "R")) {
      start = end;
    } else if (startLetter === "R" && currentLetter === "L") {
      let endR: number;
      let startL: number;

      if ((start + end) % 2 === 0) {
        endR = (start + end) / 2;
        startL = endR + 1;
      } else {
        endR = Math.ceil((start + end) / 2);
        startL = endR;
      }

      result = replaceDominoes(result, start + 1, endR, "R");
      result = replaceDominoes(result, startL, end, "L");
      start = end;
    } else if (
      (startLetter === "R" && currentLetter === "R") ||
      (startLetter === "R" && currentLetter === undefined)
    ) {
      result = replaceDominoes(result, start + 1, end, "R");
      start = end;
    } else if (startLetter === "." && currentLetter === "L") {
      result = replaceDominoes(result, start, end, "L");
      start = end;
    }
  }

  return result;
}

export { pushDominoes };
