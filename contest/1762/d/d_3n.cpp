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

// this is only for at most 3n times query

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  int last = 1;
  while (p.size() > 1) {
    int pn = p.size();
    std::vector<int> q(pn);
    for (int i = 1; i < pn; ++i) {
      q[i] = query(p[0], p[i]);
    }
    int mx = *std::max_element(q.begin(), q.end());
    std::vector<int> np;
    for (int i = 1; i < pn; ++i) {
      if (q[i] == mx) {
        np.emplace_back(p[i]);
      }
    }
    last = p[0];
    std::swap(p, np);
  }
  std::cout << "! " << last + 1 << ' ' << p[0] + 1 << std::endl;
  int tmp;
  std::cin >> tmp;
  std::cout << std::endl;
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