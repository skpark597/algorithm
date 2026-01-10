/* 310. Minimum Height Trees */
/** A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
 *  Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between 
 *  the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. 
 *  Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
 *  Return a list of all MHTs' root labels. You can return the answer in any order.
 *  The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 * 
 *  Example 1:
 *  Input: n = 4, edges = [[1,0],[1,2],[1,3]]
 *  Output: [1]
 *  Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
 * 
 *  Example 2:
 *  Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 *  Output: [3,4]
 * 
 *  Example 3:
 *  Input: n = 1, edges = []
 *  Output: [0]
 * 
 *  Example 4:
 *  Input: n = 2, edges = [[0,1]]
 *  Output: [0,1]
 * 
 *  Constraints:
 *  1 <= n <= 2 * 104
 *  edges.length == n - 1
 *  0 <= ai, bi < n
 *  ai != bi
 *  All the pairs (ai, bi) are distinct.
 *  The given input is guaranteed to be a tree and there will be no repeated edges. **/

/* tree의 centroid가 root 일 때, MHT 라고 생각했으나 반례가 있었음. 아래는 잘못된 풀이 */

#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

vector<int> size;
vector<int> height;
vector<vector<int>> adj;

int getSize (int here, int dad) {
    size[here] = 1;

    for (int there : adj[here]) {
        if (there == dad) continue;
        size[here] += getSize(there, here);
    }

    return size[here];
}

int getHeight (int here, int dad) {
    height[here] = 0;

    for (int there : adj[here]) {
        if (there == dad) continue;
        height[here] = max (height[here], getHeight(there, here));
    }

    return height[here]+1;
}

int getCentroid (int here, int dad, int cap) {
    
    for (int there : adj[here]) {
        if (there == dad) continue;
        if (size[there] > cap) return getCentroid(there, here, cap);
    }

    return here;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> answer;
    int root = 1;
    int centroid;
    int maxNeighbor = INT_MIN;

    if (n==1 || edges.empty()) return vector<int> {0};

    adj.resize(n);
    size.resize(n);
    height.resize(n);

    for (int i = 0; i < edges.size(); ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    getSize(root, -1);
    centroid = getCentroid(root, -1, size[root]/2);
    getHeight(centroid, -1);

    for (int there : adj[centroid]) {
        maxNeighbor = max(maxNeighbor, height[there]);
    }

    for (int there : adj[centroid]) {
        if (maxNeighbor == height[there]) {
            answer.push_back(there);
        }
    }

    if (answer.size() != 1) {
        answer.clear();
    }

    answer.push_back(centroid);

    return answer;
}

int main() {
    int n = 6;
    vector<int> edge1 {0,1};
    vector<int> edge2 {0,2};
    vector<int> edge3 {0,3};
    vector<int> edge4 {3,4};
    vector<int> edge5 {4,5};
    //vector<int> edge1 {3,0};
    //vector<int> edge2 {3,1};
    //vector<int> edge3 {3,2};
    //vector<int> edge4 {3,4};
    //vector<int> edge5 {5,4};
    //vector<int> edge1 {0,1};
    //vector<int> edge2 {0,2};
    vector<vector<int>> edges {edge1, edge2, edge3, edge4, edge5};
    //vector<vector<int>> edges {edge1, edge2};

    vector<int> answer = findMinHeightTrees(n, edges);

    for (int iter : answer) {
        cout << iter << endl;
    }

    return 0;
}



