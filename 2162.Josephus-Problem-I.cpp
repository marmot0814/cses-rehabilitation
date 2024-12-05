/*
   CSES - Josephus Problem I
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Consider a game where there are n children (numbered 1,2,...,n) in a
   circle. During the game, every other child is removed from the circle
   until there are no children left. In which order will the children be
   removed?

Input

   The only input line has an integer n.

Output

   Print n integers: the removal order.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5

Example

   Input:
7

   Output:
2 4 6 1 5 3 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto que = queue<int>{};
  for (int i = 1; i <= n; i++)
    que.push(i);

  while (que.size()) {
    auto p1 = que.front(); que.pop(); que.push(p1);
    auto p2 = que.front(); que.pop();
    cout << p2 << ' ';
  }
}
