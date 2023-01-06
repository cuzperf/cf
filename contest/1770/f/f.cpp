// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int lowbit(int x) {
  return x & -x;
}

bool isSub(LL x, LL y) {
  return x >= 0 && y >= 0 && (x & y) == x;
}

void solve() {
  LL n, x;
  int y;
  std::cin >> n >> x >> y;
  if (n % 2 == 0) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  for (int yy = y; yy; yy = (yy - 1) & y) {
    for (int i = 1; i <= y; i <<= 1) if (yy & i) {
      if (isSub(x - i, yy * n - i)) {
        ans ^= i;
      }
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
