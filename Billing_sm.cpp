// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <windows.h>
// using namespace std;

// class Bill
// {
// private:
//     string Item;
//     int Rate, Quantity;

// public:
//     Bill() : Item(""), Rate(0), Quantity(0) {}

//     void setItem(string item)
//     {
//         Item = item;
//     }

//     void setRate(int rate)
//     {
//         Rate = rate;
//     }

//     void setQuantity(int quant)
//     {
//         Quantity = quant;
//     }

//     string getItem()
//     {
//         return Item;
//     }

//     int getRate()
//     {
//         return Rate;
//     }

//     int getQuant()
//     {
//         return Quantity;
//     }
// };

// void addItem(Bill b)
// {
//     bool close = false;
//     while (!close)
//     {
//         int choice;
//         cout << "\t1. Add Item" << endl;
//         cout << "\t2. Close" << endl;
//         cout << "\tEnter choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             system("cls");
//             string item;
//             int rate, quant;

//             cout << "\tEnter Item Name: ";
//             cin >> item;
//             b.setItem(item);

//             cout << "\tEnter Rate Of Item: ";
//             cin >> rate;
//             b.setRate(rate);

//             cout << "\tEnter Quantity Of Item: ";
//             cin >> quant;
//             b.setQuantity(quant);
//             // ofStream => Output file stream //to write files
//             // ios :: app ==> append to add at the end of file without erasing
//             ofstream out("C:\\Users\\91798\\OneDrive\\Desktop\\Bill.txt", ios::app);
//             if (!out)
//             {
//                 cout << "\tfile cannot be opened" << endl;
//             }
//             else
//             {
//                 out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl
//                     << endl;
//             }
//             out.close();
//             cout << "\tItem Added Successfuly" << endl;
//             Sleep(3000);
//         }
//         else if (choice == 2)
//         {
//             system("cls");
//             close = true;
//             cout << "\tBack to Main Menu" << endl;
//             Sleep(3000);
//         }
//     }
// }
// void printBill()
// {
//     system("cls");
//     int count = 0;
//     bool close = false;
//     while (!close)
//     {
//         system("cls");
//         int choice;
//         cout << "\t1.Add Bill." << endl;
//         cout << "\t2.Close Session." << endl;
//         cout << "\tEnter Choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             string item;
//             int quant;
//             cout << "\tEnter Item: ";
//             cin >> item;
//             cout << "\tEnter Quantity: ";
//             cin >> quant;

//             ifstream in("C:\\Users\\91798\\OneDrive\\Desktop\\Bill.txt");
//             ofstream out("C:\\Users\\91798\\OneDrive\\Desktop\\Bill Temp.txt");

//             string line;
//             bool found = false;

//             while (getline(in, line))
//             {
//                 stringstream ss;
//                 ss << line;
//                 string itemName;
//                 int itemRate, itemQuant;
//                 char delimiter;
//                 ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

//                 if (item == itemName)
//                 {
//                     found = true;
//                     if (quant <= itemQuant)
//                     {
//                         int amount = itemRate * quant;
//                         cout << "\t Item | Rate | Quantity | Amount" << endl;
//                         cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
//                         int newQuant = itemQuant - quant;
//                         itemQuant = newQuant;
//                         count += amount;

//                         out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
//                     }
//                     else
//                     {
//                         cout << "\tSorry, " << item << " Ended!" << endl;
//                     }
//                 }
//                 else
//                 {
//                     // saves the item that are not entered by the user to orginal list
//                     out << line << endl;
//                 }
//             }
//             if (!found)
//             {
//                 cout << "\tItem Not Available!" << endl;
//             }
//             out.close();
//             in.close();
//             remove("C:\\Users\\91798\\OneDrive\\Desktop\\Bill.txt");
//             rename("C:\\Users\\91798\\OneDrive\\Desktop\\Bill Temp.txt", "C:\\Users\\91798\\OneDrive\\Desktop\\Bill.txt");
//         }
//         else if (choice == 2)
//         {
//             close = true;
//             cout << "\tCounting Total Bill" << endl;
//         }
//         Sleep(3000);
//     }
//     system("cls");
//     cout << endl
//          << endl;
//     cout << "\t Total Bill ----------------- : " << count << endl
//          << endl;
//     cout << "\tThanks For Shopping!" << endl;
//     Sleep(5000);
// }

// ;

// int main()
// {
//     Bill b;
//     bool exit =false ;
//     while (!exit)
//     {
//         // cls clears the console output
//         system("cls");
//         int val;
//         cout << "\tWelcome To Super Market Billing System" << endl;
//         cout << "\t**************************************" << endl;
//         cout << "\t\t1. Add Item" << endl;
//         cout << "\t\t2. Print Bill" << endl;
//         cout << "\t\t3. Exit" << endl;
//         cout << "\t\tEnter Choice: ";
//         cin >> val;

//         if (val == 1)
//         {
//             addItem(b);
//         }
//         else if (val == 2)
//         {
//             printBill();
//         }
//         else if (val == 3)
//         {
//             system("cls");
//             exit = true;
//             cout << "\tGood Luck!" << endl;
//             Sleep(3000);
//         }
//     }

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
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

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;
            b.setQuantity(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out) {
                cout << "\tFile cannot be opened" << endl;
            } else {
                out << b.getItem() << ":" << b.getRate() << ":" << b.getQuant() << endl;
                out.close();
                cout << "\tItem Added Successfully" << endl;
            }
            Sleep(3000);
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu" << endl;
            Sleep(3000);
        }
    }
}

void printBill() {
    system("cls");
    int count = 0;
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("Bill.txt");
            ofstream out("BillTemp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                getline(ss, itemName, ':');
                ss >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
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
            Sleep(3000);
        } else if (choice == 2) {
            close = true;
            cout << "\tCounting Total Bill" << endl;
            Sleep(3000);
        }
    }

    system("cls");
    cout << "\n\n\tTotal Bill ----------------- : " << count << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
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
        cout << "\t3. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            addItem(b);
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
