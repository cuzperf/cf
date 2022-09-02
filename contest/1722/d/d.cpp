// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  LL ans = 0;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int l = i, r = n - 1 - i;
    int now = (s[i] == 'L' ? l : r);
    ans += now;
    a[i] = std::max(l, r) - now;
  }
  std::sort(a.begin(), a.end());
  for (int i = 1; i <= n; ++i) {
    ans += a[n - i];
    std::cout << ans << " \n"[i == n];
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
