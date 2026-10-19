# UNIQUE2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Unique Elements 2

You are given an array $A$ containing $N$ integers. The array may contain duplicate elements.

Your task is to print all distinct elements of the array in the order of their first occurrence. Each element should appear exactly once in the output.

### Input Format
- The first line contains an integer $N$, representing the size of the array.
- The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$, representing the array elements.
### Output Format

Print all distinct elements separated by a single space, preserving their order of first occurrence.

### Constraints
- $1 \leq N \leq 10^5$
- $1 \leq A_i \leq 10^5$
### Sample 1:
Input
Output

```
7
5 5 8 8 3 5 3
```

```
5 8 3
```

### Explanation:

The elements $5$, $8$, and $3$ appear for the first time in that order. Repeated occurrences are excluded from the output.

### Sample 2:
Input
Output

```
9
12 7 12 4 7 15 4 9 15
```

```
12 7 4 15 9
```

### Explanation:

The distinct elements are $12$, $7$, $4$, $15$, and $9$, in the order of their first occurrence. All subsequent occurrences of these elements are ignored.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T16:18:47.087Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	set<int> s;
	for(int i = 0; i < n; i++){
	    if(s.find(a[i]) == s.end()) {
	        cout << a[i] << " ";
	        s.insert(a[i]);
	    }
	}
	
}

```

---

[View on CodeChef](https://www.codechef.com/problems/UNIQUE2)