
      { name: "cucumber", quantity: 1, unit: "pc" },
      { name: "tomato", quantity: 2, unit: "pcs" },
      { name: "feta cheese", quantity: 100, unit: "g" }
    ],
    tags: ["vegetarian", "salad", "quick"]
  });
  await recipesCollection.insertMany([
    {
      title: "Spaghetti Aglio e Olio",
      prep_time_minutes: 15,
      servings: 2,
      ingredients: [
        { name: "spaghetti", quantity: 200, unit: "g" },
        { name: "garlic", quantity: 4, unit: "cloves" },
        { name: "olive oil", quantity: 3, unit: "tbsp" }
      ],
      tags: ["pasta", "vegetarian", "quick"]
    },
    {
      title: "Vegetable Curry",
      prep_time_minutes: 40,
      servings: 4,
      ingredients: [
        { name: "potato", quantity: 2, unit: "pcs" },
        { name: "carrot", quantity: 2, unit: "pcs" },
        { name: "coconut milk", quantity: 400, unit: "ml" }
      ],
      tags: ["curry", "vegetarian", "dinner"]
    },
    {
      title: "Chicken Stir Fry",
      prep_time_minutes: 25,
      servings: 3,
      ingredients: [
        { name: "chicken breast", quantity: 300, unit: "g" },
        { name: "bell pepper", quantity: 1, unit: "pc" },
        { name: "soy sauce", quantity: 2, unit: "tbsp" }
      ],
      tags: ["non-vegetarian", "chinese", "easy"]
    },
    {
      title: "Berry Oatmeal Bowl",
      prep_time_minutes: 8,
      servings: 1,
      ingredients: [
        { name: "rolled oats", quantity: 50, unit: "g" },
        { name: "almond milk", quantity: 200, unit: "ml" },
        { name: "blueberries", quantity: 30, unit: "g" }
      ],
      tags: ["breakfast", "vegetarian", "healthy"]
    }
  ]);
  /*
  ===========================================
  TASK 1
