/*
   CSES - Ferris Wheel
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n children who want to go to a Ferris wheel, and your task is
   to find a gondola for each child.

   Each gondola may have one or two children in it, and in addition, the
   total weight in a gondola may not exceed x. You know the weight of
   every child.

   What is the minimum number of gondolas needed for the children?

Input

   The first input line contains two integers n and x: the number of
   children and the maximum allowed weight.

   The next line contains n integers p_1,p_2,…,p_n: the weight of
   each child.

Output

   Print one integer: the minimum number of gondolas.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x ≤ 10^9
     * 1 ≤ p_i ≤ x

Example

   Input:
4 10
7 2 3 9

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;
  sort(a.begin(), a.end());
  int i = 0, ans = 0;
  while (a.size() - i > 1) {
    if (a.back() + a[i] <= m)
      i++;
    a.pop_back();
    ans++;
  }

  if (a.size() - i >= 1)
    ans++;

  cout << ans << '\n';
}
