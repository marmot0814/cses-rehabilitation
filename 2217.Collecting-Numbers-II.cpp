/*
   CSES - Collecting Numbers II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array that contains each number between 1 ... n
   exactly once. Your task is to collect the numbers from 1 to n in
   increasing order.

   On each round, you go through the array from left to right and collect
   as many numbers as possible.

   Given m operations that swap two numbers in the array, your task is to
   report the number of rounds after each operation.

Input

   The first line has two integers n and m: the array size and the number
   of operations.

   The next line has n integers x_1,x_2,...,x_n: the numbers in the
   array.

   Finally, there are m lines that describe the operations. Each line has
   two integers a and b: the numbers at positions a and b are swapped.

Output

   Print m integers: the number of rounds after each swap.

Constraints

     * 1 ≤ n, m ≤ 2 ⋅ 10^5
     * 1 ≤ a,b ≤ n

Example

   Input:
5 3
4 2 1 5 3
2 3
1 5
2 3

   Output:
2
3
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;

  auto a = vector<pii>(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());
  auto perm = vector<int>(n);
  for (int i = 0; i < n; i++)
    perm[a[i].second] = i;

  int ans = 1;
  for (int i = 1; i < n; i++)
    ans += a[i - 1].second > a[i].second;

  while (m--) {
    int x, y; cin >> x >> y;
    x--, y--;

    if (perm[x] > perm[y]) swap(x, y);
    int px = perm[x];
    int py = perm[y];

    if (px - 1 >= 0)
      ans -= a[px - 1].second > a[px].second;
    if (px + 1 < n)
      ans -= a[px].second > a[px + 1].second;

    if (py - 1 >= 0 and px + 1 != py)
      ans -= a[py - 1].second > a[py].second;
    if (py + 1 < n)
      ans -= a[py].second > a[py + 1].second;

    swap(a[perm[x]].second, a[perm[y]].second);
    swap(perm[x], perm[y]);

    if (px -  1 >= 0)
      ans += a[px - 1].second > a[px].second;
    if (px + 1 < n)
      ans += a[px].second > a[px + 1].second;

    if (py - 1 >= 0 and px + 1 != py)
      ans += a[py - 1].second > a[py].second;
    if (py + 1 < n)
      ans += a[py].second > a[py + 1].second;

    cout << ans << '\n';
  }
}
