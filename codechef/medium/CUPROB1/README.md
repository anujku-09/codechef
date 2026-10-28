# CUPROB1

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Part 3 - Build the Express Scraping Endpoint

you will implement backend that fetches real CodeChef profile data by  **scraping**  the user profile page directly from CodeChef.com

By the end of this part, your backend will:

- Accept a CodeChef username from the frontend.
- Scrape the user’s public profile page using Cheerio, a library for reading HTML.
- Extract useful information such as name, country, ratings, ranks, and problems solved.
- Return all that data as a JSON response through an Express API endpoint.

 **Overview:** 

- You’re given an incomplete server.js (or index.js) file containing blanks; you’ll need to fill them in.
- Your job is to complete the missing imports, middleware setup, scraping logic, and API route so that it can fetch and return real profile data.
- The key library you’ll use is Cheerio, which allows you to: Load the HTML of a web page. Use jQuery-style selectors (like $(".class")) to find and extract specific text or numbers.
- All required libraries are already installed; there’s no need to install anything. You can simply focus on completing the functionality.
- The styling file App.css is already provided for you. You don’t need to modify or implement it.
- Additionally, we’ve provided you with an incomplete App.jsx file from the frontend. You’ll need to complete it here again so that you can test and verify the backend functionality.

 **Your Tasks:** 

- Import Required Modules Import express, cors, and cheerio libraries. Docs: Cheerio - Official Documentation Docs: CORS Middleware for Express
- Initialize Middlewares Enable CORS and JSON parsing so your server can receive requests and send responses. Docs: Express Middleware Guide
- Implement the Scraping Function (scrapeCodeChefProfile()) We’ve already written the scrapeCodeChefProfile() function for you—just go through it carefully and understand how it fetches the CodeChef page, loads HTML into Cheerio, and extracts data like name, ratings, ranks, and problem stats. You’ll then call this function from your API route.
- Create the GET API Route Add a route GET /profile/:username that:
- Reads the username from req.params.
- Validates it (returns a 400 error if missing).
- Calls scrapeCodeChefProfile(username) to get data.
- Sends the scraped data as a JSON response to the client. Docs: Routing in Express

 **Expected Behaviour:**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-28T18:04:17.458Z  

```cpp
      $(".user-details-container")
        .find("li:contains('Institution')")
    institution =
    let organisation = "";

    let institution = "";
    // Extract Affiliation (Institution / Organisation)

    const name = $(".user-details-container h1").first().text().trim() || "N/A";

    // Extract BASIC INFO
    const data = await response.text();
    const $ = cheerio.load(data); //data

    // Load HTML into Cheerio
    const response = await fetch(`https://www.codechef.com/users/${username}`); //encodeURIComponent(username)

    // In case of non-200 response, throw error with status code
    if (!response.ok) throw new Error(`HTTP ${response.status}`); //response.status

// Function: Scrape CodeChef profile data
const scrapeCodeChefProfile = async (username) => {
  try {
    // Fetch CodeChef user profile page
app.use(express.json());  //express.json()
// Enable CORS and JSON parsing middleware
app.use(cors()); //cors()

const app = express();

import express from "express";
import cors from "cors";
import * as cheerio from "cheerio";
        .text()
```

---

[View on CodeChef](https://www.codechef.com/problems/CUPROB1)