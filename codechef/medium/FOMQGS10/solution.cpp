  
  async function placeOrder() {
    try {
      const grindResult = await grindCoffeeBeans();
      console.log(grindResult);
  
      const brewResult = await brewCoffee();
      console.log(brewResult);
  
      const pourResult = await pourCoffee();
      console.log(pourResult);
  
      return "☕ Your coffee is ready!";
    } catch (error) {
      return "Something went wrong while making your coffee.";
  }
  
  function pourCoffee() {
    return new Promise(resolve => {
      setTimeout(() => {
        resolve("Coffee poured!");
      }, 500); // Simulate pouring for 0.5 seconds
    });
    }
  }
  }
    });
        resolve("Coffee brewed!");
      }, 2000); // Simulate brewing for 2 seconds
      setTimeout(() => {
    return new Promise(resolve => {
  function brewCoffee() {
  
  }