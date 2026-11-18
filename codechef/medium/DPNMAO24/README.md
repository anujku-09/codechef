# DPNMAO24

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Last Word Length

You are given a string $S$ which consists of words and spaces.
Your task is to find the length of the last word in the string. A word is defined as a maximal substring consisting of non space characters only. The string may have leading or trailing spaces.

### Input Format
- The first and only line of input contains the string $S$.
### Output Format
- Print a single integer representing the length of the last word.
### Constraints
- $1 \leq |S| \leq 10^5$
### Sample 1:
Input
Output

```
  I am  a passionate   Developer  
```

```
9
```

### Sample 2:
Input
Output

```
Hello World
```

```
5
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:40:19.081Z  

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

[View on CodeChef](https://www.codechef.com/problems/DPNMAO24)