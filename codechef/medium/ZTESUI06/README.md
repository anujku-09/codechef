# ZTESUI06

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### File Organizer Script

You're building a simple script to organize files. The script should take a file name as input.

### Here's the problem:

Your script should first check if a file with the given name exists. If the file  *doesn't*  exist, it should create it.
Then, regardless of whether it was created or already existed, the script should add the text use `appendFileSync(file_name, "text to be added")` to add the text in the file.

```
"File organized!"

```

Finally, the script should rename the file to `organized_file.txt`. And the output strings should show the name of the files dynamically.

The output should look like the image given below:

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-08T04:36:40.947Z  

```cpp
const organizedFilePath = path.resolve(__dirname, organizedFileName);

// write your code here
if (!fs.existsSync(initialFilePath)) {
    fs.writeFileSync(initialFilePath, '');
    console.log(`Created new file: ${initialFileName}`);
}

fs.appendFileSync(initialFilePath, 'File organized!');
console.log(`Appended "File organized!" to ${initialFileName}`);

fs.renameSync(initialFilePath, organizedFilePath);
console.log(`File renamed to ${organizedFileName}`);
const initialFilePath = path.resolve(__dirname, initialFileName);

const organizedFileName = 'organized_file.txt';
```

---

[View on CodeChef](https://www.codechef.com/problems/ZTESUI06)