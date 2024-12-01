/*
   CSES - Increasing Array
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers. You want to modify the array so
   that it is increasing, i.e., every element is at least as large as the
   previous element.

   On each move, you may increase the value of any element by one. What is
   the minimum number of moves required?

Input

   The first input line contains an integer n: the size of the array.

   Then, the second line contains n integers x_1,x_2,…,x_n: the
   contents of the array.

Output

   Print the minimum number of moves.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
5
3 2 5 1 7

   Output:
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += max(0, a[i - 1] - a[i]);
    a[i] = max(a[i], a[i - 1]);
  }
  cout << ans << '\n';
}
