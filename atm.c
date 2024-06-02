#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ACCOUNTS 10
#define MAX_HISTORY 100

// Structures
typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} Account;

typedef struct {
    char type[50];
    int accountNumber;
    double amount;
} Transaction;

// Global variables
Account accounts[MAX_ACCOUNTS];
Transaction history[MAX_HISTORY];
int accountCount = 0;
int transactionCount = 0;

// Function prototypes
void createAccount();
void checkBalance();
void deposit();
void withdraw();
void transfer();
void printHistory();
void addTransaction(const char* type, int accountNumber, double amount);

int main() {
    int choice;

    while (1) {
        printf("\nATM Simulator\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Transfer Money\n");
        printf("6. Transaction History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                printHistory();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts, maximum limit reached.\n");
        return;
    }
    accounts[accountCount].accountNumber = accountCount + 1;
    printf("Enter the name for account %d: ", accounts[accountCount].accountNumber);
    scanf("%s", accounts[accountCount].name);
    accounts[accountCount].balance = 0.0;
    printf("Account created successfully. Account Number: %d\n", accounts[accountCount].accountNumber);
    accountCount++;
}

void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d, Name: %s, Balance: Rs.%.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void deposit() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully. New Balance: Rs.%.2f\n", accounts[i].balance);
            addTransaction("Deposit", accountNumber, amount);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully. New Balance: Rs.%.2f\n", accounts[i].balance);
                addTransaction("Withdraw", accountNumber, amount);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void transfer() {
    int fromAccount, toAccount;
    double amount;
    printf("Enter from account number: ");
    scanf("%d", &fromAccount);
    printf("Enter to account number: ");
    scanf("%d", &toAccount);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);

    Account *from = NULL, *to = NULL;

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == fromAccount) {
            from = &accounts[i];
        }
        if (accounts[i].accountNumber == toAccount) {
            to = &accounts[i];
        }
    }

    if (from && to) {
        if (from->balance >= amount) {
            from->balance -= amount;
            to->balance += amount;
            printf("Amount transferred successfully. New Balance of from account: Rs.%.2f\n", from->balance);
            addTransaction("Transfer", fromAccount, amount);
        } else {
            printf("Insufficient balance in from account.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void printHistory() {
    printf("Transaction History:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%s - Account Number: %d, Amount: Rs.%.2f\n", history[i].type, history[i].accountNumber, history[i].amount);
    }
}

void addTransaction(const char* type, int accountNumber, double amount) {
    if (transactionCount >= MAX_HISTORY) {
        printf("Transaction history is full.\n");
        return;
    }
    strcpy(history[transactionCount].type, type);
    history[transactionCount].accountNumber = accountNumber;
    history[transactionCount].amount = amount;
    transactionCount++;
}