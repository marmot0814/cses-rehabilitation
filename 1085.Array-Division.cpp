/*
   CSES - Array Division
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array containing n positive integers.

   Your task is to divide the array into k subarrays so that the maximum
   sum in a subarray is as small as possible.

Input

   The first input line contains two integers n and k: the size of the
   array and the number of subarrays in the division.

   The next line contains n integers x_1,x_2,…,x_n: the contents of
   the array.

Output

   Print one integer: the maximum sum in a subarray in the optimal
   division.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ k ≤ n
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
5 3
2 4 7 3 5

   Output:
8

   Explanation: An optimal division is [2,4],[7],[3,5] where the sums of
   the subarrays are 6,7,8. The largest sum is the last sum 8.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int check(auto &a, ll m) {
  ll sum = 0, ans = 1;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] > m) return n + 1;
    if (sum + a[i] > m) {
      sum = a[i];
      ans++;
    } else {
      sum += a[i];
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;
  ll l = 0, r = 1e18; while (r - l > 1) {
    ll m = (l + r) / 2;
    (check(a, m) <= k ? r : l) = m;
  }
  cout << r << '\n';
}
