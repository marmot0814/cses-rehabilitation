/*
   CSES - Trailing Zeros
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to calculate the number of trailing zeros in the factorial
   n!.

   For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input

   The only input line has an integer n.

Output

   Print the number of trailing zeros in n!.

Constraints

     * 1 ≤ n ≤ 10^9

Example

   Input:
20

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int five = 0;

  while (n) {
    five += n / 5;
    n /= 5;
  }

  cout << five << '\n';
}
