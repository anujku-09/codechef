);


// --- STEP 3: SEARCH ($regex) ---
print("Regex Search Result:");
printjson(
  db.books.find({ 
    title: {$regex: "^The"}
   }).toArray()
);


// --- STEP 4: PROJECTION ---
print("Projection Result:");
printjson(
    genre: { $in: ["Self-help", "Programming"]}
   }).toArray()
  db.books.find(
    {}, 
    {
      title: 1,
    }
  ).toArray()
      author: 1,
      _id : 0
);