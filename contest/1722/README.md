# [Codeforces Round #817 (Div. 4)](https://codeforces.com/contest/1722)

## A

排序后看是否为 `Timru`

## B

`G` 都替换成 `B` 看是否相等

## C

用 set 存下各自的内容，然后看每一个是否在其它地方出现过

## D

对于每个人向左向右的答案都是固定的，然后看最优策略和当前的差值，把差值排序，每次加上最大的差值即可得到最终答案

## E

考虑二维前缀和即可，具体利用包容排斥原理

## F

直接模拟，如果答案为 YES，那么对于每个 `*` 的位置，必然可以找到唯一的 `L` 包含它，这样的记 `L` 所在的 2x2 正方形左上角为 $(x, y)$，那么四个格子的每一个周围都不可能有除了正方形外的 `*`

## G

注意到 $2n ^ (2n + 1) = 1$，再注意到 $1 ^ 2 ^ 3 = 0$，然后 $n = 2$ 肯定是无解的，但是样例中已经给了 $n = 6$ 的解法，所以照样抄一下即可