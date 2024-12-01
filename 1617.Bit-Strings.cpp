/*
   CSES - Bit Strings
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to calculate the number of bit strings of length n.

   For example, if n=3, the correct answer is 8, because the possible bit
   strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

   The only input line has an integer n.

Output

   Print the result modulo 10^9+7.

Constraints

     * 1 ≤ n ≤ 10^6

Example

   Input:
3

   Output:
8
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
int fpow(int a, int n) {
  if (n == 0) return 1;
  int k = fpow(a, n / 2);
  int k2 = 1ll * k * k % MOD;
  if (n % 2)
    k2 = 1ll * k2 * a % MOD;
  return k2;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  cout << fpow(2, n) << '\n';
}
