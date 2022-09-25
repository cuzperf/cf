// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  std::vector<int> a(10);
  std::string ans;
  for (int i = 0; i < 10; ++i) {
    for (int j = s.size() - 1; j >= 0; --j) if (s[j] - '0' == i) {
      for (int k = 0; k <= j; ++k) {
        if (s[k] - '0' == i) ++a[i];
        else ++a[std::min(s[k] - '0' + 1, 9)];
      }
      s = std::string(s.begin() + j + 1, s.end());
      break;
    }
    ans += std::string(a[i], i + '0');
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
