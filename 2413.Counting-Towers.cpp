/*
   CSES - Counting Towers
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to build a tower whose width is 2 and height is n. You
   have an unlimited supply of blocks whose width and height are integers.

   For example, here are some possible solutions for n=6:

   Given n, how many different towers can you build? Mirrored and rotated
   towers are counted separately if they look different.

Input

   The first input line contains an integer t: the number of tests.

   After this, there are t lines, and each line contains an integer n: the
   height of the tower.

Output

   For each test, print the number of towers modulo 10^9+7.

Constraints

     * 1 ≤ t ≤ 100
     * 1 ≤ n ≤ 10^6

Example

   Input:
3
2
6
1337

   Output:
8
2864
640403945
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = 1e6;
  auto dp = vector<vector<ll>>(2, vector<ll>(n + 1));
  dp[0][1] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[0][i] = (4 * dp[0][i - 1] + dp[1][i - 1]) % MOD;
    dp[1][i] = (dp[0][i - 1] + 2 * dp[1][i - 1]) % MOD;
  }
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    cout << (dp[0][n] + dp[1][n]) % MOD << '\n';
  }
}
