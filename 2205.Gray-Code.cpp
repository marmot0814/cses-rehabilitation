/*
   CSES - Gray Code
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   A Gray code is a list of all 2^n bit strings of length n, where any two
   successive strings differ in exactly one bit (i.e., their Hamming
   distance is one).

   Your task is to create a Gray code for a given length n.

Input

   The only input line has an integer n.

Output

   Print 2^n lines that describe the Gray code. You can print any valid
   solution.

Constraints

     * 1 ≤ n ≤ 16

Example

   Input:
2

   Output:
00
01
11
10
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto gen(int n) {
  if (n == 1)
    return vector<string>{"0", "1"};

  auto ret = gen(n - 1);
  int sz = ret.size();
  for (int i = 0; i < sz; i++)
    ret.push_back(ret[sz - i - 1]);
  for (int i = 0; i < sz; i++)
    ret[i] += '0';
  for (int i = 0; i < sz; i++)
    ret[sz + i] += '1';
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto ans = gen(n);
  for (auto &v : ans)
    cout << v << '\n';
}
