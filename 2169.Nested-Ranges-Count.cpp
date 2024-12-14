/*
   CSES - Nested Ranges Count
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given n ranges, your task is to count for each range how many other
   ranges it contains and how many other ranges contain it.

   Range [a,b] contains range [c,d] if a ≤ c and d ≤ b.

Input

   The first input line has an integer n: the number of ranges.

   After this, there are n lines that describe the ranges. Each line has
   two integers x and y: the range is [x,y].

   You may assume that no range appears more than once in the input.

Output

   First print a line that describes for each range (in the input order)
   how many other ranges it contains.

   Then print a line that describes for each range (in the input order)
   how many other ranges contain it.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x < y ≤ 10^9

Example

   Input:
4
1 6
2 4
4 8
3 6

   Output:
2 0 0 0
0 1 0 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Event {
  int op, id;

  bool operator< (const Event &rhs) {
    auto a = std::tuple{op, id};
    auto b = std::tuple{rhs.op, rhs.id};
    return a < b;
  }
};

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
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto l = vector<int>(n);
  auto r = vector<int>(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    mp[l[i]];
    mp[r[i]];
  }

  int st = 0;
  for (auto &[k, v] : mp)
    v = st++;

  auto events = vector<vector<Event>>(mp.size());
  for (int i = 0; i < n; i++) {
    l[i] = mp[l[i]];
    r[i] = mp[r[i]];
    events[l[i]].push_back({-1, i});
    events[r[i]].push_back({+1, i});
  }

  auto ans1 = vector<int>(n);
  auto bit1 = BIT(mp.size());
  for (auto &event_ : events) {
    for (auto &[op, id] : event_)
      if (op == 1)
        bit1.m(l[id], 1);

    for (auto &[op, id] : event_)
      if (op == 1)
        ans1[id] = bit1.q(mp.size()) - bit1.q(l[id]) - 1;
  }

  auto ans2 = vector<int>(n);
  auto bit2 = BIT(mp.size());
  for (auto &event_ : events) {
    for (auto &[op, id] : event_)
      if (op == -1)
        bit2.m(l[id], 1);

    for (auto &[op, id] : event_)
      if (op == 1)
        ans2[id] = bit2.q(l[id] + 1) - 1;

    for (auto &[op, id] : event_)
      if (op == 1)
        bit2.m(l[id], -1);
  }

  for (int i = 0; i < n; i++)
    cout << ans1[i] << " \n"[i + 1 == n];
  for (int i = 0; i < n; i++)
    cout << ans2[i] << " \n"[i + 1 == n];
}
