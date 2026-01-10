/* Cheapest Flights Within K Stops */
/** There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
 *  Now given all the cities and flights, together with starting city src and the destination dst, 
 *  your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 * 
 *  Example 1:
 *  Input: n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 *  src = 0, dst = 2, k = 1
 *  Output: 200
 *  Explanation: The graph looks like this:
 *  The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
 * 
 *  Example 2:
 *  Input: n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 *  src = 0, dst = 2, k = 0
 *  Output: 500
 *  Explanation: The graph looks like this:
 *  The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 * 
 *  Constraints:
 *  The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
 *  The size of flights will be in range [0, n * (n - 1) / 2].
 *  The format of each flight will be (src, dst, price).
 *  The price of each flight will be in the range [1, 10000].
 *  k is in the range of [0, n - 1].
 *  There will not be any duplicated flights or self cycles. **/

/* Discussion을 보고 구현함. BFS를 level별로 수행하고, 한 level이 끝날 때 stopCount를 1 증가시키는 방법 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<pair<int,int>> adj[100]; // (node, cost)
int dist[100];

void init(int n, vector<vector<int>> &flights) {
    fill(dist, dist+100, INT_MAX);
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < flights.size(); ++i) {
        adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    queue<pair<int,int>> queue;
    int queueSize;
    int stopCount = 0;

    init(n, flights);
    queue.push(make_pair(src, 0));

    while (stopCount <= K) {
        queueSize = queue.size();

        for (int i = 0; i < queueSize; ++i) {
            int here = queue.front().first;
            int cost = queue.front().second;
            queue.pop();

            for (int j = 0; j < adj[here].size(); ++j) {
                int there = adj[here][j].first;
                int nextDist = cost + adj[here][j].second;

                if (nextDist < dist[there]) {
                    dist[there] = nextDist;
                    queue.push(make_pair(there, nextDist));
                }
            }
        }

        stopCount++;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    vector<int> edge00 {0,1,100};
    vector<int> edge01 {1,2,100};
    vector<int> edge02 {0,2,500};
    vector<vector<int>> edges0 {edge00, edge01, edge02};

    vector<int> edge10 {0,1,100};
    vector<int> edge11 {1,2,100};
    vector<int> edge12 {0,2,500};
    vector<vector<int>> edges1 {edge10, edge11, edge12};
 
    vector<int> edge20 {0,1,1};
    vector<int> edge21 {0,2,5};
    vector<int> edge22 {1,2,1};
    vector<int> edge23 {2,3,1};
    vector<vector<int>> edges2 {edge20, edge21, edge22, edge23};

    vector<int> edge40 {0,1,5};
    vector<int> edge41 {1,2,5};
    vector<int> edge42 {0,3,2};
    vector<int> edge43 {3,1,2};
    vector<int> edge44 {1,4,1};
    vector<int> edge45 {4,2,1};
    vector<vector<int>> edges3 {edge40, edge41, edge42, edge43, edge44, edge45};

    int ans0 = findCheapestPrice(3, edges0, 0, 2, 1);
    int ans1 = findCheapestPrice(3, edges1, 0, 2, 0);
    int ans2 = findCheapestPrice(4, edges2, 0, 3, 1);
    int ans3 = findCheapestPrice(5, edges3, 0, 2, 2);
 
    cout << ans0 << endl; // 200
    cout << ans1 << endl; // 500
    cout << ans2 << endl; // 6
    cout << ans3 << endl; // 7

    return 0;
}


