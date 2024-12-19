/*
   CSES - Counting Rooms
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given a map of a building, and your task is to count the number
   of its rooms. The size of the map is n × m squares, and each
   square is either floor or wall. You can walk left, right, up, and down
   through the floor squares.

Input

   The first input line has two integers n and m: the height and width of
   the map.

   Then there are n lines of m characters describing the map. Each
   character is either . (floor) or # (wall).

Output

   Print one integer: the number of rooms.

Constraints

     * 1 ≤ n,m ≤ 1000

Example

   Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(auto &B, int x, int y) {
  int n = B.size(), m = B[0].size();
  B[x][y] = '#';
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 or nx >= n or ny < 0 or ny >= m)
      continue;
    if (B[nx][ny] == '#') continue;
    dfs(B, nx, ny);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto B = vector<vector<char>>(n, vector<char>(m));
  for (auto &vv : B)
    for (auto &v : vv)
      cin >> v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (B[i][j] == '#') continue;
      ans++;
      dfs(B, i, j);
    }
  }
  cout << ans << '\n';
}
