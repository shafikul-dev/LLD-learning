// Example 3: Strategy Pattern - OCP Compliant Algorithm Selection
// This demonstrates how to make algorithms extensible using the Strategy pattern

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Strategy interface
class SortingStrategy {
public:
    virtual ~SortingStrategy() = default;
    virtual void sort(vector<int>& data) = 0;
    virtual string getAlgorithmName() = 0;
};

// Concrete Strategy: Bubble Sort
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "  - Using Bubble Sort algorithm..." << endl;
        int n = data.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
    
    string getAlgorithmName() override {
        return "Bubble Sort";
    }
};

// Concrete Strategy: Quick Sort
class QuickSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "  - Using Quick Sort algorithm..." << endl;
        quickSort(data, 0, data.size() - 1);
    }
    
    string getAlgorithmName() override {
        return "Quick Sort";
    }
    
private:
    void quickSort(vector<int>& data, int low, int high) {
        if (low < high) {
            int pivot = partition(data, low, high);
            quickSort(data, low, pivot - 1);
            quickSort(data, pivot + 1, high);
        }
    }
    
    int partition(vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[high]);
        return i + 1;
    }
};

// Concrete Strategy: Merge Sort
class MergeSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "  - Using Merge Sort algorithm..." << endl;
        mergeSort(data, 0, data.size() - 1);
    }
    
    string getAlgorithmName() override {
        return "Merge Sort";
    }
    
private:
    void mergeSort(vector<int>& data, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(data, left, mid);
            mergeSort(data, mid + 1, right);
            merge(data, left, mid, right);
        }
    }
    
    void merge(vector<int>& data, int left, int mid, int right) {
        vector<int> leftArray(data.begin() + left, data.begin() + mid + 1);
        vector<int> rightArray(data.begin() + mid + 1, data.begin() + right + 1);
        
        int i = 0, j = 0, k = left;
        
        while (i < leftArray.size() && j < rightArray.size()) {
            if (leftArray[i] <= rightArray[j]) {
                data[k] = leftArray[i];
                i++;
            } else {
                data[k] = rightArray[j];
                j++;
            }
            k++;
        }
        
        while (i < leftArray.size()) {
            data[k] = leftArray[i];
            i++;
            k++;
        }
        
        while (j < rightArray.size()) {
            data[k] = rightArray[j];
            j++;
            k++;
        }
    }
};

// NEW: Heap Sort Strategy (added without modifying existing code!)
class HeapSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "  - Using Heap Sort algorithm..." << endl;
        int n = data.size();
        
        // Build heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(data, n, i);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(data[0], data[i]);
            heapify(data, i, 0);
        }
    }
    
    string getAlgorithmName() override {
        return "Heap Sort";
    }
    
private:
    void heapify(vector<int>& data, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && data[left] > data[largest]) {
            largest = left;
        }
        
        if (right < n && data[right] > data[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(data[i], data[largest]);
            heapify(data, n, largest);
        }
    }
};

// NEW: Radix Sort Strategy (added without modifying existing code!)
class RadixSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "  - Using Radix Sort algorithm..." << endl;
        int max = *max_element(data.begin(), data.end());
        
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(data, exp);
        }
    }
    
    string getAlgorithmName() override {
        return "Radix Sort";
    }
    
private:
    void countingSort(vector<int>& data, int exp) {
        vector<int> output(data.size());
        vector<int> count(10, 0);
        
        for (int i = 0; i < data.size(); i++) {
            count[(data[i] / exp) % 10]++;
        }
        
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        for (int i = data.size() - 1; i >= 0; i--) {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < data.size(); i++) {
            data[i] = output[i];
        }
    }
};

// Context class - STABLE, never needs to change!
class Sorter {
private:
    SortingStrategy* strategy;
    
public:
    Sorter(SortingStrategy* strategy) : strategy(strategy) {}
    
    void setStrategy(SortingStrategy* newStrategy) {
        strategy = newStrategy;
    }
    
    void sortData(vector<int>& data) {
        cout << "Sorting data using " << strategy->getAlgorithmName() << ":" << endl;
        strategy->sort(data);
    }
    
    void printData(const vector<int>& data) {
        cout << "  - Result: [";
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i];
            if (i < data.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "=== STRATEGY PATTERN EXAMPLE ===" << endl;
    cout << "Demonstrating OCP-compliant algorithm selection" << endl << endl;
    
    vector<int> data = {64, 34, 25, 12, 22, 11, 90, 5};
    
    // Test different sorting strategies
    BubbleSortStrategy bubbleSort;
    QuickSortStrategy quickSort;
    MergeSortStrategy mergeSort;
    HeapSortStrategy heapSort;
    RadixSortStrategy radixSort;
    
    Sorter sorter(&bubbleSort);
    
    // Test Bubble Sort
    vector<int> data1 = data;
    sorter.sortData(data1);
    sorter.printData(data1);
    cout << endl;
    
    // Test Quick Sort
    vector<int> data2 = data;
    sorter.setStrategy(&quickSort);
    sorter.sortData(data2);
    sorter.printData(data2);
    cout << endl;
    
    // Test Merge Sort
    vector<int> data3 = data;
    sorter.setStrategy(&mergeSort);
    sorter.sortData(data3);
    sorter.printData(data3);
    cout << endl;
    
    // Test NEW: Heap Sort (added without modifying existing code!)
    vector<int> data4 = data;
    sorter.setStrategy(&heapSort);
    sorter.sortData(data4);
    sorter.printData(data4);
    cout << endl;
    
    // Test NEW: Radix Sort (added without modifying existing code!)
    vector<int> data5 = data;
    sorter.setStrategy(&radixSort);
    sorter.sortData(data5);
    sorter.printData(data5);
    cout << endl;
    
    cout << "=== BENEFITS OF STRATEGY PATTERN ===" << endl;
    cout << "1. Adding Heap Sort: Created new class, no modifications!" << endl;
    cout << "2. Adding Radix Sort: Created new class, no modifications!" << endl;
    cout << "3. Sorter class never needs to change!" << endl;
    cout << "4. Easy to switch algorithms at runtime!" << endl;
    cout << "5. Each algorithm can be tested independently!" << endl;
    cout << "6. Follows Open/Closed Principle perfectly!" << endl;
    
    return 0;
}
