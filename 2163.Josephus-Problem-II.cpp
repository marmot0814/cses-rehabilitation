/*
   CSES - Josephus Problem II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider a game where there are n children (numbered 1,2,...,n) in a
   circle. During the game, repeatedly k children are skipped and one
   child is removed from the circle. In which order will the children be
   removed?

Input

   The only input line has two integers n and k.

Output

   Print n integers: the removal order.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 0 ≤ k ≤ 10^9

Example

   Input:
7 2

   Output:
3 6 2 7 5 1 4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct BIT {
  vector<int> bit;
  BIT(int n) : bit(n) {}
  void m(int x, int d) {
    x++;
    while (x <= bit.size()) {
      bit[x - 1] += d;
      x += x & -x;
    }
  }
  int q(int x) {
    int ret = 0;
    while (x > 0) {
      ret += bit[x - 1];
      x -= x & -x;
    }
    return ret;
  }

  int lower_bound(int v) {
    int pos = 0, n = bit.size();
    for (int h = __lg(n); h >= 0; h--) {
      if (pos + (1 << h) > n) continue;
      if (bit[pos + (1 << h) - 1] >= v) continue;
      v -= bit[pos + (1 << h) - 1];
      pos += 1 << h;
    }
    return pos + 1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto bit = BIT(n);

  for (int i = 0; i < n; i++)
    bit.m(i, 1);

  int v = 0;
  for (int i = n; i > 0; i--) {
    int l = bit.q(v);
    int r = i - l;
//    cout << "l: " << l << '\n';
//    cout << "r: " << r << '\n';
    int nx = k % i + 1;
    if (r >= nx) {
      v = bit.lower_bound(l + nx);
//      cout << "lower_bound(" << l + nx << "): " << v << '\n';
    } else {
      v = bit.lower_bound(nx - r);
//      cout << "lower_bound(" << nx - r << "): " << v << '\n';
    }
    bit.m(v - 1, -1);
//    cout << "v: " << v << '\n';
//    for (int x = 0; x < n; x++)
//      cout << bit.q(x + 1) - bit.q(x) << ' ';
//    cout << '\n';
    cout << v << ' ';
  }
  cout << '\n';
}
