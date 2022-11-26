// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> ans;
  int l = 3 * n, r = 5 * n;
  while (ans.size() < n) {
    int x = n - ans.size();
    if (x == 1) {
      ans.emplace_back(4 * n);
    } else {
      ans.emplace_back(l++);
      ans.emplace_back(r--);
    }
  }
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
}


int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
