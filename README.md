# Transaction Settlement Program

This program helps to minimize the number of transactions required to settle debts among friends after multiple transactions. It uses a `multiset` to track and settle balances efficiently.

## Features

- Calculates the net balance for each person after a series of transactions.
- Minimizes the number of transactions required to settle all debts.
- Outputs the transactions needed for settlement.

---

## How It Works

1. **Input Transactions**:
   - The program takes the number of transactions and friends as input.
   - It records each transaction where one person pays another a certain amount.

2. **Net Balances**:
   - It calculates the net balance of each person. Positive balance means the person is owed money, while negative balance means the person owes money.

3. **Settlement**:
   - Using a `multiset` with a custom comparator, the program identifies the person with the highest debit and the one with the highest credit.
   - It settles the smaller of the two amounts between these two persons and adjusts their balances.
   - The process continues until all balances are zero.

4. **Output**:
   - Each transaction is printed in the format: `<debtor> will pay <amount> to <creditor>`.
   - The total number of transactions required is also printed.

---

## Input Format

1. The first line contains two integers:
   - `no_of_transactions`: The number of transactions.
   - `friends`: The number of friends involved.

2. The next `no_of_transactions` lines contain:
   - `x`: The name of the person paying the money.
   - `y`: The name of the person receiving the money.
   - `amount`: The amount of money paid.

---

## Output Format

1. Transactions in the format:
