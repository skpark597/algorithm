/* 79. Word Search */
/** Given an m x n board and a word, find if the word exists in the grid.
 *  The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. 
 *  The same letter cell may not be used more than once.
 * 
 *  Example 1:
 *  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 *  Output: true
 * 
 *  Example 2:
 *  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 *  Output: true
 * 
 *  Example 3:
 *  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 *  Output: false
 * 
 *  Constraints:
 *  m == board.length
 *  n = board[i].length
 *  1 <= m, n <= 200
 *  1 <= word.length <= 10^3
 *  board and word consists only of lowercase and uppercase English letters. **/

/** 이거 푸는데 너무 오래 걸렸네... 흑흑 
 *  backTracking 함수에서 vector<vector<char>> &board가 아니라 vector<vector<char>> board
 *  를 사용하면 board의 복사가 매번 일어나서 Time Limit으로 실패한다.*/
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// left, up, right, down
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int boardSize;
bool visited[200][200];

bool backTracking(vector<vector<char>> &board, string &word, int covered, int x, int y) {
    bool ret = false;

    if (y < 0 || y > board.size()-1 || x < 0 || x > board[0].size()-1 
        || board[y][x] != word[covered] || visited[y][x]) return false;

    covered++;
    visited[y][x] = true;
    if (covered > boardSize) return false;
    if (covered == word.length()) return true;

    for (int i = 0; i < 4; ++i) {
        if (!ret) ret = backTracking(board, word, covered, x+dx[i], y+dy[i]);
    }

    visited[y][x] = false;
    return ret;
}

bool exist(vector<vector<char>> &board, string word) {
    bool ret = false;
    if (board.empty()) return false;

    boardSize = board.size() * board[0].size();
    memset(visited, false, sizeof(visited));

    for (int x = 0; x < board[0].size(); ++x) {
        for (int y = 0; y < board.size(); ++y) {
            if (!ret) ret = backTracking(board, word, 0, x, y);
        }
    }

    return ret;
}

int main() {
    vector<char> row01 {'A','B','C','E'};
    vector<char> row02 {'S','F','C','S'};
    vector<char> row03 {'A','D','E','E'};
    vector<vector<char>> board0 {row01, row02, row03};
    string word0 = "ABCCED";

    vector<char> row11 {'A','B','C','E'};
    vector<char> row12 {'S','F','C','S'};
    vector<char> row13 {'A','D','E','E'};
    vector<vector<char>> board1 {row11, row12, row13};
    string word1 = "SEE";

    vector<char> row21 {'A','B','C','E'};
    vector<char> row22 {'S','F','C','S'};
    vector<char> row23 {'A','D','E','E'};
    vector<vector<char>> board2 {row21, row22, row23};
    string word2 = "ABCB";

    vector<char> row31 {'a','a','a','a'};
    vector<char> row32 {'a','a','a','a'};
    vector<char> row33 {'a','a','a','a'};
    vector<vector<char>> board3 {row31, row32, row33};
    string word3 = "aaaaaaaaaaaaa";

    vector<char> row41 {'C','A','A'};
    vector<char> row42 {'A','A','A'};
    vector<char> row43 {'B','C','D'};
    vector<vector<char>> board4 {row41, row42, row43};
    string word4 = "AAB";

    vector<char> row51 {'A','B','C','E'};
    vector<char> row52 {'S','F','E','S'};
    vector<char> row53 {'A','D','E','E'};
    vector<vector<char>> board5 {row51, row52, row53};
    string word5 = "ABCESEEEFS";

    bool ans0 = exist(board0, word0); 
    bool ans1 = exist(board1, word1); 
    bool ans2 = exist(board2, word2); 
    bool ans3 = exist(board3, word3); 
    bool ans4 = exist(board4, word4); 
    bool ans5 = exist(board5, word5); 

    cout << ans0 << endl; // true
    cout << ans1 << endl; // true
    cout << ans2 << endl; // false
    cout << ans3 << endl; // false
    cout << ans4 << endl; // true
    cout << ans5 << endl; // true

    return 0;
}

