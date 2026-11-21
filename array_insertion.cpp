#include <iostream>
using namespace std;

const int MAX = 10;

int main() {
    int arr[MAX] = {2, 4, 6, 8, 12};
    int n = 5;
    int number, position;

    // Display the original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Enter the new number and its position
    cout << "\nEnter the number to insert: ";
    cin >> number;

    cout << "Enter the position (1 to " << n + 1 << "): ";
    cin >> position;

    // Check whether the position is valid
    if (position < 1 || position > n + 1 || n == MAX) {
        cout << "Invalid position or array is full." << endl;
        return 1;
    }

    // Shift elements one position to the right
    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new number
    arr[position - 1] = number;
    n++;

    // Display the updated array
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
