# CODEVITA23A

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Zero Count

You are given a binary string B of length L which contains K ones and remaining zeros. You are required to place the K ones in the binary string in such a way that the longest consecutive zeros have the least length possible. Once such a binary string is constructed, you are required to print the length of the contiguous block of zeros, which has the largest length.

### Input Format

Single line consisting of two space separated integers denoting $L$ and $K$.

### Output Format

Print a single integer denoting the length of the longest consecutive zeros as per the problem.

### Constraints
- $0 \leq K \leq L$
- $1 \leq L \leq 10^6$
### Sample 1:
Input
Output

```
3 1

```

```
1
```

### Explanation:

B is of length 3 and it has 1 one’s.
So the possible strings as per the problem are 010, 001, 100.
In the first case, the maximum length of consecutive zeros is 1 whereas in the other two cases it is 2. Hence the constructed binary string is 010 and the output is 1.

### Sample 2:
Input
Output

```
3 3
```

```
0
```

### Explanation:

B is of length 3 and it has all three one’s. There is no block of zeros, hence the output is 0.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T18:47:51.364Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, k;
	if(!(cin >> l >> k)) return 0;
	
	int zeros = l - k;
	if(zeros == 0) {
	    cout << 0 << "\n";
        return 0;
	}
	int slots = k + 1;
	int ans = (zeros + slots - 1) / slots;
    cout << ans << "\n";
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CODEVITA23A)