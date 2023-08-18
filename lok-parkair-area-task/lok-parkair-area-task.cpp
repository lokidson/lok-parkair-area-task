// lok-parkair-area-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// For double checking results and for more information on formula used, see more here: https://www.omnicalculator.com/math/3-sides-triangle-area

#include <iostream>
#include <cmath>
#include <vector>
#include <limits> // Include the limits header for input validation
using namespace std;


// Function to calculate the area of a triangle
double calculateTriangleArea(const std::vector<double>& sides) {
    // Check if the vector contains exactly three sides
    if (sides.size() != 3) {
        std::cerr << "Error: Invalid number of sides provided." << std::endl;
        return 0.0;
    }

    // Extract the sides from the vector
    double a = sides[0];
    double b = sides[1];
    double c = sides[2];

    // Check if the sides can form a triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cerr << "Error: These side lengths cannot form a triangle." << std::endl;
        return 0.0;
    }

    // Calculate the semi-perimeter
    double s = (a + b + c) / 2.0;

    // Calculate the area using Heron's formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

int main() {
    std::vector<double> sides(3);

    // Input the lengths of the sides
    size_t i {0};
    do {
        std::cout << "Enter length of side " << i + 1 << " in meters: \n";

        if (cin >> sides[i]) {
            i++;
            continue;
        }
        else {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (i < 3);

    // Calculate the area
    double area = calculateTriangleArea(sides);

    // Display the result
    std::cout << "The area of the triangle is: " << area << " square meters" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu