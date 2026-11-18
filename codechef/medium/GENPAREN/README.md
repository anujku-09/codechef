# GENPAREN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:40:31.359Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') i--;

    int len = 0;
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    cout << len << "\n";
}
```

---

[View on CodeChef](https://www.codechef.com/problems/GENPAREN)