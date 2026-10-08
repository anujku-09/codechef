console.log('Reading words.txt...');

fs.readFile('words.txt', 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }

  const words = data.split('\n').map(word => word.trim()).filter(Boolean);
  const shortWords = words.filter(word => word.length <= 5);
  const result = shortWords.join('\n');

  console.log('Writing short words to short_words.txt...');

  fs.writeFile('short_words.txt', result, 'utf8', (err) => {
    if (err) {
      console.error(err);
      return;
    }
    console.log('Short words written successfully!');

  });
});