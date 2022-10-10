// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegTree {
  int n_;
  std::vector<int> mx_;
  void pushUp(int p) {
    mx_[p] = std::min(mx_[p << 1], mx_[p << 1 | 1]);
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) {
      return mx_[p];
    }
    int m = (l + r) / 2;
    int ans = INT_MAX;
    if (L < m) ans = std::min(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::min(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegTree(std::vector<int>& a) : n_(a.size()), mx_(n_ * 4, INT_MAX) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        mx_[p] = a[l];
      } else {
        int m = (l + r) / 2;
        build(l, m, p << 1);
        build(m, r, p << 1 | 1);
        pushUp(p);
      }
    };
    build(0, n_, 1);
  }
  int query(int l, int r) {
    return query(l, r, 0, n_, 1);
  }
};

// a_i >= 1
// a_i

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    a[i] -= i;
  }
  SegTree A(a);
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n;
    while (l <= r) {
      int m = (l + r) / 2;
      if (A.query(i, m) <= -i) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    ans += r - i;
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
