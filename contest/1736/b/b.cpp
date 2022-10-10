// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#include <vector>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// b0, b1, b2, b3..., bn
//   a1, a2, a3....,an
//
// a_i-1 | b_i-1
// a_i+1 | b_i
// a_i = gcd(b_i - 1, b_i)


bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] % std::gcd(a[i - 1], a[i + 1])) {
      return false;
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
