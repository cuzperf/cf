// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;

  std::vector<std::multiset<int>> e(n);
  std::vector<int> vis(n);
  std::queue<int> Q;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i]-- == b[i]--) {
      ans = 1ll * ans * n % M;
      if (vis[a[i]]) return 0;
      Q.push(a[i]);
      vis[a[i]] = 1;
    } else {
      e[a[i]].emplace(b[i]);
      e[b[i]].emplace(a[i]);
    }
  }
  // step 1: assign value using self-loop
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : e[u]) {
      if (vis[v]) return 0;
      vis[v] = 1;
      Q.push(v);
      e[v].erase(e[v].find(u));
    }
  }
  for (int u = 0; u < n; ++u) if (!vis[u]) {
    int x = e[u].size();
    if (x == 0) return 0;
    if (x == 1) {
      Q.push(u);
    }
  }

  // step 2: assign for leafs
  while (!Q.empty()) {
    int u = Q.front();
    vis[u] = 1;
    Q.pop();
    int v = *e[u].begin();
    e[v].erase(e[v].find(u));
    if (e[v].empty()) return 0;
    if (e[v].size() == 1) {
      Q.push(v);
    }
  }

  // the reset are connected compoents with degree 2
  std::vector<int> p(n, -1);
  for (int i = 0; i < n; ++i) if (!vis[i]) {
    assert(e[i].size() == 2);
    p[i] = i;
  }
  std::function<int(int)> find = [&](int x) -> int {
    return x == p[x] ? x : p[x] = find(p[x]);
  };
  for (int u = 0; u < n; ++u) if (!vis[u]) {
    int fu = find(u);
    for (auto v : e[u]) if (!vis[v]) {
      p[find(v)] = fu;
    }
  }
  for (int i = 0; i < n; ++i) if (p[i] == i) {
    ans *= 2;
    if (ans >= M) ans -= M;
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
