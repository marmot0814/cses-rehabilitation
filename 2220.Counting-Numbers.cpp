/*
   CSES - Counting Numbers
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to count the number of integers between a and b where no
   two adjacent digits are the same.

Input

   The only input line has two integers a and b.

Output

   Print one integer: the answer to the problem.

Constraints

     * 0 ≤ a ≤ b ≤ 10^{18}

Example

   Input:
123 321

   Output:
171
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

ll solve(auto &s, int i, int prev, int op, auto &dp) {
  if (i == s.size()) return 1;
  if (op == 0 and ~dp[i][prev]) return dp[i][prev];

  auto lim = op ? s[i] - '0' : 9;
  dp[i][prev] = 0;
  for (int k = 0; k <= lim; k++) {
    if (prev == k) continue;
    if (prev == 10 and k == 0)
      dp[i][prev] += solve(s, i + 1, 10, op && k == lim, dp);
    else
      dp[i][prev] += solve(s, i + 1, k, op && k == lim, dp);
  }

  return dp[i][prev];
}

ll solve(ll n) {
  auto s = to_string(n);
  auto dp = vector<vector<ll>>(20, vector<ll>(11, -1));
  auto ans = solve(s, 0, 10, 1, dp);
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll l, r; cin >> l >> r;
  cout << solve(r) - solve(l - 1) << '\n';
}
