/*
   CSES - Apartments
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   There are n applicants and m free apartments. Your task is to
   distribute the apartments so that as many applicants as possible will
   get an apartment.

   Each applicant has a desired apartment size, and they will accept any
   apartment whose size is close enough to the desired size.

Input

   The first input line has three integers n, m, and k: the number of
   applicants, the number of apartments, and the maximum allowed
   difference.

   The next line contains n integers a_1, a_2, …, a_n: the desired
   apartment size of each applicant. If the desired size of an applicant
   is x, he or she will accept any apartment whose size is between x-k and
   x+k.

   The last line contains m integers b_1, b_2, …, b_m: the size of
   each apartment.

Output

   Print one integer: the number of applicants who will get an apartment.

Constraints

     * 1 ≤ n, m ≤ 2 ⋅ 10^5
     * 0 ≤ k ≤ 10^9
     * 1 ≤ a_i, b_i ≤ 10^9

Example

   Input:
4 3 5
60 45 80 60
30 60 75

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;

  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;
  auto b = vector<int>(m);
  for (auto &v : b) cin >> v;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int a_ptr = 0, b_ptr = 0, ans = 0;
  while (a_ptr < a.size() and b_ptr < b.size()) {
    if (abs(a[a_ptr] - b[b_ptr]) <= k) {
      ans++;
      a_ptr++;
      b_ptr++;
    } else if (a[a_ptr] < b[b_ptr])
      a_ptr++;
    else
      b_ptr++;
  }
  cout << ans << '\n';
}
