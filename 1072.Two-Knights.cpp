/*
   CSES - Two Knights
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to count for k=1,2,…,n the number of ways two knights
   can be placed on a k × k chessboard so that they do not attack
   each other.

Input

   The only input line contains an integer n.

Output

   Print n integers: the results.

Constraints

     * 1 ≤ n ≤ 10000

Example

   Input:
8

   Output:
0
6
28
96
252
550
1056
1848
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (ll k = 1; k <= n; k++) {
    ll k2 = k * k;
    ll all = k2 * (k2 - 1) / 2;
    if (k >= 3)
      all -= (k - 3 + 1) * (k - 2 + 1) * 4;
    cout << all << '\n';
  }
}
