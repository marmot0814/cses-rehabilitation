/*
   CSES - Flight Discount
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to find a minimum-price flight route from Syrjälä to
   Metsälä. You have one discount coupon, using which you can halve the
   price of any single flight during the route. However, you can only use
   the coupon once.

   When you use the discount coupon for a flight whose price is x, its
   price becomes ⌊ x/2 ⌋ (it is rounded down to an integer).

Input

   The first input line has two integers n and m: the number of cities and
   flight connections. The cities are numbered 1,2,…,n. City 1 is
   Syrjälä, and city n is Metsälä.

   After this there are m lines describing the flights. Each line has
   three integers a, b, and c: a flight begins at city a, ends at city b,
   and its price is c. Each flight is unidirectional.

   You can assume that it is always possible to get from Syrjälä to
   Metsälä.

Output

   Print one integer: the price of the cheapest route from Syrjälä to
   Metsälä.

Constraints

     * 2 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n
     * 1 ≤ c ≤ 10^9

Example

   Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

   Output:
2
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
auto dijkstra(auto &G, int s) {
  int n = G.size();
  auto pq = priority_queue<Edge, vector<Edge>, greater<Edge>>{};
  auto d = vector<ll>(n, INF);
  d[s] = 0;
  pq.push({s, 0});

  while (pq.size()) {
    auto [u, s] = pq.top(); pq.pop();
    if (d[u] < s) continue;
    for (auto &[v, w] : G[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push({v, d[v]});
      }
    }
  }

  return d;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto G = vector<vector<pil>>(n * 2);
  while (m--) {
    int u, v; ll w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({v, w});
    G[u + n].push_back({v + n, w});
    G[u].push_back({v + n, w / 2});
  }

  cout << dijkstra(G, 0)[2 * n - 1] << '\n';
}
