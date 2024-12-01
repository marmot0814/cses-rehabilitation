/*
   CSES - Apple Division
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n apples with known weights. Your task is to divide the
   apples into two groups so that the difference between the weights of
   the groups is minimal.

Input

   The first input line has an integer n: the number of apples.

   The next line has n integers p_1,p_2,...,p_n: the weight of each
   apple.

Output

   Print one integer: the minimum difference between the weights of the
   groups.

Constraints

     * 1 ≤ n ≤ 20
     * 1 ≤ p_i ≤ 10^9

Example

   Input:
5
3 2 7 4 1

   Output:
1

   Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group
   2 has weights 1 and 7 (total weight 8).
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;

  ll ans = LLONG_MAX;
  for (int S = 0; S < (1 << n); S++) {
    ll cnt[2] = {};
    for (int i = 0; i < n; i++)
      cnt[(S >> i) & 1] += a[i];
    ans = min(ans, abs(cnt[0] - cnt[1]));
  }
  cout << ans << '\n';
}
