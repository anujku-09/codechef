# DSA3B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Sliding Window Maximum

You are given an array $A = [A_1, A_2, \ldots, A_N]$ of $N$ integers and an integer $X$.

Find the maximum element in each contiguous subarray of size $X$, considering the subarrays from left to right.

The first output value is $\max(A_1, A_2, \ldots, A_X)$, the second, if it exists, is $\max(A_2, A_3, \ldots, A_{X+1})$, and so on, until the last value $\max(A_{N-X+1}, \ldots, A_N)$.

Print these $N-X+1$ maximum values as space-separated integers.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains two space-separated integers $N$ and $X$ — the number of elements in the array and the size of subarrays. The next line contains $N$ space-separated integers, the elements of array $A$.
### Output Format

For each test case, print $N-X+1$ space-separated integers on a single line. The $i$-th integer must be $\max(A_i, A_{i+1}, \ldots, A_{i+X-1})$, for $1 \le i \le N-X+1$.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq X \leq N \leq 10^5$
- $1 \leq A_i \leq 10^9$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Subtasks
- Subtask 1 (30 points): $1 \leq X \leq N \leq 1000$
- Subtask 2 (70 points): Original Constraints.
### Sample 1:
Input
Output

```
3
4 2
1 2 3 4
4 3
4 3 2 1
3 1
9 7 10

```

```
2 3 4
4 3
9 7 10

```

### Explanation:

 **Test case $1$:**  For the array $A = [1, 2, 3, 4]$:

- The maximum element in the subarray $[1, 2]$ is $2$.
- The maximum element in the subarray $[2, 3]$ is $3$.
- The maximum element in the subarray $[3, 4]$ is $4$.

Note that the subarrays are traversed from left to right.

 **Test case $2$:**  For the array $A = [4, 3, 2, 1]$:

- The maximum element in the subarray $[4, 3, 2]$ is $4$.
- The maximum element in the subarray $[3, 2, 1]$ is $3$.

 **Test case $3$:**  For the array $A = [9, 7, 10]$:

- The maximum element in the subarray $[9]$ is $9$.
- The maximum element in the subarray $[7]$ is $7$.
- The maximum element in the subarray $[10]$ is $10$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T16:27:50.011Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= n - x; i++){
            int mx = a[i];
            for(int j = i + 1; j < i; j++){
                if(a[j] > mx){
                    mx = a[j];
                }
            }
            cout << mx << " ";
        }
        cout << endl;
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DSA3B)