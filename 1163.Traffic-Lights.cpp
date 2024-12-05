/*
   CSES - Traffic Lights
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There is a street of length x whose positions are numbered
   0,1,…,x. Initially there are no traffic lights, but n sets of
   traffic lights are added to the street one after another.

   Your task is to calculate the length of the longest passage without
   traffic lights after each addition.

Input

   The first input line contains two integers x and n: the length of the
   street and the number of sets of traffic lights.

   Then, the next line contains n integers p_1,p_2,…,p_n: the
   position of each set of traffic lights. Each position is distinct.

Output

   Print the length of the longest passage without traffic lights after
   each addition.

Constraints

     * 1 ≤ x ≤ 10^9
     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 0 < p_i < x

Example

   Input:
8 3
3 6 2

   Output:
5 3 3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, n; cin >> x >> n;
  auto loc = set<int>{{0, x}};
  auto seg = multiset<int>{{x}};

  while (n--) {
    int id; cin >> id;
    auto r = *loc.upper_bound(id);
    auto l = *prev(loc.upper_bound(id));

    seg.erase(seg.find(r - l));

    loc.insert(id);
    seg.insert(id - l);
    seg.insert(r - id);
    cout << *seg.rbegin() << ' ';
  }
}
