# CUCPRANKMED

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T12:25:13.935Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    deque<int> dq;
    for(int  i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= i - x){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i >= x - 1){
            cout << arr[dq.front()] << (i == n - 1 ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/CUCPRANKMED)