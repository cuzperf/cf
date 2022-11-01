// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;
void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    int x;
    ++cnt[--x];
  }
  std::vector<int> cc(n + 1);
  for (auto x : cnt) ++cc[x];
  std::vector<int> lim(n + 1);
  for (int i = 0, res = n, now = 0; i <= n; ++i) {
    now += i * cc[i];
    res -= cc[i];
    lim[i] = now + res * i;
  }
  std::vector dp(n + 1, std::vector<int>(n + 1));
  dp[0][0] = 1;
  for (int last = n; last > 0; --last) {
    for (int i = 0; i + last <= n; ++i) {
      for (int j = 0; j * last <= i; ++j) {
        if (i + last <= lim[j + 1]) {
          add(dp[i + last][j + 1], dp[i][j]);
        }
      }
    }
  }
  std::cout << std::accumulate(dp[n].begin(), dp[n].back(), 0LL) % M << '\n';
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
