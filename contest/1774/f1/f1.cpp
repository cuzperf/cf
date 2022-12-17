// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int N = 2e5 + 1;

constexpr int M = 998244353;
constexpr int inv2 = (M + 1) / 2;

void add(int&x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int q;
  std::cin >> q;
  std::vector<int> f(N);
  LL d = 0, dd = 0;
  std::map<LL, int> mp;
  int s = 1, sinv = 1;
  auto cal = [&]() {
    std::vector<int> g(N);
    for (LL i = dd + 1; i < N; ++i) g[i - dd] = f[i];
    std::swap(f, g);

    for (auto [x, c] : mp) {
      LL xd = x - dd;
      if (xd > 0 && xd < N) {
        add(f[xd], 1ll * c * s % M);
      }
    }
    mp.clear();
    d += dd;
    dd = 0;
    s = sinv = 1;
  };
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 3) {
      if (d + dd == 0) {
        add(s, s);
        sinv = 1ll * sinv * inv2 % M;
      } else if (d + dd < N) {
        cal();
        std::vector<int> g(N);
        for (int i = d + 1; i < N; ++i) g[i - d] = f[i];
        for (int i = 1; i < N; ++i) add(f[i], g[i]);
        d *= 2;
      }
    } else {
      int x;
      std::cin >> x;
      if (op == 1) {
        add(mp[x + dd], sinv);
        // x += dd;
        // mp[x] += sinv;
        // if (mp[x] >= M) mp[x] -= M;
      } else {
        dd += x;
      }
    }
  }
  cal();
  std::cout << std::accumulate(f.begin() + 1, f.end(), 0ll) % M << '\n';
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
