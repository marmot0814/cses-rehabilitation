/*
   CSES - Nearest Smaller Values
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   Given an array of n integers, your task is to find for each array
   position the nearest position to its left having a smaller value.

Input

   The first input line has an integer n: the size of the array.

   The second line has n integers x_1,x_2,...,x_n: the array values.

Output

   Print n integers: for each array position the nearest position with a
   smaller value. If there is no such position, print 0.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
8
2 5 1 4 8 3 2 5

   Output:
0 1 0 3 4 3 3 7
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto arr = vector<int>(n);
  for (auto &v : arr) cin >> v;

  auto stk = vector<int>{};
  for (int i = 0; i < n; i++) {
    while (stk.size() and arr[stk.back()] >= arr[i])
      stk.pop_back();
    int l = -1, r = stk.size(); while (r - l > 1) {
      int m = (l + r) / 2;
      (arr[stk[m]] >= arr[i] ? r : l) = m;
    }

    cout << (l == -1 ? 0 : stk[l] + 1) << ' ';
    stk.push_back(i);
  }
  cout << '\n';
}
