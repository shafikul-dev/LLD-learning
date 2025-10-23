// Example 5: Plugin Architecture - OCP Compliant Extensible System
// This demonstrates how to build a plugin-based system that's open for extension

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

// Abstract Plugin interface
class Plugin {
public:
    virtual ~Plugin() = default;
    virtual string getName() = 0;
    virtual string getVersion() = 0;
    virtual bool initialize() = 0;
    virtual void execute() = 0;
    virtual void cleanup() = 0;
};

// Abstract Plugin Manager
class PluginManager {
private:
    map<string, Plugin*> plugins;
    
public:
    void registerPlugin(Plugin* plugin) {
        string name = plugin->getName();
        plugins[name] = plugin;
        cout << "✅ Registered plugin: " << name << " v" << plugin->getVersion() << endl;
    }
    
    void unregisterPlugin(const string& name) {
        if (plugins.find(name) != plugins.end()) {
            plugins[name]->cleanup();
            delete plugins[name];
            plugins.erase(name);
            cout << "✅ Unregistered plugin: " << name << endl;
        }
    }
    
    void initializeAll() {
        cout << "=== Initializing All Plugins ===" << endl;
        for (auto& pair : plugins) {
            if (pair.second->initialize()) {
                cout << "✅ " << pair.first << " initialized successfully" << endl;
            } else {
                cout << "❌ " << pair.first << " initialization failed" << endl;
            }
        }
        cout << endl;
    }
    
    void executeAll() {
        cout << "=== Executing All Plugins ===" << endl;
        for (auto& pair : plugins) {
            cout << "Executing " << pair.first << "..." << endl;
            pair.second->execute();
        }
        cout << endl;
    }
    
    void cleanupAll() {
        cout << "=== Cleaning Up All Plugins ===" << endl;
        for (auto& pair : plugins) {
            pair.second->cleanup();
        }
        cout << endl;
    }
    
    Plugin* getPlugin(const string& name) {
        if (plugins.find(name) != plugins.end()) {
            return plugins[name];
        }
        return nullptr;
    }
    
    vector<string> getPluginNames() {
        vector<string> names;
        for (auto& pair : plugins) {
            names.push_back(pair.first);
        }
        return names;
    }
};

// Concrete Plugin: File Logger
class FileLoggerPlugin : public Plugin {
private:
    string logFile;
    
public:
    FileLoggerPlugin(string filename) : logFile(filename) {}
    
    string getName() override {
        return "FileLogger";
    }
    
    string getVersion() override {
        return "1.0.0";
    }
    
    bool initialize() override {
        cout << "  - Initializing file logger to: " << logFile << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Logging to file: " << logFile << endl;
        cout << "  - File log entry: Application started" << endl;
    }
    
    void cleanup() override {
        cout << "  - Closing file logger: " << logFile << endl;
    }
};

// Concrete Plugin: Database Logger
class DatabaseLoggerPlugin : public Plugin {
private:
    string connectionString;
    
public:
    DatabaseLoggerPlugin(string connStr) : connectionString(connStr) {}
    
    string getName() override {
        return "DatabaseLogger";
    }
    
    string getVersion() override {
        return "2.1.0";
    }
    
    bool initialize() override {
        cout << "  - Connecting to database: " << connectionString << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Logging to database: " << connectionString << endl;
        cout << "  - Database log entry: Application started" << endl;
    }
    
    void cleanup() override {
        cout << "  - Disconnecting from database: " << connectionString << endl;
    }
};

// Concrete Plugin: Email Notifier
class EmailNotifierPlugin : public Plugin {
private:
    string emailAddress;
    
public:
    EmailNotifierPlugin(string email) : emailAddress(email) {}
    
    string getName() override {
        return "EmailNotifier";
    }
    
    string getVersion() override {
        return "1.5.0";
    }
    
    bool initialize() override {
        cout << "  - Setting up email notifier for: " << emailAddress << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Sending email notification to: " << emailAddress << endl;
        cout << "  - Email subject: Application Status Update" << endl;
    }
    
    void cleanup() override {
        cout << "  - Closing email notifier for: " << emailAddress << endl;
    }
};

