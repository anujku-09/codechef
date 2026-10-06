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