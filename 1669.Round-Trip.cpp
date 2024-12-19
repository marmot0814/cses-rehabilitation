/*
   CSES - Round Trip
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Byteland has n cities and m roads between them. Your task is to design
   a round trip that begins in a city, goes through two or more other
   cities, and finally returns to the starting city. Every intermediate
   city on the route has to be distinct.

Input

   The first input line has two integers n and m: the number of cities and
   roads. The cities are numbered 1,2,...,n.

   Then, there are m lines describing the roads. Each line has two
   integers a and b: there is a road between those cities.

   Every road is between two different cities, and there is at most one
   road between any two cities.

Output

   First print an integer k: the number of cities on the route. Then print
   k cities in the order they will be visited. You can print any valid
   solution.

   If there are no solutions, print "IMPOSSIBLE".

Constraints

     * 1 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n

Example

   Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

   Output:
4
3 5 1 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

void dfs(auto &G, int p, int u, auto &vis, auto &ins, auto &stk) {
  vis[u] = 1;
  stk.push_back(u);
  ins[u] = 1;
  for (auto &v : G[u]) {
    if (v == p) continue;
    if (not ins[v])
      dfs(G, u, v, vis, ins, stk);
    else {
      auto ans = vector<int>{v + 1};
      while (stk.back() != v) {
        ans.push_back(stk.back() + 1);
        stk.pop_back();
      }
      ans.push_back(v + 1);
      cout << ans.size() << '\n';
      for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
      exit(0);
    }
  }
  stk.pop_back();
  ins[u] = 0;
}

struct DSU {
  vector<int> pa;
  DSU(int n) : pa(n, -1) {}
  int find(int x) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x]);
  }
  bool merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) return false;
    if (pa[x] > pa[y])
      swap(x, y);
    pa[x] += pa[y];
    pa[y] = x;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto G = vector<vector<int>>(n);

  auto ok = false;
  auto dsu = DSU(n);
  while (m--) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
    if (not dsu.merge(u, v))
      ok = true;
  }

  if (not ok) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  auto vis = vector<int>(n);
  auto ins = vector<int>(n);
  vector<int> stk;
  for (int i = 0; i < n; i++) {
    if (ins[i]) continue;
    dfs(G, i, i, vis, ins, stk);
  }
}
