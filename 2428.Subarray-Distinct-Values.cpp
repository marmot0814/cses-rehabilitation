/*
   CSES - Subarray Distinct Values
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to calculate the number of
   subarrays that have at most k distinct values.

Input

   The first input line has two integers n and k.

   The next line has n integers x_1,x_2,...,x_n: the contents of the
   array.

Output

   Print one integer: the number of subarrays.

Constraints

     * 1 ≤ k ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
5 2
1 2 3 1 1

   Output:
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;
  auto mp = map<int, int>{};
  ll ans = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n and (mp.size() < k or mp.count(a[r])))
      mp[a[r++]]++;
    ans += r - l;
    mp[a[l]]--;
    if (mp[a[l]] == 0)
      mp.erase(a[l]);
  }
  cout << ans << '\n';
}
