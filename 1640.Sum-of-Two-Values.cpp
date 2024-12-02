/*
   CSES - Sum of Two Values
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers, and your task is to find two
   values (at distinct positions) whose sum is x.

Input

   The first input line has two integers n and x: the array size and the
   target sum.

   The second line has n integers a_1,a_2,...,a_n: the array values.

Output

   Print two integers: the positions of the values. If there are several
   solutions, you may print any of them. If there are no solutions, print
   IMPOSSIBLE.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x,a_i ≤ 10^9

Example

   Input:
4 8
2 7 5 1

   Output:
2 4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x >= k) continue;
    if (mp.count(k - x)) {
      cout << mp[k - x] << ' ' << i << '\n';
      return 0;
    }
    mp[x] = i;
  }
  cout << "IMPOSSIBLE\n";
}
