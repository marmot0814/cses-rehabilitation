/*
   CSES - Collecting Numbers
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array that contains each number between 1 ... n
   exactly once. Your task is to collect the numbers from 1 to n in
   increasing order.

   On each round, you go through the array from left to right and collect
   as many numbers as possible. What will be the total number of rounds?

Input

   The first line has an integer n: the array size.

   The next line has n integers x_1,x_2,...,x_n: the numbers in the
   array.

Output

   Print one integer: the number of rounds.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5

Example

   Input:
5
4 2 1 5 3

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<pii>(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  int ans = 1;
  for (int i = 1; i < n; i++)
    ans += a[i - 1].second > a[i].second;
  cout << ans << '\n';
}
