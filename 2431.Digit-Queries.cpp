/*
   CSES - Digit Queries
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider an infinite string that consists of all positive integers in
   increasing order:
12345678910111213141516171819202122232425...

   Your task is to process q queries of the form: what is the digit at
   position k in the string?

Input

   The first input line has an integer q: the number of queries.

   After this, there are q lines that describe the queries. Each line has
   an integer k: a 1-indexed position in the string.

Output

   For each query, print the corresponding digit.

Constraints

     * 1 ≤ q ≤ 1000
     * 1 ≤ k ≤ 10^{18}

Example

   Input:
3
7
19
12

   Output:
7
4
1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cal(ll m) {
  // digit number of 1234....m
  ll base = 1, ret = 0, digit = 1;
  do {
    base *= 10;
    if (base <= m) {
      ret += (base - base / 10) * digit;
    } else {
      ret += (m + 1 - base / 10) * digit;
    }
    digit++;
  } while (base <= m);
  return ret;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t; while (t--) {
    ll k; cin >> k;
    ll l = 0, r = 1e18; while (r - l > 1) {
      ll m = (l + r) / 2;
      (cal(m) < k ? l : r) = m;
    }
    auto rs = to_string(r);
    auto diff = cal(r) - k;
    cout << rs[rs.size() - diff - 1] << '\n';
  }
}
