# CUPROB2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Implementing Endpoints for Adding & Editing Posts

you built the React UI for creating and editing posts. Now it’s time to bring your frontend to life by implementing a fully functional backend using  **Express.js**,  **MongoDB**, and  **Mongoose**.

By the end your backend will:

- Store posts (title, content, likes, and comments) in a MongoDB database.
- Allow users to create new posts and edit their existing ones.
- Support liking and commenting features.
- Protect default seeded posts from being modified.

 **Overview:** 
In this part, your backend setup already includes:

- Predefined routes for getting all posts, adding new posts, liking posts, commenting, and editing posts.
- A seeding function that adds two default posts when the database is empty.
- All required libraries are already installed; there’s no need to install anything. You can simply focus on completing the functionality.
- The styling file App.css is already provided for you. You don’t need to modify or implement it.
- Additionally, we’ve provided you with an incomplete App.jsx file from the frontend. You’ll need to complete it here again so that you can test and verify the backend functionality.

You’ll complete the missing parts of the backend logic to make these APIs fully functional.

 **Your Tasks:** 

- Import Required Modules Import express, cors, and cheerio libraries. Docs: CORS Middleware for Express
- Initialize Middlewares Enable CORS and JSON parsing so your server can receive requests and send responses. Docs: Express Middleware Guide
- Connect to MongoDB
- Define a MONGO_URI variable with your MongoDB connection string. 🔑 How to get the connection string: Go to MongoDB Atlas Create a new cluster (free tier is fine). Add a database user with a username and password. In the cluster dashboard, click Connect → Connect your application. Copy the connection string and replace <username>, <password>, and <dbname> with your actual details. Docs: MongoDB Connection String
- Use mongoose.connect(MONGO_URI) to establish the connection.
- Define the Mongoose Schemas
- Create a commentSchema containing: text (String, required) date (Date, default: current date)
- Create a postSchema containing: id (Number, unique, required) title and content (String, required) likes (Number, default: 0) comments (Array of commentSchema) isSeeded (Boolean, default: false) — marks seeded posts that should not be edited.
- Create a Post model using mongoose.model(). Docs: Mongoose Schemas
- Implement the /posts API (Add a New Post)
- Extract title and content from the request body.
- Validate both fields — return a 400 error if either is missing.
- Find the latest post to calculate a new unique id.
- Create a new post with: likes: 0 comments: [] isSeeded: false
- Save it to MongoDB and return the created post as a response. Docs Mongoose Model.save() Docs HTTP Status Codes
- Implement the /posts/:id API (Edit a Post)
- Fetch title and content from the request body.
- Validate input — return 400 if either is missing.
- Find the post by its id.
- Return a 404 if not found.
- If the post is seeded (isSeeded: true), return a 403 with a message like: "You cannot edit default seeded posts."
- Otherwise, update the post’s title and content, save it, and return the updated post. Docs: Express Routing Docs: Mongoose Queries
- Extra APIs (Already Defined) You’ll also notice two supporting APIs already included in your code:
- POST /posts/:id/like → Increments likes for a specific post.
- POST /posts/:id/comment → Adds a new comment to a post.

Make sure these routes work correctly after connecting your database.

 **Expected Behaviour:**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T18:16:31.406Z  

```cpp
    await newPost.save();

    });
      isSeeded: false  //false
      comments: [],  //[]
      likes: 0,  //0
      content,
      title,
      id: newId,
    const newPost = new Post({

    // Create new post with 0 likes, empty comments, isSeeded false
    const newId = lastPost ? lastPost.id + 1 : 1;
    const lastPost = await Post.findOne().sort({ id: -1 });

}
    .json({ error: "Both title and content are required." });
    .status(400)
if (!title || !content) {
  return res
    // If either title or content is missing, return 400 error

    const { title, content } = req.body; // title; content
    // Fetch title and content from request body

  try {

```

---

[View on CodeChef](https://www.codechef.com/problems/CUPROB2)