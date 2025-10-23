// Problem 17: Shipping Strategy
// Level: Intermediate
// 
// Original Problem (OCP Violation):
// class ShippingCalculator {
//     double calculateShipping(string method, double weight, double distance) {
//         if (method == "standard") {
//             return weight * 0.5 + distance * 0.1;
//         } else if (method == "express") {
//             return weight * 1.0 + distance * 0.2;
//         } else if (method == "overnight") {
//             return weight * 2.0 + distance * 0.5;
//         } else if (method == "international") {
//             return weight * 1.5 + distance * 0.3 + 25.0;
//         }
//         return 0;
//     }
// };
//
// Task: Refactor to follow OCP.
//
// Write your solution below:

#include <iostream>
#include <string>
using namespace std;

// Your solution here...
