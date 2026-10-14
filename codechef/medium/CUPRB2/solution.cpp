});
      return res.status(404).json({
        message: "Book not found"
      });
    }

    books.splice(index, 1);

    res.json({
      message: "Book deleted successfully"
    });
  } catch (error) {
    res.status(500).json({
      message: "Error deleting book",
      error: error.message
    });
  }

// Server
app.listen(PORT, () => {
  console.log(`🚀 Server running at http://localhost:${PORT}`);
});

export default app;

