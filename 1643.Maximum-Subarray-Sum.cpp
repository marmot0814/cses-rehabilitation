/*
   CSES - Maximum Subarray Sum
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to find the maximum sum of
   values in a contiguous, nonempty subarray.

Input

   The first input line has an integer n: the size of the array.

   The second line has n integers x_1,x_2,...,x_n: the array values.

Output

   Print one integer: the maximum subarray sum.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * -10^9 ≤ x_i ≤ 10^9

Example

   Input:
8
-1 3 -2 5 3 -5 2 2

   Output:
9
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  ll sum = 0, ans = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    ll v; cin >> v;
    sum += v;
    ans = max(ans, sum);
    sum = max(0ll, sum);
  }

  cout << ans << '\n';
}
