/*
   CSES - Shortest Routes II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n cities and m roads between them. Your task is to process q
   queries where you have to determine the length of the shortest route
   between two given cities.

Input

   The first input line has three integers n, m and q: the number of
   cities, roads, and queries.

   Then, there are m lines describing the roads. Each line has three
   integers a, b and c: there is a road between cities a and b whose
   length is c. All roads are two-way roads.

   Finally, there are q lines describing the queries. Each line has two
   integers a and b: determine the length of the shortest route between
   cities a and b.

Output

   Print the length of the shortest route for each query. If there is no
   route, print -1 instead.

Constraints

     * 1 ≤ n ≤ 500
     * 1 ≤ m ≤ n^2
     * 1 ≤ q ≤ 10^5
     * 1 ≤ a,b ≤ n
     * 1 ≤ c ≤ 10^9

Example

   Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

   Output:
5
5
8
-1
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q; cin >> n >> m >> q;
  auto G = vector<vector<ll>>(n, vector<ll>(n, INF));
  while (m--) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--, v--;
    G[u][v] = min(G[u][v], w);
    G[v][u] = min(G[v][u], w);
  }
  for (int i = 0; i < n; i++)
    G[i][i] = 0;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

  while (q--) {
    int u, v; cin >> u >> v;
    u--, v--;
    if (G[u][v] == INF)
      cout << -1 << '\n';
    else
      cout << G[u][v] << '\n';
  }
}
