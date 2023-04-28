#include <iostream>

using namespace std;

void Login()
{
   string Account_Type = "0", Name = "0", Password = "0";
   cout << "Для запуска программы, пожалуйста введите тип аккаунта, логин и пароль:";
   while ((Account_Type != "Farmworker" && Name != "Farmworker1" && Password != "FarmworkerPassword") || (Account_Type != "Supplier" && Name != "Supplier1" && Password != "SupplierPassword"))
   {
      cout << "Тип аккаунта: ";
      cin >> Account_Type;
      cout << "Логин: ";
      cin >> Name;
      cout << "Пароль: ";
      cin >> Password;
      cout << "Извините, но мы не нашли такой тип аккаунта или у вас неправильно введены логин и/или пароль пожалуйста повторите.\n";
   }
}

int main()
{
   Login();
   return 0;
}