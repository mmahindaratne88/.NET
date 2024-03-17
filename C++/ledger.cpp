#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transaction {
public:
    float amount;
    string type; // "Deposit" or "Withdrawal"

    Transaction(float amount, string type) {
        this->amount = amount;
        this->type = type;
    }
};

class Account {
public:
    int account_number;
    string name;
    float balance;
    vector<Transaction> transactions;

    Account(int account_number, string name) {
        this->account_number = account_number;
        this->name = name;
        this->balance = 0;
    }

    void deposit(float amount) {
        balance += amount;
        transactions.push_back(Transaction(amount, "Deposit"));
        cout << "Deposit successful!" << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction(amount, "Withdrawal"));
        cout << "Withdrawal successful!" << endl;
    }

    void checkBalance() {
        cout << "Balance for account " << account_number << ": " << balance << endl;
    }

    void viewTransactions() {
        cout << "Transaction history for account " << account_number << ":" << endl;
        for (Transaction transaction : transactions) {
            cout << transaction.type << ": " << transaction.amount << endl;
        }
    }
};

int main() {
    int choice;
    int account_number;
    float amount;
    string name;

    vector<Account> accounts;

    do {
        cout << "\nBank Account Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. View Transactions" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter name: ";
                cin >> name;
                accounts.push_back(Account(account_number, name));
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                for (Account &account : accounts) {
                    if (account.account_number == account_number) {
                        account.deposit(amount);
                        break;
                    }
                }
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                for (Account &account : accounts) {
                    if (account.account_number == account_number) {
                        account.withdraw(amount);
                        break;
                    }
                }
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> account_number;
                for (Account &account : accounts) {
                    if (account.account_number == account_number) {
                        account.checkBalance();
                        break;
                    }
                }
                break;
            case 5:
                cout << "Enter account number: ";
                cin >> account_number;
                for (Account &account : accounts) {
                    if (account.account_number == account_number) {
                        account.viewTransactions();
                        break;
                    }
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
