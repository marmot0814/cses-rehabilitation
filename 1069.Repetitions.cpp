/*
   CSES - Repetitions
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given a DNA sequence: a string consisting of characters A, C,
   G, and T. Your task is to find the longest repetition in the sequence.
   This is a maximum-length substring containing only one type of
   character.

Input

   The only input line contains a string of n characters.

Output

   Print one integer: the length of the longest repetition.

Constraints

     * 1 ≤ n ≤ 10^6

Example

   Input:
ATTCGGGA

   Output:
3
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; cin >> s;
  auto prev = '\0';
  auto cnt = 0, ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != prev) {
      prev = s[i];
      cnt = 1;
    } else
      cnt++;
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}
