/*
   CSES - Subarray Sums II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to count the number of
   subarrays having sum x.

Input

   The first input line has two integers n and x: the size of the array
   and the target sum x.

   The next line has n integers a_1,a_2,...,a_n: the contents of the
   array.

Output

   Print one integer: the required number of subarrays.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * -10^9 ≤ x,a_i ≤ 10^9

Example

   Input:
5 7
2 -1 3 5 -2

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; ll x;
  cin >> n >> x;
  auto a = vector<ll>(n);
  auto preS = vector<ll>{0};
  for (auto &v : a) {
    cin >> v;
    preS.push_back(preS.back() + v);
  }
  ll ans = 0;
  map<ll, int> cnt;
  for (int i = 0; i <= n; i++) {
    if (cnt.count(preS[i] - x))
      ans += cnt[preS[i] - x];
    cnt[preS[i]]++;
  }
  cout << ans << '\n';
}
