/*
   CSES - Removal Game
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There is a list of n numbers and two players who move alternately. On
   each move, a player removes either the first or last number from the
   list, and their score increases by that number. Both players try to
   maximize their scores.

   What is the maximum possible score for the first player when both
   players play optimally?

Input

   The first input line contains an integer n: the size of the list.

   The next line has n integers x_1,x_2,…,x_n: the contents of the
   list.

Output

   Print the maximum possible score for the first player.

Constraints

     * 1 ≤ n ≤ 5000
     * -10^9 ≤ x_i ≤ 10^9

Example

   Input:
4
4 5 1 3

   Output:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

ll solve(int l, int r, auto &preS, auto &vt, auto &dp) {
  if (l == r) return 0;
  if (vt[l][r]) return dp[l][r];
  dp[l][r] = LLONG_MIN;
  dp[l][r] = max(dp[l][r], preS[r] - preS[l] - solve(l + 1, r, preS, vt, dp));
  dp[l][r] = max(dp[l][r], preS[r] - preS[l] - solve(l, r - 1, preS, vt, dp));
  vt[l][r] = 1;
  return dp[l][r];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<ll>(n);
  auto preS = vector<ll>{0};
  for (auto &v : a) {
    cin >> v;
    preS.push_back(preS.back() + v);
  }

  auto vt = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
  auto dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1));

  cout << solve(0, n, preS, vt, dp) << '\n';
}
