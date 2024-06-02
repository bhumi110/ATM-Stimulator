# ATM-Stimulator
ATM Stimulator is a C language-based program that will help you manage your account balance more efficiently with simple steps. It involves implementing various functionalities such as checking balances, withdrawing, depositing, transferring funds between accounts, and maintaining transaction history. 

# Explanation:

1. Data Structures : 
- `Account` structure stores the details of an account.
- `Transaction` structure stores details of a transaction.

3. Global Variables :
- `accounts` array holds all accounts.
- `history` array holds transaction history.
- `accountCount` keeps track of the number of accounts.
- `transactionCount` keeps track of the number of transactions.

4. Functions :
- `createAccount()`: Creates a new account.
- `checkBalance()`: Checks the balance of a given account.
- `deposit()`: Deposits money into an account.
- `withdraw()`: Withdraws money from an account.
- `transfer()`: Transfers money between two accounts.
- `printHistory()`: Prints the transaction history.
- `addTransaction()`: Adds a transaction to the history.
