// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) return false;
  }
  for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
    if (b[i] - b[(i + 1) % n] > 1) return false;
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
