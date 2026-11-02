# MATSORTDIAG

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Sort Matrix Diagonally

A  **matrix diagonal**  consists of cells that follow the same diagonal. Two cells `A[i][j]` and `A[x][y]` belong to the same diagonal if `i - j = x - y`, using 0-based indexing.

Given an `N x M` matrix, sort the elements of each diagonal in ascending order from top-left to bottom-right.
For eg. see the following matrix and its diagonal sorting:

### Input Format
- The first line of input will contain two space separated integers $N$ and $M$, denoting the no. of rows and columns in the input matrix.
- Next $N$ lines contains $M$ space separated integers, the elements of the matrix.
### Output Format
- Output $N$ lines, each containing $M$ space separated integers, the elements of diagonally sorted matrix.
### Constraints
- $1 \leq N, M \leq 100$
- The elements of the matrix are non-negative and won't exceed $1000$.
### Sample 1:
Input
Output

```
3 3
3 1 5
8 2 1
4 6 0
```

```
0 1 5
6 2 1
4 8 3
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T15:18:30.673Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/MATSORTDIAG)