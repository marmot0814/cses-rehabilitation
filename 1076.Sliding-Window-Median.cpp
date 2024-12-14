/*
   CSES - Sliding Window Median
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers. Your task is to calculate the
   median of each window of k elements, from left to right.

   The median is the middle element when the elements are sorted. If the
   number of elements is even, there are two possible medians and we
   assume that the median is the smaller of them.

Input

   The first input line contains two integers n and k: the number of
   elements and the size of the window.

   Then there are n integers x_1,x_2,…,x_n: the contents of the
   array.

Output

   Print n-k+1 values: the medians.

Constraints

     * 1 ≤ k ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
8 3
2 4 3 5 8 1 2 1

   Output:
3 4 5 5 2 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void mentain(auto &st1, auto &st2) {
  int n = st1.size() + st2.size();
  while (st2.size() > n / 2) {
    st1.insert(*st2.begin());
    st2.erase(st2.begin());
  }
  while (st2.size() < n / 2) {
    st2.insert(*st1.rbegin());
    st1.erase(prev(st1.end()));
  }
}

void print(auto &st1, auto &st2) {
  std::cout << "st1: ";
  for (auto &v : st1)
    cout << v << ' ';
  cout << '\n';
  std::cout << "st2: ";
  for (auto &v : st2)
    cout << v << ' ';
  cout << '\n';
}

void add(int v, auto &st1, auto &st2) {
  if (st1.size() == 0) {
    st1.insert(v);
    return ;
  }

  if (*st1.rbegin() >= v)
    st1.insert(v);
  else
    st2.insert(v);
  mentain(st1, st2);
}

void remove(int v, auto &st1, auto &st2) {
  if (*st1.rbegin() >= v) {
    st1.erase(st1.find(v));
  } else {
    st2.erase(st2.find(v));
  }
  mentain(st1, st2);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto a = vector<int>(n);
  for (auto &v : a) cin >> v;

  auto st1 = multiset<int>{};
  auto st2 = multiset<int>{};
  for (int i = 0; i < k - 1; i++)
    add(a[i], st1, st2);

  for (int i = k - 1; i < n; i++) {
    add(a[i], st1, st2);
    cout << *st1.rbegin() << ' ';
    remove(a[i - k + 1], st1, st2);
  }
  cout << '\n';
}
