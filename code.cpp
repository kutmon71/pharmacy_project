#include <iostream>
#include <fstream>
#include <limits>
#include <string>


using namespace std;

string AccountType;
int OperationSelection;

struct Pill{
   string Name;
   int Price;
   int Quantity;
};

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
   cin >> OperationSelection;
   do
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

         switch (OperationSelection)
         {
            case 1:
               Search();
               break;
            case 2:
               ListOfMedications();
               break;
            case 3:
               ChangePrice();
               break;
            case 4:
               Sell();
               break;
            case 5:
               Stock();
               break;
            case 6:
               Order();
               break;
            case 7:
               Information();
               break;
            case 8:
               break;
            default:
               cout << "Please choose from the options provided.";
               break;
         }
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

         switch (OperationSelection)
         {
            case 1:
               ListOfMedications();
               break;
            case 2:
               MedicineForDelivery();
               break;
            case 3:
               DeliverMedicine();
               break;
            case 4:
               DeliveredMedicines();
               break;
            case 5:
               Information();
               break;
            case 6:
               break;
            default:
               cout << "Please choose from the options provided.";
               break;
         }
      }
   } while (OperationSelection != 8);
}

void ListOfMedications(){
   string Pills;
   ifstream PillsFile("pills.txt");
   while (getline (PillsFile, Pills)){
      cout << Pills << endl;
   }
   PillsFile.close();
}

void Stock(){/
      cout << R"(
         1. Show the medicine with the lowest amount
         2. Show the medicine with the most
         3. Show medicine with an amount equal to 0
         4. Show all amounts of the medicine
      )";
      cin >> OperationSelection;
      switch (OperationSelection)
      {
      case 1:
         StockLowest();
         break;
      case 2:
         StockMost();
         break;
      case 3:
         StockZero;
         break;
      case 4:
         StockAmount;
         break; 
      default:
         break;
      }
}

void StockLowest(){
   ifstream PillsFfile("pills.txt");
   Pill minQuantityMedicine, medicine;
   minQuantityMedicine = numeric_limits<int>::max();

   while(PillsFfile >> medicine.Name >> medicine.Price >> medicine.Quantity){
      if(medicine.Quantity < minQuantityMedicine.Quantity){
         minQuantityMedicine = medicine;
      }
   }

   PillsFfile.close();

   cout << "The medicine with the least amount:" << endl;
   cout << minQuantityMedicine.Name << " " << minQuantityMedicine.Quantity;
}

void StockMost(){
   ifstream PillsFfile("pills.txt");
   Pill maxQuantityMedicine, medicine;
   maxQuantityMedicine = numeric_limits<int>::min();

   while(PillsFfile >> medicine.Name >> medicine.Price >> medicine.Quantity){
      if(medicine.Quantity > maxQuantityMedicine.Quantity){
         maxQuantityMedicine = medicine;
      }
   }
   PillsFfile.close();

   cout << "The medicine with the most amount:" << endl;
   cout << maxQuantityMedicine.Name << " " << maxQuantityMedicine.Quantity;
}

void StockZero(){
   cout << "Medicine with an amount equal to 0: \n";
   ifstream PillsFile("pills.txt");
   Pill medicine;
   while(PillsFile >> medicine.Name >> medicine.Price >> medicine.Quantity){
      if(medicine.Quantity == 0){
         cout << medicine.Name << endl;
      }
   }
   PillsFile.close();
}

void StockAmount(){
   ifstream PillsFile("pills.txt");
   Pill medicine;
   int amount = 0;
   while(PillsFfile >> medicine.Name >> medicine.Price >> medicine.Quantity){
      amount += medicine.Quantity;
   }
   PillsFile.close();

   cout << "All amounts of the medicine: " << amount;
}

int main()
{
   Login();
   Menu();
   Logout();
   return 0;
}