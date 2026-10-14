
// Do not modify this 
// --- Example Usage ---
if (process.env.NODE_ENV !== "test") {
  const myTicket = generateTicket("12345", "Rock Concert 2025");
  console.log("Generated Ticket:", myTicket);
    const decoded = jwt.verify(ticket, TICKET_SECRET_KEY);
    return decoded;
  } catch (error){
    return null;
  }
}

  return token;
}

function verifyTicket(ticket) {
  try{
  };

  const token = jwt.sign(payload, TICKET_SECRET_KEY, {
    expiresIn: "24h"
  });

  const verified = verifyTicket(myTicket);
  console.log("Verified Ticket Payload:", verified);

  const invalid = verifyTicket("fake.token.value");
  console.log("Invalid Ticket:", invalid);
}

export { generateTicket, verifyTicket, TICKET_SECRET_KEY };