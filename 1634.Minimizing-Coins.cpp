/*
   CSES - Minimizing Coins
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider a money system consisting of n coins. Each coin has a positive
   integer value. Your task is to produce a sum of money x using the
   available coins in such a way that the number of coins is minimal.

   For example, if the coins are {1,5,7} and the desired sum is 11, an
   optimal solution is 5+5+1 which requires 3 coins.

Input

   The first input line has two integers n and x: the number of coins and
   the desired sum of money.

   The second line has n distinct integers c_1,c_2,...,c_n: the value of
   each coin.

Output

   Print one integer: the minimum number of coins. If it is not possible
   to produce the desired sum, print -1.

Constraints

     * 1 ≤ n ≤ 100
     * 1 ≤ x ≤ 10^6
     * 1 ≤ c_i ≤ 10^6

Example

   Input:
3 11
1 5 7

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x; cin >> n >> x;
  auto dp = vector<int>(x + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int c; cin >> c;
    for (int j = c; j <= x; j++)
      dp[j] = min(dp[j], dp[j - c] + 1);
  }
  if (dp[x] == INF)
    cout << -1 << '\n';
  else
    cout << dp[x] << '\n';
}
