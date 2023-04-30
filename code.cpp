#include <iostream>

using namespace std;

void Login()
{
   string AccountType, Name, Password;
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
         AccountType = "Supplier1";
         break;
      }
      else
      {
         cout << "Sorry, but we did not find this type of account, your username and/or password were entered incorrectly, please try again.\n";
      }
   }
}

int main()
{
   Login();
   return 0;
}