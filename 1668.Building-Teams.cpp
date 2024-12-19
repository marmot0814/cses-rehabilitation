/*
   CSES - Building Teams
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n pupils in Uolevi's class, and m friendships between them.
   Your task is to divide the pupils into two teams in such a way that no
   two pupils in a team are friends. You can freely choose the sizes of
   the teams.

Input

   The first input line has two integers n and m: the number of pupils and
   friendships. The pupils are numbered 1,2,...,n.

   Then, there are m lines describing the friendships. Each line has two
   integers a and b: pupils a and b are friends.

   Every friendship is between two different pupils. You can assume that
   there is at most one friendship between any two pupils.

Output

   Print an example of how to build the teams. For each pupil, print "1"
   or "2" depending on to which team the pupil will be assigned. You can
   print any valid team.

   If there are no solutions, print "IMPOSSIBLE".

Constraints

     * 1 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n

Example

   Input:
5 3
1 2
1 3
4 5

   Output:
1 2 2 1 2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

bool dfs(auto &G, int u, auto &color) {
  for (auto &v : G[u]) {
    if (color[v] == 0) {
      color[v] = 3 - color[u];
      if (not dfs(G, v, color))
        return false;
    } else if (color[v] == color[u])
      return false;
  }
  return true;
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
  auto color = vector<int>(n);
  for (int i = 0; i < n; i++) {
    if (color[i]) continue;
    color[i] = 1;
    if (not dfs(G, i, color)) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  for (int i = 0; i < n; i++)
    cout << color[i] << " \n"[i + 1 == n];
}
