/*
   CSES - Maximum Subarray Sum II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to find the maximum sum of
   values in a contiguous subarray with length between a and b.

Input

   The first input line has three integers n, a and b: the size of the
   array and the minimum and maximum subarray length.

   The second line has n integers x_1,x_2,...,x_n: the array values.

Output

   Print one integer: the maximum subarray sum.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a ≤ b ≤ n
     * -10^9 ≤ x_i ≤ 10^9

Example

   Input:
8 1 2
-1 3 -2 5 3 -5 2 2

   Output:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b; cin >> n >> a >> b;
  auto preS = vector<ll>{0};
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    preS.push_back(preS.back() + v);
  }
  auto st = multiset<ll>{};

  //  |------i-----
  //  |----|
  // i-b  i-a
  ll ans = LLONG_MIN;
  for (int i = a; i <= n; i++) {
    st.insert(preS[i - a]);
    ans = max(ans, preS[i] - *st.begin());
    if (i - b >= 0)
      st.erase(st.find(preS[i - b]));
  }
  cout << ans << '\n';
}
