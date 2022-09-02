// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k, r, c;
  std::cin >> n >> k >> r >> c;
  --r; --c;
  std::vector<std::string> a(n, std::string(n, '.'));
  for (int l = r; l < n; l += k) {
    for (int i = 0; i < n; ++i) {
      a[(l + i) % n][(c + i) % n] = 'X';
    }
  }
  for (int l = r - k; l >= 0; l -= k) {
    for (int i = 0; i < n; ++i) {
      a[(l + i) % n][(c + i) % n] = 'X';
    }
  }
  for (auto &x : a) std::cout << x << '\n';
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
