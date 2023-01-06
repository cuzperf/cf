// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::set<LL> S;
  for (int i = 0; i < n; ++i) {
    LL x;
    std::cin >> x;
    S.insert(x);
  }
  if ((int)S.size() < n) {
    return false;
  }
  std::vector<LL> a(S.begin(), S.end());

  for (int i = 2; 2 * i <= n; ++i) {
    int pi = i;
    std::vector<int> cnt(pi);
    for (auto x : a) {
      ++cnt[x % pi];
    }
    if ((int)std::count_if(cnt.begin(), cnt.end(), [](int x) { return x > 1;}) == pi) return false;
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
