/** 374. Guess Number Higher or Lower */
/** We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I will tell you whether the number I picked is
 * higher or lower than your guess.
 * You call a pre-defined API int guess(int num), which returns three possible
 * results:
 *
 * -1: Your guess is higher than the number I picked (i.e. num > pick).
 * 1: Your guess is lower than the number I picked (i.e. num < pick).
 * 0: your guess is equal to the number I picked (i.e. num == pick).
 *
 * Return the number that I picked.
 * Example 1:
 * Input: n = 10, pick = 6
 * Output: 6
 *
 * Example 2:
 * Input: n = 1, pick = 1
 * Output: 1
 *
 * Example 3:
 * Input: n = 2, pick = 1
 * Output: 1
 *
 * Constraints:
 * 1 <= n <= 2^31 - 1
 * 1 <= pick <= n */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <iostream>
#include <vector>

using namespace std;

int pick = 0;

int guess(int num) {
  if (num < pick) {
    return 1;
  } else if (num > pick) {
    return -1;
  }

  return 0;
}

int guessNumber(int n) {
  long long left = 1;
  long long right = n;

  while (left <= right) {
    long long middle = left + (right - left) / 2;
    int diff = guess(middle);

    if (diff == 1) {
      left = middle + 1;
    } else if (diff == -1) {
      right = middle - 1;
    } else {
      return middle;
    }
  }

  return left;
}

int main() {
  pick = 6;
  int ans0 = guessNumber(10);

  pick = 1;
  int ans1 = guessNumber(1);

  pick = 1;
  int ans2 = guessNumber(2);

  cout << ans0 << endl; // 6
  cout << ans1 << endl; // 1
  cout << ans2 << endl; // 1

  return 0;
}
