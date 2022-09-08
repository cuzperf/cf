// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// ax + by = gcd(a,b)
template<typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
  if (b == 0) return {a, 1, 0};
  auto [d, y, x] = exGcd(b, a % b);
  return {d, x, y - a / b * x};
}

template<typename T>
T floor(T a, T n) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return a < 0 ? (a - n + 1) / n : a / n;
}
template<typename T>
T ceil(T a, T n) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return a < 0 ? a / n : (a + n - 1) / n;
}

void solve() {
  int n;
  std::cin >> n;
  LL sm = 0;
  std::vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    val[i] = x - y;
    sm += y;
  }
  std::sort(val.begin(), val.end(), std::greater<>());
  std::vector<LL> dp(n + 1);
  dp[0] = sm;
  for (int i = 0; i < n; ++i) {
    sm += val[i];
    dp[i + 1] = sm;
  }
  auto mx = std::max_element(dp.begin(), dp.end()) - dp.begin();
  int q;
  std::cin >> q;
  while (q--) {
    LL x, y;
    std::cin >> x >> y;
    auto [d, a, b] = exGcd(x, y);
    if (n % d) {
      std::cout << -1 << '\n';
      continue;;
    }
    // assert(a * x + b * y == d);
    // a (x / d) + b (y / d) = 1
    // (a n / d  + t y / d) * x + (b n / d - t x / d) * y = n

    LL b0 = n / d * a;
    LL k0 = y / d;
    LL b1 = n / d * b;
    LL k1 = x / d;

    // (b0 + k0 t) * x + (b1 - k1 t) * y = n

    // 0 <= k0 t + b0
    // 0 <= b1 - k1 t
    LL l = ceil(-b0, k0);
    LL r = floor(b1, k1);
    if (l > r) {
      std::cout << -1 << '\n';
      continue;
    }
    LL ans = std::max(dp[(b0 + k0 * l) * x], dp[(b0 + k0 * r) * x]);

    // (k0 t + b0) * x <= mx
    LL t = floor(mx / x - b0, k0);
    if (t >= l && t <= r) {
      ans = std::max(ans, dp[(b0 + k0 * t) * x]);
    }
    ++t;
    if (t >= l && t <= r) {
      ans = std::max(ans, dp[(b0 + k0 * t) * x]);
    }
    std::cout << ans << '\n';
  }
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
