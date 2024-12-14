/*
   CSES - Sum of Three Values
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers, and your task is to find three
   values (at distinct positions) whose sum is x.

Input

   The first input line has two integers n and x: the array size and the
   target sum.

   The second line has n integers a_1,a_2,...,a_n: the array values.

Output

   Print three integers: the positions of the values. If there are several
   solutions, you may print any of them. If there are no solutions, print
   IMPOSSIBLE.

Constraints

     * 1 ≤ n ≤ 5000
     * 1 ≤ x,a_i ≤ 10^9

Example

   Input:
4 8
2 7 5 1

   Output:
1 3 4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
  srand(time(NULL));
  cin.tie(0)->sync_with_stdio(0);
  int n; ll x;
  cin >> n >> x;
  auto a = vector<pll>(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  if (n < 3) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  sort(a.begin(), a.end());

  for (int j = 1; j + 1 < n; j++) {
    int k = n - 1;
    for (int i = 0; i < j; i++) {
      while (j + 1 < k and a[i].first + a[j].first + a[k].first > x)
        k--;
      if (j != k and a[i].first + a[j].first + a[k].first == x) {
        cout << a[i].second + 1 << ' ' << a[j].second + 1 << ' ' << a[k].second + 1 << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
