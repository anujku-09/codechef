# SPRINGPR03

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Alert Service API with Factory Pattern

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.

 **Goal :** 
Create an  **Alert Service API**  using Spring Boot and Spring Data JPA, and apply the  **Factory design pattern**.
Users send an alert by choosing a type (`email`, `sms` or `push`). A factory creates the correct notifier for that type, the notifier sends the alert, and the result is saved in the database.
Each Alert should contain:

- id (Auto-generated Primary Key)
- type
- recipient
- message
- result

 **Your Task :** 
Complete the code given in the IDE by following the requirements below :

 **1. Create Entity** 
Create a class `Alert.java`.
Fields:

- id
- type
- recipient
- message
- result

Use the following annotations:

- @Entity
- @Id
- @GeneratedValue

 **2. Create Repository** 
Create `AlertRepository.java`.
Extend:

```
JpaRepository<Alert, Long>

```

Do not write any implementation.

 **3. Create the Factory Pattern**  \

- Create a Notifier interface with a method that takes a recipient and a message and returns the result text.
- Create three classes that implement Notifier:
Class	Type	Result text returned
`EmailNotifier`	`email`	`Email sent to <recipient>: <message>`
`SmsNotifier`	`sms`	`SMS sent to <recipient>: <message>`
`PushNotifier`	`push`	`Push sent to <recipient>: <message>`
- Create a NotifierFactory class with a method that receives the type and returns the matching Notifier. The type is not case-sensitive. For an unknown or missing type, it returns null.
- Do not create notifiers with new inside the controller. Always get them from the factory.

 **4. Create Controller** 
Create `AlertController.java` with base path:

```
/api/alerts

```

 **5. Implement APIs** 
Implement the following APIs using built-in repository methods.

Method	Endpoint	Description	Success	Error
POST	`/api/alerts`	Send an alert and save it	`201 Created` with the saved alert and its generated ID	`400 Bad Request` with "Unsupported alert type"
GET	`/api/alerts`	Get all alerts	`200 OK` with the list	n/a
GET	`/api/alerts/{id}`	Get alert by ID	`200 OK` with the alert	`404 Not Found` with "Alert not found"
DELETE	`/api/alerts/{id}`	Delete an alert	`200 OK` with "Alert deleted successfully"	`404 Not Found` with "Alert not found"

An alert with an unsupported or missing `type` must  **not**  be saved.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-01T20:42:18.082Z  

```cpp
    @GetMapping("/{id}")
    public ResponseEntity<?> getAlertById(@PathVariable Long id) {
    
        return alertRepository.findById(id)
                .<ResponseEntity<?>>map(alert -> ResponseEntity.ok(alert))
                .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND)
                        .body("Alert not found"));
    }

    // DELETE /api/alerts/{id}
    @DeleteMapping("/{id}")
    // GET /api/alerts/{id}

    public ResponseEntity<?> deleteAlert(@PathVariable Long id) {

```

---

[View on CodeChef](https://www.codechef.com/problems/SPRINGPR03)