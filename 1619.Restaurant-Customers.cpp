/*
   CSES - Restaurant Customers
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given the arrival and leaving times of n customers in a
   restaurant.

   What was the maximum number of customers in the restaurant at any time?

Input

   The first input line has an integer n: the number of customers.

   After this, there are n lines that describe the customers. Each line
   has two integers a and b: the arrival and leaving times of a customer.

   You may assume that all arrival and leaving times are distinct.

Output

   Print one integer: the maximum number of customers.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a < b ≤ 10^9

Example

   Input:
3
5 8
2 4
3 9

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    mp[l]++;
    mp[r]--;
  }

  int sum = 0, ans = 0;
  for (auto &[k, v] : mp) {
    sum += v;
    ans = max(ans, sum);
  }
  cout << ans << '\n';
}
