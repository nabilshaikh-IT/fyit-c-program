#include<iostream>
#include<cstring>
using namespace std;

struct Transaction {
    int TransactionID;
    char customerName[100];
    float amount;
    char date[20];
    Transaction* next;

    // Constructor for ease of initialization
    Transaction(int id, const char* name, float amt, const char* dt) {
        TransactionID = id;
        strcpy(customerName, name);
        amount = amt;
        strcpy(date, dt);
        next = nullptr;
    }
};

class TransactionList {
public:
    Transaction* head;

    TransactionList() {
        head = nullptr;
    }

    // Function to insert a new transaction at the end
    void insertTransaction(int id, const char* name, float amt, const char* dt) {
        Transaction* newTransaction = new Transaction(id, name, amt, dt);

        if (head == nullptr) {
            head = newTransaction;
        } else {
            Transaction* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newTransaction;
        }
    }

    // Function to display all transactions
    void displayTransactions() {
        if (head == nullptr) {
            cout << "No transactions available!" << endl;
            return;
        }

        Transaction* temp = head;
        while (temp != nullptr) {
            cout << "Transaction ID: " << temp->TransactionID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Amount: " << temp->amount << endl;
            cout << "Date: " << temp->date << endl;
            cout << "-------------------------" << endl;
            temp = temp->next;
        }
    }

    // Function to delete a transaction by its ID
    void deleteTransaction(int id) {
        if (head == nullptr) {
            cout << "No transactions to delete!" << endl;
            return;
        }

        if (head->TransactionID == id) {
            Transaction* temp = head;
            head = head->next;
            delete temp;
            cout << "Transaction with ID " << id << " deleted!" << endl;
            return;
        }

        Transaction* temp = head;
        while (temp->next != nullptr && temp->next->TransactionID != id) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Transaction with ID " << id << " not found!" << endl;
        } else {
            Transaction* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            cout << "Transaction with ID " << id << " deleted!" << endl;
        }
    }

    // Function to find a transaction by its ID
    Transaction* findTransaction(int id) {
        Transaction* temp = head;
        while (temp != nullptr) {
            if (temp->TransactionID == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Destructor to delete all transactions
    ~TransactionList() {
        while (head != nullptr) {
            Transaction* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TransactionList transactions;
    int option;

    while (true) {
        cout << "\nTransaction Menu:" << endl;
        cout << "1. Add a Transaction" << endl;
        cout << "2. Display All Transactions" << endl;
        cout << "3. Find a Transaction by ID" << endl;
        cout << "4. Delete a Transaction by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore(); // To clear the input buffer for string inputs

        if (option == 1) {
            // Add a Transaction
            int id;
            char name[100];
            float amt;
            char date[20];

            cout << "Enter Transaction ID: ";
            cin >> id;
            cin.ignore(); // To clear the input buffer for string inputs
            cout << "Enter Customer Name: ";
            cin.getline(name, 100);
            cout << "Enter Amount: ";
            cin >> amt;
            cin.ignore(); // To clear the input buffer for string inputs
            cout << "Enter Date (yyyy-mm-dd): ";
            cin.getline(date, 20);

            transactions.insertTransaction(id, name, amt, date);
            cout << "Transaction added successfully!" << endl;
        }
        else if (option == 2) {
            // Display all transactions
            cout << "\nAll Transactions:" << endl;
            transactions.displayTransactions();
        }
        else if (option == 3) {
            // Find a transaction by ID
            int searchID;
            cout << "Enter Transaction ID to search: ";
            cin >> searchID;

            Transaction* t = transactions.findTransaction(searchID);
            if (t != nullptr) {
                cout << "\nFound Transaction with ID " << searchID << ":" << endl;
                cout << "Transaction ID: " << t->TransactionID << endl;
                cout << "Customer Name: " << t->customerName << endl;
                cout << "Amount: " << t->amount << endl;
                cout << "Date: " << t->date << endl;
            } else {
                cout << "Transaction with ID " << searchID << " not found!" << endl;
            }
        }
        else if (option == 4) {
            // Delete a transaction by ID
            int delID;
            cout << "Enter Transaction ID to delete: ";
            cin >> delID;
            transactions.deleteTransaction(delID);
        }
        else if (option == 5) {
            // Exit the program
            cout << "Exiting the program..." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again!" << endl;
        }
    }

    return 0;
}

