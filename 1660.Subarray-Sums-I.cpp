/*
   CSES - Subarray Sums I
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n positive integers, your task is to count the number
   of subarrays having sum x.

Input

   The first input line has two integers n and x: the size of the array
   and the target sum x.

   The next line has n integers a_1,a_2,...,a_n: the contents of the
   array.

Output

   Print one integer: the required number of subarrays.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x,a_i ≤ 10^9

Example

   Input:
5 7
2 4 1 2 7

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; ll x; cin >> n >> x;
  auto a = vector<ll>(n);
  for (auto &v : a) cin >> v;
  int r = 0, ans = 0;
  ll sum = 0;
  for (int l = 0; l < n; l++) {
    while (r < n and sum + a[r] <= x)
      sum += a[r++];
    ans += sum == x;
    sum -= a[l];
  }
  cout << ans << '\n';
}
