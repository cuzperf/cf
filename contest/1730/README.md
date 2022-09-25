# [Codeforces Round #823 (Div. 2)](https://codeforces.com/contest/1730/)

## A

用个 map 存下各个数出现的频率，然后对每个数的贡献为 出现频率和 c 的最小值

## B

考虑到最大值点必然满足 $t_i + |x_i - x_0| = t_j + |x_j - x_0|$，所以我们不妨求 $x = 2x_0$ 即

$$
2 t_i + |2 x_i - x| = 2 t_j + |2 x_j - x|
$$

此时 $x$ 必然是个整数。所以不妨把 $t_i, x_i$ 扩大两倍。

对最大时间 $m$ 二分

$$
t_i + |x - x_i| \leq m \; \Leftrightarrow \; x_i - (m - t_i) \leq x \leq x_i + (m - t_i)
$$


## C

按照 `0-9` 逐一操作，对于 $i$，找到 $s$ 中最后一个 $i$，之前的部分都存在 $a$ 中（非 $i$ 要取 $\min(j, 9)$），然后尾部为新的 $s$，
把 $a$ 中的 $i$ 丢进答案的尾部
