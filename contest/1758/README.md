# [Codeforces Round #836 (Div. 2)](https://codeforces.com/contest/1758)

> 这场几乎纯构造

## A

输出 $s$ 和反序的 $s$ 即可


## B

注意到 $(1 \oplus 3) = 2$ 且 $\frac{1 + 3}{2} = 2$

## C

注意到 如果 $i$ 不是 $x$ 的倍数，则 $a[i] = i$，为了让答案最小，到达 $x$ 处，此时 $a[x] = t x$, 且 $t > 1$, $tx | n$，所以可以选择 $\frac{n}{x}$ 的最小素因子，然后继续


## D

注意到 $\frac{3n + 5n}{2} = 4n$

## E

> 我们不妨假设要让所有的数都变成 0

记行为 $x_1, \cdots, x_n$, 列为 $y_1,\cdots, y_m$ 分别表示对应的行或者列加了多少次 1

那么有多少个非 $-1$ 的空，就有多少个方程，例如 $x_{ij} \neq -1$，那么 $x_i + y_j \equiv -x_{ij} \mod h$

所以我们可以用并查集，注意到我们总可以写成这种形式 $v[x] = k \cdot v[p[x]] + b$，且 $k = \pm 1$

如果发现矛盾就说明无解。

否则就有解，此时我们对 $-1$ 的位置检测 $x_i, y_j$ 是否是同一祖先，是的话就忽略，否则就任取一个值，然后合并这两个节点，答案乘以 `h`
