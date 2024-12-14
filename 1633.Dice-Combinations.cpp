/*
   CSES - Dice Combinations
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to count the number of ways to construct sum n by throwing
   a dice one or more times. Each throw produces an outcome between 1 and
   6.

   For example, if n=3, there are 4 ways:
     * 1+1+1
     * 1+2
     * 2+1
     * 3

Input

   The only input line has an integer n.

Output

   Print the number of ways modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 10^6

Example

   Input:
3

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto dp = vector<int>(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int x = 1; x <= 6; x++)
      if (i - x >= 0)
        (dp[i] += dp[i - x]) %= MOD;
  cout << dp[n] << '\n';
}
