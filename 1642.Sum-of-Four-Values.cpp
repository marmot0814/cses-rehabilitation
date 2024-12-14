/*
   CSES - Sum of Four Values
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers, and your task is to find four
   values (at distinct positions) whose sum is x.

Input

   The first input line has two integers n and x: the array size and the
   target sum.

   The second line has n integers a_1,a_2,...,a_n: the array values.

Output

   Print four integers: the positions of the values. If there are several
   solutions, you may print any of them. If there are no solutions, print
   IMPOSSIBLE.

Constraints

     * 1 ≤ n ≤ 1000
     * 1 ≤ x,a_i ≤ 10^9

Example

   Input:
8 15
3 2 5 8 1 3 2 3

   Output:
2 4 6 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; ll x; cin >> n >> x;
  auto a = vector<pii>(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  if (n < 4) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (int k = 2; k + 1 < n; k++) {
    for (int i = 0; i + 1 < k; i++) {
      int l = n - 1;
      for (int j = i + 1; j < k; j++) {
        ll a1 = a[i].first;
        ll a2 = a[j].first;
        ll a3 = a[k].first;
        while (k < l and a1 + a2 + a3 + a[l].first > x)
          l--;
        if (k < l and a1 + a2 + a3 + a[l].first == x) {
          cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second << ' ' << a[l].second << '\n';
          return 0;
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";
}
