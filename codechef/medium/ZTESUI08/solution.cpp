  // Step 3: Join back into string

  const filtered = fruits.filter(fruit => !fruit.toLowerCase().startsWith('b'));
  // Step 2: Filter fruits that don't start with 'b' or 'B'

  // Step 1: Split into lines
  const fruits = data.split('\n').map(fruit => fruit.trim());
  }

  if (err) {
    return console.error('Error reading file:', err);

// complete the code to read the inputFile
fs.readFile(inputFile, 'utf8', (err, data) => {

console.log('Reading fruits.txt...');
const inputFile = path.resolve(__dirname, 'fruits.txt');
const outputFile = path.resolve(__dirname, 'filtered_fruits.txt');

const path = require('path');