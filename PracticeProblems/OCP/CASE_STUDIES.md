# OCP Case Studies - Real-World Examples

## 🏢 Case Study 1: E-commerce Payment System

### The Problem
An e-commerce platform needs to support multiple payment methods: Credit Card, PayPal, Stripe, Apple Pay, Google Pay, and future payment methods.

### ❌ Bad Design (OCP Violation)
```cpp
class PaymentProcessor {
    void processPayment(string method, double amount) {
        if (method == "credit_card") {
            // Credit card processing logic
            validateCreditCard();
            chargeCreditCard(amount);
        } else if (method == "paypal") {
            // PayPal processing logic
            validatePayPal();
            chargePayPal(amount);
        } else if (method == "stripe") {
            // Stripe processing logic
            validateStripe();
            chargeStripe(amount);
        }
        // Adding new payment method requires modifying this class!
    }
};
```

**Problems:**
- Adding Apple Pay requires modifying existing code
- Testing is difficult (hard to mock)
- Violates OCP (closed for extension, open for modification)

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class PaymentMethod {
public:
    virtual bool validate() = 0;
    virtual bool process(double amount) = 0;
    virtual string getMethodName() = 0;
};

// Concrete implementations
class CreditCardPayment : public PaymentMethod {
    bool validate() override { /* credit card validation */ }
    bool process(double amount) override { /* credit card processing */ }
    string getMethodName() override { return "Credit Card"; }
};

class PayPalPayment : public PaymentMethod {
    bool validate() override { /* PayPal validation */ }
    bool process(double amount) override { /* PayPal processing */ }
    string getMethodName() override { return "PayPal"; }
};

class StripePayment : public PaymentMethod {
    bool validate() override { /* Stripe validation */ }
    bool process(double amount) override { /* Stripe processing */ }
    string getMethodName() override { return "Stripe"; }
};

// Payment processor (stable, doesn't change)
class PaymentProcessor {
    PaymentMethod* paymentMethod;
public:
    PaymentProcessor(PaymentMethod* method) : paymentMethod(method) {}
    
    bool processPayment(double amount) {
        if (paymentMethod->validate()) {
            return paymentMethod->process(amount);
        }
        return false;
    }
};
```

**Benefits:**
- Adding Apple Pay: Create new `ApplePayPayment` class
- No modification to existing code
- Easy to test (mock PaymentMethod)
- Follows OCP perfectly

## 🏢 Case Study 2: Notification System

### The Problem
A system needs to send notifications via Email, SMS, Push notifications, Slack, Discord, and future channels.

### ❌ Bad Design (OCP Violation)
```cpp
class NotificationService {
    void sendNotification(string channel, string message) {
        if (channel == "email") {
            // Email sending logic
            sendEmail(message);
        } else if (channel == "sms") {
            // SMS sending logic
            sendSMS(message);
        } else if (channel == "push") {
            // Push notification logic
            sendPushNotification(message);
        }
        // Adding Slack requires modifying this class!
    }
};
```

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class NotificationChannel {
public:
    virtual bool send(string message) = 0;
    virtual bool isAvailable() = 0;
    virtual string getChannelName() = 0;
};

// Concrete implementations
class EmailChannel : public NotificationChannel {
    bool send(string message) override { /* email logic */ }
    bool isAvailable() override { /* check email service */ }
    string getChannelName() override { return "Email"; }
};

class SMSChannel : public NotificationChannel {
    bool send(string message) override { /* SMS logic */ }
    bool isAvailable() override { /* check SMS service */ }
    string getChannelName() override { return "SMS"; }
};

class SlackChannel : public NotificationChannel {
    bool send(string message) override { /* Slack logic */ }
    bool isAvailable() override { /* check Slack API */ }
    string getChannelName() override { return "Slack"; }
};

// Notification service (stable)
class NotificationService {
    vector<NotificationChannel*> channels;
public:
    void addChannel(NotificationChannel* channel) {
        channels.push_back(channel);
    }
    
    void sendNotification(string message) {
        for (auto channel : channels) {
            if (channel->isAvailable()) {
                channel->send(message);
            }
        }
    }
};
```

**Benefits:**
- Adding Discord: Create new `DiscordChannel` class
- No modification to existing code
- Can send to multiple channels simultaneously
- Easy to test and mock

## 🏢 Case Study 3: Report Generation System

### The Problem
A business system needs to generate reports in PDF, Excel, HTML, CSV, and future formats.

