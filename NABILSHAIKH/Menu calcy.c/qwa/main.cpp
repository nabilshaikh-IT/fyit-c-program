#include<iostream>
#include<cstring>
using namespace std;

struct Transaction {
    int TransactionID;
    char customerName[100];
    float amount;
    char date[20];
    Transaction* next;

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

    void deleteTransaction(int id) {
        if (head == nullptr) {
            cout << "No transactions to delete!" << endl;
            return;
        }

        if (head->TransactionID == id) {
            Transaction* temp = head;
            head = head->next;
            delete temp;
            cout << endl;
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


    transactions.insertTransaction(1, "Alice", 150.75, "2025-08-21");
    transactions.insertTransaction(2, "Bob", 200.50, "2025-08-22");
    transactions.insertTransaction(3, "Charlie", 50.00, "2025-08-23");


    cout << "All Transactions:" << endl;
    transactions.displayTransactions();


    int searchID = 2;
    Transaction* t = transactions.findTransaction(searchID);
    if (t != nullptr) {
        cout << "Found Transaction with ID " << searchID << ":" << endl;
        cout << "Transaction ID: " << t->TransactionID << endl;
        cout << "Customer Name: " << t->customerName << endl;
        cout << "Amount: " << t->amount << endl;
        cout << "Date: " << t->date << endl;
    } else {
        cout << "Transaction with ID " << searchID << " not found!" << endl;
    }


    transactions.deleteTransaction(2);


    cout << "\nRemaining Transactions after deletion:" << endl;
    transactions.displayTransactions();

    return 0;
}
