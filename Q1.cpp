#include "CircularQueue.h"

int main() {
    CircularQueue<Car> parking(5);
    int choice;
    float totalEarning = 0;

    do {
        cout << "\n1. Park Car\n2. Remove Car\n3. Display\n4. Total Earning\n5. Exit\n"<<endl;
        cin >> choice;

        if (choice == 1) {
            Car c;
            cout << "Enter Car Number: "<<endl;
            cin >> c.carNumber;
            cout << "Enter Hours: "<<endl;
            cin >> c.hours;

            c.rate = 50;
            c.bill = c.hours * c.rate;

            parking.enqueue(c);
        }
        else if (choice == 2) {
            Car c = parking.dequeue();
            if (c.carNumber != "") {
                cout << "Bill: " << c.bill << endl;
                totalEarning += c.bill;
            }
        }
        else if (choice == 3) {
            parking.display();
        }
        else if (choice == 4) {
            cout << "Total Earning: " << totalEarning << endl;
        }

    } while (choice != 5);

    return 0;
}
