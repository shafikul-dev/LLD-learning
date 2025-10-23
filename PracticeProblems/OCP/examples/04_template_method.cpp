// Example 4: Template Method Pattern - OCP Compliant Workflow Design
// This demonstrates how to make workflows extensible using the Template Method pattern

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Template Method class
class DataProcessor {
public:
    virtual ~DataProcessor() = default;
    
    // Template Method - defines the algorithm skeleton
    void processData(const string& input) {
        cout << "=== Starting Data Processing ===" << endl;
        
        // Step 1: Validate input
        if (!validateInput(input)) {
            cout << "❌ Input validation failed!" << endl;
            return;
        }
        cout << "✅ Input validation passed" << endl;
        
        // Step 2: Parse data
        vector<string> parsedData = parseData(input);
        cout << "✅ Data parsed into " << parsedData.size() << " items" << endl;
        
        // Step 3: Transform data (varies by implementation)
        vector<string> transformedData = transformData(parsedData);
        cout << "✅ Data transformed" << endl;
        
        // Step 4: Save data (varies by implementation)
        saveData(transformedData);
        cout << "✅ Data saved" << endl;
        
        // Step 5: Send notification (varies by implementation)
        sendNotification(transformedData);
        cout << "✅ Notification sent" << endl;
        
        cout << "=== Data Processing Complete ===" << endl << endl;
    }

protected:
    // Common methods (same for all implementations)
    bool validateInput(const string& input) {
        return !input.empty() && input.length() > 0;
    }
    
    vector<string> parseData(const string& input) {
        vector<string> result;
        string current = "";
        for (char c : input) {
            if (c == ',') {
                result.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }
        if (!current.empty()) {
            result.push_back(current);
        }
        return result;
    }
    
    // Abstract methods (must be implemented by subclasses)
    virtual vector<string> transformData(const vector<string>& data) = 0;
    virtual void saveData(const vector<string>& data) = 0;
    virtual void sendNotification(const vector<string>& data) = 0;
    
    // Hook methods (optional to override)
    virtual string getProcessorName() {
        return "Generic Data Processor";
    }
};

// Concrete implementation: CSV Data Processor
class CSVDataProcessor : public DataProcessor {
protected:
    vector<string> transformData(const vector<string>& data) override {
        cout << "  - Transforming CSV data..." << endl;
        vector<string> result;
        for (const string& item : data) {
            result.push_back("CSV_" + item);
        }
        return result;
    }
    
    void saveData(const vector<string>& data) override {
        cout << "  - Saving to CSV file..." << endl;
        cout << "  - Saved " << data.size() << " CSV records" << endl;
    }
    
    void sendNotification(const vector<string>& data) override {
        cout << "  - Sending CSV processing notification..." << endl;
        cout << "  - Notified about " << data.size() << " CSV records" << endl;
    }
    
    string getProcessorName() override {
        return "CSV Data Processor";
    }
};

// Concrete implementation: JSON Data Processor
class JSONDataProcessor : public DataProcessor {
protected:
    vector<string> transformData(const vector<string>& data) override {
        cout << "  - Transforming JSON data..." << endl;
        vector<string> result;
        for (const string& item : data) {
            result.push_back("JSON_" + item);
        }
        return result;
    }
    
    void saveData(const vector<string>& data) override {
        cout << "  - Saving to JSON file..." << endl;
        cout << "  - Saved " << data.size() << " JSON records" << endl;
    }
    
    void sendNotification(const vector<string>& data) override {
        cout << "  - Sending JSON processing notification..." << endl;
        cout << "  - Notified about " << data.size() << " JSON records" << endl;
    }
    
    string getProcessorName() override {
        return "JSON Data Processor";
    }
};

// Concrete implementation: XML Data Processor
class XMLDataProcessor : public DataProcessor {
protected:
    vector<string> transformData(const vector<string>& data) override {
        cout << "  - Transforming XML data..." << endl;
        vector<string> result;
        for (const string& item : data) {
            result.push_back("XML_" + item);
        }
        return result;
    }
    
    void saveData(const vector<string>& data) override {
        cout << "  - Saving to XML file..." << endl;
        cout << "  - Saved " << data.size() << " XML records" << endl;
    }
    
    void sendNotification(const vector<string>& data) override {
        cout << "  - Sending XML processing notification..." << endl;
        cout << "  - Notified about " << data.size() << " XML records" << endl;
    }
    
    string getProcessorName() override {
        return "XML Data Processor";
    }
};

// NEW: Database Data Processor (added without modifying existing code!)
class DatabaseDataProcessor : public DataProcessor {
protected:
    vector<string> transformData(const vector<string>& data) override {
        cout << "  - Transforming database data..." << endl;
        vector<string> result;
        for (const string& item : data) {
            result.push_back("DB_" + item);
        }
        return result;
    }
    
    void saveData(const vector<string>& data) override {
        cout << "  - Saving to database..." << endl;
        cout << "  - Saved " << data.size() << " database records" << endl;
    }
    
    void sendNotification(const vector<string>& data) override {
        cout << "  - Sending database processing notification..." << endl;
        cout << "  - Notified about " << data.size() << " database records" << endl;
    }
    
    string getProcessorName() override {
        return "Database Data Processor";
    }
};

// NEW: Cloud Data Processor (added without modifying existing code!)
class CloudDataProcessor : public DataProcessor {
protected:
    vector<string> transformData(const vector<string>& data) override {
        cout << "  - Transforming cloud data..." << endl;
        vector<string> result;
        for (const string& item : data) {
            result.push_back("CLOUD_" + item);
        }
        return result;
    }
    
    void saveData(const vector<string>& data) override {
        cout << "  - Saving to cloud storage..." << endl;
        cout << "  - Saved " << data.size() << " cloud records" << endl;
    }
    
    void sendNotification(const vector<string>& data) override {
        cout << "  - Sending cloud processing notification..." << endl;
        cout << "  - Notified about " << data.size() << " cloud records" << endl;
    }
    
    string getProcessorName() override {
        return "Cloud Data Processor";
    }
};

int main() {
    cout << "=== TEMPLATE METHOD PATTERN EXAMPLE ===" << endl;
    cout << "Demonstrating OCP-compliant workflow design" << endl << endl;
    
    string testData = "apple,banana,cherry,date,elderberry";
    
    // Test different data processors
    CSVDataProcessor csvProcessor;
    JSONDataProcessor jsonProcessor;
    XMLDataProcessor xmlProcessor;
    DatabaseDataProcessor dbProcessor;
    CloudDataProcessor cloudProcessor;
    
    // Process data with different processors
    csvProcessor.processData(testData);
    jsonProcessor.processData(testData);
    xmlProcessor.processData(testData);
    dbProcessor.processData(testData);
    cloudProcessor.processData(testData);
    
    cout << "=== BENEFITS OF TEMPLATE METHOD PATTERN ===" << endl;
    cout << "1. Adding Database Processor: Created new class, no modifications!" << endl;
    cout << "2. Adding Cloud Processor: Created new class, no modifications!" << endl;
    cout << "3. DataProcessor base class never needs to change!" << endl;
    cout << "4. Common workflow steps are shared and consistent!" << endl;
    cout << "5. Each processor can customize specific steps!" << endl;
    cout << "6. Easy to add new data processing types!" << endl;
    cout << "7. Follows Open/Closed Principle perfectly!" << endl;
    
    return 0;
}
