#### Problem 2: File Manager
```cpp
class FileManager {
    void readFile(string path) { /* reads file */ }
    void writeFile(string path, string content) { /* writes file */ }
    void compressFile(string path) { /* compresses file */ }
    void encryptFile(string path) { /* encrypts file */ }
    void uploadToCloud(string path) { /* uploads to cloud */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 3: Order Processing
```cpp
class Order {
    void calculateTotal() { /* calculates order total */ }
    void applyDiscount() { /* applies discount */ }
    void generateInvoice() { /* generates invoice */ }
    void sendConfirmationEmail() { /* sends email */ }
    void updateInventory() { /* updates stock */ }
};
```
**Task**: Identify responsibilities and separate them.

#### Problem 4: Bank Account
```cpp
class BankAccount {
    double balance;
    void deposit(double amount) { /* deposits money */ }
    void withdraw(double amount) { /* withdraws money */ }
    void calculateInterest() { /* calculates interest */ }
    void generateStatement() { /* generates statement */ }
    void sendSMS() { /* sends SMS notification */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 5: Library Management
```cpp
class Book {
    string title, author;
    void borrowBook() { /* borrows book */ }
    void returnBook() { /* returns book */ }
    void calculateFine() { /* calculates fine */ }
    void sendReminder() { /* sends reminder email */ }
    void updateAvailability() { /* updates availability */ }
};
```
**Task**: Separate concerns into different classes.

#### Problem 6: Email System
```cpp
class EmailService {
    void composeEmail() { /* composes email */ }
    void validateRecipients() { /* validates recipients */ }
    void sendEmail() { /* sends email */ }
    void saveDraft() { /* saves draft */ }
    void trackDelivery() { /* tracks delivery status */ }
};
```
**Task**: Identify and separate responsibilities.

#### Problem 7: Student Management
```cpp
class Student {
    string name, rollNumber;
    void enrollCourse() { /* enrolls in course */ }
    void calculateGPA() { /* calculates GPA */ }
    void generateReportCard() { /* generates report card */ }
    void sendNotification() { /* sends notification */ }
    void updateAttendance() { /* updates attendance */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 8: Restaurant Order
```cpp
class RestaurantOrder {
    void addItem() { /* adds item to order */ }
    void calculateBill() { /* calculates bill */ }
    void applyTax() { /* applies tax */ }
    void printReceipt() { /* prints receipt */ }
    void notifyKitchen() { /* notifies kitchen */ }
};
```
**Task**: Separate different concerns.

#### Problem 9: Car Rental
```cpp
class CarRental {
    void rentCar() { /* rents car */ }
    void calculateRent() { /* calculates rent */ }
    void generateContract() { /* generates contract */ }
    void sendConfirmation() { /* sends confirmation */ }
    void updateMileage() { /* updates mileage */ }
};
```
**Task**: Identify SRP violations and refactor.

#### Problem 10: Movie Booking
```cpp
class MovieBooking {
    void bookTicket() { /* books ticket */ }
    void calculatePrice() { /* calculates price */ }
    void generateTicket() { /* generates ticket */ }
    void sendSMS() { /* sends SMS */ }
    void updateSeatAvailability() { /* updates seats */ }
};
```
**Task**: Separate responsibilities.

#### Problem 11: Gym Membership
```cpp
class GymMembership {
    void createMembership() { /* creates membership */ }
    void calculateFees() { /* calculates fees */ }
    void generateIDCard() { /* generates ID card */ }
    void sendWelcomeEmail() { /* sends welcome email */ }
    void trackAttendance() { /* tracks attendance */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 12: Insurance Policy
```cpp
class InsurancePolicy {
    void createPolicy() { /* creates policy */ }
    void calculatePremium() { /* calculates premium */ }
    void generatePolicyDocument() { /* generates document */ }
    void sendPolicyEmail() { /* sends policy email */ }
    void processClaim() { /* processes claim */ }
};
```
**Task**: Identify and separate concerns.

#### Problem 13: Hotel Booking
```cpp
class HotelBooking {
    void bookRoom() { /* books room */ }
    void calculateTotal() { /* calculates total */ }
    void generateBookingConfirmation() { /* generates confirmation */ }
    void sendBookingEmail() { /* sends email */ }
    void updateRoomAvailability() { /* updates availability */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 14: Course Management
```cpp
class Course {
    void createCourse() { /* creates course */ }
    void enrollStudents() { /* enrolls students */ }
    void calculateGrade() { /* calculates grade */ }
    void generateCertificate() { /* generates certificate */ }
    void sendNotification() { /* sends notification */ }
};
```
**Task**: Separate different responsibilities.

#### Problem 15: Product Catalog
```cpp
class ProductCatalog {
    void addProduct() { /* adds product */ }
    void updateProduct() { /* updates product */ }
    void generateCatalog() { /* generates catalog */ }
    void sendCatalogEmail() { /* sends catalog email */ }
    void trackViews() { /* tracks views */ }
};
```
**Task**: Identify SRP violations and refactor.

### **Intermediate Level (Problems 16-30)**

#### Problem 16: E-commerce Shopping Cart
```cpp
class ShoppingCart {
    vector<Product> items;
    void addItem(Product item) { /* adds item */ }
    void removeItem(Product item) { /* removes item */ }
    void calculateTotal() { /* calculates total */ }
    void applyCoupon() { /* applies coupon */ }
    void generateInvoice() { /* generates invoice */ }
    void processPayment() { /* processes payment */ }
    void sendOrderConfirmation() { /* sends confirmation */ }
    void updateInventory() { /* updates inventory */ }
    void calculateShipping() { /* calculates shipping */ }
};
```
**Task**: Refactor this complex class following SRP.

#### Problem 17: Banking Transaction System
```cpp
class BankingTransaction {
    void transferMoney() { /* transfers money */ }
    void validateTransaction() { /* validates transaction */ }
    void logTransaction() { /* logs transaction */ }
    void sendNotification() { /* sends notification */ }
    void updateBalance() { /* updates balance */ }
    void generateReceipt() { /* generates receipt */ }
    void checkFraud() { /* checks for fraud */ }
    void updateCreditScore() { /* updates credit score */ }
};
```
**Task**: Separate concerns into different classes.

#### Problem 18: Social Media Post
```cpp
class SocialMediaPost {
    void createPost() { /* creates post */ }
    void validateContent() { /* validates content */ }
    void publishPost() { /* publishes post */ }
    void sendNotification() { /* sends notification */ }
    void trackEngagement() { /* tracks engagement */ }
    void moderateContent() { /* moderates content */ }
    void generateAnalytics() { /* generates analytics */ }
    void archivePost() { /* archives post */ }
};
```
**Task**: Identify and separate responsibilities.

#### Problem 19: Flight Booking System
```cpp
class FlightBooking {
    void searchFlights() { /* searches flights */ }
    void bookFlight() { /* books flight */ }
    void calculatePrice() { /* calculates price */ }
    void generateTicket() { /* generates ticket */ }
    void sendConfirmation() { /* sends confirmation */ }
    void updateSeatAvailability() { /* updates seats */ }
    void checkIn() { /* handles check-in */ }
    void generateBoardingPass() { /* generates boarding pass */ }
    void sendReminder() { /* sends reminder */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 20: Employee Management
```cpp
class Employee {
    void hireEmployee() { /* hires employee */ }
    void calculateSalary() { /* calculates salary */ }
    void generatePayroll() { /* generates payroll */ }
    void sendPayslip() { /* sends payslip */ }
    void trackAttendance() { /* tracks attendance */ }
    void conductReview() { /* conducts review */ }
    void updatePerformance() { /* updates performance */ }
    void generateReport() { /* generates report */ }
};
```
**Task**: Separate different concerns.

#### Problem 21: Online Learning Platform
```cpp
class CourseEnrollment {
    void enrollStudent() { /* enrolls student */ }
    void trackProgress() { /* tracks progress */ }
    void calculateGrade() { /* calculates grade */ }
    void generateCertificate() { /* generates certificate */ }
    void sendNotification() { /* sends notification */ }
    void updateCurriculum() { /* updates curriculum */ }
    void moderateDiscussion() { /* moderates discussion */ }
    void generateAnalytics() { /* generates analytics */ }
};
```
**Task**: Identify SRP violations and refactor.

#### Problem 22: Inventory Management
```cpp
class InventoryManager {
    void addProduct() { /* adds product */ }
    void updateStock() { /* updates stock */ }
    void generateReport() { /* generates report */ }
    void sendLowStockAlert() { /* sends alert */ }
    void calculateReorderPoint() { /* calculates reorder point */ }
    void processOrder() { /* processes order */ }
    void trackMovement() { /* tracks movement */ }
    void generateForecast() { /* generates forecast */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 23: Event Management
```cpp
class EventManager {
    void createEvent() { /* creates event */ }
    void registerAttendee() { /* registers attendee */ }
    void sendInvitation() { /* sends invitation */ }
    void generateTicket() { /* generates ticket */ }
    void trackAttendance() { /* tracks attendance */ }
    void collectFeedback() { /* collects feedback */ }
    void generateReport() { /* generates report */ }
    void sendThankYou() { /* sends thank you */ }
};
```
**Task**: Separate responsibilities.

#### Problem 24: Content Management System
```cpp
class ContentManager {
    void createContent() { /* creates content */ }
    void editContent() { /* edits content */ }
    void publishContent() { /* publishes content */ }
    void moderateContent() { /* moderates content */ }
    void trackViews() { /* tracks views */ }
    void generateSEO() { /* generates SEO */ }
    void sendNotification() { /* sends notification */ }
    void archiveContent() { /* archives content */ }
};
```
**Task**: Identify and separate concerns.

#### Problem 25: Subscription Management
```cpp
class SubscriptionService {
    void createSubscription() { /* creates subscription */ }
    void processPayment() { /* processes payment */ }
    void sendInvoice() { /* sends invoice */ }
    void trackUsage() { /* tracks usage */ }
    void sendReminder() { /* sends reminder */ }
    void renewSubscription() { /* renews subscription */ }
    void cancelSubscription() { /* cancels subscription */ }
    void generateReport() { /* generates report */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 26: Document Management
```cpp
class DocumentManager {
    void createDocument() { /* creates document */ }
    void editDocument() { /* edits document */ }
    void saveDocument() { /* saves document */ }
    void shareDocument() { /* shares document */ }
    void trackChanges() { /* tracks changes */ }
    void generateVersion() { /* generates version */ }
    void sendNotification() { /* sends notification */ }
    void archiveDocument() { /* archives document */ }
};
```
**Task**: Separate different responsibilities.

#### Problem 27: Customer Support
```cpp
class CustomerSupport {
    void createTicket() { /* creates ticket */ }
    void assignTicket() { /* assigns ticket */ }
    void resolveTicket() { /* resolves ticket */ }
    void sendResponse() { /* sends response */ }
    void trackSatisfaction() { /* tracks satisfaction */ }
    void generateReport() { /* generates report */ }
    void escalateTicket() { /* escalates ticket */ }
    void closeTicket() { /* closes ticket */ }
};
```
**Task**: Identify SRP violations and refactor.

#### Problem 28: Project Management
```cpp
class ProjectManager {
    void createProject() { /* creates project */ }
    void assignTask() { /* assigns task */ }
    void trackProgress() { /* tracks progress */ }
    void generateReport() { /* generates report */ }
    void sendUpdate() { /* sends update */ }
    void manageBudget() { /* manages budget */ }
    void scheduleMeeting() { /* schedules meeting */ }
    void closeProject() { /* closes project */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 29: Quality Assurance
```cpp
class QualityAssurance {
    void createTestPlan() { /* creates test plan */ }
    void executeTest() { /* executes test */ }
    void reportBug() { /* reports bug */ }
    void trackDefects() { /* tracks defects */ }
    void generateReport() { /* generates report */ }
    void sendNotification() { /* sends notification */ }
    void updateStatus() { /* updates status */ }
    void closeDefect() { /* closes defect */ }
};
```
**Task**: Separate concerns.

#### Problem 30: Financial Planning
```cpp
class FinancialPlanner {
    void createPlan() { /* creates plan */ }
    void calculateBudget() { /* calculates budget */ }
    void trackExpenses() { /* tracks expenses */ }
    void generateReport() { /* generates report */ }
    void sendAlert() { /* sends alert */ }
    void updateForecast() { /* updates forecast */ }
    void recommendAction() { /* recommends action */ }
    void archivePlan() { /* archives plan */ }
};
```
**Task**: Identify and separate responsibilities.

### **Advanced Level (Problems 31-40)**

#### Problem 31: Microservices Architecture
```cpp
class UserService {
    void createUser() { /* creates user */ }
    void authenticateUser() { /* authenticates user */ }
    void sendWelcomeEmail() { /* sends welcome email */ }
    void logActivity() { /* logs activity */ }
    void updateProfile() { /* updates profile */ }
    void generateToken() { /* generates token */ }
    void validatePermission() { /* validates permission */ }
    void syncWithExternalService() { /* syncs with external service */ }
    void backupUserData() { /* backups user data */ }
    void generateAnalytics() { /* generates analytics */ }
};
```
**Task**: Refactor this complex service following SRP.

#### Problem 32: IoT Device Management
```cpp
class IoTDeviceManager {
    void registerDevice() { /* registers device */ }
    void collectData() { /* collects data */ }
    void processData() { /* processes data */ }
    void sendData() { /* sends data */ }
    void updateFirmware() { /* updates firmware */ }
    void monitorHealth() { /* monitors health */ }
    void sendAlert() { /* sends alert */ }
    void generateReport() { /* generates report */ }
    void backupData() { /* backups data */ }
    void optimizePerformance() { /* optimizes performance */ }
};
```
**Task**: Separate concerns into different classes.

#### Problem 33: Blockchain Transaction
```cpp
class BlockchainTransaction {
    void createTransaction() { /* creates transaction */ }
    void validateTransaction() { /* validates transaction */ }
    void signTransaction() { /* signs transaction */ }
    void broadcastTransaction() { /* broadcasts transaction */ }
    void mineBlock() { /* mines block */ }
    void updateLedger() { /* updates ledger */ }
    void sendNotification() { /* sends notification */ }
    void trackStatus() { /* tracks status */ }
    void generateReceipt() { /* generates receipt */ }
    void handleConflict() { /* handles conflict */ }
};
```
**Task**: Identify SRP violations and refactor.

#### Problem 34: AI Model Training
```cpp
class AIModelTrainer {
    void loadData() { /* loads data */ }
    void preprocessData() { /* preprocesses data */ }
    void trainModel() { /* trains model */ }
    void validateModel() { /* validates model */ }
    void saveModel() { /* saves model */ }
    void deployModel() { /* deploys model */ }
    void monitorPerformance() { /* monitors performance */ }
    void retrainModel() { /* retrains model */ }
    void generateReport() { /* generates report */ }
    void sendAlert() { /* sends alert */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 35: Real-time Chat System
```cpp
class ChatSystem {
    void sendMessage() { /* sends message */ }
    void receiveMessage() { /* receives message */ }
    void validateMessage() { /* validates message */ }
    void moderateMessage() { /* moderates message */ }
    void encryptMessage() { /* encrypts message */ }
    void decryptMessage() { /* decrypts message */ }
    void storeMessage() { /* stores message */ }
    void retrieveMessage() { /* retrieves message */ }
    void notifyUser() { /* notifies user */ }
    void trackActivity() { /* tracks activity */ }
};
```
**Task**: Separate different responsibilities.

#### Problem 36: E-commerce Recommendation Engine
```cpp
class RecommendationEngine {
    void collectUserData() { /* collects user data */ }
    void analyzeBehavior() { /* analyzes behavior */ }
    void generateRecommendation() { /* generates recommendation */ }
    void rankRecommendation() { /* ranks recommendation */ }
    void filterRecommendation() { /* filters recommendation */ }
    void personalizeContent() { /* personalizes content */ }
    void trackClick() { /* tracks click */ }
    void updateAlgorithm() { /* updates algorithm */ }
    void generateReport() { /* generates report */ }
    void sendNotification() { /* sends notification */ }
};
```
**Task**: Identify and separate concerns.

#### Problem 37: Healthcare Patient Management
```cpp
class PatientManager {
    void registerPatient() { /* registers patient */ }
    void scheduleAppointment() { /* schedules appointment */ }
    void recordVitalSigns() { /* records vital signs */ }
    void generatePrescription() { /* generates prescription */ }
    void sendReminder() { /* sends reminder */ }
    void trackMedication() { /* tracks medication */ }
    void generateReport() { /* generates report */ }
    void shareWithSpecialist() { /* shares with specialist */ }
    void backupMedicalData() { /* backups medical data */ }
    void complyWithRegulations() { /* complies with regulations */ }
};
```
**Task**: Refactor to follow SRP.

#### Problem 38: Smart City Traffic Management
```cpp
class TrafficManager {
    void collectTrafficData() { /* collects traffic data */ }
    void analyzeTrafficPattern() { /* analyzes traffic pattern */ }
    void optimizeTrafficFlow() { /* optimizes traffic flow */ }
    void controlTrafficLights() { /* controls traffic lights */ }
    void sendAlert() { /* sends alert */ }
    void generateReport() { /* generates report */ }
    void predictCongestion() { /* predicts congestion */ }
    void updateSignage() { /* updates signage */ }
    void backupData() { /* backups data */ }
    void integrateWithGPS() { /* integrates with GPS */ }
};
```
**Task**: Separate responsibilities.

#### Problem 39: Cybersecurity Monitoring
```cpp
class SecurityMonitor {
    void collectLogs() { /* collects logs */ }
    void analyzeThreats() { /* analyzes threats */ }
    void detectAnomaly() { /* detects anomaly */ }
    void blockThreat() { /* blocks threat */ }
    void sendAlert() { /* sends alert */ }
    void generateReport() { /* generates report */ }
    void updateFirewall() { /* updates firewall */ }
    void backupSecurityData() { /* backups security data */ }
    void complyWithStandards() { /* complies with standards */ }
    void trainAI() { /* trains AI */ }
};
```
**Task**: Identify SRP violations and refactor.

#### Problem 40: Autonomous Vehicle System
```cpp
class AutonomousVehicle {
    void collectSensorData() { /* collects sensor data */ }
    void processImage() { /* processes image */ }
    void detectObjects() { /* detects objects */ }
    void planRoute() { /* plans route */ }
    void controlSteering() { /* controls steering */ }
    void controlSpeed() { /* controls speed */ }
    void sendTelemetry() { /* sends telemetry */ }
    void handleEmergency() { /* handles emergency */ }
    void updateMap() { /* updates map */ }
    void complyWithTrafficRules() { /* complies with traffic rules */ }
};
```
**Task**: Refactor this complex system following SRP.

## **Solution Guidelines**

### **Key Principles to Remember:**

1. **Single Responsibility**: Each class should have only one reason to change
2. **Separation of Concerns**: Different responsibilities should be in different classes
3. **High Cohesion**: Related functionality should be grouped together
4. **Low Coupling**: Classes should depend on abstractions, not concretions

### **Common Refactoring Patterns:**

1. **Extract Class**: Move related methods to a new class
2. **Extract Method**: Break down large methods into smaller ones
3. **Move Method**: Move methods to more appropriate classes
4. **Replace Method with Method Object**: For complex methods

### **Solution Approach:**

1. **Identify Responsibilities**: List all the different things the class does
2. **Group Related Functionality**: Group methods that serve the same purpose
3. **Create Separate Classes**: Create new classes for each responsibility
4. **Use Composition**: Use composition to combine different classes
5. **Apply Dependency Injection**: Inject dependencies rather than creating them

### **Example Solution for Problem 1:**

**Before (SRP Violated):**
```cpp
class User {
    // Multiple responsibilities mixed together
};
```

**After (SRP Followed):**
```cpp
class User {
    // Only user data and basic operations
};

class UserValidator {
    // Only validation logic
};

class UserNotifier {
    // Only notification logic
};

class UserRepository {
    // Only data persistence logic
};
```

## **Practice Tips:**

1. **Start Simple**: Begin with basic problems and gradually move to complex ones
2. **Think About Change**: Ask "What could cause this class to change?"
3. **Focus on Cohesion**: Keep related functionality together
4. **Consider Future Requirements**: Design for extensibility
5. **Test Your Design**: Ensure each class has a single, clear purpose

## **Additional Challenges:**

- Try implementing these problems in different programming languages
- Consider how these patterns apply to microservices architecture
- Think about how to handle cross-cutting concerns like logging and security
- Practice with real-world scenarios from your domain

Happy practicing! 🚀
