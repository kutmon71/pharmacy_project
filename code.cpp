#include <iostream>

using namespace std;

string AccountType;

void Login()
{
   string Name, Password;
   cout << "To start the program, please enter your username and password: \n";
   while (true)
   {
      cout << "Login: ";
      cin >> Name;
      cout << "Password: ";
      cin >> Password;
      if (Name == "Farmworker1" && Password == "FarmworkerPassword")
      {
         AccountType = "Farmworker";
         break;
      }
      else if (Name == "Supplier1" && Password == "SupplierPassword")
      {
         break;
      }
      else
      {
         cout << "Sorry, but we did not find this type of account, your username and/or password were entered incorrectly, please try again.\n";
      }
   }
}

void Menu()
{
   if (AccountType == "Farmworker")
   {
      cout << R"(
         Greetings dear Pharmacist! Please dial the menu number to work with the program, if finished, then dial 8:

      1. Search for medicines
      2. Show the full list of medications
      3. Change the price for the medicine
      4. Sell the medicine
      5. Show the stock of medicines
      6. Order medicine
      7. Show information about the program 
      8. Exit
      )";
   }
   else
   { // that mean AccountType is Supplier
      cout << R"(
         Greetings dear Supplier! Please dial the menu number to work with the program, if finished, then dial 6:

      1. Show a list of the entire list of medicines from pharmacies
      2. Show the medicine required for delivery
      3. Deliver the medicine
      4. Show the delivered medicines
      5. Show information about the program
      6. Exit
      )";
   }
}

int main()
{
   Login();
   Menu();
   return 0;
}