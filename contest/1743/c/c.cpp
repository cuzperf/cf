// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int ans = 0, now = 0;
  while (now < n && s[now] == '1') {
    ans += a[now++];
  }
  while (now < n) {
    while (now < n && s[now] == '0') ++now;
    int last = now - 1;
    int cur = a[last];
    while (now < n && s[now] == '1') {
      cur = std::min(cur, a[now]);
      ans += a[now++];
    }
    ans += a[last] - cur;
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
