/** 733. Flood Fill  */
/** An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
 *  You are also given three integers sr, sc, and newColor. 
 *  You should perform a flood fill on the image starting from the pixel image[sr][sc].
 * 
 *  To perform a flood fill, consider the starting pixel, plus any pixels 
 *  connected 4-directionally to the starting pixel of the same color as the starting pixel, 
 *  plus any pixels connected 4-directionally to those pixels (also with the same color), 
 *  and so on. Replace the color of all of the aforementioned pixels with newColor.
 * 
 *  Return the modified image after performing the flood fill.
 * 
 *  Example 1:
 *  Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
 *  Output: [[2,2,2],[2,2,0],[2,0,1]]
 *  Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
 *  all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
 *  Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 * 
 *  Example 2:
 *  Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
 *  Output: [[2,2,2],[2,2,2]]
 * 
 *  Constraints:
 *  m == image.length
 *  n == image[i].length
 *  1 <= m, n <= 50
 *  0 <= image[i][j], newColor < 216
 *  0 <= sr < m
 *  0 <= sc < n **/

#include <vector>
#include <iostream>

using namespace std;

bool visited[50][50];
    //  up, right, down, left
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool outOfBoundary(vector<vector<int>> &image, int row, int col) {
    int rowSize = image.size();
    int colSize = image[0].size();
    
    return row < 0 || row >= rowSize || col < 0 || col >= colSize;
}

void dfs(vector<vector<int>> &image, int row, int col, int start, int newColor) {
    visited[row][col] = true;
    image[row][col] = newColor;
    
    for (int i = 0; i < 4; ++i) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        if (outOfBoundary(image, nextRow, nextCol)) continue;
        if (image[nextRow][nextCol] != start || visited[nextRow][nextCol]) continue;
        dfs(image, nextRow, nextCol, start, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int start = image[sr][sc];
    memset(visited, false, sizeof(visited));
    dfs(image, sr, sc, start, newColor);        
    return image;
}

int main() {
    return 0;
}