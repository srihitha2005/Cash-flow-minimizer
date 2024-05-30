# Cashflow Minimizer
=====================

This repository contains a simple console application that helps a group of people settle their debts with the minimum number of transactions. The application uses a graph-based approach to calculate the minimum cashflow between people.

## Features

* Calculates the minimum cashflow between people based on their transactions
* Displays the transactions required to settle the debts

## Requirements

* A C++ compiler to build and run the application

## Building the Application

### Step 1: Save the source code

Save the provided source code in a file named `main.cpp`

### Step 2: Build the application

Use a C++ compiler to build the application. For example, with `g++`:

``g++ -o cashflow main.cpp``


## Running the Application

### Step 1: Run the application

Run the compiled application:

``./cashflow``


### Step 2: Follow the prompts

Follow the prompts to enter the number of people, their names, and the transactions between them

### Step 3: View the results

The application will display the final transactions required to settle the debts

## Code Overview

The code is structured as follows:

### `getNetAmounts`

Calculates the net amount each person has to pay or receive

### `minCashflowRec`

Recursive function to calculate the minimum cashflow

### `minCashflow`

Main function to calculate the minimum cashflow and display the transactions

### `main`

The entry point of the application, handles user input and output

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
