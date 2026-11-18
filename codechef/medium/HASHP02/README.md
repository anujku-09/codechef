# HASHP02

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Length of Longest Palindrome

Given a string $s$ which consists of lowercase latin letters, return the length of the  **longest palindrome**  that can be built with those letters.

### Input Format
- The first and only line of input contains the string s.
### Output Format
- Output on a single line, the length of the longest palindrome that can be format using the letters of s.
### Constraints
- $1 \leq s.length \leq 10^5$
- s consists of lowercase English letters only.
### Sample 1:
Input
Output

```
bbd
```

```
3
```

### Explanation:
- Longest palindromic string: bdb
### Sample 2:
Input
Output

```
aabdcd
```

```
5
```

### Explanation:
- Longest possible palindromic strings: adbda, adcda, dabad, dacad

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T18:23:43.898Z  

```c_cpp
int longest_palindrome_length(const string& s) {
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;

    int ans = 0;
    bool odd = false;
    for (int count : freq) {
        ans += (count / 2) * 2;
        if (count % 2 == 1) odd = true;
    }
    if (odd) ans++;
    return ans;
}



```

---

[View on CodeChef](https://www.codechef.com/problems/HASHP02)