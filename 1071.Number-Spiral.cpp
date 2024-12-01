/*
   CSES - Number Spiral
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   A number spiral is an infinite grid whose upper-left square has number
   1. Here are the first five layers of the spiral:

   Your task is to find out the number in row y and column x.

Input

   The first input line contains an integer t: the number of tests.

   After this, there are t lines, each containing integers y and x.

Output

   For each test, print the number in row y and column x.

Constraints

     * 1 ≤ t ≤ 10^5
     * 1 ≤ y,x ≤ 10^9

Example

   Input:
3
2 3
1 1
4 2

   Output:
8
1
15
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t; while (t--) {
    int x, y; cin >> x >> y;
    ll m = max(x, y);
    if (m % 2 == 0) {
      if (x < y) {
        cout << (m - 1) * (m - 1) + x << '\n';
      } else {
        cout << m * m - y + 1 << '\n';
      }
    } else {
      if (x < y) {
        cout << m * m - x + 1 << '\n';
      } else {
        cout << (m - 1) * (m - 1) + y << '\n';
      }
    }
  }
}
