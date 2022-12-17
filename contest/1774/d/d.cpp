// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  for (auto &ai : a) for (auto& x : ai) std::cin >> x;
  std::vector<int> sz(n);
  for (int i = 0; i < n; ++i) sz[i] = std::accumulate(a[i].begin(), a[i].end(), 0);
  int sm = std::accumulate(sz.begin(), sz.end(), 0);
  if (sm % n) {
    std::cout << -1 << '\n';
    return;
  }
  int av = sm / n;
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) { return sz[i] < sz[j];});

  std::vector<std::tuple<int, int, int>> ans;
  int l = 0, r = n - 1;
  while (l < r) {
    int pl = p[l], pr = p[r];
    auto& xl = a[pl];
    auto& xr = a[pr];
    for (int i = 0; i < m && sz[pl] < av && sz[pr] > av; ++i) {
      if (xl[i] == 0 && xr[i] == 1) {
        ans.emplace_back(pl, pr, i);
        ++sz[pl];
        --sz[pr];
        std::swap(xl[i], xr[i]);
      }
    }
    if (sz[pl] == av) ++l;
    if (sz[pr] == av) --r;
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) std::cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
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
