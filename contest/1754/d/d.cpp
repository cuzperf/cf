// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n, p;
  std::cin >> n >> p;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++mp[x];
  }
  while (!mp.empty()) {
    auto [x, cnt] = *mp.begin();
    if (x == p) break;
    if (cnt % (x + 1) != 0) return false;
    mp.erase(mp.begin());
    mp[x + 1] += cnt / (x + 1);
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
