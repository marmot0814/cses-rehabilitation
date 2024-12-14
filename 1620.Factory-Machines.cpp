/*
   CSES - Factory Machines
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   A factory has n machines which can be used to make products. Your goal
   is to make a total of t products.

   For each machine, you know the number of seconds it needs to make a
   single product. The machines can work simultaneously, and you can
   freely decide their schedule.

   What is the shortest time needed to make t products?

Input

   The first input line has two integers n and t: the number of machines
   and products.

   The next line has n integers k_1,k_2,...,k_n: the time needed to make
   a product using each machine.

Output

   Print one integer: the minimum time needed to make t products.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ t ≤ 10^9
     * 1 ≤ k_i ≤ 10^9

Example

   Input:
3 7
3 2 5

   Output:
8

   Explanation: Machine 1 makes two products, machine 2 makes four
   products and machine 3 makes one product.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

__int128_t cal(auto &a, ll t) {
  __int128_t ret = 0;
  for (auto &v : a)
    ret += t / v;
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t; cin >> n >> t;
  auto a = vector<ll>(n);
  for (auto &v : a) cin >> v;
  ll l = 0, r = 1e18 + 5; while (r - l > 1) {
    ll m = (l + r) / 2;
    (cal(a, m) >= t ? r : l) = m;
  }
  cout << r << '\n';
}
