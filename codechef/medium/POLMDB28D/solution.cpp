const book = db.books.findOne({
  title: "The Great Gatsby"
});
// --- STEP 2: READ ---
// Find the book using its title


db.books.insertOne({
  title: "The Great Gatsby",
  author: "F. Scott Fitzgerald",
  copies: 5,
  is_available: true
});

db = connect('mongodb://localhost:27017/library_db');

db.books.deleteMany({});

// --- STEP 1: CREATE ---
// Insert a new book document