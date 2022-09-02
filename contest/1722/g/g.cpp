// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  int n4 = n % 4;
  if (n4 == 0) {
    for (int i = 1; i <= n; ++i) {
      a.emplace_back(i + 1);
    }
  } else if (n4 == 3) {
    for (int i = 1; i <= n; ++i) {
      a.emplace_back(i);
    }
  } else if (n4 == 1) {
    a.emplace_back(0);
    for (int i = 2; i <= n; ++i) {
      a.emplace_back(i);
    }
  } else {
    a.emplace_back(1);
    a.emplace_back(2);
    a.emplace_back(3);
    a.emplace_back(4);
    a.emplace_back(8);
    a.emplace_back(12);
    for (int i = 7; i <= n; ++i) {
      a.emplace_back(i + 7);
    }
  }
  assert((int)a.size() == n);
  int sm = 0;
  for (auto &x : a) sm ^= x;
  assert(sm == 0);
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " \n"[i == n - 1];
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
