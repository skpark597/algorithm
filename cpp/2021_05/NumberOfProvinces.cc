/** 547. Number of Provinces */
/** There are n cities. Some of them are connected, while some are not. 
 *  If city a is connected directly with city b, and city b is connected directly with city c, 
 *  then city a is connected indirectly with city c.
 * 
 *  A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 *  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city 
 *  are directly connected, and isConnected[i][j] = 0 otherwise.
 *  
 *  Return the total number of provinces.
 * 
 *  Example 1:
 *  Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 *  Output: 2
 * 
 *  Example 2:
 *  Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 *  Output: 3
 * 
 *  Constraints:
 *  1 <= n <= 200
 *  n == isConnected.length
 *  n == isConnected[i].length
 *  isConnected[i][j] is 1 or 0.
 *  isConnected[i][i] == 1
 *  isConnected[i][j] == isConnected[j][i] **/

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 200;
int parent[MAX_SIZE];
bool isRoot[MAX_SIZE];

void init() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        parent[i] = i;
    }

    memset(isRoot, false, sizeof(isRoot));
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    } 
    
    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int findCircleNum(vector<vector<int>> &isConnected) {
    int answer = 0;

    init();

    for (int i = 0; i < isConnected.size(); ++i) {
        for (int j = i+1; j < isConnected[0].size(); ++j) {
            if (isConnected[i][j] == 1) unionSet(i,j);
        }
    }

    for (int i = 0; i < isConnected.size(); ++i) {
        int root = find(i);
        if (!isRoot[root]) {
            isRoot[root] = true;
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> isConnected0 {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> isConnected1 {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> isConnected2 {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

    int ans0 = findCircleNum(isConnected0);
    int ans1 = findCircleNum(isConnected1);
    int ans2 = findCircleNum(isConnected2);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 3
    cout << ans2 << endl; // 1

    return 0;
}
