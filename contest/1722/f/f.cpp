// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto &x : a) {
    std::cin >> x;
  }
  auto check = [&](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '*';
  };
  auto sm = [&](int i, int j) -> int {
    int ans = 0;
    if (check(i, j)) ++ans;
    if (check(i + 1, j)) ++ans;
    if (check(i, j + 1)) ++ans;
    if (check(i + 1, j + 1)) ++ans;
    return ans;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (a[i][j] == '*') {
      int cnt = 0;
      int x, y;
      if (sm(i, j) == 3) {
        ++cnt;
        x = i;
        y = j;
      }
      if (sm(i, j - 1) == 3) {
        ++cnt;
        x = i;
        y = j - 1;
      }
      if (sm(i - 1, j) == 3) {
        ++cnt;
        x = i - 1;
        y = j;
      }
      if (sm(i - 1, j - 1) == 3) {
        ++cnt;
        x = i - 1;
        y = j - 1;
      }
      if (cnt != 1) return false;
      if (a[x][y] == '*') {
        if (check(x - 1, y + 1)) return false;
        if (check(x - 1, y    )) return false;
        if (check(x - 1, y - 1)) return false;
        if (check(x,     y - 1)) return false;
        if (check(x + 1, y - 1)) return false;
      }
      if (a[x + 1][y] == '*') {
        if (check(x,     y - 1)) return false;
        if (check(x + 1, y - 1)) return false;
        if (check(x + 2, y - 1)) return false;
        if (check(x + 2, y )) return false;
        if (check(x + 2, y + 1)) return false;
      }
      if (a[x][y + 1] == '*') {
        if (check(x - 1, y)) return false;
        if (check(x - 1, y + 1)) return false;
        if (check(x - 1, y + 2)) return false;
        if (check(x,     y + 2)) return false;
        if (check(x + 1, y + 2)) return false;
      }
      if (a[x + 1][y + 1] == '*') {
        if (check(x + 2, y)) return false;
        if (check(x + 2, y + 1)) return false;
        if (check(x + 2, y + 2)) return false;
        if (check(x + 1, y + 2)) return false;
        if (check(x,     y + 2)) return false;
      }
    }
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
