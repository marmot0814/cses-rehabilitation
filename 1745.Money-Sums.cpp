/*
   CSES - Money Sums
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You have n coins with certain values. Your task is to find all money
   sums you can create using these coins.

Input

   The first input line has an integer n: the number of coins.

   The next line has n integers x_1,x_2,...,x_n: the values of the
   coins.

Output

   First print an integer k: the number of distinct money sums. After
   this, print all possible sums in increasing order.

Constraints

     * 1 ≤ n ≤ 100
     * 1 ≤ x_i ≤ 1000

Example

   Input:
4
4 2 5 2

   Output:
9
2 4 5 6 7 8 9 11 13
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<int>(n);
  int sum = 0;
  for (auto &v : a) {
    cin >> v;
    sum += v;
  }
  auto dp = vector<int>(sum + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = sum; j >= a[i]; j--)
      dp[j] |= dp[j - a[i]];
  int ans = 0;
  for (int i = 1; i <= sum; i++)
    ans += dp[i];
  cout << ans << '\n';
  for (int i = 1; i <= sum; i++)
    if (dp[i])
      cout << i << ' ';
  cout << '\n';
}
