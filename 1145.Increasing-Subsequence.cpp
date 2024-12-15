/*
   CSES - Increasing Subsequence
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array containing n integers. Your task is to determine
   the longest increasing subsequence in the array, i.e., the longest
   subsequence where every element is larger than the previous one.

   A subsequence is a sequence that can be derived from the array by
   deleting some elements without changing the order of the remaining
   elements.

Input

   The first line contains an integer n: the size of the array.

   After this there are n integers x_1,x_2,…,x_n: the contents of the
   array.

Output

   Print the length of the longest increasing subsequence.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
8
7 3 5 3 6 2 9 8

   Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto lis = vector<int>{};
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    auto it = lower_bound(lis.begin(), lis.end(), v) - lis.begin();
    if (lis.size() == it)
      lis.push_back(v);
    else
      lis[it] = v;
  }
  cout << lis.size() << '\n';
}
