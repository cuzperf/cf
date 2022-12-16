// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> dp(n);
  dp[0] = 1;
  int res = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      dp[i] = dp[i - 1] * 2 % M;
      ++res;
    } else {
      dp[i] = dp[i - res - 1];
      res = 0;
    }
  }
  std::cout << std::accumulate(dp.begin(), dp.end(), 0ll) % M << '\n';
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
