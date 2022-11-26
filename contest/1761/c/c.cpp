// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> b(n);
  for (auto &x : b) std::cin >> x;
  std::vector<std::vector<int>> e(n);
  std::vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == '1') {
        e[i].emplace_back(j);
        ++d[j];
      }
    }
  }
  std::vector<std::set<int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].insert(i + 1);
  }
  std::queue<int> Q;
  for (int i = 0;i < n; ++i) {
    if (d[i] == 0) {
      Q.push(i);
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : e[u]) {
      a[v].insert(a[u].begin(), a[u].end());
      if (--d[v] == 0) {
        Q.push(v);
      }
    }
  }
  for (const auto & ai : a) {
    std::cout << ai.size() << ' ';
    for (auto x : ai) std::cout << x << ' ';
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
