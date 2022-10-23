// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

/*
// 1 p 2 p + 1, 3, p + 2.. 2p
n = 4
2 4 1 3
n = 5
1 3 2 4 5
4 1 3 5 2
n = 6
1 4 2 5 3 6

3 6 2 5 1 4

5 2 4 1 3

*/

void solve() {
  int n;
  std::cin >> n;
  if (n & 1) {
    std::cout << n << ' ';
    --n;
  }
  for (int i = n / 2; i > 0; --i) {
    std::cout << i << ' ' << n / 2 + i << ' ';
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
