/*
   CSES - Projects
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n projects you can attend. For each project, you know its
   starting and ending days and the amount of money you would get as
   reward. You can only attend one project during a day.

   What is the maximum amount of money you can earn?

Input

   The first input line contains an integer n: the number of projects.

   After this, there are n lines. Each such line has three integers a_i,
   b_i, and p_i: the starting day, the ending day, and the reward.

Output

   Print one integer: the maximum amount of money you can earn.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a_i ≤ b_i ≤ 10^9
     * 1 ≤ p_i ≤ 10^9

Example

   Input:
4
2 4 4
3 6 6
6 8 2
5 7 3

   Output:
7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

struct Project {
  int l, r, p;
};

struct BIT {
  vector<ll> bit;
  BIT(int n) : bit(n) {}
  void m(int x, ll d) {
    x++;
    while (x <= bit.size()) {
      bit[x - 1] = max(bit[x - 1], d);
      x += x & -x;
    }
  }

  ll q(int r) {
    ll ret = 0;
    while (r > 0) {
      ret = max(ret, bit[r - 1]);
      r -= r & -r;
    }
    return ret;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto projects = vector<Project>(n);
  map<int, int> mp;
  for (auto &[l, r, p] : projects) {
    cin >> l >> r >> p;
    mp[l]; mp[r];
  }

  int st = 0;
  for (auto &[k, v] : mp) v = st++;

  sort(projects.begin(), projects.end(), [](auto &a, auto &b){
    return a.r < b.r;
  });

  auto dp = BIT(st);

  for (auto &[l, r, p] : projects) {
    l = mp[l];
    r = mp[r];
    dp.m(r, dp.q(l) + p);
  }

  cout << dp.q(st) << '\n';
}
