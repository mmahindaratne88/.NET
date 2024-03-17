#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct {
    int account_number;
    char name[100];
    float balance;
    float transactions[MAX_TRANSACTIONS];
    int transaction_count;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void createAccount(int account_number, char *name) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached!\n");
        return;
    }

    accounts[num_accounts].account_number = account_number;
    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = 0;
    accounts[num_accounts].transaction_count = 0;
    num_accounts++;
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            accounts[i].transactions[accounts[i].transaction_count++] = amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (amount > accounts[i].balance) {
                printf("Insufficient funds!\n");
                return;
            }
            accounts[i].balance -= amount;
            accounts[i].transactions[accounts[i].transaction_count++] = -amount;
            printf("Withdrawal successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void checkBalance(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Balance for account %d: %.2f\n", account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void viewTransactions(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Transaction history for account %d:\n", account_number);
            for (int j = 0; j < accounts[i].transaction_count; j++) {
                printf("%s %.2f\n", (accounts[i].transactions[j] > 0) ? "Deposit:" : "Withdrawal:", accounts[i].transactions[j]);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    int account_number;
    float amount;
    char name[100];

    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. View Transactions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter name: ");
                scanf("%s", name);
                createAccount(account_number, name);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                checkBalance(account_number);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                viewTransactions(account_number);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