### ❌ Bad Design (OCP Violation)
```cpp
class ReportGenerator {
    void generateReport(string format, Data data) {
        if (format == "pdf") {
            // PDF generation logic
            generatePDF(data);
        } else if (format == "excel") {
            // Excel generation logic
            generateExcel(data);
        } else if (format == "html") {
            // HTML generation logic
            generateHTML(data);
        }
        // Adding CSV requires modifying this class!
    }
};
```

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class ReportFormat {
public:
    virtual bool generate(Data data) = 0;
    virtual string getFileExtension() = 0;
    virtual string getMimeType() = 0;
};

// Concrete implementations
class PDFReportFormat : public ReportFormat {
    bool generate(Data data) override { /* PDF generation */ }
    string getFileExtension() override { return ".pdf"; }
    string getMimeType() override { return "application/pdf"; }
};

class ExcelReportFormat : public ReportFormat {
    bool generate(Data data) override { /* Excel generation */ }
    string getFileExtension() override { return ".xlsx"; }
    string getMimeType() override { return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"; }
};

class CSVReportFormat : public ReportFormat {
    bool generate(Data data) override { /* CSV generation */ }
    string getFileExtension() override { return ".csv"; }
    string getMimeType() override { return "text/csv"; }
};

// Report generator (stable)
class ReportGenerator {
    ReportFormat* format;
public:
    ReportGenerator(ReportFormat* format) : format(format) {}
    
    bool generateReport(Data data) {
        return format->generate(data);
    }
};
```

**Benefits:**
- Adding new formats: Create new format classes
- No modification to existing code
- Easy to add format-specific features
- Can generate multiple formats simultaneously

## 🏢 Case Study 4: Logging System

### The Problem
An application needs to log to File, Database, Cloud storage, and future destinations.

### ❌ Bad Design (OCP Violation)
```cpp
class Logger {
    void log(string level, string message) {
        if (destination == "file") {
            // File logging logic
            writeToFile(level, message);
        } else if (destination == "database") {
            // Database logging logic
            writeToDatabase(level, message);
        } else if (destination == "cloud") {
            // Cloud logging logic
            writeToCloud(level, message);
        }
        // Adding new destination requires modifying this class!
    }
};
```

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class LogDestination {
public:
    virtual bool log(string level, string message) = 0;
    virtual bool isAvailable() = 0;
    virtual string getDestinationName() = 0;
};

// Concrete implementations
class FileLogDestination : public LogDestination {
    bool log(string level, string message) override { /* file logging */ }
    bool isAvailable() override { /* check file system */ }
    string getDestinationName() override { return "File"; }
};

class DatabaseLogDestination : public LogDestination {
    bool log(string level, string message) override { /* database logging */ }
    bool isAvailable() override { /* check database connection */ }
    string getDestinationName() override { return "Database"; }
};

class CloudLogDestination : public LogDestination {
    bool log(string level, string message) override { /* cloud logging */ }
    bool isAvailable() override { /* check cloud service */ }
    string getDestinationName() override { return "Cloud"; }
};

// Logger (stable)
class Logger {
    vector<LogDestination*> destinations;
public:
    void addDestination(LogDestination* destination) {
        destinations.push_back(destination);
    }
    
    void log(string level, string message) {
        for (auto destination : destinations) {
            if (destination->isAvailable()) {
                destination->log(level, message);
            }
        }
    }
};
```

**Benefits:**
- Adding new destinations: Create new destination classes
- No modification to existing code
- Can log to multiple destinations
- Easy to configure and test

## 🏢 Case Study 5: Authentication System

### The Problem
A system needs to support OAuth, JWT, SAML, LDAP, and future authentication methods.

### ❌ Bad Design (OCP Violation)
```cpp
class AuthenticationService {
    bool authenticate(string method, string credentials) {
        if (method == "oauth") {
            // OAuth authentication logic
            return authenticateOAuth(credentials);
        } else if (method == "jwt") {
            // JWT authentication logic
            return authenticateJWT(credentials);
        } else if (method == "saml") {
            // SAML authentication logic
            return authenticateSAML(credentials);
        }
        // Adding LDAP requires modifying this class!
    }
};
```

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class AuthenticationMethod {
public:
    virtual bool authenticate(string credentials) = 0;
    virtual bool isAvailable() = 0;
    virtual string getMethodName() = 0;
};

// Concrete implementations
class OAuthAuthentication : public AuthenticationMethod {
    bool authenticate(string credentials) override { /* OAuth logic */ }
    bool isAvailable() override { /* check OAuth service */ }
    string getMethodName() override { return "OAuth"; }
};

class JWTAuthentication : public AuthenticationMethod {
    bool authenticate(string credentials) override { /* JWT logic */ }
    bool isAvailable() override { /* check JWT service */ }
    string getMethodName() override { return "JWT"; }
};

class LDAPAuthentication : public AuthenticationMethod {
    bool authenticate(string credentials) override { /* LDAP logic */ }
    bool isAvailable() override { /* check LDAP server */ }
    string getMethodName() override { return "LDAP"; }
};

// Authentication service (stable)
class AuthenticationService {
    vector<AuthenticationMethod*> methods;
public:
    void addMethod(AuthenticationMethod* method) {
        methods.push_back(method);
    }
    
