// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

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

bool solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int nm = n * m - 3; // less than 1e6
  std::vector<int> a(k);
  for (auto &x : a) std::cin >> x;
  Bitree<int> A(k);
  for (int i = 0; i < k; ++i) {
    int x = a[i];
    if (A.sum(x) >= nm) return false;
    A.add(--x, 1);
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YA" : "TIDAK") << '\n';
  }
  return 0;
}
