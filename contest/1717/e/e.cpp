// https://github.com/cuzperf/cf
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

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
constexpr int M = 1e9 + 7;
using mint = MInt<M>;

template<typename T>
std::vector<T> DirichletProduct(const std::vector<T>& a, const std::vector<T>& b, int n) {
  std::vector<T> c(n);
  for (int i = 1; i < n; ++i) {
    for (int j = 1, ij = i; ij < n; ij += i, ++j) {
      c[ij] += a[i] * b[j];
    }
  }
  return c;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<mint> mu(n);
  mu[1] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = i * 2; j < n; j += i) {
      mu[j] -= mu[i];
    }
  }
  std::vector<mint> f(n);
  std::iota(f.begin(), f.end(), 0);
  f = DirichletProduct(f, mu, n);
  --f[1];
  std::vector<mint> g(n);
  for (int i = 1; i < n; ++i) {
    g[i] = i / std::gcd(n, i);
  }
  f = DirichletProduct(f, g, n);
  mint ans{0};
  for (int i = 1; i < n; ++i) {
    ans += f[i] * mint(n - i);
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
