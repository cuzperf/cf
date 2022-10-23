// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int cnt = 0;
  for (auto x : s) {
    if (x == 'Q') ++cnt;
    else cnt = std::max(0, cnt - 1);
  }
  return cnt == 0;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
