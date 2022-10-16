// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct Bitree {
  const int n_;
  std::vector<T> s_;
  Bitree() {}
  Bitree(int n) : n_(n), s_(n) {}
  static int lowbit(int n) { return n & (-n); }
  void add(int id, T p) {
    for (int i = id + 1; i <= n_; i += lowbit(i)) {
      s_[i - 1] += p;
    }
  }
  T sum(int id) {
    T r = 0;
    for (int i = id; i > 0; i -= lowbit(i)) {
      r += s_[i - 1];
    }
    return r;
  }
  T sum(int l, int r) { return sum(r) - sum(l); }
};

constexpr int CNT = 52;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto b = a;
  std::vector<int> op(q), l(q), r(q), k(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> op[i] >> l[i] >> r[i];
    --l[i];
    if (op[i] == 1) {
      b.emplace_back(r[i]);
    } else {
      std::cin >> k[i];
    }
  }
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  for (auto &x : a) x = std::lower_bound(b.begin(), b.end(), x) - b.begin();
  for (int i = 0; i < q; ++i) if (op[i] == 1) {
    r[i] = std::lower_bound(b.begin(), b.end(), r[i]) - b.begin();
  }
  int m = b.size();
  std::vector<int> ans(q, 1);
  for (int _ = 0; _ < CNT; ++_) {
    std::vector<int> f(m);
    for (int i = 0; i < m; ++i) {
      f[i] = rnd() % 998244353;
    }
    Bitree<LL> A(n);
    for (int i = 0; i < n; ++i) {
      A.add(i, f[a[i]]);
    }
    auto c = a;
    for (int i = 0; i < q; ++i) {
      if (op[i] == 1) {
        A.add(l[i], f[r[i]] - f[c[l[i]]]);
        c[l[i]] = r[i];
      } else {
        if (ans[i] && A.sum(l[i], r[i]) % k[i] != 0) {
          ans[i] = 0;
        }
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    if (op[i] == 2) {
      std::cout << (ans[i] ? "YES" : "NO") << '\n';
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
