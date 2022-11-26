// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::vector<int> spf(int N) {
  std::vector<int> sp(N), p{0, 2};
  p.reserve(N);
  for (int i = 2; i < N; i += 2) {
    sp[i] = 2;
  }
  for (int i = 1; i < N; i += 2) {
    sp[i] = i;
  }
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) {
      p.emplace_back(i);
    }
    for (int j = 2, np = (int)p.size(); j < np && p[j] <= sp[i] && i * p[j] < N; ++j) {
      sp[i * p[j]] = p[j];  // Note that sp[x] is assigned only once foreach x
    }
  }
  return sp;
}

constexpr int N = 2e5 + 2;
std::vector<int> sp = spf(N);

void solve() {
  int n, x;
  std::cin >> n >> x;
  if (n % x) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> a(n + 1);
  a[1] = x; a[n] = 1;
  for (int now = 2; now < n; ++now) {
    if (now == x) {
      int t = sp[n / x];
      x *= t;
      a[now] = x;
    } else {
      a[now] = now;
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << a[i] << " \n"[i == n];
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
