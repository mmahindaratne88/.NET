using System;
using System.Collections.Generic;

class Transaction {
    public float Amount { get; }
    public string Type { get; }

    public Transaction(float amount, string type) {
        Amount = amount;
        Type = type;
    }
}

class Account {
    public int AccountNumber { get; }
    public string Name { get; }
    public float Balance { get; private set; }
    private List<Transaction> transactions;

    public Account(int accountNumber, string name) {
        AccountNumber = accountNumber;
        Name = name;
        Balance = 0;
        transactions = new List<Transaction>();
    }

    public void Deposit(float amount) {
        Balance += amount;
        transactions.Add(new Transaction(amount, "Deposit"));
        Console.WriteLine("Deposit successful!");
    }

    public void Withdraw(float amount) {
        if (amount > Balance) {
            Console.WriteLine("Insufficient funds!");
            return;
        }
        Balance -= amount;
        transactions.Add(new Transaction(amount, "Withdrawal"));
        Console.WriteLine("Withdrawal successful!");
    }

    public void CheckBalance() {
        Console.WriteLine($"Balance for account {AccountNumber}: {Balance}");
    }

    public void ViewTransactions() {
        Console.WriteLine($"Transaction history for account {AccountNumber}:");
        foreach (Transaction transaction in transactions) {
            Console.WriteLine($"{transaction.Type}: {transaction.Amount}");
        }
    }
}

class Program {
    static void Main(string[] args) {
        int choice;
        int accountNumber;
        float amount;
        string name;

        List<Account> accounts = new List<Account>();

        do {
            Console.WriteLine("\nBank Account Management System");
            Console.WriteLine("1. Create Account");
            Console.WriteLine("2. Deposit");
            Console.WriteLine("3. Withdraw");
            Console.WriteLine("4. Check Balance");
            Console.WriteLine("5. View Transactions");
            Console.WriteLine("6. Exit");
            Console.Write("Enter your choice: ");
            choice = int.Parse(Console.ReadLine());

            switch (choice) {
                case 1:
                    Console.Write("Enter account number: ");
                    accountNumber = int.Parse(Console.ReadLine());
                    Console.Write("Enter name: ");
                    name = Console.ReadLine();
                    accounts.Add(new Account(accountNumber, name));
                    break;
                case 2:
                    Console.Write("Enter account number: ");
                    accountNumber = int.Parse(Console.ReadLine());
                    Console.Write("Enter amount to deposit: ");
                    amount = float.Parse(Console.ReadLine());
                    foreach (Account account in accounts) {
                        if (account.AccountNumber == accountNumber) {
                            account.Deposit(amount);
                            break;
                        }
                    }
                    break;
                case 3:
                    Console.Write("Enter account number: ");
                    accountNumber = int.Parse(Console.ReadLine());
                    Console.Write("Enter amount to withdraw: ");
                    amount = float.Parse(Console.ReadLine());
                    foreach (Account account in accounts) {
                        if (account.AccountNumber == accountNumber) {
                            account.Withdraw(amount);
                            break;
                        }
                    }
                    break;
                case 4:
                    Console.Write("Enter account number: ");
                    accountNumber = int.Parse(Console.ReadLine());
                    foreach (Account account in accounts) {
                        if (account.AccountNumber == accountNumber) {
                            account.CheckBalance();
                            break;
                        }
                    }
                    break;
                case 5:
                    Console.Write("Enter account number: ");
                    accountNumber = int.Parse(Console.ReadLine());
                    foreach (Account account in accounts) {
                        if (account.AccountNumber == accountNumber) {
                            account.ViewTransactions();
                            break;
                        }
                    }
                    break;
                case 6:
                    Console.WriteLine("Exiting...");
                    break;
                default:
                    Console.WriteLine("Invalid choice!");
                    break;
            }
        } while (choice != 6);
    }
}
