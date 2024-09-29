#include <iostream>
#include <set>
#include <map>
using namespace std;

// Comparator class to order persons based on their net balance
class person_compare
{
public:
   // Mark operator() as const
   bool operator()(pair<string, int> p1, pair<string, int> p2) const
   {
      return p1.second < p2.second; // Sort by amount (ascending)
   }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int no_of_transactions, friends;
   cin >> no_of_transactions >> friends;

   string x, y;
   int amount;
   map<string, int> net; // To keep track of the net balance of each person

   // Input transactions
   while (no_of_transactions--)
   {
      cin >> x >> y >> amount;

      if (net.count(x) == 0)
      {
         net[x] = 0;
      }
      if (net.count(y) == 0)
      {
         net[y] = 0;
      }

      net[x] -= amount; // x owes money
      net[y] += amount; // y gets money
   }

   // Insert persons with non-zero balances into the multiset
   multiset<pair<string, int>, person_compare> m;

   for (auto p : net)
   {
      string person = p.first;
      int balance = p.second;
      if (balance != 0)
      {
         m.insert(make_pair(person, balance));
      }
   }

   // Settlement process
   int cnt = 0; // Count of transactions
   while (!m.empty())
   {
      auto low = m.begin();      // Person with max debit (lowest balance)
      auto high = prev(m.end()); // Person with max credit (highest balance)

      int debit = low->second;
      string debit_person = low->first;

      int credit = high->second;
      string credit_person = high->first;

      // Remove them from the set
      m.erase(low);
      m.erase(high);

      // Settle the amount between debit and credit
      int settled_amount = min(-debit, credit); // Min of debit or credit
      debit += settled_amount;
      credit -= settled_amount;

      // Print the transaction
      cout << debit_person << " will pays " << settled_amount << " to " << credit_person << endl;

      // If any balance remains, reinsert them into the set
      if (debit != 0)
      {
         m.insert(make_pair(debit_person, debit));
      }
      if (credit != 0)
      {
         m.insert(make_pair(credit_person, credit));
      }

      cnt++; // Count each transaction
   }

   // Output the number of transactions
   cout << cnt << endl;

   return 0;
}
