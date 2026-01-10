/* 785. Is Graph Biparitite? */
/** Given an undirected graph, return true if and only if it is bipartite.
 *  Recall that a graph is bipartite if we can split its set of nodes into two independent subsets A and B, 
 *  such that every edge in the graph has one node in A and another node in B.
 *  The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
 *  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, 
 *  and it doesn't contain any element twice.
 *  
 *  Example 1:
 *  Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 *  Output: true
 *  Explanation: We can divide the vertices into two groups: {0, 2} and {1, 3}.
 * 
 *  Example 2:
 *  Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 *  Output: false
 *  Explanation: We cannot find a way to divide the set of nodes into two independent subsets.
 * 
 *  Constraints:
 *  1 <= graph.length <= 100
 *  0 <= graph[i].length < 100
 *  0 <= graph[i][j] <= graph.length - 1
 *  graph[i][j] != i
 *  All the values of graph[i] are unique.
 *  The graph is guaranteed to be undirected. **/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

enum color {RED, BLACK};
int vColors[100];
int count;
bool biparitie;

void dfs(int vertex, int vColor, vector<vector<int>> &adj) {
    if (vColors[vertex] != -1 || adj.size() == count) return;
    vColors[vertex] = vColor;
    count++;

    for (int i = 0; i < adj[vertex].size(); ++i) {
        int neighbor = adj[vertex][i];
        if (vColors[neighbor] == -1) {
            dfs (neighbor, (vColor+1)%2, adj);
        } else if (vColors[neighbor] == vColor) {
            biparitie = false;
            return;
        }
    }

}

bool isBipartite(vector<vector<int>> &graph) {
    memset (vColors, -1, sizeof(vColors));
    count = 0;
    biparitie = true;

    for (int i = 0; i < graph.size(); ++i) {
        if (count == graph.size()) break;
        dfs(i, RED, graph);
    }

    return biparitie;
}

int main() {
    vector<int> edge0 {1,3};
    vector<int> edge1 {0,2};
    vector<int> edge2 {1,3};
    vector<int> edge3 {0,2};
    vector<vector<int>> graph0 {edge0, edge1, edge2, edge3};

    vector<int> edge00 {1,2,3};
    vector<int> edge01 {0,2};
    vector<int> edge02 {0,1,3};
    vector<int> edge03 {0,2};
    vector<vector<int>> graph1 {edge00, edge01, edge02, edge03};

    [[1],[0],[4],[4],[2,3]]

    bool ans0 = isBipartite(graph0);
    bool ans1 = isBipartite(graph1);

    cout << ans0 << endl;
    cout << ans1 << endl;

    return 0;
}


