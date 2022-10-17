// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;

template<typename T>
class SegTree {
  int n;
  std::vector<T> mx, tag;
  void pushUp(int p) {
    mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
  }
  void deal(T val, int l, int r, int p) {
    mx[p] = tag[p] = val;
  }
  void pushDown(int l, int r, int p) {
    if (tag[p]) {
      int m = (l + r) / 2;
      deal(tag[p], l, m, p << 1);
      deal(tag[p], m, r, p << 1 | 1);
      tag[p] = 0;
    }
  }
  void update(int L, int R, T val, int l, int r, int p) {
    if (L <= l && R >= r) {
      deal(val, l, r, p);
    } else {
      pushDown(l, r, p);
      int m = (l + r) / 2;
      if (L < m) update(L, R, val, l, m, p << 1);
      if (R > m) update(L, R, val, m, r, p << 1 | 1);
      pushUp(p);
    }
  }
  T query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) {
      return mx[p];
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    T ans = 0;
    if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegTree(int _n) : n(_n), mx(4 * n), tag(4 * n) {}
  void update(int L, int R, T val) {
    update(L, R + 1, val, 0, n, 1);
  }
  T query(int id) {
    return query(id, id + 1, 0, n, 1);
  }
};

using Tree = SegTree<int>;
constexpr int N = 3e5 + 2;

void solve() {
  Tree A(N);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    std::cin >> l >> r;
    A.update(l, r, i);
  }
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < N; ++i) {
    ++cnt[A.query(i)];
  }
  std::vector<int> p2(n);
  p2[0] = 1;
  for (int i = 1; i < n; ++i) {
    p2[i] = p2[i - 1] * 2 % M;
  }
  std::vector<int> p3(n);
  p3[0] = 1;
  for (int i = 1; i < n; ++i) {
    p3[i] = 1LL * p3[i - 1] * 3 % M;
  }
  int ans = 1LL * cnt[1] * p2[n - 1] % M;
  for (int i = 1; i < n; ++i) {
    ans = (ans + 1LL * cnt[i + 1] * p2[n - i] % M * p3[i - 1]) % M;
  }
  std::cout << ans << '\n';
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
