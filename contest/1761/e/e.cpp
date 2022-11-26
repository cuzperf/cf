// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

struct DSU {
  std::vector<int> p_;
  std::vector<std::set<int>> s_;
  DSU(int n) : p_(n), s_(n) {
    iota(p_.begin(), p_.end(), 0);
    for (int i = 0; i < n; ++i) s_[i].insert(i);
  }
  int find(int x) {
    return x == p_[x] ? x : p_[x] = find(p_[x]);
  }
  void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (s_[px].size() > s_[py].size()) std::swap(px, py);
    s_[py].merge(s_[px]);
    s_[px].clear();
    p_[px] = py;
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  DSU A(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i][j] == '1') A.merge(i, j);
    }
  }
  {
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (A.p_[i] == i) ++cnt;
    if (cnt == 1) {
      std::cout << 0 << '\n';
      return;
    }
  }
  int mi = INT_MAX, c = 0;
  for (int i = 0; i < n; ++i) if (A.p_[i] == i) {
    int ni = A.s_[i].size();
    std::vector<int> now(A.s_[i].begin(), A.s_[i].end());
    std::vector<int> cnt(ni);
    for (int j = 0; j < ni; ++j) {
      for (int k = 0; k < ni; ++k) if (j != k) {
        cnt[j] += a[now[j]][now[k]] - '0';
      }
    }
    int x = std::min_element(cnt.begin(), cnt.end()) - cnt.begin();
    if (ni == 1 || cnt[x] < ni - 1) {
      std::cout << 1 << '\n';
      std::cout << now[x] + 1 << '\n';
      return;
    }
    mi = std::min(mi, ni);
    ++c;
  }
  if (c == 2) {
    std::cout << mi << '\n';
    for (int i = 0; i < n; ++i) if (A.p_[i] == i) {
      if (A.s_[i].size() == mi) {
        for (auto x : A.s_[i]) {
          std::cout << x + 1 << ' ';
        }
        std::cout << '\n';
        return;
      }
    }
  } else {
    std::cout << 2 << '\n';
    for (int i = 0, t = 0; i < n && t < 2; ++i) if (A.p_[i] == i) {
      ++t;
      std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
  }
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
