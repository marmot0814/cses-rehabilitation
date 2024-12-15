/*
   CSES - Two Sets II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to count the number of ways numbers 1,2,…,n can be
   divided into two sets of equal sum.

   For example, if n=7, there are four solutions:
     * {1,3,4,6} and {2,5,7}
     * {1,2,5,6} and {3,4,7}
     * {1,2,4,7} and {3,5,6}
     * {1,6,7} and {2,3,4,5}

Input

   The only input line contains an integer n.

Output

   Print the answer modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 500

Example

   Input:
7

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
int fpow(int a, int n) {
  if (n == 0) return 1;
  int k = fpow(a, n / 2);
  int k2 = 1ll * k * k % MOD;
  if (n % 2 == 1)
    return 1ll * k2 * a % MOD;
  return k2;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;

  int n2 = n * (n + 1) / 2;
  if (n2 % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }

  auto dp = vector<ll>(n2 + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = n2; j >= i; j--)
      (dp[j] += dp[j - i]) %= MOD;
  cout << dp[n2 / 2] * fpow(2, MOD - 2) % MOD << '\n';

}
