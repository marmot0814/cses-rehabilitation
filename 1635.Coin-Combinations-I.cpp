/*
   CSES - Coin Combinations I
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider a money system consisting of n coins. Each coin has a positive
   integer value. Your task is to calculate the number of distinct ways
   you can produce a money sum x using the available coins.

   For example, if the coins are {2,3,5} and the desired sum is 9, there
   are 8 ways:
     * 2+2+5
     * 2+5+2
     * 5+2+2
     * 3+3+3
     * 2+2+2+3
     * 2+2+3+2
     * 2+3+2+2
     * 3+2+2+2

Input

   The first input line has two integers n and x: the number of coins and
   the desired sum of money.

   The second line has n distinct integers c_1,c_2,...,c_n: the value of
   each coin.

Output

   Print one integer: the number of ways modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 100
     * 1 ≤ x ≤ 10^6
     * 1 ≤ c_i ≤ 10^6

Example

   Input:
3 9
2 3 5

   Output:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x; cin >> n >> x;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;
  auto dp = vector<int>(x + 1, 0);
  dp[0] = 1;
  for (int j = 0; j <= x; j++)
    for (int i = 0; i < n; i++)
      if (j >= a[i])
        (dp[j] += dp[j - a[i]]) %= MOD;
  cout << dp[x] << '\n';
}
