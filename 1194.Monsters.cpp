/*
   CSES - Monsters
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You and some monsters are in a labyrinth. When taking a step to some
   direction in the labyrinth, each monster may simultaneously take one as
   well. Your goal is to reach one of the boundary squares without ever
   sharing a square with a monster.

   Your task is to find out if your goal is possible, and if it is, print
   a path that you can follow. Your plan has to work in any situation;
   even if the monsters know your path beforehand.

Input

   The first input line has two integers n and m: the height and width of
   the map.

   After this there are n lines of m characters describing the map. Each
   character is . (floor), # (wall), A (start), or M (monster). There is
   exactly one A in the input.

Output

   First print "YES" if your goal is possible, and "NO" otherwise.

   If your goal is possible, also print an example of a valid path (the
   length of the path and its description using characters D, U, L, and
   R). You can print any path, as long as its length is at most n ⋅ m
   steps.

Constraints

     * 1 ≤ n,m ≤ 1000

Example

   Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

   Output:
YES
5
RRDDR
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

bool success(int x, int y, int n, int m) {
  return x == 0 or y == 0 or x == n - 1 or y == m - 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto B = vector<vector<char>>(n, vector<char>(m));
  auto q = queue<tuple<int, int, int>>{};
  auto invalid = vector<vector<int>>(n, vector<int>(m));
  auto pre = vector<vector<int>>(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      if (B[i][j] == 'M') {
        q.push({i, j, 0});
        invalid[i][j] = 1;
      }
    }
  }

  auto s = pii{};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (B[i][j] == 'A') {
        q.push({i, j, 1});
        s = {i, j};
      }

  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
  while (q.size()) {
    auto [x, y, o] = q.front(); q.pop();
    if (o == 1 and success(x, y, n, m)) {
      cout << "YES\n";
      const string dir = "RDLU";
      auto ans = string{};
      while (x != s.first or y != s.second) {
        int d = pre[x][y];
        ans += dir[d];
        auto rd = (d + 2) % 4;
        x += dx[rd];
        y += dy[rd];
      }
      reverse(ans.begin(), ans.end());
      cout << ans.size() << '\n';
      cout << ans << '\n';
      return 0;
    }

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= n or ny < 0 or ny >= m)
        continue;
      if (B[nx][ny] == '#')
        continue;
      if (invalid[nx][ny])
        continue;
      q.push({nx, ny, o});
      invalid[nx][ny] = 1;
      if (o == 1)
        pre[nx][ny] = d;
    }
  }

  cout << "NO\n";
}
