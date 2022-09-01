#include <bits/stdc++.h>
#include <cstring>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 1002;
LL a[N][N];

void solve() {
  int n, q;
  std::cin >> n >> q;
  memset(a, 0, sizeof (a));
  for (int i = 0; i < n; ++i) {
    int h, w;
    std::cin >> h >> w;
    a[h][w] += h * w;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  while (q--) {
    int h1, w1, h2, w2;
    std::cin >> h1 >> w1 >> h2 >> w2;
    --h2; --w2;
    std::cout << a[h2][w2] - a[h2][w1] - a[h1][w2] + a[h1][w1] << '\n';
  }
}

int main() {
  cerr(sizeof (a));
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
