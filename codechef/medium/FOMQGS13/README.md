# FOMQGS13

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Simulated API Call with Error Handling

Let's create a simulated API call that randomly succeeds or fails. This example demonstrates error handling using async/await, promises, and callbacks. Imagine we're fetching user data from a server. Sometimes the server responds correctly, and sometimes it has issues. We'll simulate this randomness.

### Working:

 **1.**  First, let's see the `fetchUserData` function.
This function will simulate fetching user data and randomly resolve or reject the promise.
 **2.**  Now, let's use `async/await` with `try...catch` to handle potential errors: This is the async/await version.
 **3.**  Next, let's see the code to implement the same functionality using `.then()` and `.catch()`
 **4.**  Finally, let's see the function that uses callbacks to handle the request.

Run it, and observe the output. Sometimes you'll see "User data: { id: 123, name: 'John Doe' }", and sometimes you'll see "Error fetching user data: Failed to fetch user data.". This demonstrates how to handle asynchronous errors gracefully using different approaches.

Each time you run the script, the simulated API call has a 50% chance of failing, so observe the different outputs you may receive.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-06T07:03:45.494Z  

```cpp
  }
        console.error("Promise → Error fetching user data:", error);
      });
      .catch(error => {
      })
        console.log("Promise → User data:", userData);
      .then(userData => {
    fetchUserData()
  function getUserDataPromise() {
  // Promise .then/.catch version
  
  }
    } catch (error) {
      console.error("Async/Await → Error fetching user data:", error);
    }
      console.log("Async/Await → User data:", userData);
      const userData = await fetchUserData();
    try {
  async function getUserDataAsyncAwait() {
  // Async/Await version
  
  }
    });
```

---

[View on CodeChef](https://www.codechef.com/problems/FOMQGS13)