/*
   CSES - Tasks and Deadlines
     * Time limit: 1.00 s
     * Memory limit: 512 MB

   You have to process n tasks. Each task has a duration and a deadline,
   and you will process the tasks in some order one after another. Your
   reward for a task is d-f where d is its deadline and f is your
   finishing time. (The starting time is 0, and you have to process all
   tasks even if a task would yield negative reward.)

   What is your maximum reward if you act optimally?

Input

   The first input line has an integer n: the number of tasks.

   After this, there are n lines that describe the tasks. Each line has
   two integers a and d: the duration and deadline of the task.

Output

   Print one integer: the maximum reward.

Constraints

     * 1 ≤ n ≤ 2 ⋅ 10^5
     * 1 ≤ a,d ≤ 10^6

Example

   Input:
3
6 10
8 15
5 12

   Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  auto arr = vector<pii>(n);
  for (auto &[f, s] : arr)
    cin >> f >> s;
  sort(arr.begin(), arr.end());
  ll ans = 0, t = 0;
  for (auto &[a, d] : arr) {
    t += a;
    ans += d - t;
  }
  cout << ans << '\n';
}
