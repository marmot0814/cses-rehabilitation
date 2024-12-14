/*
   CSES - Reading Books
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n books, and Kotivalo and Justiina are going to read them
   all. For each book, you know the time it takes to read it.

   They both read each book from beginning to end, and they cannot read a
   book at the same time. What is the minimum total time required?

Input

   The first input line has an integer n: the number of books.

   The second line has n integers t_1,t_2,...,t_n: the time required to
   read each book.

Output

   Print one integer: the minimum total time.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ t_i ≤ 10^9

Example

   Input:
3
2 8 3

   Output:
16
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<ll>(n);
  ll sum = 0, maxv = 0;
  for (auto &v : a) {
    cin >> v;
    sum += v;
    maxv = max(maxv, v);
  }

  if (maxv >= sum - maxv) {
    cout << maxv * 2 << '\n';
  } else {
    cout << sum << '\n';
  }
}
