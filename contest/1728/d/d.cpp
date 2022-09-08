// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// int solve(std::string& s) {
//   if (s.empty()) return 0;
//   int n = (int)s.size();
//   char x = std::min(s.front(), s.back());
//   int l = 0, r = 0;
//   while (l < n && s[l] == x) ++l;
//   if (l == n) return 0;
//   while (r < n && s[n - 1 - r] == x) ++r;
//   std::string ns(s.begin() + l, s.end() - r);
//   if (l == 0) {
//     if (r % 2 == 1) return s[n - 1 - r] > x ? 1 : -1;
//     return solve(ns);
//   }
//   if (r == 0) {
//     if (l % 2 == 1) return s[l] > x ? 1 : -1;
//     return solve(ns);
//   }
//   int lr = l + r;
//   if (s[l] > x && s[n - 1 - r] > x) {
//     if (lr % 2 == 1) return 1;
//     return solve(ns);
//   }
//   if (s[l] < x && s[n - 1 - r] < x) {
//     return (lr % 2 == 1) ? 1 : -1;
//   }
//   return (lr % 2 == 1) ? -1 : 1;
// }

// int main() {
//   std::cin.tie(nullptr)->sync_with_stdio(false);
//   int cas = 1;
//   std::cin >> cas;
//   while (cas--) {
//     std::string s;
//     std::cin >> s;
//     int x = solve(s);
//     if (x == 1) {
//       std::cout << "Alice\n";
//     } else if (x == -1) {
//       std::cout << "Bob\n";
//     } else {
//       std::cout << "Draw\n";
//     }
//   }
//   return 0;
// }

int f(char x, char y) {
  if (x == y) return 0;
  return x < y ? 1 : -1;
}

void solve() {
  std::string s;
  std::cin >> s;
  int n = (int)s.size();
  std::vector<int> a(n + 1);
  for (int st = 2; st <= n; st += 2) {
    std::vector<int> b(n - st + 1);
    for (int j = 0; j + st <= n; ++j) {
      // j, j + 1, ..., j + st - 1
      // choose j
      int x = -1;
      {
        int y = 1;
        // choose j + st - 1
        if (a[j + 1] == 0) y = std::min(y, f(s[j], s[j + st - 1]));
        else y = std::min(y, f(0, a[j + 1]));
        // choose j + 1
        if (a[j + 2] == 0) y = std::min(y, f(s[j], s[j + 1]));
        else y = std::min(y, f(0, a[j + 2]));
        x = std::max(x, y);
      }
      // choose j + st - 1
      {
        int y = 1;
        // choose j
        if (a[j + 1] == 0) y = std::min(y, f(s[j + st - 1], s[j]));
        else y = std::min(y, f(0, a[j + 1]));
        // choose j + st - 2
        if (a[j] == 0) y = std::min(y, f(s[j + st - 1], s[j + st - 2]));
        else y = std::min(y, f(0, a[j]));
        x = std::max(x, y);
      }
      b[j] = x;
    }
    std::swap(a, b);
  }
  if (a[0] == 1) {
    std::cout << "Alice\n";
  } else if (a[0] == -1) {
    std::cout << "Bob\n";
  } else {
    std::cout << "Draw\n";
  }
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
