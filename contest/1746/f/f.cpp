// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegTree {
  int n;
  std::vector<int> g;
  void pull(int p) {
    g[p] = std::gcd(g[p << 1], g[p << 1| 1]);
  }
  void update(int x, int val, int l, int r, int p) {
    if (r - l == 1) {
      g[p] = val;
    } else {
      int m = (l + r) / 2;
      if (x < m) update(x, val, l, m, p << 1);
      else update(x, val, m, r, p << 1 | 1);
      pull(p);
    }
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) {
      return g[p];
    }
    int m = (l + r) / 2;
    int ans = 0;
    if (L < m) ans = std::gcd(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::gcd(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegTree(std::vector<int>& a) : n(a.size()), g(n * 4) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        g[p] = a[l];
      } else {
        int m = (l + r) / 2;
        build(l, m, p << 1);
        build(m, r, p << 1 | 1);
        pull(p);
      }
    };
    build(0, n, 1);
  }
  void update(int x, int val) {
    update(x - 1, val, 0, n, 1);
  }
  int query(int l, int r) {
    return query(l - 1, r, 0, n, 1);
  }
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  SegTree A(a);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, val;
      std::cin >> x >> val;
      A.update(x, val);
    } else {
      int l, r, k;
      std::cin >> l >> r >> k;
      std::cerr << l << ' ' << r << ' ' << A.query(l, r) << '\n';
      std::cout << (A.query(l, r) % k == 0 ? "YES" : "NO") << '\n';
    }
  }
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
