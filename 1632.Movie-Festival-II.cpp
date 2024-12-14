/*
   CSES - Movie Festival II
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   In a movie festival, n movies will be shown. Syrjälä's movie club
   consists of k members, who will be all attending the festival.

   You know the starting and ending time of each movie. What is the
   maximum total number of movies the club members can watch entirely if
   they act optimally?

Input

   The first input line has two integers n and k: the number of movies and
   club members.

   After this, there are n lines that describe the movies. Each line has
   two integers a and b: the starting and ending time of a movie.

Output

   Print one integer: the maximum total number of movies.

Constraints

     * 1 ≤ k ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a < b ≤ 10^9

Example

   Input:
5 2
1 5
8 10
3 6
2 5
6 9

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto a = vector<pii>(n);
  for (auto &[f, s] : a)
    cin >> f >> s;
  sort(a.begin(), a.end(), [](auto &x, auto &y){ return x.second < y.second; });
  auto st = multiset<int>{};
  for (int i = 0; i < k; i++)
    st.insert(0);
  int ans = 0;
  for (auto [s, e] : a) {
    auto it = st.upper_bound(s);
    if (it == st.begin())
      continue;
    it = prev(it);
    st.erase(it);
    st.insert(e);
    ans++;
  }
  cout << ans << '\n';
}
