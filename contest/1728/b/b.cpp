// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  if (n % 2) {
    std::cout << 1 << ' ';
    for (int i = n - 2; i > 1; i -= 2) {
      std::cout << i << ' ' << i - 1 << ' ';
    }
    std::cout << n - 1 << ' ' << n << '\n';
  } else {
    for (int i = n - 2; i > 1; i -= 2) {
      std::cout << i << ' ' << i - 1 << ' ';
    }
    std::cout << n - 1 << ' ' << n << '\n';
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
