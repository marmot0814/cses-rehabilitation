/*
   CSES - Labyrinth
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given a map of a labyrinth, and your task is to find a path
   from start to end. You can walk left, right, up and down.

Input

   The first input line has two integers n and m: the height and width of
   the map.

   Then there are n lines of m characters describing the labyrinth. Each
   character is . (floor), # (wall), A (start), or B (end). There is
   exactly one A and one B in the input.

Output

   First print "YES", if there is a path, and "NO" otherwise.

   If there is a path, print the length of the shortest such path and its
   description as a string consisting of characters L (left), R (right), U
   (up), and D (down). You can print any valid solution.

Constraints

     * 1 ≤ n,m ≤ 1000

Example

   Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

   Output:
YES
9
LDDRRRRRU
*/
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const string dir = "RDLU";
void bfs(pii s, auto &B, auto &vis, auto &pre) {
  queue<pii> q; q.push(s); vis[s.F][s.S] = 0;
  int n = B.size(), m = B[0].size();
  while (q.size()) {
    auto p = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = p.first + dx[d];
      int ny = p.second + dy[d];
      if (nx < 0 or nx >= n or ny < 0 or ny >= m)
        continue;
      if (B[nx][ny] == '#') continue;
      if (vis[nx][ny] != -1) continue;
      vis[nx][ny] = vis[p.first][p.second] + 1;
      q.push({nx, ny});
      pre[nx][ny] = d;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto B = vector<vector<char>>(n, vector<char>(m));
  pii s, e;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      if (B[i][j] == 'A')
        s = {i, j};
      if (B[i][j] == 'B')
        e = {i, j};
    }
  }

  auto vis = vector<vector<int>>(n, vector<int>(m, -1));
  auto pre = vector<vector<int>>(n, vector<int>(m, -1));

  bfs(s, B, vis, pre);
  if (vis[e.first][e.second] == -1) {
    cout << "NO\n";
    return 0;
  } else
    cout << "YES\n";
  cout << vis[e.first][e.second] << '\n';
  auto ans = string{};
  auto p = e;
  while (pre[p.first][p.second] != -1) {
    auto d = pre[p.first][p.second];
    ans += dir[d];
    auto rd = (d + 2) % 4;
    int nx = p.first + dx[rd];
    int ny = p.second + dy[rd];
    p = {nx, ny};
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
