# OCP Self-Assessment Framework

## 🎯 How to Verify Your OCP Understanding

Use this checklist to verify that you truly understand the Open/Closed Principle.

## ✅ Core OCP Questions

### 1. Extension vs Modification
- [ ] **Can you add new behavior without modifying existing code?**
  - If YES → Good OCP design
  - If NO → OCP violation

### 2. Abstraction Design
- [ ] **Are your abstractions stable and concrete implementations variable?**
  - Stable abstractions = Interfaces that don't change often
  - Variable implementations = Classes that can be added/modified

### 3. Mental Model
- [ ] **Do you think "new class" instead of "modify existing class"?**
  - Adding functionality = Create new class
  - Changing behavior = Modify existing class (but only if necessary)

### 4. Prediction Skills
- [ ] **Can you predict where requirements will change?**
  - Identify variation points early
  - Design abstractions for those points

## 🔍 Code Review Checklist

### Red Flags (OCP Violations)
- [ ] **Long if-else or switch statements**
  ```cpp
  if (type == "A") { /* logic A */ }
  else if (type == "B") { /* logic B */ }
  else if (type == "C") { /* logic C */ }
  ```

- [ ] **Hard-coded dependencies**
  ```cpp
  class Service {
      void doSomething() {
          Database db;  // Hard-coded!
          db.save();
      }
  };
  ```

- [ ] **Classes that change for multiple reasons**
  - Payment class handling validation, processing, and notification
  - User class handling authentication, authorization, and profile management

- [ ] **"What if we need to add..." questions that require code changes**
  - "What if we need to add PayPal?" → Requires modifying existing code
  - "What if we need to add email notifications?" → Requires modifying existing code

### Green Flags (OCP Compliant)
- [ ] **New functionality added via new classes**
  ```cpp
  class NewPaymentMethod : public PaymentMethod {
      // New implementation
  };
  ```

- [ ] **Stable abstractions with variable implementations**
  ```cpp
  class PaymentProcessor {
      PaymentMethod* method;  // Stable abstraction
  };
  ```

- [ ] **Dependency injection**
  ```cpp
  class Service {
      Database* db;  // Injected dependency
  public:
      Service(Database* database) : db(database) {}
  };
  ```

- [ ] **Polymorphic behavior**
  ```cpp
  method->process();  // No if-else needed!
  ```

## 🧠 Mental Model Verification

### The "What Will Change?" Test
Ask yourself:
1. **What aspects of this system are most likely to change?**
2. **Have I designed abstractions for those variation points?**
3. **Can I add new functionality without modifying existing code?**

### The "New Class" Test
When adding new functionality:
1. **Can I create a new class that implements an existing interface?**
2. **Or do I need to modify existing classes?**

