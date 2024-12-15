/*
   CSES - Array Description
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You know that an array has n integers between 1 and m, and the absolute
   difference between two adjacent values is at most 1.

   Given a description of the array where some values may be unknown, your
   task is to count the number of arrays that match the description.

Input

   The first input line has two integers n and m: the array size and the
   upper bound for each value.

   The next line has n integers x_1,x_2,...,x_n: the contents of the
   array. Value 0 denotes an unknown value.

Output

   Print one integer: the number of arrays modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 10^5
     * 1 ≤ m ≤ 100
     * 0 ≤ x_i ≤ m

Example

   Input:
3 5
2 0 2

   Output:
3

   Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the
   description.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;

  auto dp = vector<vector<int>>(2, vector<int>(m + 1));
  if (a[0] == 0)
    for (int i = 1; i <= m; i++)
      dp[0][i] = 1;
  else
    dp[0][a[0]] = 1;

  for (int i = 1; i < n; i++) {
    dp[i % 2] = vector<int>(m + 1);
    int v = a[i];
    if (v == 0) {
      for (int j = 1; j <= m; j++) {
        if (j - 1 >= 1)
          (dp[i % 2][j] += dp[(i - 1) % 2][j - 1]) %= MOD;
        if (j + 1 <= m)
          (dp[i % 2][j] += dp[(i - 1) % 2][j + 1]) %= MOD;
        (dp[i % 2][j] += dp[(i - 1) % 2][j]) %= MOD;
      }
    } else {
      if (v - 1 >= 0)
        (dp[i % 2][v] += dp[(i - 1) % 2][v - 1]) %= MOD;
      if (v + 1 <= m)
        (dp[i % 2][v] += dp[(i - 1) % 2][v + 1]) %= MOD;
      (dp[i % 2][v] += dp[(i - 1) % 2][v]) %= MOD;
    }
  }

  int ans = 0;
  if (a.back() == 0)
    for (int i = 1; i <= m; i++)
      (ans += dp[(n - 1) % 2][i]) %= MOD;
  else
    ans = dp[(n - 1) % 2][a.back()];
  cout << ans << '\n';
}
