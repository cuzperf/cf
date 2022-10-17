// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int now = 0;
  while (now < n && s[now] == '0') ++now;
  s = std::string(s.begin() + now, s.end());
  n -= now;
  if (n == 0) {
    std::cout << 0 << '\n';
    return;
  }
  now = 0;
  while (now < n && s[now] == '1') ++now;
  if (now == n) {
    std::cout << s << '\n';
    return;
  }
  std::string ans = s;
  for (int i = 1; i <= now; ++i) {
    std::string cur = s;
    for (int j = i; j < n; ++j) {
      cur[j] |= s[j - i];
    }
    ans = std::max(ans, cur);
  }
  std::cout << ans << '\n';
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
