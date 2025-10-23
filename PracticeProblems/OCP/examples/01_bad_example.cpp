// Example 1: OCP Violation - The "If-Else Chain" Anti-Pattern
// This demonstrates what NOT to do when designing extensible systems

#include <iostream>
#include <string>
using namespace std;

// BAD DESIGN - OCP Violation
class PaymentProcessor {
public:
    void processPayment(string paymentType, double amount) {
        cout << "Processing payment of $" << amount << " using ";
        
        if (paymentType == "credit_card") {
            cout << "Credit Card" << endl;
            // Credit card specific logic
            validateCreditCard();
            chargeCreditCard(amount);
            sendCreditCardReceipt();
            
        } else if (paymentType == "paypal") {
            cout << "PayPal" << endl;
            // PayPal specific logic
            validatePayPal();
            chargePayPal(amount);
            sendPayPalReceipt();
            
        } else if (paymentType == "stripe") {
            cout << "Stripe" << endl;
            // Stripe specific logic
            validateStripe();
            chargeStripe(amount);
            sendStripeReceipt();
            
        } else if (paymentType == "apple_pay") {
            cout << "Apple Pay" << endl;
            // Apple Pay specific logic
            validateApplePay();
            chargeApplePay(amount);
            sendApplePayReceipt();
            
        } else {
            cout << "Unknown payment method!" << endl;
        }
    }

private:
    // Credit Card methods
    void validateCreditCard() {
        cout << "  - Validating credit card..." << endl;
    }
    
    void chargeCreditCard(double amount) {
        cout << "  - Charging credit card: $" << amount << endl;
    }
    
    void sendCreditCardReceipt() {
        cout << "  - Sending credit card receipt..." << endl;
    }
    
    // PayPal methods
    void validatePayPal() {
        cout << "  - Validating PayPal account..." << endl;
    }
    
    void chargePayPal(double amount) {
        cout << "  - Charging PayPal: $" << amount << endl;
    }
    
    void sendPayPalReceipt() {
        cout << "  - Sending PayPal receipt..." << endl;
    }
    
    // Stripe methods
    void validateStripe() {
        cout << "  - Validating Stripe account..." << endl;
    }
    
    void chargeStripe(double amount) {
        cout << "  - Charging Stripe: $" << amount << endl;
    }
    
    void sendStripeReceipt() {
        cout << "  - Sending Stripe receipt..." << endl;
    }
    
    // Apple Pay methods
    void validateApplePay() {
        cout << "  - Validating Apple Pay..." << endl;
    }
    
    void chargeApplePay(double amount) {
        cout << "  - Charging Apple Pay: $" << amount << endl;
    }
    
    void sendApplePayReceipt() {
        cout << "  - Sending Apple Pay receipt..." << endl;
    }
};

int main() {
    cout << "=== OCP VIOLATION EXAMPLE ===" << endl;
    cout << "This demonstrates what NOT to do!" << endl << endl;
    
    PaymentProcessor processor;
    
    // Test different payment methods
    processor.processPayment("credit_card", 100.0);
    cout << endl;
    
    processor.processPayment("paypal", 50.0);
    cout << endl;
    
    processor.processPayment("stripe", 75.0);
    cout << endl;
    
    processor.processPayment("apple_pay", 25.0);
    cout << endl;
    
    cout << "=== PROBLEMS WITH THIS DESIGN ===" << endl;
    cout << "1. Adding Google Pay requires modifying this class" << endl;
    cout << "2. Adding Bitcoin requires modifying this class" << endl;
    cout << "3. Changing credit card logic affects the entire class" << endl;
    cout << "4. Testing is difficult (hard to mock)" << endl;
    cout << "5. Violates Open/Closed Principle!" << endl;
    
    return 0;
}
