# DSCPPAS277

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Flipping subarray
- You are given a binary array $arr$ whose elements are only $0$ and $1$. Your task is to find the length of the longest subarray that contains only $1s$ after flipping exactly one contiguous subarray from $0$ to $1$.
- You must perform the flip operation at least once.
### Input Format
- The first line contains one integer $n$, the size of the array. - Next line contains $n$ integers $arr[0],arr[1]...arr[n]$, representing the elements of the array.
### Output Format
- Find length of longest subarray with $1$ after flipping one contiguous subarray.
### Constraints
- $1 \leq n \leq 10^5$
- $0 \leq arr[i] \leq 1$
### Sample 1:
Input
Output

```
3
0 1 0

```

```
2
```

### Explanation:

Flip the first contiguous 0 to make it 1, the arr would look like 1,1,0. it contains 2 ones that are maximum from all possible cases.

### Sample 2:
Input
Output

```
3
0 0 0

```

```
3
```

### Explanation:

FLip all the elements as it is contiguous, then the arr would look like 1,1,1 and it has a maximum number of ones that is 3.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T12:02:00.738Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, ans = 0, zero_groups = 0;
    for (int r = 0; r < n; r++) {
        if (a[r] == 0 && (r == 0 || a[r - 1] == 1)) zero_groups++;
        while (zero_groups > 1) {
            if (a[l] == 0 && a[l + 1] == 1) zero_groups--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << (zero_groups == 0 ? n - 1 : ans) << "\n";
}
```

---

[View on CodeChef](https://www.codechef.com/problems/DSCPPAS277)