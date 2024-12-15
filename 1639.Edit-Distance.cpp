/*
   CSES - Edit Distance
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   The edit distance between two strings is the minimum number of
   operations required to transform one string into the other.

   The allowed operations are:
     * Add one character to the string.
     * Remove one character from the string.
     * Replace one character in the string.

   For example, the edit distance between LOVE and MOVIE is 2, because you
   can first replace L with M, and then add I.

   Your task is to calculate the edit distance between two strings.

Input

   The first input line has a string that contains n characters between
   A–Z.

   The second input line has a string that contains m characters between
   A–Z.

Output

   Print one integer: the edit distance between the strings.

Constraints

     * 1 ≤ n,m ≤ 5000

Example

   Input:
LOVE
MOVIE

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  auto s = string{};
  auto t = string{};
  cin >> s >> t;
  auto dp = vector<vector<int>>(2, vector<int>(t.size() + 1));
  for (int i = 0; i <= t.size(); i++)
    dp[0][i] = i;
  for (int i = 1; i <= s.size(); i++) {
    dp[i % 2][0] = i;
    for (int j = 1; j <= t.size(); j++) {
      dp[i % 2][j] = min({
        dp[(i - 1) % 2][j - 1] + (s[i - 1] != t[j - 1]),
        dp[(i - 1) % 2][j] + 1,
        dp[i % 2][j - 1] + 1
      });
    }
  }
  cout << dp[s.size() % 2].back() << '\n';
}
