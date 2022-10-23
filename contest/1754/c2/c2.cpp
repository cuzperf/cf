// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int cnt = std::count(a.begin(), a.end(), 1);
  int cnt1 = std::count(a.begin(), a.end(), -1);
  cnt -= cnt1;
  int cur = 1;
  if (cnt < 0) {
    cur = -1;
    cnt = -cnt;
  }
  if (cnt & 1) {
    std::cout << "-1\n";
    return;
  }
  cnt /= 2;
  std::vector<int> b;
  for (int i = 1; i < n; ++i) {
    if (a[i] == cur && a[i - 1] != -cur) {
      b.emplace_back(i++);
    }
  }
  assert(b.size() >= cnt);
  b.resize(cnt);
  std::vector<std::pair<int, int>> ans;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j < b.size() && b[j] == i + 1) {
      ans.emplace_back(i, i + 1);
      ++i;
      ++j;
    } else {
      ans.emplace_back(i, i);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x + 1 << ' ' << y + 1 << '\n';
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
