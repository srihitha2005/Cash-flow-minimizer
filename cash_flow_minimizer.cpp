#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_PEOPLE = 100;

vector<int> getNetAmounts(const vector<vector<int>>& transactionGraph) {
    vector<int> netAmounts(transactionGraph.size(), 0);
    for (int i = 0; i < transactionGraph.size(); i++) {
        for (int j = 0; j < transactionGraph.size(); j++) {
            netAmounts[i] += transactionGraph[j][i] - transactionGraph[i][j];
        }
    }
    return netAmounts;
}

void minCashflowRec(vector<int>& netAmounts, const vector<string>& people) {
    int maxCreditor = max_element(netAmounts.begin(), netAmounts.end()) - netAmounts.begin();
    int maxDebtor = min_element(netAmounts.begin(), netAmounts.end()) - netAmounts.begin();
    if (netAmounts[maxCreditor] == 0 && netAmounts[maxDebtor] == 0) {
        return;
    }
    int minVal = min(-netAmounts[maxDebtor], netAmounts[maxCreditor]);
    netAmounts[maxCreditor] -= minVal;
    netAmounts[maxDebtor] += minVal;
    cout << "\n" << people[maxDebtor] << " will pay " << minVal << " to " << people[maxCreditor] << endl;
    minCashflowRec(netAmounts, people);
}

void minCashflow(const vector<vector<int>>& transactionGraph, const vector<string>& people) {
    vector<int> netAmounts = getNetAmounts(transactionGraph);
    minCashflowRec(netAmounts, people);
}

int main() {
    cout << "\t\t\t*********" << "Welcome to Cashflow minimizer" << "*********" << endl;
    cout << "\t\t************" << "Settle your debts with minimum number of Transaction." << "************" << endl;
    cout << "\nEnter no. of people: ";
    int n;
    cin >> n;
    if (n > MAX_PEOPLE) {
        cout << "Error: Maximum number of people exceeded." << endl;
        return 1;
    }
    vector<vector<int>> transactionGraph(n, vector<int>(n, 0));
    vector<string> people(n);
    cout << "Enter names of people" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter name#" << i + 1 << ": ";
        cin >> people[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            cout << "How much " << people[i] << " has to pay " << people[j] << "?   ";
            cin >> transactionGraph[i][j];
        }
    }
    cout << "\n\t\t********************<<<-FINAL TRANSACTIONS TO BE MADE ARE->>>***************\n";
    minCashflow(transactionGraph, people);
    return 0;
}
