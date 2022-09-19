// https://github.com/cuzperf/cf
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = k; i < n; ++i) {
    a[i % k] = std::max(a[i % k], a[i]);
  }
  std::cout << std::accumulate(a.begin(), a.begin() + k, 0LL) << '\n';
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
