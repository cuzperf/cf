// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

using pi = std::pair<int, int>;

int mod;
int norm(int x) {
  if (x < 0) x += mod;
  else if (x >= mod) x -= mod;
  return x;
}

struct DSU {
  std::vector<int> p;
  std::vector<pi> a;
  DSU(int n) : p(n), a(n, {1, 0}) {
    iota(p.begin(), p.end(), 0);
  }
  int find(int x) {
    if (x == p[x]) return x;
    int r = find(p[x]);
    // v[p[x]] = v[r] * k + b
    auto [k, b] = a[p[x]];
    // v[x] = v[px] * a[x].first + a[x].second
    a[x] = {a[x].first * k, norm(a[x].first * b + a[x].second)};
    return p[x] = r;
  }
  bool merge(int x, int y, int b) {
    int px = find(x), py = find(y);
    auto [kx, bx] = a[x];
    auto [ky, by] = a[y];
    if (px == py) {
      if (kx + ky) return false;
      if (norm(bx + by) != b) return false;
    } else {
      // v[x] = v[px] * kx + bx
      // v[y] = v[py] * ky + by
      // v[px] = (v[x] - bx) * kx
      //       = (b - v[y] - bx) * kx
      //       = (b - v[py] * ky - by - bx) * kx
      int k = -kx * ky;
      b = norm(b - bx);
      b = norm(b - by);
      b = norm (b * kx);
      a[px] = {k, b};
      p[px] = py;
    }
    return true;
  }
};

constexpr int M = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m >> mod;
  std::vector a(n, std::vector<int>(m));
  for (auto &ai : a) for (auto& x : ai) {
    std::cin >> x;
  }
  DSU A(n + m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (int x = a[i][j]; x != -1) {
      if (!A.merge(i, n + j, norm(-x))) {
        std::cout << 0 << '\n';
        return;
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (a[i][j] == -1) {
      int px = A.find(i);
      int py = A.find(n + j);
      if (px != py) {
        A.merge(px, py, 0);
        ans = 1LL * ans * mod % M;
      }
    }
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
