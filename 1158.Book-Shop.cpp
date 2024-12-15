/*
   CSES - Book Shop
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are in a book shop which sells n different books. You know the
   price and number of pages of each book.

   You have decided that the total price of your purchases will be at most
   x. What is the maximum number of pages you can buy? You can buy each
   book at most once.

Input

   The first input line contains two integers n and x: the number of books
   and the maximum total price.

   The next line contains n integers h_1,h_2,…,h_n: the price of each
   book.

   The last line contains n integers s_1,s_2,…,s_n: the number of
   pages of each book.

Output

   Print one integer: the maximum number of pages.

Constraints

     * 1 ≤ n ≤ 1000
     * 1 ≤ x ≤ 10^5
     * 1 ≤ h_i, s_i ≤ 1000

Example

   Input:
4 10
4 8 5 3
5 12 8 1

   Output:
13

   Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the
   number of pages is 5+8=13.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x; cin >> n >> x;
  auto page = vector<int>(n);
  auto price = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> page[i];
  auto dp = vector<int>(x + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = x; j >= price[i]; j--) {
      dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
    }
  }
  cout << dp[x] << '\n';
}
