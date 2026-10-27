const updatedBook = db.books.findOne({
  title: "The Great Gatsby"
});
print("Book after borrowing:");
printjson(updatedBook);

// --- STEP 4: DELETE ---
// Delete the book using its title
db.books.deleteOne({
  title: "The Great Gatsby"
});
// Display final collection details
const count = db.books.countDocuments();
const allBooks = db.books.find().toArray();
print("Total documents in 'books' collection: " + count);
printjson(allBooks);