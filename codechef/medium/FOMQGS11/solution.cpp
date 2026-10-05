  
  async function prepareSandwich() {
    const step1 = await prepareBread();
    console.log(step1); // Log: Bread prepared!
  
    const step2 = await addFilling();
    console.log(step2); // Log: Filling added!
  
    const step3 = await wrapSandwich();
    console.log(step3); // Log: Sandwich wrapped!
  
    return "Sandwich is ready to eat!";
  }
  
  }
    });
      }, 500); // Simulate wrapping for 0.5 seconds
        resolve("Sandwich wrapped!");
  prepareSandwich().then(result => console.log(result));
  