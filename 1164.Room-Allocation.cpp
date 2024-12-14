/*
   CSES - Room Allocation
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There is a large hotel, and n customers will arrive soon. Each customer
   wants to have a single room.

   You know each customer's arrival and departure day. Two customers can
   stay in the same room if the departure day of the first customer is
   earlier than the arrival day of the second customer.

   What is the minimum number of rooms that are needed to accommodate all
   customers? And how can the rooms be allocated?

Input

   The first input line contains an integer n: the number of customers.

   Then there are n lines, each of which describes one customer. Each line
   has two integers a and b: the arrival and departure day.

Output

   Print first an integer k: the minimum number of rooms required.

   After that, print a line that contains the room number of each customer
   in the same order as in the input. The rooms are numbered 1,2,…,k.
   You can print any valid solution.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a ≤ b ≤ 10^9

Example

   Input:
3
1 2
2 4
4 4

   Output:
2
1 2 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Event {
  int x, op, id;

  bool operator< (const Event &rhs) {
    auto a = tuple{x, op, id};
    auto b = tuple{rhs.x, rhs.op, rhs.id};
    return a < b;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto events = vector<Event>{};
  for (int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    events.push_back({l, -1, i});
    events.push_back({r, +1, i});
  }

  sort(events.begin(), events.end());

  vector<int> room, empty_room;
  vector<int> which(n);

  for (auto &[x, op, id] : events) {
    if (op == -1) {
      if (empty_room.size()) {
        auto rid = empty_room.back();
        empty_room.pop_back();
        room[rid] = id;
        which[id] = rid;
      } else {
        auto rid = room.size();
        room.resize(rid + 1);
        room[rid] = id;
        which[id] = rid;
      }
    } else {
      auto rid = which[id];
      room[rid] = -1;
      empty_room.push_back(rid);
    }
  }
  cout << room.size() << '\n';
  for (int i = 0; i < n; i++)
    cout << which[i] + 1 << " \n"[i + 1 == n];
}
