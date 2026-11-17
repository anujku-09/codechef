# ISOMORPHICST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Check Isomorphic Strings

You are given two strings, $s$ and $t$. Determine whether these two strings are `isomorphic`.

Two strings are said to be  **isomorphic**  if characters in string $s$ can be replaced to get string $t$, such that:

- Each character in $s$ maps to exactly one character in $t$.
- No two different characters in $s$ map to the same character in $t$.
- The order of characters is preserved.
- A character is allowed to map to itself.
## Function Declaration
### Function Name

$isIsomorphic$ – This function checks whether two strings are isomorphic.

### Parameters
- $s$ : A string representing the source string.
- $t$ : A string representing the target string.
### Return Value
- Returns $true$ if the strings $s$ and $t$ are isomorphic.
- Returns $false$ otherwise.
## Constraints
- $1 \leq N \leq 100$
- $1 \leq |s| = |t| \leq 10^5$
- Strings $s$ and $t$ consist of ASCII characters.
### Input Format
- The first line contains a single integer $N$ — the number of test cases.
- For each test case: The first line contains the string $s$. The second line contains the string $t$.
### Output Format
- For each test case, print: "YES" if the strings are isomorphic. "NO" otherwise.
### Sample 1:
Input
Output

```
2
mno
pqr
hello
world

```

```
YES
NO

```

### Explanation:
- "mno" -> "pqr": mapping m->p, n->q, o->r YES
- "hello" -> "world": 'l' maps to two different letters 'r' and 'l' NO
### Sample 2:
Input
Output

```
3
abcabc
xyzxyz
pqrpqr
mnopmn
abcd
abcc

```

```
YES
NO
NO

```

### Explanation:
- "abcabc" -> "xyzxyz" YES
- "pqrpqr" -> "mnopmn" NO
- "abcd" -> "abcc" last character maps to two letters.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T20:05:33.567Z  

```c_cpp
bool isIsomorphic(const string &s, const string &t) {
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = m2[t[i]] = i + 1;
    }
    return true;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/ISOMORPHICST)