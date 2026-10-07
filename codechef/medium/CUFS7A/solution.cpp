    const hashed = hashPassword("mySecurePass123");
    console.log("Hashed Password:", hashed);

    console.log("Correct Password Check:", verifyPassword("mySecurePass123", hashed));
    console.log("Wrong Password Check:", verifyPassword("wrongPass", hashed));

    const myToken = generateToken("U100", "user@secureauth.com");
    console.log("Generated Token:", myToken);

    console.log("Decoded Token Payload:", decodeToken(myToken));
    console.log("Invalid Token:", decodeToken("fake.token.value"));
}


// Export for testing
export { hashPassword, verifyPassword, generateToken, decodeToken, AUTH_SECRET_KEY };