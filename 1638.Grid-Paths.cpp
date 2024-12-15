/*
   CSES - Grid Paths
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider an n × n grid whose squares may have traps. It is not
   allowed to move to a square with a trap.

   Your task is to calculate the number of paths from the upper-left
   square to the lower-right square. You can only move right or down.

Input

   The first input line has an integer n: the size of the grid.

   After this, there are n lines that describe the grid. Each line has n
   characters: . denotes an empty cell, and * denotes a trap.

Output

   Print the number of paths modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 1000

Example

   Input:
4
....
.*..
...*
*...

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto G = vector<vector<char>>(n, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> G[i][j];
  if (G[0][0] == '*' or G[n - 1][n - 1] == '*') {
    cout << 0 << '\n';
    return 0;
  }
  auto dp = vector<vector<int>>(n, vector<int>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G[i][j] == '*') continue;
      if (i - 1 >= 0) (dp[i][j] += dp[i - 1][j]) %= MOD;
      if (j - 1 >= 0) (dp[i][j] += dp[i][j - 1]) %= MOD;
    }
  }
  cout << dp[n - 1][n - 1] << '\n';
}
