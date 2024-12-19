/*
   CSES - High Score
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You play a game consisting of n rooms and m tunnels. Your initial score
   is 0, and each tunnel increases your score by x where x may be both
   positive or negative. You may go through a tunnel several times.

   Your task is to walk from room 1 to room n. What is the maximum score
   you can get?

Input

   The first input line has two integers n and m: the number of rooms and
   tunnels. The rooms are numbered 1,2,...,n.

   Then, there are m lines describing the tunnels. Each line has three
   integers a, b and x: the tunnel starts at room a, ends at room b, and
   it increases your score by x. All tunnels are one-way tunnels.

   You can assume that it is possible to get from room 1 to room n.

Output

   Print one integer: the maximum score you can get. However, if you can
   get an arbitrarily large score, print -1.

Constraints

     * 1 ≤ n ≤ 2500
     * 1 ≤ m ≤ 5000
     * 1 ≤ a,b ≤ n
     * -10^9 ≤ x ≤ 10^9

Example

   Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

   Output:
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

auto bellman_fold(auto &G, int s) {
  int n = G.size();
  auto d = vector<ll>(n, INF);
  d[s] = 0;

  auto cnt = vector<int>(n, 0);
  auto inq = vector<int>(n, 0);
  queue<int> q; q.push(s); inq[s] = 1;
  while (q.size()) {
    int u = q.front(); q.pop();
    inq[u] = 0;

    cnt[u]++;
    if (cnt[u] > n)
      d[u] = -INF;

    for (auto &[v, w] : G[u]) {
      if (d[v] == -INF)
        continue;

      if (d[u] == -INF) {
        d[v] = -INF;
      } else if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
      } else continue;

      if (inq[v])
        continue;
      q.push(v);
      inq[v] = 1;
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
    G[u].push_back({v, -w});
  }

  auto d = bellman_fold(G, 0);
  if (d.back() == -INF)
    cout << -1 << '\n';
  else
    cout << -d.back() << '\n';
}
