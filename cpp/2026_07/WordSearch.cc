/**79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or
vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board? */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

// right, down, left, up
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int r, int c, int i) {
  if (i == word.size()) return true;
  if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] != word[i])
    return false;

  visited[r][c] = true;

  for (int j = 0; j < 4; ++j) {
    int nr = r + dr[j], nc = c + dc[j];
    if (backtracking(board, visited, word, nr, nc, i + 1)) return true;
  }

  visited[r][c] = false;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  int row = board.size(), col = board[0].size();
  vector<vector<bool>> visited(row, vector<bool>(col, false));

  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
      if (backtracking(board, visited, word, r, c, 0)) return true;
    }
  }

  return false;
}

int main() {
  vector<vector<char>> board0{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board1{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board2{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> board3{{'a'}};
  vector<vector<char>> board4{{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};

  string word0 = "ABCCED";
  string word1 = "SEE";
  string word2 = "ABCB";
  string word3 = "a";
  string word4 = "AAB";

  bool ret0 = exist(board0, word0);
  bool ret1 = exist(board1, word1);
  bool ret2 = exist(board2, word2);
  bool ret3 = exist(board3, word3);
  bool ret4 = exist(board4, word4);

  assert(ret0 == true);
  assert(ret1 == true);
  assert(ret2 == false);
  assert(ret3 == true);
  assert(ret4 == true);

  return 0;
}