// Example 2: OCP Compliant Design - Using Polymorphism
// This demonstrates the CORRECT way to design extensible systems

#include <iostream>
#include <string>
using namespace std;

// GOOD DESIGN - OCP Compliant
// Abstract interface for payment methods
class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual bool validate() = 0;
    virtual bool process(double amount) = 0;
    virtual string getMethodName() = 0;
    virtual void sendReceipt() = 0;
};

// Concrete implementation for Credit Card
class CreditCardPayment : public PaymentMethod {
private:
    string cardNumber;
    string expiryDate;
    
public:
    CreditCardPayment(string card, string expiry) 
        : cardNumber(card), expiryDate(expiry) {}
    
    bool validate() override {
        cout << "  - Validating credit card..." << endl;
        return cardNumber.length() == 16; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Charging credit card: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "Credit Card";
    }
    
    void sendReceipt() override {
        cout << "  - Sending credit card receipt..." << endl;
    }
};

// Concrete implementation for PayPal
class PayPalPayment : public PaymentMethod {
private:
    string email;
    
public:
    PayPalPayment(string email) : email(email) {}
    
    bool validate() override {
        cout << "  - Validating PayPal account..." << endl;
        return email.find("@") != string::npos; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Charging PayPal: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "PayPal";
    }
    
    void sendReceipt() override {
        cout << "  - Sending PayPal receipt..." << endl;
    }
};

// Concrete implementation for Stripe
class StripePayment : public PaymentMethod {
private:
    string apiKey;
    
public:
    StripePayment(string key) : apiKey(key) {}
    
    bool validate() override {
        cout << "  - Validating Stripe account..." << endl;
        return apiKey.length() > 0; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Charging Stripe: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "Stripe";
    }
    
    void sendReceipt() override {
        cout << "  - Sending Stripe receipt..." << endl;
    }
};

// Concrete implementation for Apple Pay
class ApplePayPayment : public PaymentMethod {
private:
    string deviceId;
    
public:
    ApplePayPayment(string device) : deviceId(device) {}
    
    bool validate() override {
        cout << "  - Validating Apple Pay..." << endl;
        return deviceId.length() > 0; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Charging Apple Pay: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "Apple Pay";
    }
    
    void sendReceipt() override {
        cout << "  - Sending Apple Pay receipt..." << endl;
    }
};

// NEW: Google Pay (added without modifying existing code!)
class GooglePayPayment : public PaymentMethod {
private:
    string googleAccount;
    
public:
    GooglePayPayment(string account) : googleAccount(account) {}
    
    bool validate() override {
        cout << "  - Validating Google Pay..." << endl;
        return googleAccount.length() > 0; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Charging Google Pay: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "Google Pay";
    }
    
    void sendReceipt() override {
        cout << "  - Sending Google Pay receipt..." << endl;
    }
};

// NEW: Bitcoin Payment (added without modifying existing code!)
class BitcoinPayment : public PaymentMethod {
private:
    string walletAddress;
    
public:
    BitcoinPayment(string wallet) : walletAddress(wallet) {}
    
    bool validate() override {
        cout << "  - Validating Bitcoin wallet..." << endl;
        return walletAddress.length() > 20; // Simple validation
    }
    
    bool process(double amount) override {
        cout << "  - Processing Bitcoin transaction: $" << amount << endl;
        return true; // Simplified
    }
    
    string getMethodName() override {
        return "Bitcoin";
    }
    
    void sendReceipt() override {
        cout << "  - Sending Bitcoin receipt..." << endl;
    }
};

// Payment Processor - STABLE, never needs to change!
class PaymentProcessor {
public:
    void processPayment(PaymentMethod* method, double amount) {
        cout << "Processing payment of $" << amount << " using " 
             << method->getMethodName() << endl;
        
        if (method->validate()) {
            if (method->process(amount)) {
                method->sendReceipt();
                cout << "  - Payment successful!" << endl;
            } else {
                cout << "  - Payment failed!" << endl;
            }
        } else {
            cout << "  - Validation failed!" << endl;
        }
    }
};

int main() {
    cout << "=== OCP COMPLIANT DESIGN ===" << endl;
    cout << "This demonstrates the CORRECT way to design!" << endl << endl;
    
    PaymentProcessor processor;
    
    // Test existing payment methods
    CreditCardPayment creditCard("1234567890123456", "12/25");
    processor.processPayment(&creditCard, 100.0);
    cout << endl;
    
    PayPalPayment paypal("user@example.com");
    processor.processPayment(&paypal, 50.0);
    cout << endl;
    
    StripePayment stripe("sk_test_123456789");
    processor.processPayment(&stripe, 75.0);
    cout << endl;
    
    ApplePayPayment applePay("iPhone_12345");
    processor.processPayment(&applePay, 25.0);
    cout << endl;
    
    // NEW: Test new payment methods (added without modifying existing code!)
    GooglePayPayment googlePay("user@gmail.com");
    processor.processPayment(&googlePay, 30.0);
    cout << endl;
    
    BitcoinPayment bitcoin("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");
    processor.processPayment(&bitcoin, 0.001);
    cout << endl;
    
    cout << "=== BENEFITS OF THIS DESIGN ===" << endl;
    cout << "1. Adding Google Pay: Created new class, no modifications!" << endl;
    cout << "2. Adding Bitcoin: Created new class, no modifications!" << endl;
    cout << "3. Changing credit card logic: Only affects CreditCardPayment!" << endl;
    cout << "4. Testing is easy: Mock PaymentMethod interface!" << endl;
    cout << "5. Follows Open/Closed Principle perfectly!" << endl;
    cout << "6. PaymentProcessor never needs to change!" << endl;
    
    return 0;
}
