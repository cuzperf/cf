// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int p1, p2, h, s;
  LL t1, t2;
  std::cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
  p1 -= s; p2 -= s;
  std::vector<LL> dp(h + 1);
  for (int i = 1; i <= h; ++i) {
    dp[i] = std::min(dp[std::max(0, i - p1)] + t1, dp[std::max(0, i - p2)] + t2);
    for (int j = 1; j <= i; ++j) {
      if (j * t1 >= t2) {
        LL dmg = (j - 1) * p1 + (j * t1 / t2 - 1) * p2 + (p1 + p2 + s);
        dp[i] = std::min(dp[i], dp[std::max(0LL, i - dmg)] + j * t1);
      }
      if (j * t2 >= t1) {
        LL dmg = (j - 1) * p2 + (j * t2 / t1 - 1) + (p1 + p2 + s);
        dp[i] = std::min(dp[i], dp[std::max(0LL, i - dmg)] + j * t2);
      }
    }
  }
  std::cout << dp[h] << '\n';
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
