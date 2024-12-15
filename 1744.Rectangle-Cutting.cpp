/*
   CSES - Rectangle Cutting
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an a × b rectangle, your task is to cut it into squares. On
   each move you can select a rectangle and cut it into two rectangles in
   such a way that all side lengths remain integers. What is the minimum
   possible number of moves?

Input

   The only input line has two integers a and b.

Output

   Print one integer: the minimum number of moves.

Constraints

     * 1 ≤ a,b ≤ 500

Example

   Input:
3 5

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int solve(int a, int b, auto &dp) {
  if (a > b) return solve(b, a, dp);
  if (~dp[a][b]) return dp[a][b];
  if (a == b) return 0;
  dp[a][b] = INF;
  for (int i = 1; i < b; i++)
    dp[a][b] = min(dp[a][b], solve(a, i, dp) + solve(a, b - i, dp) + 1);
  for (int i = 1; i < a; i++)
    dp[a][b] = min(dp[a][b], solve(i, b, dp) + solve(a - i, b, dp) + 1);
  return dp[a][b];
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  const int MAXN = 500;
  auto dp = vector<vector<int>>(MAXN + 1, vector<int>(MAXN + 1, -1));
  cout << solve(a, b, dp) << '\n';
}
