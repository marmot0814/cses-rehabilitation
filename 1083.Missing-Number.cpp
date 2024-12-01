/*
   CSES - Missing Number
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given all numbers between 1,2,…,n except one. Your task is
   to find the missing number.

Input

   The first input line contains an integer n.

   The second line contains n-1 numbers. Each number is distinct and
   between 1 and n (inclusive).

Output

   Print the missing number.

Constraints

     * 2 ≤ n ≤ 2 ⋅ 10^5

Example

   Input:
5
2 3 1 5

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  ll sum = 1ll * (1 + n) * n / 2;
  for (int i = 1; i < n; i++) {
    int x; cin >> x;
    sum -= x;
  }
  cout << sum << '\n';
}
