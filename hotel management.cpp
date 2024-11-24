#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hotel {
private:
    struct Room {
        int roomNumber;
        string roomType;
        bool isBooked;
        string guestName;
        vector<string> foodOrders;
        double foodBill;
        double roomRate;
        bool roomCleaningRequested;
        double cleaningCharge;
    };

    Room rooms[5];  // Array of 5 rooms for simplicity
    double cleaningFee = 20.0;  // Set the cleaning fee for room service

    struct MenuItem {
        string itemName;
        double price;
    };

    vector<MenuItem> breakfastMenu;
    vector<MenuItem> lunchMenu;
    vector<MenuItem> dinnerMenu;

public:
    Hotel() {
        // Initialize rooms with different types and rates
        rooms[0] = {101, "single", false, "", {}, 0.0, 50.0, false, 0.0};
        rooms[1] = {102, "double", false, "", {}, 0.0, 75.0, false, 0.0};
        rooms[2] = {103, "suite", false, "", {}, 0.0, 150.0, false, 0.0};
        rooms[3] = {104, "deluxe", false, "", {}, 0.0, 100.0, false, 0.0};
        rooms[4] = {105, "single", false, "", {}, 0.0, 50.0, false, 0.0};

        // Initialize breakfast menu items
        breakfastMenu.push_back({"Idli", 2.50});
        breakfastMenu.push_back({"Vada", 2.00});
        breakfastMenu.push_back({"Dosa", 3.50});
        breakfastMenu.push_back({"Uttapam", 3.75});
        breakfastMenu.push_back({"Pongal", 4.00});
        breakfastMenu.push_back({"Upma", 3.25});
        breakfastMenu.push_back({"Medu Vada", 2.99});
        breakfastMenu.push_back({"Pesarattu", 4.25});
        breakfastMenu.push_back({"Rava Dosa", 4.50});
        breakfastMenu.push_back({"Filter Coffee", 1.50});

        // Initialize lunch menu items
        lunchMenu.push_back({"Sambar Rice", 6.99});
        lunchMenu.push_back({"Lemon Rice", 5.99});
        lunchMenu.push_back({"Curd Rice", 5.49});
        lunchMenu.push_back({"Veg Thali", 7.99});
        lunchMenu.push_back({"Rasam", 4.99});
        lunchMenu.push_back({"Tomato Rice", 5.75});
        lunchMenu.push_back({"Bisibele Bath", 6.49});
        lunchMenu.push_back({"Puliyogare (Tamarind Rice)", 5.75});
        lunchMenu.push_back({"Coconut Rice", 5.50});
        lunchMenu.push_back({"Buttermilk", 2.99});

        // Initialize dinner menu items
        dinnerMenu.push_back({"Masala Dosa", 4.99});
        dinnerMenu.push_back({"Appam with Stew", 7.49});
        dinnerMenu.push_back({"Bisi Bele Bath", 6.99});
        dinnerMenu.push_back({"Upma", 3.99});
        dinnerMenu.push_back({"Pesarattu with Chutney", 5.49});
        dinnerMenu.push_back({"Mysore Pak", 2.99});
        dinnerMenu.push_back({"Ghee Roast Dosa", 5.99});
        dinnerMenu.push_back({"Chole Batura", 7.49});
        dinnerMenu.push_back({"Schezwan Idli", 4.99});
        dinnerMenu.push_back({"Payasam", 3.49});
    }

    void bookRoom() {
        string roomType, guestName;
        cout << "Enter room type (single, double, suite, deluxe): ";
        cin >> roomType;

        for (auto& room : rooms) {
            if (room.roomType == roomType && !room.isBooked) {
                cout << "Enter guest name: ";
                cin.ignore();
                getline(cin, guestName);

                room.isBooked = true;
                room.guestName = guestName;

                cout << "Room " << room.roomNumber << " (" << room.roomType 
                     << ") successfully booked for " << guestName << ".\n";
                return;
            }
        }
        cout << "No available rooms of type " << roomType << ".\n";
    }

    void displayRoomDetails(int roomNumber) {
        for (int i = 0; i < 5; i++) {
            if (rooms[i].roomNumber == roomNumber) {
                cout << "Room Number: " << rooms[i].roomNumber << "\n";
                cout << "Room Type: " << rooms[i].roomType << "\n";
                cout << "Booking Status: " << (rooms[i].isBooked ? "Booked" : "Available") << "\n";
                if (rooms[i].isBooked) {
                    cout << "Guest Name: " << rooms[i].guestName << "\n";
                }
                cout << "Food Orders: \n";
                for (const auto& item : rooms[i].foodOrders) {
                    cout << "- " << item << "\n";
                }
                cout << "Food Bill: $" << rooms[i].foodBill << "\n";
                cout << "Cleaning Service Requested: " << (rooms[i].roomCleaningRequested ? "Yes" : "No") << "\n";
                cout << "Cleaning Charge: $" << rooms[i].cleaningCharge << "\n";
                return;
            }
        }
        cout << "Room " << roomNumber << " not found.\n";
    }

    void checkAvailableRooms() {
        bool available = false;
        cout << "Available rooms:\n";
        for (int i = 0; i < 5; i++) {
            if (!rooms[i].isBooked) {
                cout << "Room " << rooms[i].roomNumber << " (" << rooms[i].roomType << ")\n";
                available = true;
            }
        }
        if (!available) {
            cout << "No rooms available.\n";
        }
    }

    void viewGuestList() {
        bool hasGuests = false;
        cout << "\nCurrent Guests and Room Numbers:\n";
        for (const auto& room : rooms) {
            if (room.isBooked) {
                cout << "Room " << room.roomNumber << ": " << room.guestName << "\n";
                hasGuests = true;
            }
        }
        if (!hasGuests) {
            cout << "No guests are currently checked in.\n";
        }
    }

    void displayMenu() {
        cout << "\n--- South Indian Breakfast Menu ---\n";
        for (size_t i = 0; i < breakfastMenu.size(); i++) {
            cout << i + 1 << ". " << breakfastMenu[i].itemName << " - $" << breakfastMenu[i].price << "\n";
        }
        cout << "\n--- South Indian Lunch Menu ---\n";
        for (size_t i = 0; i < lunchMenu.size(); i++) {
            cout << i + 1 << ". " << lunchMenu[i].itemName << " - $" << lunchMenu[i].price << "\n";
        }
        cout << "\n--- South Indian Dinner Menu ---\n";
        for (size_t i = 0; i < dinnerMenu.size(); i++) {
            cout << i + 1 << ". " << dinnerMenu[i].itemName << " - $" << dinnerMenu[i].price << "\n";
        }
    }

    void orderFoodFromMenu(int roomNumber) {
        for (int i = 0; i < 5; i++) {
            if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked) {
                int mealChoice, itemChoice;
                do {
                    cout << "\nChoose a meal type to order from:\n";
                    cout << "1. Breakfast\n2. Lunch\n3. Dinner\n0. Finish ordering\n";
                    cout << "Enter your choice: ";
                    cin >> mealChoice;

                    if (mealChoice == 1) {
                        for (size_t i = 0; i < breakfastMenu.size(); i++) {
                            cout << i + 1 << ". " << breakfastMenu[i].itemName << " - $" << breakfastMenu[i].price << "\n";
                        }
                        cout << "Enter the item number to order (0 to finish): ";
                        cin >> itemChoice;
                        if (itemChoice > 0 && itemChoice <= static_cast<int>(breakfastMenu.size())) {
                            rooms[i].foodOrders.push_back(breakfastMenu[itemChoice - 1].itemName);
                            rooms[i].foodBill += breakfastMenu[itemChoice - 1].price;
                        }
                    } else if (mealChoice == 2) {
                        for (size_t i = 0; i < lunchMenu.size(); i++) {
                            cout << i + 1 << ". " << lunchMenu[i].itemName << " - $" << lunchMenu[i].price << "\n";
                        }
                        cout << "Enter the item number to order (0 to finish): ";
                        cin >> itemChoice;
                        if (itemChoice > 0 && itemChoice <= static_cast<int>(lunchMenu.size())) {
                            rooms[i].foodOrders.push_back(lunchMenu[itemChoice - 1].itemName);
                            rooms[i].foodBill += lunchMenu[itemChoice - 1].price;
                        }
                    } else if (mealChoice == 3) {
                        for (size_t i = 0; i < dinnerMenu.size(); i++) {
                            cout << i + 1 << ". " << dinnerMenu[i].itemName << " - $" << dinnerMenu[i].price << "\n";
                        }
                        cout << "Enter the item number to order (0 to finish): ";
                        cin >> itemChoice;
                        if (itemChoice > 0 && itemChoice <= static_cast<int>(dinnerMenu.size())) {
                            rooms[i].foodOrders.push_back(dinnerMenu[itemChoice - 1].itemName);
                            rooms[i].foodBill += dinnerMenu[itemChoice - 1].price;
                        }
                    }
                } while (mealChoice != 0);
                return;
            }
        }
        cout << "Room " << roomNumber << " not found or not booked.\n";
    }

    void requestRoomCleaning(int roomNumber) {
        for (int i = 0; i < 5; i++) {
            if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked) {
                if (!rooms[i].roomCleaningRequested) {
                    rooms[i].roomCleaningRequested = true;
                    rooms[i].cleaningCharge = cleaningFee;
                    cout << "Room cleaning requested for room " << roomNumber << ". Cleaning charge: $" << cleaningFee << "\n";
                } else {
                    cout << "Room cleaning has already been requested for this room.\n";
                }
                return;
            }
        }
        cout << "Room " << roomNumber << " not found or not booked.\n";
    }

    void checkBill(int roomNumber) {
        for (int i = 0; i < 5; i++) {
            if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked) {
                double totalBill = rooms[i].roomRate + rooms[i].foodBill + rooms[i].cleaningCharge;
                cout << "\nBill for Room " << roomNumber << ":\n";
                cout << "Room Rate: $" << rooms[i].roomRate << "\n";
                cout << "Food Charges: $" << rooms[i].foodBill << "\n";
                cout << "Cleaning Charges: $" << rooms[i].cleaningCharge << "\n";
                cout << "Total Bill: $" << totalBill << "\n";
                return;
            }
        }
        cout << "Room " << roomNumber << " not found or not booked.\n";
    }

    void checkOut(int roomNumber) {
        for (int i = 0; i < 5; i++) {
            if (rooms[i].roomNumber == roomNumber && rooms[i].isBooked) {
                checkBill(roomNumber);
                
                // Clear room details for next guest
                rooms[i].isBooked = false;
                rooms[i].guestName.clear();
                rooms[i].foodOrders.clear();
                rooms[i].foodBill = 0.0;
                rooms[i].roomCleaningRequested = false;
                rooms[i].cleaningCharge = 0.0;

                cout << "Room " << roomNumber << " has been checked out and is now available for new bookings.\n";
                return;
            }
        }
        cout << "Room " << roomNumber << " not found or not booked.\n";
    }
};

int main() {
    Hotel hotel;
    int choice, roomNumber;

    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Book Room\n2. Check Available Rooms\n3. View Guest List\n";
        cout << "4. Display Room Details\n5. Display Menu\n6. Order Food\n7. Request Room Cleaning\n";
        cout << "8. Check Bill\n9. Check Out\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom();
                break;
            case 2:
                hotel.checkAvailableRooms();
                break;
            case 3:
                hotel.viewGuestList();
                break;
            case 4:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.displayRoomDetails(roomNumber);
                break;
            case 5:
                hotel.displayMenu();
                break;
            case 6:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.orderFoodFromMenu(roomNumber);
                break;
            case 7:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.requestRoomCleaning(roomNumber);
                break;
            case 8:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.checkBill(roomNumber);
                break;
            case 9:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.checkOut(roomNumber);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}