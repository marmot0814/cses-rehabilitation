/*
   CSES - Two Sets
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to divide the numbers 1,2,…,n into two sets of equal
   sum.

Input

   The only input line contains an integer n.

Output

   Print "YES", if the division is possible, and "NO" otherwise.

   After this, if the division is possible, print an example of how to
   create the sets. First, print the number of elements in the first set
   followed by the elements themselves in a separate line, and then, print
   the second set in a similar way.

Constraints

     * 1 ≤ n ≤ 10^6

Example 1

   Input:
7

   Output:
YES
4
1 2 4 7
3
3 5 6

Example 2

   Input:
6

   Output:
NO
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n; cin >> n;
  auto sum = (1 + n) * n / 2;
  if (sum % 2 == 1) {
    cout << "NO\n";
    return 0;
  }
  auto tar = sum / 2;
  cout << "YES\n";
  int cnt = 0;
  auto used = vector<int>(n + 1, 0);
  ll ptr = n;
  while (tar) {
    auto choose = min(ptr, tar);
    used[choose] = 1;
    ptr = choose - 1;
    tar -= choose;
    cnt++;
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++)
    if (used[i])
      cout << i << ' ';
  cout << '\n';
  cout << n - cnt << '\n';
  for (int i = 1; i <= n; i++)
    if (used[i] == 0)
      cout << i << ' ';
  cout << '\n';
}
