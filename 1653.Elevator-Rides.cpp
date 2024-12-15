/*
   CSES - Elevator Rides
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n people who want to get to the top of a building which has
   only one elevator. You know the weight of each person and the maximum
   allowed weight in the elevator. What is the minimum number of elevator
   rides?

Input

   The first input line has two integers n and x: the number of people and
   the maximum allowed weight in the elevator.

   The second line has n integers w_1,w_2,...,w_n: the weight of each
   person.

Output

   Print one integer: the minimum number of rides.

Constraints

     * 1 ≤ n ≤ 20
     * 1 ≤ x ≤ 10^9
     * 1 ≤ w_i ≤ x

Example

   Input:
4 10
4 8 6 1

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; ll x; cin >> n >> x;
  auto a = vector<ll>(n);
  for (auto &v : a) cin >> v;

  auto dp = vector<ll>(1 << n, INF);
  dp[0] = 0;
  for (int S = 1; S < (1 << n); S++) {
    for (int i = 0; i < n; i++) {
      if (((S >> i) & 1) == 0)
        continue;
      auto rem = (x - dp[S ^ (1 << i)] % x) % x;
      if (a[i] > rem)
        dp[S] = min(dp[S], dp[S ^ (1 << i)] + rem + a[i]);
      else
        dp[S] = min(dp[S], dp[S ^ (1 << i)] + a[i]);
    }
  }
  cout << (dp[(1 << n) - 1] - 1 + x) / x << '\n';
}
