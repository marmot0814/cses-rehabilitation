/*
   CSES - Movie Festival
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   In a movie festival n movies will be shown. You know the starting and
   ending time of each movie. What is the maximum number of movies you can
   watch entirely?

Input

   The first input line has an integer n: the number of movies.

   After this, there are n lines that describe the movies. Each line has
   two integers a and b: the starting and ending times of a movie.

Output

   Print one integer: the maximum number of movies.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a < b ≤ 10^9

Example

   Input:
3
3 5
4 9
5 8

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<pii>(n);
  for (auto &[f, s] : a)
    cin >> f >> s;
  sort(a.begin(), a.end(), [](auto &x, auto &y){
    return x.second < y.second;
  });

  int ans = 0, prev = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first >= prev) {
      ans++;
      prev = a[i].second;
    }
  }
  cout << ans << '\n';
}
