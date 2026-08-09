#include <iostream>
#include <cstring>  // For strcpy and strcmp

using namespace std;

const int MAX_CARS = 100;
const int MAKE_LENGTH = 50;
const int MODEL_LENGTH = 50;

struct Car {
    int id;
    char make[MAKE_LENGTH];
    char model[MODEL_LENGTH];
    int year;
    float price;
};

Car cars[MAX_CARS];
int carCount = 0;

void clearInputBuffer() {
    cin.clear(); // Clear any error flags
    cin.ignore(10000, '\n'); // Ignore up to 10000 characters or until newline
}

void addCar() {
    if (carCount >= MAX_CARS) {
        cout << "The car list is full. Cannot add more cars." << endl;
        return;
    }

    Car car;
    cout << "Enter car ID: ";
    cin >> car.id;
    clearInputBuffer(); // Clear input buffer

    cout << "Enter car make: ";
    cin.getline(car.make, MAKE_LENGTH);

    cout << "Enter car model: ";
    cin.getline(car.model, MODEL_LENGTH);

    cout << "Enter car year: ";
    cin >> car.year;
    clearInputBuffer(); // Clear input buffer

    cout << "Enter car price: $";
    cin >> car.price;
    clearInputBuffer(); // Clear input buffer

    cars[carCount++] = car;
    cout << "Car added successfully!" << endl;
}

void viewCars() {
    if (carCount == 0) {
        cout << "No cars available to display." << endl;
        return;
    }

    cout << "\n--- Car List ---" << endl;
    for (int i = 0; i < carCount; ++i) {
        cout << "ID: " << cars[i].id << endl;
        cout << "Make: " << cars[i].make << endl;
        cout << "Model: " << cars[i].model << endl;
        cout << "Year: " << cars[i].year << endl;
        cout << "Price: $" << cars[i].price << endl;
        cout << "-------------------" << endl;
    }
}

void deleteCar() {
    if (carCount == 0) {
        cout << "No cars available to delete." << endl;
        return;
    }

    int id;
    cout << "Enter the ID of the car to delete: ";
    cin >> id;
    clearInputBuffer(); // Clear input buffer

    int index = -1;
    for (int i = 0; i < carCount; ++i) {
        if (cars[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Car with ID " << id << " not found." << endl;
        return;
    }

    for (int i = index; i < carCount - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    --carCount;
    cout << "Car deleted successfully!" << endl;
}

void searchCar() {
    if (carCount == 0) {
        cout << "No cars available for search." << endl;
        return;
    }

    int id;
    cout << "Enter the ID of the car to search: ";
    cin >> id;
    clearInputBuffer(); // Clear input buffer

    for (int i = 0; i < carCount; ++i) {
        if (cars[i].id == id) {
            cout << "\nCar found!" << endl;
            cout << "ID: " << cars[i].id << endl;
            cout << "Make: " << cars[i].make << endl;
            cout << "Model: " << cars[i].model << endl;
            cout << "Year: " << cars[i].year << endl;
            cout << "Price: $" << cars[i].price << endl;
            return;
        }
    }

    cout << "Car with ID " << id << " not found." << endl;
}

void displayMenu() {
    cout << "\n--- Car Management System ---" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. View Cars" << endl;
    cout << "3. Delete Car" << endl;
    cout << "4. Search Car" << endl;
    cout << "5. Exit" << endl;
}

void initializeDefaultCars() {
    // Adding some default cars
    Car defaultCars[] = {
        {1, "Toyota", "Corolla", 2020, 20000},
        {2, "Honda", "Civic", 2019, 22000},
        {3, "Ford", "Mustang", 2021, 30000}
    };

    for (int i = 0; i < 3; ++i) {
        cars[carCount++] = defaultCars[i];
    }
}

int main() {
    initializeDefaultCars(); // Initialize with default cars

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        clearInputBuffer(); // Clear input buffer

        switch (choice) {
        case 1:
            addCar();
            break;
        case 2:
            viewCars();
            break;
        case 3:
            deleteCar();
            break;
        case 4:
            searchCar();
            break;
        case 5:
            cout << "Exiting system. Thank you for using the Car Management System!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
