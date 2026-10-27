const http = require('http');

const USERNAME = 'Harry';  // You can set it to null or '' to test the "Guest" fallback

const server = http.createServer((req, res) => {
  // Prepare the greeting message
  const name = USERNAME && USERNAME.trim() !== '' ? USERNAME : 'Guest';
  const greeting = `Hello, ${name}!`;

  // Set the Content-Type header to plain text
  res.writeHead(200, { 'Content-Type': 'text/plain' });

  // Write the greeting and end the response
  res.write(greeting);
  res.end();
});

server.listen(3000, () => {
  console.log('Greeting Server is running at http://localhost:3000');
});
