# WEGUW01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T19:37:03.569Z  

```c_cpp
int minAddToMakeValidNaive(string s) {
    int open = 0, ans = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            if (open > 0) open--;
            else ans++;
        }
    }
    return ans + open;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/WEGUW01)