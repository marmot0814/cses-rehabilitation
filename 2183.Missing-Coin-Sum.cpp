/*
   CSES - Missing Coin Sum
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You have n coins with positive integer values. What is the smallest sum
   you cannot create using a subset of the coins?

Input

   The first input line has an integer n: the number of coins.

   The second line has n integers x_1,x_2,...,x_n: the value of each
   coin.

Output

   Print one integer: the smallest coin sum.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
5
2 9 1 2 7

   Output:
6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<ll>(n);
  for (auto &v : a) cin >> v;
  sort(a.begin(), a.end());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + 1 < a[i]) {
      cout << sum + 1 << '\n';
      return 0;
    }
    sum += a[i];
  }
  cout << sum + 1 << '\n';
}
