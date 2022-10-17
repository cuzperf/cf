// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int M = 998244353;

template<int N>
class MInt {
  static inline constexpr int M = N;
  int n_;
  // |x| <= max(1, b), |y| <= a ===> |y - a / b * x| <= a % b + a / b * b = a
  static std::tuple<int, int, int> exGcdInternal(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [d, y, x] = exGcdInternal(b, a % b);
    return {d, x, y - a / b * x};
  }
  static int inv(int a) {
    auto [d, x, y] = exGcdInternal(a, M);
    // assert(d == 1);
    return x < 0 ? x + M : x;
  }
  // assum M is prime
  static int invP(int x) {
    return x == 1 ? x : 1LL * (M - M / x) * invP(M % x) % M;
  }
 public:
  template<typename T>
   operator T() const {
    return static_cast<T>(n_);
  }
  static void setMod(int m) {
    assert(M == m);
  }
  static constexpr int mod() {
    return M;
  }
  // assume 0 <= x < M
  static MInt raw(int x) {
    MInt A;
    A.n_ = x;
    return A;
  }
  MInt() { n_ = 0;}
  MInt(const int& x) : n_(x % M) {
    if (n_ < 0) n_ += M;
  }
  MInt(const LL& x) : n_(x % M) {
    if (n_ < 0) n_ += M;
  }
  MInt operator-() const {
    return n_ == 0 ? *this : raw(M - n_);
  }
  MInt& operator++() {
    if (++n_ == M) n_ = 0;
    return *this;
  }
  MInt& operator--() {
    if (n_-- == 0) n_ += M;
    return *this;
  }
  MInt& operator+=(const MInt& A) {
    n_ += A.n_;
    if (n_ >= M) n_ -= M;
    return (*this);
  }
  MInt& operator-=(const MInt& A) {
    n_ -= A.n_;
    if (n_ < 0) n_ += M;
    return (*this);
  }
  MInt& operator*=(const MInt& A) {
    n_ = 1LL * n_ * A.n_ % M;
    return (*this);
  }
  MInt& operator/=(const MInt& A) {
    return (*this) *= A.inv();
  }
  MInt operator+(const MInt& A) const {
    return MInt(*this) += A;
  }
  MInt operator-(const MInt& A) const {
    return MInt(*this) -= A;
  }
  MInt operator*(const MInt& A) const {
    return MInt(*this) *= A;
  }
  MInt operator/(const MInt& A) const {
    return MInt(*this) /= A;
  }
  MInt operator<<(int x) const {
    static constexpr int bits = 32;
    LL r = n_;
    while (x > bits) {
      x -= bits;
      r <<= bits;
      r %= M;
    }
    r <<= x;
    return MInt(r);
  }
  MInt& operator<<=(int x) {
    return (*this) = (*this) << x;
  }
  bool operator==(const MInt& A) const {
    return n_ == A.n_;
  }
  bool operator!=(const MInt& A) const {
    return n_ != A.n_;
  }
  MInt inv() const {
    return inv(n_);
  }
  MInt invP() const {
    return invP(n_);
  }
  friend MInt pow(MInt A, int n) {
    MInt R(1);
    while (n) {
      if (n & 1) R *= A;
      n >>= 1;   A *= A;
    }
    return R;
  }
  friend std::istream& operator>>(std::istream& in, MInt& A) {
    LL x;
    in >> x;
    A = MInt(x);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const MInt& A) {
    out << A.n_;
    return out;
  }
};

using mod = MInt<M>;

template<typename T>
class SegTree {
  int n;
  std::vector<T> sm, tag;
  void pushUp(int p) {
    sm[p] = sm[p << 1] + sm[p << 1 | 1];
  }
  void deal(T val, int l, int r, int p) {
    tag[p] = val;
    sm[p] = val * T(r - l);
  }
  void pushDown(int l, int r, int p) {
    if (tag[p] != T(0)) {
      int m = (l + r) / 2;
      deal(tag[p], l, m, p << 1);
      deal(tag[p], m, r, p << 1 | 1);
      tag[p] = 0;
    }
  }
  void update(int L, int R, T val, int l, int r, int p) {
    if (L <= l && R >= r) {
      deal(val, l, r, p);
    } else {
      pushDown(l, r, p);
      int m = (l + r) / 2;
      if (L < m) update(L, R, val, l, m, p << 1);
      if (R > m) update(L, R, val, m, r, p << 1 | 1);
      pushUp(p);
    }
  }
 public:
  SegTree(int _n) : n(_n), sm(4 * n), tag(4 * n) {}
  void update(int L, int R, T val) {
    update(L, R + 1, val, 0, n, 1);
  }
  T sum() {
    return sm[1];
  }
};

using Tree = SegTree<mod>;
constexpr int N = 3e5 + 2;

void solve() {
  mod T = 1, inv2 = mod(2).inv();
  Tree A(N);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    A.update(l, r, T);
    if (i > 0) {
      T *= 3;
      T *= inv2;
    }
  }
  mod ans = pow(mod(2), n - 1) * A.sum();
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
