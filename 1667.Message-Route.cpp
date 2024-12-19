/*
   CSES - Message Route
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Syrjälä's network has n computers and m connections. Your task is to
   find out if Uolevi can send a message to Maija, and if it is possible,
   what is the minimum number of computers on such a route.

Input

   The first input line has two integers n and m: the number of computers
   and connections. The computers are numbered 1,2,...,n. Uolevi's
   computer is 1 and Maija's computer is n.

   Then, there are m lines describing the connections. Each line has two
   integers a and b: there is a connection between those computers.

   Every connection is between two different computers, and there is at
   most one connection between any two computers.

Output

   If it is possible to send a message, first print k: the minimum number
   of computers on a valid route. After this, print an example of such a
   route. You can print any valid solution.

   If there are no routes, print "IMPOSSIBLE".

Constraints

     * 2 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n

Example

   Input:
5 5
1 2
1 3
1 4
2 3
5 4

   Output:
3
1 4 5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

void bfs(auto &G, int s, auto &lvl, auto &pre) {
  queue<int> q; q.push(s); lvl[s] = 1;
  while (q.size()) {
    int p = q.front(); q.pop();
    for (auto &v : G[p]) {
      if (lvl[v] != -1) continue;
      lvl[v] = lvl[p] + 1;
      pre[v] = p;
      q.push(v);
    }
  }
}

void print(int s, auto &pre) {
  if (s == -1) return ;
  print(pre[s], pre);
  cout << s + 1 << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto G = vector<vector<int>>(n);
  while (m--) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  auto lvl = vector<int>(n, -1);
  auto pre = vector<int>(n, -1);
  bfs(G, 0, lvl, pre);
  if (lvl[n - 1] == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << lvl[n - 1] << '\n';

  print(n - 1, pre);
  cout << '\n';
}
