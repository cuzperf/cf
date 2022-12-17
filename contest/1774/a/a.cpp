// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  bool flag = true;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '1') {
      std::cout << (flag ? '-' : '+');
      flag = !flag;
    } else {
      std::cout << "+";
    }
  }
  std::cout << '\n';
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
