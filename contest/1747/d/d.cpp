// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
  }
  std::map<int, int> zero;
  int now = 1;
  while (now <= n) {
    while (now <= n && a[now] != a[now - 1]) ++now;
    int i = now;
    while (now <= n && a[now] == a[now - 1]) ++now;
    if (i < now) zero[i] = now;
  }
  std::map<int, int> mp[2];
  std::vector<int> left(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (mp[(i & 1) == 0].count(a[i])) {
      left[i] = mp[((i & 1) ^ 1)][a[i]];
    }
    mp[i & 1][a[i]] = i;
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (a[r] != a[l - 1]) {
      std::cout << -1 << '\n';
    } else {
      auto it = zero.upper_bound(l);
      if (it != zero.begin() && (--it)->second > r) {
        std::cout << 0 << '\n';
      } else if ((r - l) % 2 == 0) {
        std::cout << 1 << '\n';
      } else if (left[r] > l) {
        std::cout << 2 << '\n';
      } else {
        std::cout << -1 << '\n';
      }
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
