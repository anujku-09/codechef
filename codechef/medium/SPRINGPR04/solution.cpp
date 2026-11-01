            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Title is required");
        if (book.getTitle() == null || book.getTitle().trim().isEmpty()) {
    public ResponseEntity<?> addBook(@RequestBody Book book) {

    @PostMapping
    }
        return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Book not found");
        }
            }
                return ResponseEntity.ok(b);
            if (b.getId() == id) {
    public ResponseEntity<?> getBookById(@PathVariable int id) {
        for (Book b : books) {
        }
        book.setId(counter++);
        books.add(book);
        return ResponseEntity.status(HttpStatus.CREATED).body(book);
    }

    @PutMapping("/{id}")
    public ResponseEntity<?> updateBook( @PathVariable int id, @RequestBody Book updatedBook) {
        for (Book b : books) {
            if (b.getId() == id) {
                if (updatedBook.getTitle() == null || updatedBook.getTitle().trim().isEmpty()) {
                    return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Title is required");
                }
                b.setTitle(updatedBook.getTitle());
                b.setAuthor(updatedBook.getAuthor());
                b.setPrice(updatedBook.getPrice());

                return ResponseEntity.ok(b);
            }
        }
        return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Book not found");
    }
