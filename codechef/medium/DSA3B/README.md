# DSA3B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Sliding Window Maximum

 ***Sliding Window Maximum** *

You are given an array $A$ consisting of $N$ integers and an integer $X$.

Find the  **maximum**  element in each subarray of size $X$.
Print $(N-X+1)$ space-separated integers where the $i^{th}$ integer denotes the maximum element of the $i^{th}$ subarray of size $X$ from left.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains two space-separated integers $N$ and $X$ — the number of elements in the array and the size of subarrays. The next line contains $N$ space-separated integers, the elements of array $A$.
### Output Format

For each test case, output on a new line, the  **maximum**  element in each subarray of size $X$.
Print $(N-X+1)$ space-separated integers where the $i^{th}$ integer denotes the maximum element of the $i^{th}$ subarray of size $X$ from left.

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

Note that the subarrays are traverses from left to right.

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
**Submitted:** 2026-10-04T12:25:10.880Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    deque<int> dq;
    for(int  i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= i - x){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i >= x - 1){
            cout << arr[dq.front()] << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DSA3B)