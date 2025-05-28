// Include standard libraries
#include <iostream>   // For input and output (cin, cout)
#include <iomanip>    // For formatting output (e.g., setprecision)
#include <string>     // For using the string type
#include <sstream>    // For stringstream (used to convert string input to integers)

#ifdef _WIN32
#include <cstdlib>    // For system() function (Windows only)
#endif

int main() {
#ifdef _WIN32
    system("chcp 65001");  // Set console character encoding to UTF-8 (only on Windows)
#endif

    std::string input;     // To store user input as a string
    int choice = 0;        // To store the menu selection
    int quantity = 0;      // To store the number of items user wants
    double total = 0.0;    // To store the total cost

    // Start infinite loop for the vending menu
    while (true) {
        // Display menu
        std::cout << "Hello and Welcome to the Vending Machine, ensuring you stay hydrated and fed\n";
        std::cout << "1. Water       - £1.00\n";
        std::cout << "2. Grapefruit  - £1.50\n";
        std::cout << "3. Crisps      - £1.20\n";
        std::cout << "4. Chocolate   - £1.80\n";
        std::cout << "5. Exit\n\n";

        // Prompt user for selection
        std::cout << "Please select an item (1-5): ";
        std::getline(std::cin, input);               // Get input as string to handle errors gracefully
        std::stringstream(input) >> choice;          // Convert input to integer

        // Exit condition
        if (choice == 5) {
            std::cout << "Thank you for using the vending machine!\n";
            break;
        }

        // Prompt for quantity based on selection
        switch (choice) {
            case 1:
                std::cout << "Enter quantity of Water: ";
                break;
            case 2:
                std::cout << "Enter quantity of Grapefruit: ";
                break;
            case 3:
                std::cout << "Enter quantity of Crisps: ";
                break;
            case 4:
                std::cout << "Enter quantity of Chocolate: ";
                break;
            default:
                std::cout << "Invalid selection. Please try again.\n";
                continue;  // Skip rest of loop if invalid choice
        }

        // Get quantity from user
        std::getline(std::cin, input);
        std::stringstream(input) >> quantity;

        // Calculate total based on item selected
        switch (choice) {
            case 1: total = quantity * 1.00; break;
            case 2: total = quantity * 1.50; break;
            case 3: total = quantity * 1.20; break;
            case 4: total = quantity * 1.80; break;
        }

        // Format and display total cost
        std::cout << std::fixed << std::setprecision(2);  // Set 2 decimal places
        std::cout << "Total to pay: £" << total << "\n";
        std::cout << "Thank you for your purchase!\n\n";
    }

    return 0;  // End of program
}
