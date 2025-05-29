// SwimClubApp.cpp
// A simple Swim Club management system in C++
// Includes greeting, facility display, member check-in, and steam room booking

#include <iostream>     // for input/output operations
#include <vector>       // for using std::vector container
#include <string>       // for std::string support

// SwimClub class definition
class SwimClub {
private:
    std::string name;
    std::string openingTime;
    std::string closingTime;
    std::vector<std::string> openingTeams;
    std::vector<std::string> facilities;
    double memberPrice;
    double nonMemberPrice;
    bool steamRoomBooked;

public:
    // Constructor to initialize club details
    SwimClub(std::string clubName)
        : name(clubName), openingTime("06:00 AM"), closingTime("10:00 PM"),
          memberPrice(5.00), nonMemberPrice(10.00), steamRoomBooked(false) {
        openingTeams = {"Steam room all day", "Pool all day", "Sauna all day"};
        facilities = {"Sauna", "Hot Tub", "Steam Room", "Olympic Pool", "Kids Pool"};
    }

    // Display welcome message and opening hours
    void welcome() {
        std::cout << "Welcome to " << name << " Swim Club!" << std::endl;
        std::cout << "Open daily from " << openingTime << " to " << closingTime << ".\n" << std::endl;
    }

    // Display the opening teams
    void showOpeningTeams() {
        std::cout << "Opening Teams:\n";
        for (const auto& team : openingTeams) {
            std::cout << "- " << team << std::endl;
        }
        std::cout << std::endl;
    }

    // Display available facilities
    void showFacilities() {
        std::cout << "Facilities Offered:\n";
        for (const auto& facility : facilities) {
            std::cout << "- " << facility << std::endl;
        }
        std::cout << std::endl;
    }

    // Show pricing for members and non-members
    void showPrices() {
        std::cout << "Prices:\n";
        std::cout << "Member: GBP " << memberPrice << std::endl;
        std::cout << "Non-Member: GBP " << nonMemberPrice << "\n" << std::endl;
    }

    // Check-in function that asks if user is a member
    void checkIn() {
        std::string response;
        std::cout << "Are you a member? (yes/no): ";
        std::getline(std::cin, response);

        if (response == "yes" || response == "Yes") {
            std::cout << "Welcome, member! Entry fee is GBP " << memberPrice << ". Enjoy your swim!\n" << std::endl;
        } else if (response == "no" || response == "No") {
            std::cout << "Welcome, guest! Entry fee is GBP " << nonMemberPrice << ". Enjoy your swim!\n" << std::endl;
        } else {
            std::cout << "Invalid response. Please try again.\n" << std::endl;
        }
    }

    // Allow users to book the steam room
    void bookSteamRoom() {
        std::string confirm;
        std::cout << "Would you like to book the steam room for Monday 5:00 PM - 8:00 PM? (yes/no): ";
        std::getline(std::cin, confirm);

        if (confirm == "yes" || confirm == "Yes") {
            if (!steamRoomBooked) {
                steamRoomBooked = true;
                std::cout << "Steam room booked successfully!\n" << std::endl;
            } else {
                std::cout << "Steam room is already booked for that time.\n" << std::endl;
            }
        } else {
            std::cout << "Steam room booking skipped.\n" << std::endl;
        }
    }
};

// Main function
int main() {
    SwimClub club("Ocean Breeze");

    club.welcome();
    club.showOpeningTeams();
    club.showFacilities();
    club.showPrices();
    club.checkIn();
    club.bookSteamRoom();

    // Pause before exit
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
