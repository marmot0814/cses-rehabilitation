/*
   CSES - Palindrome Reorder
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given a string, your task is to reorder its letters in such a way that
   it becomes a palindrome (i.e., it reads the same forwards and
   backwards).

Input

   The only input line has a string of length n consisting of characters
   A–Z.

Output

   Print a palindrome consisting of the characters of the original string.
   You may print any valid solution. If there are no solutions, print "NO
   SOLUTION".

Constraints

     * 1 ≤ n ≤ 10^6

Example

   Input:
AAAACACBA

   Output:
AACABACAA
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s; cin >> s;
  auto cnt = vector<int>(26);
  for (auto &c : s)
    cnt[c - 'A']++;
  int odd = 0, odd_id = -1;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) {
      odd++;
      odd_id = i;
    }
  }
  if (odd > 1) {
    cout << "NO SOLUTION\n";
  } else {
    for (int i = 0; i < 26; i++)
      for (int x = 0; x < cnt[i] / 2; x++)
        cout << char('A' + i);
    if (odd_id != -1)
      cout << char('A' + odd_id);
    for (int i = 25; i >= 0; i--)
      for (int x = 0; x < cnt[i] / 2; x++)
        cout << char('A' + i);
    cout << '\n';
  }
}
