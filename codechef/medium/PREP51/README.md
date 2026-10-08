# PREP51

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Hashing - Minimum Window Substring

You are given a string $S$ of length $N$ and a string $T$ of length $M$ consisting of lowercase english characters.

Find the  **shortest**  substring of $S$ which contains all characters present in $T$ (in any order including duplicates). If there are multiple such substring, return the first occurring  **shortest**  substring.

If there is no substring in $S$ that contains all characters of $T$, print $-1$ instead.

Note that a substring is obtained by deleting some (possible zero) characters from the beginning and some (possibly zero) characters from the end of the string.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains two space-separated integers $N$ and $M$ — the lengths of strings $S$ and $T$ respectively. The second line of each test case contains a string with $N$ lowercase english alphabets — the string $S$. The third line of each test case contains a string with $M$ lowercase english alphabets — the string $T$.
### Output Format

For each test case, output on a new line, the  **shortest**  substring of $S$ which contains all characters present in $T$ (in any order including duplicates). If there is no substring in $S$ that contains all characters of $T$, print $-1$ instead.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq N, M \leq 10^5$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
- The sum of $M$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
3
8 4
baccaccb
acbc
3 2
bac
ac
1 1
c
a

```

```
bacc
ac
-1
```

### Explanation:

 **Test case $1$:**  The substring $S[1:4] = bacc$ and $S[5:8] = accb$ both will be the smallest substring in $S$ contains all characters of the string $T$ but $S[1:4] = bacc$ occurs first.

 **Test case $2$:**  The substring $S[2:3] = ac$ will be shortest substring that contains all characters in $T$.

 **Test case $3$:**  No substring present in $S$ that contains all characters in $T$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-08T05:52:19.365Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

string shortestSubstring(const string& S, const string& T){
    unordered_map<char, int> targetCnt, windowCnt;
    for(char c : T){
        targetCnt[c]++;
    }
    int lft = 0, rgt = 0, cnt = 0;
    int minLen = INT_MAX, st = 0;
    
    while(rgt < S.length()){
        if(targetCnt[S[rgt]] > 0){
            windowCnt[S[rgt]]++;
            if(windowCnt[S[rgt]] <= targetCnt[S[rgt]]){
                cnt++;
            }
        }
        while(cnt == T.length()){
            if(rgt - lft + 1 < minLen) {
                minLen = rgt - lft + 1;
                st = lft;
            }
            if(targetCnt[S[lft]] > 0){
                windowCnt[S[lft]]--;
                if(windowCnt[S[lft]] < targetCnt[S[lft]]){
                    cnt--;
                }
            }
            lft++;
        }
        rgt--;
    }
    return minLen == INT_MAX ? "-1" : S.substr(st, minLen);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        string S, T;
        cin >> S >> T;
        
        cout << shortestSubstring(S, T) << "\n";
    }
    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/PREP51)