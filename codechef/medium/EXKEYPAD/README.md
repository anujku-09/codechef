# EXKEYPAD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### The Sticky Keypad

You are given $2$ integers $N$ and $D$.

Find the smallest integer $x$ which is

- greater than or equal to $N$
- typeable without the digit $D$.

Formally, a non-negative integer $x$ is  **typeable**  if its usual decimal representation (no leading zeros; zero is written as the single digit $0$) does not contain the digit $D$.

### Input Format
- The first line contains a single integer $T$, the number of test cases.
- Each of the next $T$ lines contains two space-separated integers $N$ and $D$.
### Output Format

For each test case, output on a new line the smallest integer $x \ge N$ typeable without digit $D$.

### Constraints
- $1 \le T \le 10^{3}$
- $1 \le N \le 10^{9}$
- $0 \le D \le 9$
### Sample 1:
Input
Output

```
5
99 9
1000 0
12345 3
7 7
2026 5
```

```
100
1111
12400
8
2026

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T15:55:00.808Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    long long n;
	    int d;
	    cin >> n >> d;
	    
	    while(true) {
	        long long temp = n;
	        bool found = false;
	        if(temp ==0 && d == 0) {
	            found = true;
	        }
	        
	        while(temp > 0) {
	            int dig = temp % 10;
	            if(dig == d) {
	                found = true;
	                break;
	            }
	            temp = temp / 10;
	        }
	        if(found == false) {
	            cout << n << endl;
	            break;
	        }
	        n++;
	    }
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/EXKEYPAD)