        System.out.println(line);
        for (Book b : books) {
            System.out.printf("| %-6d | %-26s | %-18s | %10.2f |%n",
                    b.getBookId(), b.getTitle(), b.getAuthor(), b.getPrice());
        }
        System.out.println(line);
        System.out.println("Total books: " + books.size());
    }

    public void displayError(String message) {
        System.err.println("Error: " + message);
    }
}
