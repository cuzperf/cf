// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int l = 0, r = n - 1;
  int ans = 0;
  while (l <= r) {
    while (l <= r && a[l] == 0) ++l;
    while (l <= r && a[r] == 1) --r;
    if (l <= r) ++ans;
    ++l;
    --r;
  }
  std::cout << ans << '\n';
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
