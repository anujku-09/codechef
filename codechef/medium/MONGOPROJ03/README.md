# MONGOPROJ03

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Recipe Book - Insert Operations

The cooking blog wants its recipe page live. The engineering team has already built the entire backend API and the frontend page that displays whatever's in the database - every route, every query, all of it. The one piece missing is the data itself: nobody has written the code that actually gets the recipes into MongoDB.

That's the whole job here. This exercise is deliberately narrow: you will write exactly two operations, `insertOne` and `insertMany`, and the real skill being tested is whether you structure the documents correctly while doing it. Once your inserts run, the page should populate itself - you won't touch routing, querying, or any frontend code at all.

 **Your task: `db.js`** 

Open `db.js`. You'll find it already handles connecting to MongoDB, switching to the `recipebook` database, and clearing out the `recipes` collection on every server start (so re-running the server always gives you a clean slate). Two `TODO` blocks are left for you to fill in.

 **Task 1 - `insertOne`** 
Insert a single recipe document with exactly these fields:

Field	Type
`title`	String
`prep_time_minutes`	Number
`servings`	Number
`ingredients`	Array of `{ name, quantity, unit }` objects
`tags`	Array of Strings

 **Task 2 - `insertMany`** 
Insert  **at least four more**  recipes in a single `insertMany` call, using the identical document shape from Task 1. To make sure your batch has real variety rather than four near-duplicates:

- Every recipe needs all five fields, with ingredients having at least 3 items and tags having at least 2.
- At least one recipe should be tagged "vegetarian".
- At least one recipe should have prep_time_minutes of 15 or less.
- servings shouldn't be identical across every recipe — include some spread.

 **Note:**  After completing the `insertOne()` and `insertMany()` tasks, start (or restart) the backend server so that `initDB()` runs and populates the database with your recipe documents. Once the data has been inserted correctly, the frontend should display the recipes.

 **Expected output**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T15:05:17.648Z  

```cpp

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

```

---

[View on CodeChef](https://www.codechef.com/problems/MONGOPROJ03)