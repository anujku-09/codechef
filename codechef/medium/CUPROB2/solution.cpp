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
