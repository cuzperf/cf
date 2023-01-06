// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// n n - 1, ... n - k + 2, 1, 2, 3, k - 1
//

void solve() {
  int n, k;
  std::cin >> n >> k;
  int l = 1, r = n;
  while (l <= r) {
    std::cout << r-- << ' ';
    for (int i = 2; i < k && l <= r; ++i) {
      std::cout << r-- << ' ';
    }
    if (l <= r) {
      std::cout << l++ << ' ';
    }
    for (int i = 2; i < k && l <= r; ++i) {
      std::cout << l++ << ' ';
    }
  }
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
