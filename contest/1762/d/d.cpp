// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int query(int x, int y) {
  std::cout << "? " << x + 1 << ' ' << y + 1 << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  int l = 0, r = 1;
  int g = query(l, r);
  for (int i = 2; i < n; ++i) {
    int li = query(l, i);
    int ri = query(r, i);
    if (li > std::max(ri, g)) {
      r = i;
      g = li;
    } else if (ri > std::max(li, g)) {
      l = i;
      g = ri;
    }
  }
  std::cout << "! " << l + 1 << ' ' << r + 1 << std::endl;
  int ans;
  std::cin >> ans;
  assert(ans == 1);
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