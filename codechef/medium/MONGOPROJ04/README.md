# MONGOPROJ04

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Recipe Book - Find & Filter

The Recipe Book already contains a fully seeded collection of recipes in MongoDB. What it lacks is a way to search them. In this exercise, you'll focus entirely on MongoDB queries using `find()`, `comparison operators`, `array matching`, and the `logical operators` `$and` and `$or`. The data is already provided and remains fixed, so your only task is to write the queries that power the search routes.

`db.js` connects to MongoDB, clears out old data, and inserts a fixed batch of recipes every time the server starts - so your data is always the same, and you can always reset back to a known state by restarting the server.

 **The data you're querying against** 
Every recipe document has this shape. Note the two array fields (`ingredients`, `tags`) and the three boolean dietary flags - these are the fields your queries in `routes.js` will target:

```
{
  title: "Spaghetti Carbonara",
  prep_time_minutes: 20,
  servings: 4,
  ingredients: [
    { name: "spaghetti", quantity: 400, unit: "g" },
    { name: "eggs", quantity: 4, unit: "whole" },
    { name: "parmesan cheese", quantity: 100, unit: "g" }
  ],
  tags: ["italian", "dinner"],
  is_vegetarian: false,
  is_vegan: false,
  is_gluten_free: false
}

```

`prep_time_minutes` and `servings` are numeric fields, making them suitable for comparison operators such as `$gte` and `$lte`. `ingredients` is an array of objects, so ingredient searches should target the nested `ingredients.name` field. `tags` is an array of strings, allowing direct tag matching, while the `is_*` fields are simple booleans that can be queried with equality checks.

The complete seed dataset is already provided in `db.js`. Review it before writing your queries so you understand the available recipes and the results each route should return.

 **Your task: `routes.js`** 
You'll find five `TODO` blocks, each focused on a different querying concept. The route definitions, error handling, and response logic are already written - you're only filling in the `find()` calls.

 **Task 1 - Comparison operators: `GET /recipes/quick`** 

Return recipes that take  **20 minutes or less**  to prep. This is the simplest case: a single field, compared against a fixed number using `$lte`.

 **Task 2 - Comparison operators with a range: `GET /recipes/by-time-range?min=10&max=30`** 

Return recipes whose `prep_time_minutes` falls  **between**  `min` and `max`, both inclusive. The query-string parsing is already handled for you - `min` and `max` arrive as numbers. You need two comparison operators on the same field, combined inside a single filter object.

 **Task 3 - Array queries: `GET /recipes/with-ingredient?name=chicken`** 

Return recipes that contain a specific ingredient by name. Remember that `ingredients` is an array of objects, not an array of plain strings - you're matching against `ingredients.name`, the field nested inside each array element, not the array itself.

 **Task 4 - Logical `$and`: `GET /recipes/vegetarian-quick`** 

Return recipes that are  **both**  vegetarian  **and**  take 20 minutes or less to prep. Both conditions have to be true at once - this is where `$and` (or an equivalent way of expressing "both of these") comes in, combining a boolean equality check with a comparison operator.

 **Task 5 - Logical `$or` combined with array and dietary queries: `GET /recipes/flexible-search?tag=dinner`** 

This is the most involved route, and it's deliberately built to combine everything from Tasks 1–4 into one query. Return recipes that match  **either**  of these two conditions:

- the recipe is vegan, or
- the recipe's tags array contains the tag passed in as a query parameter

 **Note:**  Start or restart the backend server before testing your solution. The seed data is inserted when `db.js` runs, and the query routes rely on that data being present.

 **Expected output**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T15:12:01.440Z  

```cpp
import express from "express";
import cors from "cors";
import { initDB } from "./db.js";
import router from "./routes.js";
 
const app = express();
 
app.use(cors());
app.use(express.json());
 
await initDB();
 
app.use("/recipes", router);
 
const server = app.listen(8080, () => {
  console.log("Server running on Port 8080");
});
 
export default server;
```

---

[View on CodeChef](https://www.codechef.com/problems/MONGOPROJ04)