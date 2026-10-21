# SPRINGHARD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Product Manager API

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.

 **Goal :** 
Create a  **Bank Transfer API**  using Spring Boot and Spring Data JPA.
The application should  **transfer money between two accounts inside a `@Transactional` method**, prove that  **rollback works**  when an exception occurs mid-transfer, and return a  **clean JSON error**  using a global exception handler.
Each BankAccount should contain:

- id (Auto-generated Primary Key)
- accountHolder
- balance

 **Your Task :** 
Complete the code, given in IDE By following the below Requirements :

 **1. Create Entity** 
Create a class `BankAccount.java` inside the model package.
Fields:

- id
- accountHolder
- balance

Use the following annotations:

- @Entity
- @Id
- @GeneratedValue

 **2. Create Repository** 
Create `BankAccountRepository.java` inside the repository package.
Extend:

```
JpaRepository<BankAccount, Long>

```

Do not write any implementation.

 **3. Create Custom Exception** 
Create `InsufficientFundsException.java` inside the exception package. \

- It must extend RuntimeException
- It must accept a message in its constructor

 **4. Create Service** 
Create `BankService.java` inside the service package. \

- Use constructor-based Dependency Injection for the repository
- Implement transfer(fromId, toId, amount) annotated with @Transactional
- Implement transferWithFailure(fromId, toId, amount) annotated with @Transactional

Transfer Logic:

- Fetch both accounts
- If the sender's balance is less than the amount, throw InsufficientFundsException
- Debit the sender and credit the receiver, then save both

Rollback Demo Logic (`transferWithFailure`):

- Debit the sender and save
- Throw a RuntimeException before the receiver is credited
- Because of @Transactional, the debit must be rolled back

 **5. Create Global Exception Handler** 
Create `GlobalExceptionHandler.java` inside the exception package. \

- Annotate with @ControllerAdvice (or @RestControllerAdvice)
- Handle InsufficientFundsException using @ExceptionHandler
- Return HTTP status 400 Bad Request with a clean JSON body

 **6. Create Controller** 
Create `BankController.java` inside the controller package.
Base path:

```
/api/accounts

```

 **7. Implement APIs** 

Method	Endpoint	Description	Success Response
GET	`/api/accounts`	Get all accounts	List of accounts
GET	`/api/accounts/{id}`	Get account by id	Single account
POST	`/api/accounts/transfer`	Transfer money between two accounts	`Transfer successful!`
POST	`/api/accounts/transfer-with-failure`	Rollback demo: fails mid-transfer	`500` error, balances unchanged

 **Sample Data (loaded on startup)** 

```
ID 1 - Arjun - 5000
ID 2 - Meera - 3000

```

 **Example Request (POST)** 

```
POST /api/accounts/transfer

```

Body:

```
{
  "fromAccountId": 1,
  "toAccountId": 2,
  "amount": 1000
}

```

 **Response:** 

```
Transfer successful!

```

After this, Arjun's balance is `4000` and Meera's balance is `4000`.

 **Example Error (Insufficient Funds)** 

Body:

```
{
  "fromAccountId": 1,
  "toAccountId": 2,
  "amount": 99999
}

```

 **Response (400 Bad Request):** 

```
{
  "status": 400,
  "error": "Insufficient Funds",
  "message": "Account 1 does not have enough balance"
}

```

 **Rollback Check** 

- Call GET /api/accounts and note both balances
- Call POST /api/accounts/transfer-with-failure with a valid body
- The API returns an error
- Call GET /api/accounts again. Both balances must be unchanged

Note :

- Test All the API endpoints properly
- Do NOT write transfer logic inside the controller
- To See Database : Open H2 Console In the lab URL, after codechef-apps.com Add : \

```
/h2-console/login.jsp

```

Login using below details-

```
JDBC URL : jdbc:h2:mem:testdb
Username : sa
Password : (leave empty)

```

Then Run Query : `SELECT * FROM BANK_ACCOUNT`
& Observe the result in Table `BANK_ACCOUNT`.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T10:26:55.374Z  

```cpp
package com.example.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class DemoApplication {

    public static void main(String[] args) {

        SpringApplication.run(DemoApplication.class, args);
        

        System.out.println("Spring Boot application started!");
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRINGHARD)