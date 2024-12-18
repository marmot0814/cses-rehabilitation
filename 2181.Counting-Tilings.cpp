/*
   CSES - Counting Tilings
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to count the number of ways you can fill an n × m
   grid using 1 × 2 and 2 × 1 tiles.

Input

   The only input line has two integers n and m.

Output

   Print one integer: the number of ways modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 10
     * 1 ≤ m ≤ 1000

Example

   Input:
4 7

   Output:
781
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto dp1 = vector<int>(1 << n);
  dp1[0] = 1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      auto dp2 = vector<int>(1 << n);
      for (int S = 0; S < (1 << n); S++) {
        if ((S >> j) & 1) {
          (dp2[S ^ (1 << j)] += dp1[S]) %= MOD;
        } else {
          if (j - 1 >= 0 and ((S >> (j - 1)) & 1) == 1)
            (dp2[S ^ (1 << (j - 1))] += dp1[S]) %= MOD;
          (dp2[S ^ (1 << j)] += dp1[S]) %= MOD;
        }
      }
      swap(dp1, dp2);
    }
  }

  cout << dp1[0] << '\n';
}
