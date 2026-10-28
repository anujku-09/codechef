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