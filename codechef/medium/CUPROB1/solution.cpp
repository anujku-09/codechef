    const username = String(req.params.username || "").trim();

    // If username is missing, return 400 error
    if (!username)  //!username
      return res.status(400).json({ error: "Username is required" }); //400

    // Scrape data using the function
    const profileData = await scrapeCodeChefProfile(username); //scrapeCodeChefProfile(username);

    // Send scraped data as JSON response
    res.json(profileData); //profileData

  } catch (err) {
    res
      .status(500)
      .json({ error: "Failed to fetch profile", message: err.message });
  }
});

const PORT = 8080;
app.listen(PORT, () => console.log(`🚀 Server running on port ${PORT}`));