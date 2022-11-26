// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// 1 2 3 2 1 2 3 2
// 1 2 3 1 2 1 2 1 2
// 1 3 2 1 3 1 2
// 3 2 1 3 1
// 3
// 1 3 1 3 1 2 1 2
// 1 2 1 2 1 2

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    s.insert(a[i]);
  }
  if (s.size() != 2) {
    std::cout << n << '\n';
  } else {
    std::cout << n / 2 + 1 << '\n';
  }
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
