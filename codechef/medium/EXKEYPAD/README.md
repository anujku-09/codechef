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
**Submitted:** 2026-10-21T16:05:40.529Z  

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
	        string s = to_string(n);
	        int pos = -1;
	        for(int i = 0; i < s.size(); i++) {
	            if(s[i] == char('0' + d)) {
	                pos = i;
	                break;
	            }
	        }
	        if(pos == -1) {
	            cout << n << endl;
	            break;
	        }
	        bool chnge = false;
	        for(int i = pos; i >= 0; i--) {
	            if(s[i] < '9') {
	                s[i]++;
	                chnge = true;
	                break;
	            }
	            s[i] = '0';
	        }
	        if(!chnge) {
	            s = "1" + s;
	        }
	        for(int i = pos + 1; i < s.size(); i++) {
	            s[i] = '0';
	        }
	        
	        n = stoll(s);
	    }
	}
}

```

---

[View on CodeChef](https://www.codechef.com/problems/EXKEYPAD)