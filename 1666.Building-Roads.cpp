/*
   CSES - Building Roads
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Byteland has n cities, and m roads between them. The goal is to
   construct new roads so that there is a route between any two cities.

   Your task is to find out the minimum number of roads required, and also
   determine which roads should be built.

Input

   The first input line has two integers n and m: the number of cities and
   roads. The cities are numbered 1,2,...,n.

   After that, there are m lines describing the roads. Each line has two
   integers a and b: there is a road between those cities.

   A road always connects two different cities, and there is at most one
   road between any two cities.

Output

   First print an integer k: the number of required roads.

   Then, print k lines that describe the new roads. You can print any
   valid solution.

Constraints

     * 1 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n

Example

   Input:
4 2
1 2
3 4

   Output:
1
2 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

struct DSU {
  vector<int> pa;
  DSU(int n) : pa(n, -1) {}
  int find(int x) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x]);
  }
  void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) return ;
    if (pa[x] > pa[y])
      swap(x, y);
    pa[x] += pa[y];
    pa[y] = x;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto dsu = DSU(n);
  while (m--) {
    int u, v; cin >> u >> v;
    u--, v--;
    dsu.merge(u, v);
  }
  auto ans = vector<int>{};
  for (int i = 0; i < n; i++) {
    if (dsu.find(i) != i) continue;
    ans.push_back(i + 1);
  }
  cout << ans.size() - 1 << '\n';
  for (int i = 1; i < ans.size(); i++)
    cout << ans[i - 1] << ' ' << ans[i] << '\n';
}
