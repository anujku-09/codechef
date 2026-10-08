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