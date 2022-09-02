// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::set<std::string> S[3];
  std::cin >> n;
  for (int _ = 0; _ < 3; ++_) {
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      S[_].insert(std::move(s));
    }
  }
  int ans[3]{};
  for (int _ = 0; _ < 3; ++_) {
    for (auto &x : S[_]) {
      int t = 0;
      for (int i = 0; i < 3; ++i) if (i != _) {
        if (S[i].count(x)) ++t;
      }
      if (t == 0) ans[_] += 3;
      else if (t == 1) ++ans[_];
    }
  }
  std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
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
