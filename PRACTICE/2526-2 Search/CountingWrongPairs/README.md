# <p align='center'> G. Counting: Wrong Pairs </p>
<p align='center'> time limit per test: 1 second </p>
<p align='center'> memory limit per test: 16 megabytes </p>
You are given an array of n integers indexed 0 to n−1. Count how many index pairs (i,j) satisfy 0 ≤ i < j < n and A<sub>i</sub> > A<sub>j</sub>. Output this count as a single integer.  

## Input
The first line contains one integer n (1 ≤ n ≤ 105). The second line contains n integers A<sub>0</sub>, A<sub>1</sub>,…, A<sub>n−1</sub>, each in the range −109 to 109.

## Output
Print a single integer: the number of pairs (i,j) such that i< j and A<sub>i</sub> > A<sub>j</sub>.

## Examples
*Input*
```
6  
1 -1 0 0 0 1  
```
*Output*
```
4
```

---

*Input*
```
14
-2 -3 -3 -2 -1 -2 -2 -2 0 1 -2 -3 -1 0
```

*Output*
```
20
```

---

*Input*
```
24
0 -7 1 -7 -1 -6 2 -1 -2 0 1 -5 -7 -2 -4 -1 -7 5 7 6 1 0 -6 7
```

*Output*
```
100
```

---

## Note
The answer can be as large as $\frac{n(n-1)}{2}$, so use 64-bit signed arithmetic.