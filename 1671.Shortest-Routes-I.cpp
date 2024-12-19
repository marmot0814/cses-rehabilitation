/*
   CSES - Shortest Routes I
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n cities and m flight connections between them. Your task is
   to determine the length of the shortest route from Syrjälä to every
   city.

Input

   The first input line has two integers n and m: the number of cities and
   flight connections. The cities are numbered 1,2,...,n, and city 1 is
   Syrjälä.

   After that, there are m lines describing the flight connections. Each
   line has three integers a, b and c: a flight begins at city a, ends at
   city b, and its length is c. Each flight is a one-way flight.

   You can assume that it is possible to travel from Syrjälä to all other
   cities.

Output

   Print n integers: the shortest route lengths from Syrjälä to cities
   1,2,...,n.

Constraints

     * 1 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n
     * 1 ≤ c ≤ 10^9

Example

   Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

   Output:
0 5 2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
const int MOD = 1e9 + 7;

struct Edge {
  int v;
  ll w;
  bool operator> (const Edge &rhs) const {
    return w > rhs.w;
  }
};

const ll INF = 0x3f3f3f3f3f3f3f3f;
vector<ll> dijkstra(auto &G, int s) {
  int n = G.size();
  auto d = vector<ll>(n, INF);
  d[s] = 0;

  auto pq = priority_queue<Edge, vector<Edge>, greater<Edge>>{};
  pq.push({s, 0});
  while (pq.size()) {
    auto [u, w] = pq.top(); pq.pop();
    if (d[u] < w) continue;
    for (auto &[v, c] : G[u]) {
      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        pq.push({v, d[v]});
      }
    }
  }

  return d;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto G = vector<vector<pil>>(n);
  while (m--) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({v, w});
  }
  auto d = dijkstra(G, 0);
  for (int i = 0; i < n; i++)
    cout << d[i] << " \n"[i + 1 == n];
}
