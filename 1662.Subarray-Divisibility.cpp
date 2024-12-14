/*
   CSES - Subarray Divisibility
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to count the number of
   subarrays where the sum of values is divisible by n.

Input

   The first input line has an integer n: the size of the array.

   The next line has n integers a_1,a_2,...,a_n: the contents of the
   array.

Output

   Print one integer: the required number of subarrays.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * -10^9 ≤ a_i ≤ 10^9

Example

   Input:
5
3 1 2 7 4

   Output:
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int, int> cnt;
  cnt[0]++;
  int sum = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    (sum += (v % n + n) % n) %= n;
    if (cnt.count(sum))
      ans += cnt[sum];
    cnt[sum]++;
  }
  cout << ans << '\n';
}
