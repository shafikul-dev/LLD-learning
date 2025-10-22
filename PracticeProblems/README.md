# Single Responsibility Principle (SRP) - Practice Problems

This directory contains 40 practice problems to master the Single Responsibility Principle, organized by difficulty level.

## 📂 File Structure

Each problem has its own file: `1_solution.cpp`, `2_solution.cpp`, ..., `40_solution.cpp`

- Problem statement is included as comments at the top of each file
- Original violating code is shown for reference
- Space provided for your solution

## 🎯 Problem Categories

### **Beginner Level (Problems 1-15)**
Focus on identifying basic responsibilities and simple refactoring.

| # | Problem | File |
|---|---------|------|
| 1 | User Management System | `1_solution.cpp` |
| 2 | File Manager | `2_solution.cpp` |
| 3 | Order Processing | `3_solution.cpp` |
| 4 | Bank Account | `4_solution.cpp` |
| 5 | Library Management | `5_solution.cpp` |
| 6 | Email System | `6_solution.cpp` |
| 7 | Student Management | `7_solution.cpp` |
| 8 | Restaurant Order | `8_solution.cpp` |
| 9 | Car Rental | `9_solution.cpp` |
| 10 | Movie Booking | `10_solution.cpp` |
| 11 | Gym Membership | `11_solution.cpp` |
| 12 | Insurance Policy | `12_solution.cpp` |
| 13 | Hotel Booking | `13_solution.cpp` |
| 14 | Course Management | `14_solution.cpp` |
| 15 | Product Catalog | `15_solution.cpp` |

### **Intermediate Level (Problems 16-30)**
More complex systems with multiple interacting responsibilities.

| # | Problem | File |
|---|---------|------|
| 16 | E-commerce Shopping Cart | `16_solution.cpp` |
| 17 | Banking Transaction System | `17_solution.cpp` |
| 18 | Social Media Post | `18_solution.cpp` |
| 19 | Flight Booking System | `19_solution.cpp` |
| 20 | Employee Management | `20_solution.cpp` |
| 21 | Online Learning Platform | `21_solution.cpp` |
| 22 | Inventory Management | `22_solution.cpp` |
| 23 | Event Management | `23_solution.cpp` |
| 24 | Content Management System | `24_solution.cpp` |
| 25 | Subscription Management | `25_solution.cpp` |
| 26 | Document Management | `26_solution.cpp` |
| 27 | Customer Support | `27_solution.cpp` |
| 28 | Project Management | `28_solution.cpp` |
| 29 | Quality Assurance | `29_solution.cpp` |
| 30 | Financial Planning | `30_solution.cpp` |

### **Advanced Level (Problems 31-40)**
Complex real-world systems requiring sophisticated design.

| # | Problem | File |
|---|---------|------|
| 31 | Microservices Architecture | `31_solution.cpp` |
| 32 | IoT Device Management | `32_solution.cpp` |
| 33 | Blockchain Transaction | `33_solution.cpp` |
| 34 | AI Model Training | `34_solution.cpp` |
| 35 | Real-time Chat System | `35_solution.cpp` |
| 36 | E-commerce Recommendation Engine | `36_solution.cpp` |
| 37 | Healthcare Patient Management | `37_solution.cpp` |
| 38 | Smart City Traffic Management | `38_solution.cpp` |
| 39 | Cybersecurity Monitoring | `39_solution.cpp` |
| 40 | Autonomous Vehicle System | `40_solution.cpp` |

## 🚀 How to Use

1. **Start with Problem 1** - Already has a complete solution as a reference
2. **Work through problems sequentially** - Build from simple to complex
3. **Compile and test** your solutions:
   ```bash
   g++ -o solution N_solution.cpp && ./solution
   ```
4. **Track your progress** by checking off completed problems below

## ✅ Progress Tracker

Copy this to track your progress:

```
Beginner:
[ ] Problem 1  [ ] Problem 2  [ ] Problem 3  [ ] Problem 4  [ ] Problem 5
[ ] Problem 6  [ ] Problem 7  [ ] Problem 8  [ ] Problem 9  [ ] Problem 10
[ ] Problem 11 [ ] Problem 12 [ ] Problem 13 [ ] Problem 14 [ ] Problem 15

Intermediate:
[ ] Problem 16 [ ] Problem 17 [ ] Problem 18 [ ] Problem 19 [ ] Problem 20
[ ] Problem 21 [ ] Problem 22 [ ] Problem 23 [ ] Problem 24 [ ] Problem 25
[ ] Problem 26 [ ] Problem 27 [ ] Problem 28 [ ] Problem 29 [ ] Problem 30

Advanced:
[ ] Problem 31 [ ] Problem 32 [ ] Problem 33 [ ] Problem 34 [ ] Problem 35
[ ] Problem 36 [ ] Problem 37 [ ] Problem 38 [ ] Problem 39 [ ] Problem 40
```

## 💡 Key Principles to Remember

1. **Single Responsibility**: Each class should have only one reason to change
2. **Separation of Concerns**: Different responsibilities → different classes
3. **High Cohesion**: Related functionality grouped together
4. **Low Coupling**: Classes depend on abstractions, not concretions

## 📚 Common Class Naming Patterns

| Purpose | Pattern | Example |
|---------|---------|---------|
| Data/Entity | Noun | `User`, `Order`, `Product` |
| Coordinator | Noun + Manager | `UserManager`, `OrderManager` |
| External Operations | Noun + Service | `EmailService`, `PaymentService` |
| Data Access | Noun + Repository | `UserRepository`, `OrderRepository` |
| Validation | Noun + Validator | `EmailValidator`, `PasswordValidator` |
| Creation | Noun + Factory/Builder | `UserFactory`, `ReportBuilder` |

## 🎓 Learning Path

1. **Understand** the problem - Read the original code
2. **Identify** responsibilities - What does each method do?
3. **Group** related functionality - Which methods belong together?
4. **Create** separate classes - One responsibility per class
5. **Test** your design - Compile and run your solution
6. **Reflect** - Does each class have a single reason to change?

## 📖 Additional Resources

- Problem 1 (`1_solution.cpp`) contains a complete reference solution
- Review the naming convention guide in the main solution
- Consider edge cases and real-world scenarios

Happy Learning! 🚀

