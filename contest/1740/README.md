# [Codeforces Round #831 (Div. 1 + Div. 2)](https://codeforces.com/contest/1740)

## A

$2$ 是唯一的偶素数

## B

不妨假设 $a_i \leq b_i$，那么答案就是 $2(\sum a_i) + 2(\max b_i)$

## c

先排序，然后注意到 $w_2$ 可选的为一个区间时候是最佳的，然后这个区间的最值总能被左区间和右区间的最值覆盖

## D

注意到当前已经占据的位置不超过 $nm - 3$ 时，必可以把任意位置移到另外的任意位置

## E

树上 dp，考虑当前节点为有贡献和无贡献下的最值。位置这个值即可

## F

看了题解也不理解！在群友 [yzc2005](https://codeforces.com/profile/yzc2005) 提示下知道了题解啥意思

记 $c_i$ 为 $a$ 中 $i$ 出现的次数。

对于 $n$ 个集合 $M_1, \cdots, M_n$（$|M_1| \geq \cdots \geq |M_n| \geq 0$）是可由题意中生成的当且仅当 $\sum_{i = 1}^n |M_i| = n$ 且 $\sum_{i = 1}^k |M_i| \leq \sum_{i = 1}^n \min(k, c_i)$ 对任意 $1 \leq k \leq n$ 成立。注意不等式右边对于固定的数组 $a$ 是固定的。因此最终答案可以对 $k$ 动态规划（显然 $k$ 这一维的空间可以优化），然后记录前缀和以及最后一次的值。

实现抄一波 jiangly 的代码，$\lim[k] = \sum_{i = 1}^n \min(k, c_i)$，$cc$ 的作用是用来快速计算 lim 的。前缀和为 $i$，当前进度为 $j$。