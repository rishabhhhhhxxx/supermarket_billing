#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <limits>

using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuantity(int quant) { Quantity = quant; }

    string getItem() const { return Item; }
    int getRate() const { return Rate; }
    int getQuant() const { return Quantity; }
};

void addItem(Bill &b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Close" << endl;
        cout << "\tEnter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tInvalid input. Please enter a number.\n";
            Sleep(2000);
            continue;
        }

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin.ignore();  // Flush newline
            getline(cin, item);
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid rate input.\n";
                Sleep(2000);
                continue;
            }
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid quantity input.\n";
                Sleep(2000);
                continue;
            }
            b.setQuantity(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out) {
                cout << "\tFile cannot be opened" << endl;
            } else {
                out << b.getItem() << ":" << b.getRate() << ":" << b.getQuant() << endl;
                out.close();
                cout << "\tItem Added Successfully" << endl;
            }
            Sleep(2000);
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu" << endl;
            Sleep(2000);
        } else {
            cout << "\tInvalid choice. Please try again.\n";
            Sleep(2000);
        }
    }
}

void updateItem() {
    system("cls");
    string item;
    cout << "\tEnter Item Name to Update/Delete: ";
    cin.ignore();
    getline(cin, item);

    ifstream in("Bill.txt");
    ofstream out("BillTemp.txt");

    string line;
    bool found = false;
    int action;
    cout << "\t1. Update Item\n\t2. Delete Item\n\tEnter your choice: ";
    cin >> action;

    if (cin.fail() || (action != 1 && action != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tInvalid choice.\n";
        Sleep(2000);
        return;
    }

    while (getline(in, line)) {
        stringstream ss(line);
        string itemName, rateStr, quantStr;

        getline(ss, itemName, ':');
        getline(ss, rateStr, ':');
        getline(ss, quantStr);

        if (item == itemName) {
            found = true;
            if (action == 1) {
                int newRate, newQuant;
                cout << "\tEnter New Rate: ";
                cin >> newRate;
                cout << "\tEnter New Quantity: ";
                cin >> newQuant;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\tInvalid input.\n";
                    Sleep(2000);
                    return;
                }
                out << itemName << ":" << newRate << ":" << newQuant << endl;
            } else if (action == 2) {
                cout << "\tItem Deleted Successfully!" << endl;
            }
        } else {
            out << line << endl;
        }
    }

    out.close();
    in.close();
    remove("Bill.txt");
    rename("BillTemp.txt", "Bill.txt");

    if (!found) {
        cout << "\tItem Not Found!" << endl;
    } else if (action == 1) {
        cout << "\tItem Updated Successfully!" << endl;
    }
    Sleep(3000);
}

void printStock() {
    system("cls");
    ifstream in("Bill.txt");
    string line;
    cout << "\tItem | Rate | Quantity" << endl;
    cout << "\t------------------------" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string itemName, rateStr, quantStr;
        getline(ss, itemName, ':');
        getline(ss, rateStr, ':');
        getline(ss, quantStr);
        cout << "\t" << itemName << " | " << rateStr << " | " << quantStr << endl;
    }
    in.close();
    system("pause");
}

void printBill() {
    system("cls");
    int count = 0;
    ofstream printable("PrintableBill.txt");
    printable << "\tItem | Rate | Quantity | Amount\n";
    printable << "\t-------------------------------\n";
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tInvalid input.\n";
            Sleep(2000);
            continue;
        }

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin.ignore();
            getline(cin, item);
            cout << "\tEnter Quantity: ";
            cin >> quant;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid quantity.\n";
                Sleep(2000);
                continue;
            }

            ifstream in("Bill.txt");
            ofstream out("BillTemp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName, rateStr, quantStr;

                getline(ss, itemName, ':');
                getline(ss, rateStr, ':');
                getline(ss, quantStr);

                int itemRate = stoi(rateStr);
                int itemQuant = stoi(quantStr);

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t" << amount << endl;
                        printable << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t" << amount << endl;
                        int newQuant = itemQuant - quant;
                        count += amount;
                        out << itemName << ":" << itemRate << ":" << newQuant << endl;
                    } else {
                        cout << "\tSorry, " << item << " is out of stock!" << endl;
                        out << itemName << ":" << itemRate << ":" << itemQuant << endl;
                    }
                } else {
                    out << line << endl;
                }
            }

            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }

            out.close();
            in.close();
            remove("Bill.txt");
            rename("BillTemp.txt", "Bill.txt");
            Sleep(2000);
        } else if (choice == 2) {
            close = true;
        } else {
            cout << "\tInvalid choice.\n";
            Sleep(2000);
        }
    }

    printable << "\n\tTotal Bill: " << count << endl;
    printable << "\tThanks for shopping!\n";
    printable.close();

    cout << "\n\tTotal Bill: " << count << endl;
    cout << "\tThanks for shopping! Printable bill saved to 'PrintableBill.txt'.\n";
    system("pause");
}

int main() {
    Bill b;
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Super Market Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Print Bill" << endl;
        cout << "\t3. Update/Delete Item" << endl;
        cout << "\t4. View Stock" << endl;
        cout << "\t5. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tInvalid input. Try again.\n";
            Sleep(2000);
            continue;
        }

        if (val == 1) {
            addItem(b);
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            updateItem();
        } else if (val == 4) {
            printStock();
        } else if (val == 5) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(2000);
        } else {
            cout << "\tInvalid option.\n";
            Sleep(2000);
        }
    }
    return 0;
}
