/*
   CSES - Removing Digits
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an integer n. On each step, you may subtract one of the
   digits from the number.

   How many steps are required to make the number equal to 0?

Input

   The only input line has an integer n.

Output

   Print one integer: the minimum number of steps.

Constraints

     * 1 ≤ n ≤ 10^6

Example

   Input:
27

   Output:
5

   Explanation: An optimal solution is 27 → 20 → 18
   → 10 → 9 → 0.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int solve(auto &dp, int n) {
  if (~dp[n]) return dp[n];
  dp[n] = INF;
  int x = n;
  while (x) {
    dp[n] = min(dp[n], solve(dp, n - x % 10) + 1);
    x /= 10;
  }
  return dp[n];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto dp = vector<int>(n + 1, -1);
  dp[0] = 0;
  cout << solve(dp, n) << '\n';
}