### The "Stability" Test
1. **Does the core system remain unchanged when adding new features?**
2. **Are the interfaces stable (don't change often)?**
3. **Are the implementations variable (can be added/modified)?**

## 🎯 Design Pattern Recognition

### Can you identify when to use these OCP-supporting patterns?

- [ ] **Strategy Pattern**
  - Multiple algorithms for the same task
  - Example: Payment methods, sorting algorithms

- [ ] **Template Method Pattern**
  - Common workflow with variable steps
  - Example: Data processing pipelines

- [ ] **Factory Pattern**
  - Creating objects of different types
  - Example: UI components, database connections

- [ ] **Observer Pattern**
  - One-to-many dependencies
  - Example: Event systems, notifications

- [ ] **Decorator Pattern**
  - Adding behavior dynamically
  - Example: Middleware chains, feature toggles

## 🚀 Real-World Application Test

### Scenario 1: E-commerce Payment System
**Question**: "We need to add Apple Pay support."
- [ ] Can you add it without modifying existing code?
- [ ] Do you create a new `ApplePayPayment` class?
- [ ] Does it implement an existing `PaymentMethod` interface?

### Scenario 2: Notification System
**Question**: "We need to add Slack notifications."
- [ ] Can you add it without modifying existing code?
- [ ] Do you create a new `SlackNotifier` class?
- [ ] Does it implement an existing `NotificationChannel` interface?

### Scenario 3: Report Generator
**Question**: "We need to add PDF report generation."
- [ ] Can you add it without modifying existing code?
- [ ] Do you create a new `PDFReportFormat` class?
- [ ] Does it implement an existing `ReportFormat` interface?

## 🎓 Mastery Level Assessment

### Beginner Level
- [ ] Can identify basic OCP violations (if-else chains)
- [ ] Can create simple abstractions (interfaces)
- [ ] Can implement basic polymorphism
- [ ] Can refactor simple violating code

### Intermediate Level
- [ ] Can design complex systems with multiple variation points
- [ ] Can choose appropriate design patterns
- [ ] Can handle dependency injection
- [ ] Can refactor complex violating code

### Advanced Level
- [ ] Can design enterprise-level extensible systems
- [ ] Can predict future requirements and design accordingly
- [ ] Can create plugin architectures
- [ ] Can mentor others on OCP principles

## 🔧 Practical Exercises

### Exercise 1: Identify Violations
Look at this code and identify OCP violations:
```cpp
class OrderProcessor {
    void processOrder(string type, Order order) {
        if (type == "online") {
            // Online processing
        } else if (type == "phone") {
            // Phone processing
        } else if (type == "store") {
            // Store processing
        }
    }
};
```

**Questions:**
1. What OCP violations do you see?
2. How would you refactor this?
3. What abstraction would you create?

### Exercise 2: Design for Extension
Design a system that can handle:
- Multiple payment methods (Credit Card, PayPal, Stripe)
- Multiple notification channels (Email, SMS, Push)
- Multiple storage backends (Database, File, Cloud)

**Questions:**
1. What abstractions would you create?
2. How would you make it extensible?
3. What design patterns would you use?

## 🎯 Success Criteria

You've mastered OCP when you can:

- [ ] **Automatically think "What will change?" when designing**
- [ ] **See if-else chains as red flags**
- [ ] **Design interfaces before implementations**
- [ ] **Prefer composition over inheritance**
- [ ] **Think "new class" instead of "modify class"**
- [ ] **Can explain why OCP matters in real scenarios**
- [ ] **Can refactor violating code to follow OCP**
- [ ] **Can predict where systems will need to extend**
- [ ] **Can choose appropriate design patterns for extensibility**
- [ ] **Can design plugin architectures**

## 🚨 Common Mistakes to Avoid

### Mistake 1: Over-Abstraction
- Creating interfaces for everything
- Making simple systems overly complex
- **Solution**: Only abstract where you expect variation

### Mistake 2: Under-Abstraction
- Not identifying variation points
- Hard-coding dependencies
- **Solution**: Think about what might change

### Mistake 3: Interface Pollution
- Adding methods to interfaces that not all implementations need
- **Solution**: Follow Interface Segregation Principle

### Mistake 4: Premature Optimization
- Designing for changes that may never happen
- **Solution**: Design for likely changes, not all possible changes

## 🎓 Final Assessment

### Can you answer these questions confidently?

1. **What is the Open/Closed Principle?**
2. **Why does OCP matter in real-world development?**
3. **How do you identify OCP violations in existing code?**
4. **What design patterns support OCP?**
5. **How do you design new systems with OCP in mind?**
6. **What's the difference between "open for extension" and "closed for modification"?**
7. **How do you balance OCP with other design principles?**
8. **When is it okay to violate OCP?**
9. **How do you refactor violating code to follow OCP?**
10. **How do you test OCP-compliant code?**

If you can answer all these questions confidently, you've mastered the Open/Closed Principle! 🎉

Remember: **OCP is about designing for change. The best designs anticipate what will change and make it easy to extend!**
