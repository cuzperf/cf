// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

//
// p1 > p2, t1 > t2
LL f(int p1, int p2, LL t1, LL t2, int h) {
  LL ans = INT64_MAX, cur = 0;
  while (h > 0) {
    ans = std::min(ans, cur + (h + p2 - 1) / p2 * t2);
    cur += t1;
    h -= p1;
  }
  ans = std::min(ans, cur);
  return ans;
}

void solve() {
  int p1, p2, h, s;
  LL t1, t2;
  std::cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
  LL ans1 = f(p1 + p2 - s, p2 - s, std::max(t1, t2), t2, h);
  LL ans2 = f(p1 + p2 - s, p1 - s, std::max(t1, t2), t1, h);
  std::cout << std::min(ans1, ans2) << '\n';
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
