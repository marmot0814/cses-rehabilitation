/*
   CSES - Sliding Window Cost
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You are given an array of n integers. Your task is to calculate for
   each window of k elements, from left to right, the minimum total cost
   of making all elements equal.

   You can increase or decrease each element with cost x where x is the
   difference between the new and the original value. The total cost is
   the sum of such costs.

Input

   The first input line contains two integers n and k: the number of
   elements and the size of the window.

   Then there are n integers x_1,x_2,…,x_n: the contents of the
   array.

Output

   Output n-k+1 values: the costs.

Constraints

     * 1 ≤ k ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ x_i ≤ 10^9

Example

   Input:
8 3
2 4 3 5 8 1 2 1

   Output:
2 2 5 7 7 1
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void mentain(auto &st1, auto &st2, auto &st1s, auto &st2s) {
  int n = st1.size() + st2.size();
  while (st2.size() > n / 2) {
    st1.insert(*st2.begin());
    st1s += *st2.begin();
    st2s -= *st2.begin();
    st2.erase(st2.begin());
  }
  while (st2.size() < n / 2) {
    st2.insert(*st1.rbegin());
    st2s += *st1.rbegin();
    st1s -= *st1.rbegin();
    st1.erase(prev(st1.end()));
  }
}

void add(int v, auto &st1, auto &st2, auto &st1s, auto &st2s) {
  if (st1.size() == 0) {
    st1.insert(v);
    st1s += v;
    return ;
  }

  if (*st1.rbegin() >= v) {
    st1.insert(v);
    st1s += v;
  } else {
    st2.insert(v);
    st2s += v;
  }
  mentain(st1, st2, st1s, st2s);
}

void remove(int v, auto &st1, auto &st2, auto &st1s, auto &st2s) {
  if (*st1.rbegin() >= v) {
    st1.erase(st1.find(v));
    st1s -= v;
  } else {
    st2.erase(st2.find(v));
    st2s -= v;
  }
  mentain(st1, st2, st1s, st2s);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  auto a = vector<int>(n);
  auto preS = vector<ll>{0};
  for (auto &v : a) {
    cin >> v;
    preS.push_back(preS.back() + v);
  }

  ll st1s = 0, st2s = 0;
  auto st1 = multiset<int>{};
  auto st2 = multiset<int>{};
  for (int i = 0; i < k - 1; i++)
    add(a[i], st1, st2, st1s, st2s);

  for (int i = k - 1; i < n; i++) {
    add(a[i], st1, st2, st1s, st2s);
    ll tar = *st1.rbegin();
    cout << tar * st1.size() - st1s + st2s - tar * st2.size() << ' ';
    remove(a[i - k + 1], st1, st2, st1s, st2s);
  }
  cout << '\n';
}
