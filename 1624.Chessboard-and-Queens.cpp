/*
   CSES - Chessboard and Queens
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Your task is to place eight queens on a chessboard so that no two
   queens are attacking each other. As an additional challenge, each
   square is either free or reserved, and you can only place queens on the
   free squares. However, the reserved squares do not prevent queens from
   attacking each other.

   How many possible ways are there to place the queens?

Input

   The input has eight lines, and each of them has eight characters. Each
   square is either free (.) or reserved (*).

Output

   Print one integer: the number of ways you can place the queens.

Example

   Input:
........
........
..*.....
........
........
.....**.
...*....
........

   Output:
65
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(auto &B, auto &R, auto &C, auto &S1, auto &S2, int cnt, auto &ans) {
  if (cnt == 8) {
    ans++;
    return ;
  }

  int i = cnt;
  for (int j = 0; j < 8; j++) {
    if (B[i][j] == '*') continue;
    if (R[i] or C[j] or S1[i + j] or S2[i - j + 7])
      continue;
    R[i] = 1;
    C[j] = 1;
    S1[i + j] = 1;
    S2[i - j + 7] = 1;
    B[i][j] = '*';
    dfs(B, R, C, S1, S2, cnt + 1, ans);
    R[i] = 0;
    C[j] = 0;
    S1[i + j] = 0;
    S2[i - j + 7] = 0;
    B[i][j] = '.';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  auto B = vector<vector<char>>(8, vector<char>(8));
  auto R = vector<int>(8);
  auto C = vector<int>(8);
  auto S1 = vector<int>(15);
  auto S2 = vector<int>(15);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      cin >> B[i][j];

  int ans = 0;
  dfs(B, R, C, S1, S2, 0, ans);
  cout << ans << '\n';
}
