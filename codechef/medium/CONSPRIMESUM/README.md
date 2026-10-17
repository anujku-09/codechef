# CONSPRIMESUM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Consecutive Prime Sum

Some prime numbers can be expressed as a sum of other consecutive prime numbers.

 **For Example** 

- $5 = 2 + 3$,
- $17 = 2 + 3 + 5 + 7$,
- $41 = 2 + 3 + 5 + 7 + 11 + 13$.

Your task is to find out how many prime numbers which satisfy this property are present in the range $3$ to $N$ subject to a constraint that summation should always start with number $2$.

Write code to find out the number of prime numbers that satisfy the above-mentioned property in a given range.

### Input Format
- The first line of input will contain a single integer $N$
### Output Format

Print the total number of all such prime numbers which are less than or equal to $N$.

### Constraints
- $2 \lt N \leq 10^{5}$
### Sample 1:
Input
Output

```
20
```

```
2
```

### Explanation:

Below $20$ are two such cases $5$ and $17$

- $5=2+3$
- $17=2+3+5+7$
### Sample 2:
Input
Output

```
45
```

```
3
```

### Explanation:

Below $45$ are three such cases $5,~17~and~41$

- $5=2+3$
- $17=2+3+5+7$
- $41=2+3+5+7+11+13.$

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T17:41:18.323Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	if(!(cin >> n)) return 0;
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	
	for(int p = 2; p * p <= n; p++) {
	    if(isPrime[p]){
	        for(int i = p * p; i <= n; i += p){
	            isPrime[i] = false;
	        }
	    }
	}
	
	vector<int> primes;
	for(int p = 2; p <= n; p++){
	    if(isPrime[p]){
	        primes.push_back(p);
	    }
	}
	
	long long sum = 0;
	int cnt = 0;
	for(int i = 0; i < primes.size(); i++){
	    sum += primes[i];
	    if(sum > n){
	        break;
	    }
	    if(i >= 1 && isPrime[sum]) {
	        cnt++;
	    }
	}
	cout << cnt << "\n";
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CONSPRIMESUM)