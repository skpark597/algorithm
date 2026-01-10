/* 787. Cheapest Flights Within K Stops */
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

/* Time Limit Exceeded 된 풀이... 그래도 logic은 맞지 않을까 생각한다 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits.h>

using namespace std;

//cost, node, stopcount
vector<pair<int,int>> adj[100];
int dist[100];

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    priority_queue<tuple<int, int, int>> pq;
    int stopCount = 0;

    fill(dist, dist+100, INT_MAX);

    for (int i = 0; i < 100; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < flights.size(); ++i) {
        adj[flights[i][0]].push_back(make_pair(flights[i][2], flights[i][1]));
    }

    pq.push(make_tuple(0, src, 0));
    while (!pq.empty()) {
        int cost = -get<0>(pq.top());
        int here = get<1>(pq.top());
        int stopCount = get<2>(pq.top());
        pq.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].second;
            int nextDist = cost + adj[here][i].first;

            if (stopCount <= K) {
                pq.push(make_tuple(-nextDist, there, stopCount+1));
                dist[there] = min(nextDist, dist[there]);
            }
        }
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



