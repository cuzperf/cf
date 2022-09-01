#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string A, B;
  std::cin >> n >> A >> B;
  for (auto &x : A) if (x == 'G') x = 'B';
  for (auto &x : B) if (x == 'G') x = 'B';
  std::cout << (A == B ? "YES" : "NO") << '\n';
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
