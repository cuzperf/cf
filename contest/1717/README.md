# [Codeforces Round #818 (Div. 2)](https://codeforces.com/contest/1717)

> 这场题目我很喜欢！题目很有意思

## A

$\frac{\text{lcm}(a, b)}{\gcd(a, b)} = 1, 2, 3$ 这三种情况，所以答案即 $a = b, a = 2b, a = 3b, b = 2a, b = 3a$ 五种具体情况

## B

一眼没看出来怎么作，最后做的时候才发现，原来是斜对角线贪心，然后再把隔着 $k$ 个行或者列再来一次

## C

首先注意到 $a_i \leq b_i$ 必须要满足，如果 $a_i < b_i$，那么必须要满足 $b_i < b_{(i + 1) \mod n}$ （编号从 $0$ 开始）

## D

由于初始位置任意可换，因此我们不妨假设左边必胜。假设（编号从 $0$ 开始）那么经过 二进制表示的 $1$ 的个数的改变，它就能成为获胜者。然后这就是经典二项式了。我们自然把最大的数字放在最右边，这种只有一个即 $\binom{n}{0}$，然后一次方次大的放在只有一个 $0$ 的地方，依次下去

## E

$$
\begin{aligned}
\sum_{a + b + c = n} \text{lcm}(c, \gcd(a, b))
&= \sum_{c = 1}^{n - 1} \sum_{d | n - c} \text{lcm(c, d)} \sum_{a + b = \frac{n - c}{d}} \sum_{x | a, x | b} \mu(x) \\
&= \sum_{c = 1}^{n - 1} \sum_{d | n - c} \text{lcm(c, d)} \sum_{a + b = \frac{n - c}{d}} \sum_{x | a, x | b} \mu(x) \\
&= \sum_{c = 1}^{n - 1} (n - c) \sum_{d | c} \frac{d}{\gcd(n, d)} \sum_{x | \frac{c}{d}} \mu(x) (\frac{c}{dx} - 1) \\
&= \sum_{c = 1}^{n - 1} (n - c) \cdot (f * g)(c)
\end{aligned}
$$

其中  $f(n) = \sum_{x | n} \mu(x) (\frac{n}{x} - 1) = \sum_{x | n} \mu(x) \frac{n}{x} - I(n)$,  $g(n) = \frac{d}{\gcd(n, d)}$，$f * g$ 为它们的 Dirichlet 乘积。
