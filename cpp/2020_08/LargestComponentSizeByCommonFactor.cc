/* 952. Largest Component Size by Common Factor */
/** Given a non-empty array of unique positive integers A, consider the following graph:
 *  There are A.length nodes, labelled A[0] to A[A.length - 1];
 *  There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
 *  Return the size of the largest connected component in the graph.
 * 
 *  Example 1:
 *  Input: [4,6,15,35]
 *  Output: 4
 * 
 *  Example 2:
 *  Input: [20,50,9,63]
 *  Output: 2
 * 
 *  Example 3:
 *  Input: [2,3,6,7,4,12,21,39]
 *  Output: 8
 * 
 *  Note:
 *  1 <= A.length <= 20000
 *  1 <= A[i] <= 100000 */

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

int gcd (int a, int b) {
    int bigger = max (a,b);
    int smaller = min (a,b);
    int remainder = bigger % smaller;

    if (remainder == 0) {
        return smaller;
    }

    return gcd (smaller, remainder);
}

void makeGraph(vector<int> &A) {
    int size = A.size();
    adj.resize(size, std::vector<int>());
    visited.resize(size, false);

    for (int i=0; i < size; ++i) {
        for (int j=i+1; j < size; ++j) {
            if (gcd (A[i], A[j]) > 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

void dfs (int index, int &length) {
    if (visited[index]) return;

    int next;
    visited[index] = true;
    length++;

    for (int i=0; i < adj[index].size(); ++i) {
        next = adj[index][i];
        if (!visited[next]) dfs(next, length);
    }
}

int largestComponentSize(vector<int>& A) {
    int answer = 0;
    makeGraph(A);

    for (int i=0; i < adj.size(); ++i) {
        int length =0;
        dfs (i, length);
        answer = max (answer, length);
    }

    return answer;
}

int main() {
    vector<int> A {2,3,6,7,4,12,21,39};
    int answer = largestComponentSize(A);
    cout << answer << endl;

    return 0;
}







