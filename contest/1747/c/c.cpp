// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// a1 = 0 lost, otherwise
// if ai = 0 for some i > 1 win, otherwise
// if a1 = 1, lost, otherwise
// if ai = 1 for some i > 1 win, otherwise

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  return a[0] > *std::min_element(a.begin() + 1, a.end());
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Alice" : "Bob") << '\n';
  }
  return 0;
}
