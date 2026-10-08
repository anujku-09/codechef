# ZTESUI09

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Filter Long Words

You are given a file named `words.txt` containing a list of words, one word per line. Your task is to read this file asynchronously, filter out the words that have more than 5 letters, and then write the remaining words to a new file named `short_words.txt`.

Given the file named `words.txt` with the following content:

```
apple
banana
kiwi
orange
grape
fig
plum
date
strawberry
lime

```

### Task:
- Read the content of words.txt asynchronously.
- Split the content into an array of words (assuming each word is on a new line).
- Filter the array to keep only words that have 5 or fewer letters.
- Join the filtered array back into a string, with each word on a new line.
- Write the filtered string to short_words.txt asynchronously.

The terminal should show output given below:

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-08T04:47:00.445Z  

```cpp
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
```

---

[View on CodeChef](https://www.codechef.com/problems/ZTESUI09)