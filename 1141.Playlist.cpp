/*
   CSES - Playlist
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given a playlist of a radio station since its establishment.
   The playlist has a total of n songs.

   What is the longest sequence of successive songs where each song is
   unique?

Input

   The first input line contains an integer n: the number of songs.

   The next line has n integers k_1,k_2,…,k_n: the id number of each
   song.

Output

   Print the length of the longest sequence of unique songs.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ k_i ≤ 10^9

Example

   Input:
8
1 2 1 3 2 7 4 2

   Output:
5
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;

  auto st = set<int>{};
  int ans = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n and not st.count(a[r]))
      st.insert(a[r++]);
    ans = max(ans, (int)st.size());
    st.erase(a[l]);
  }
  cout << ans << '\n';
}
