/*
   CSES - Coin Piles
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You have two coin piles containing a and b coins. On each move, you can
   either remove one coin from the left pile and two coins from the right
   pile, or two coins from the left pile and one coin from the right pile.

   Your task is to efficiently find out if you can empty both the piles.

Input

   The first input line has an integer t: the number of tests.

   After this, there are t lines, each of which has two integers a and b:
   the numbers of coins in the piles.

Output

   For each test, print "YES" if you can empty the piles and "NO"
   otherwise.

Constraints

     * 1 ≤ t ≤ 10^5
     * 0 ≤ a, b ≤ 10^9

Example

   Input:
3
2 1
2 2
3 3

   Output:
YES
NO
YES
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t; while (t--) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    int diff = y - x;
    if (x < diff) {
      cout << "NO\n";
      continue;
    }
    x -= diff;
    if (x % 3 == 0) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
