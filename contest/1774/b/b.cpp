// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(m);
  for (auto &x : a) std::cin >> x;
  if (k > m) return false;
  std::sort(a.begin(), a.end(), std::greater<>());
  for (int i = 0; i < m; ++i) {
    if ((n - i - 1) / k + 1 < a[i]) return false;
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
