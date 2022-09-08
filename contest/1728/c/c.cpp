// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
using Node = std::map<int, int>;

int f(int x) {
  int ans = 0;
  while (x) {
    ++ans;
    x /= 10;
  }
  return ans;
}

int f(Node & a) {
  int ans = 0;
  Node b;
  for (auto [x, y] : a) {
    if (x < 10) {
      b[x] += y;
    } else {
      b[f(x)] += y;
      ans += y;
    }
  }
  std::swap(a, b);
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  Node a, b;
  std::set<int> S;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++a[x];
    S.insert(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++b[x];
    S.insert(x);
  }
  for (auto x : S) {
    auto ia = a.find(x);
    auto ib = b.find(x);
    if (ia != a.end() && ib != b.end()) {
      int t = std::min(ia->second, ib->second);
      ia->second -= t;
      if (ia->second == 0) a.erase(ia);
      ib->second -= t;
      if (ib->second == 0) b.erase(ib);
    }
  }
  int ans = 0;
  ans += f(a);
  ans += f(b);
  for (int i = 2; i < 10; ++i) {
    auto [x, y] = std::minmax(a[i], b[i]);
    ans += y - x;
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