// NEW: Cloud Logger Plugin (added without modifying existing code!)
class CloudLoggerPlugin : public Plugin {
private:
    string cloudEndpoint;
    
public:
    CloudLoggerPlugin(string endpoint) : cloudEndpoint(endpoint) {}
    
    string getName() override {
        return "CloudLogger";
    }
    
    string getVersion() override {
        return "3.0.0";
    }
    
    bool initialize() override {
        cout << "  - Connecting to cloud service: " << cloudEndpoint << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Logging to cloud: " << cloudEndpoint << endl;
        cout << "  - Cloud log entry: Application started" << endl;
    }
    
    void cleanup() override {
        cout << "  - Disconnecting from cloud: " << cloudEndpoint << endl;
    }
};

// NEW: Slack Notifier Plugin (added without modifying existing code!)
class SlackNotifierPlugin : public Plugin {
private:
    string webhookUrl;
    
public:
    SlackNotifierPlugin(string webhook) : webhookUrl(webhook) {}
    
    string getName() override {
        return "SlackNotifier";
    }
    
    string getVersion() override {
        return "2.0.0";
    }
    
    bool initialize() override {
        cout << "  - Setting up Slack webhook: " << webhookUrl << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Sending Slack notification to: " << webhookUrl << endl;
        cout << "  - Slack message: Application Status Update" << endl;
    }
    
    void cleanup() override {
        cout << "  - Closing Slack notifier: " << webhookUrl << endl;
    }
};

// NEW: Metrics Collector Plugin (added without modifying existing code!)
class MetricsCollectorPlugin : public Plugin {
private:
    string metricsEndpoint;
    
public:
    MetricsCollectorPlugin(string endpoint) : metricsEndpoint(endpoint) {}
    
    string getName() override {
        return "MetricsCollector";
    }
    
    string getVersion() override {
        return "1.2.0";
    }
    
    bool initialize() override {
        cout << "  - Setting up metrics collection: " << metricsEndpoint << endl;
        return true;
    }
    
    void execute() override {
        cout << "  - Collecting metrics: " << metricsEndpoint << endl;
        cout << "  - Metrics: CPU usage, memory usage, response time" << endl;
    }
    
    void cleanup() override {
        cout << "  - Stopping metrics collection: " << metricsEndpoint << endl;
    }
};

int main() {
    cout << "=== PLUGIN ARCHITECTURE EXAMPLE ===" << endl;
    cout << "Demonstrating OCP-compliant extensible system" << endl << endl;
    
    PluginManager manager;
    
    // Register existing plugins
    manager.registerPlugin(new FileLoggerPlugin("app.log"));
    manager.registerPlugin(new DatabaseLoggerPlugin("mysql://localhost:3306/app"));
    manager.registerPlugin(new EmailNotifierPlugin("admin@example.com"));
    
    // Register NEW plugins (added without modifying existing code!)
    manager.registerPlugin(new CloudLoggerPlugin("https://logs.example.com/api"));
    manager.registerPlugin(new SlackNotifierPlugin("https://hooks.slack.com/services/..."));
    manager.registerPlugin(new MetricsCollectorPlugin("https://metrics.example.com/api"));
    
    cout << endl;
    
    // Initialize all plugins
    manager.initializeAll();
    
    // Execute all plugins
    manager.executeAll();
    
    // Clean up all plugins
    manager.cleanupAll();
    
    cout << "=== BENEFITS OF PLUGIN ARCHITECTURE ===" << endl;
    cout << "1. Adding Cloud Logger: Created new class, no modifications!" << endl;
    cout << "2. Adding Slack Notifier: Created new class, no modifications!" << endl;
    cout << "3. Adding Metrics Collector: Created new class, no modifications!" << endl;
    cout << "4. PluginManager never needs to change!" << endl;
    cout << "5. Plugins can be loaded/unloaded at runtime!" << endl;
    cout << "6. Each plugin can be developed independently!" << endl;
    cout << "7. Easy to add new functionality without breaking existing code!" << endl;
    cout << "8. Follows Open/Closed Principle perfectly!" << endl;
    
    return 0;
}