    bool authenticate(string credentials) {
        for (auto method : methods) {
            if (method->isAvailable()) {
                if (method->authenticate(credentials)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

**Benefits:**
- Adding new authentication methods: Create new method classes
- No modification to existing code
- Can try multiple authentication methods
- Easy to configure and test

## 🏢 Case Study 6: Data Storage System

### The Problem
An application needs to store data in Local files, Database, Cloud storage, and future storage systems.

### ❌ Bad Design (OCP Violation)
```cpp
class DataStorage {
    void storeData(string type, Data data) {
        if (type == "file") {
            // File storage logic
            storeToFile(data);
        } else if (type == "database") {
            // Database storage logic
            storeToDatabase(data);
        } else if (type == "cloud") {
            // Cloud storage logic
            storeToCloud(data);
        }
        // Adding new storage type requires modifying this class!
    }
};
```

### ✅ Good Design (OCP Compliant)
```cpp
// Abstract interface
class StorageProvider {
public:
    virtual bool store(Data data) = 0;
    virtual Data retrieve(string id) = 0;
    virtual bool delete(string id) = 0;
    virtual bool isAvailable() = 0;
    virtual string getProviderName() = 0;
};

// Concrete implementations
class FileStorageProvider : public StorageProvider {
    bool store(Data data) override { /* file storage */ }
    Data retrieve(string id) override { /* file retrieval */ }
    bool delete(string id) override { /* file deletion */ }
    bool isAvailable() override { /* check file system */ }
    string getProviderName() override { return "File"; }
};

class DatabaseStorageProvider : public StorageProvider {
    bool store(Data data) override { /* database storage */ }
    Data retrieve(string id) override { /* database retrieval */ }
    bool delete(string id) override { /* database deletion */ }
    bool isAvailable() override { /* check database connection */ }
    string getProviderName() override { return "Database"; }
};

class CloudStorageProvider : public StorageProvider {
    bool store(Data data) override { /* cloud storage */ }
    Data retrieve(string id) override { /* cloud retrieval */ }
    bool delete(string id) override { /* cloud deletion */ }
    bool isAvailable() override { /* check cloud service */ }
    string getProviderName() override { return "Cloud"; }
};

// Data storage service (stable)
class DataStorageService {
    vector<StorageProvider*> providers;
public:
    void addProvider(StorageProvider* provider) {
        providers.push_back(provider);
    }
    
    bool storeData(Data data) {
        for (auto provider : providers) {
            if (provider->isAvailable()) {
                if (provider->store(data)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

**Benefits:**
- Adding new storage types: Create new provider classes
- No modification to existing code
- Can use multiple storage providers
- Easy to configure and test

## 🎯 Key Takeaways from Case Studies

### Common Patterns
1. **Identify the variation point** (payment methods, notification channels, etc.)
2. **Create an abstraction** (interface/abstract class)
3. **Implement concrete classes** for each variation
4. **Use dependency injection** to make it configurable
5. **Keep the main service stable** (no modifications needed)

### Benefits of OCP Design
- ✅ **Easy to extend** with new functionality
- ✅ **No modification** of existing code
- ✅ **Better testing** (mock dependencies)
- ✅ **Loose coupling** between components
- ✅ **High cohesion** within components

### Red Flags to Avoid
- ❌ Long if-else or switch statements
- ❌ Hard-coded dependencies
- ❌ Classes that change for multiple reasons
- ❌ Tight coupling between components

## 🎓 Case Study Analysis Framework

When analyzing a system for OCP compliance:

1. **Identify variation points**: What might change?
2. **Check for abstractions**: Are there interfaces for variations?
3. **Look for hard-coded dependencies**: Are they injected?
4. **Test extensibility**: Can you add new features without modification?
5. **Verify stability**: Does the core system remain unchanged?

Remember: **OCP is about designing for change. The best designs anticipate what will change and make it easy to extend!**
