#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

string AccountType;

struct Pill
{
   string Name;
   int Price;
   int Quantity;
};


void Login()
{ 
   //a function for logging into the account of a pharmacist or a deliverer
   
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


void ListOfMedications()
{ 
   // a function for displaying a list of all medications

   string Pills;
   ifstream PillsFile("pills.txt");

   if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

   while (getline(PillsFile, Pills))
   {
      cout << Pills << endl;
   }
   PillsFile.close();
}

void Stock()
{
   // function for viewing medicines in stock
   
   // Declaration of a nested function
   void StockLowest();
   void StockMost();
   void StockZero();
   void StockAmount();

   cout<< R"(
         1. Show the medicine with the lowest amount
         2. Show the medicine with the most
         3. Show medicine with an amount equal to 0
         4. Show all amounts of the medicine
      )";

   int OperationSelection;
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

   void StockLowest()
   {

      // function for withdrawal of the medicine with the least amount in stock

      ifstream PillsFfile("pills.txt");

      if(!PillsFile){
         cerr << "Failed to open pills.txt" << endl;
         return;
      }

      Pill minQuantityMedicine, medicine;
      minQuantityMedicine.Quantity = numeric_limits<int>::max();

      while (PillsFfile >> medicine.Name >> medicine.Price >> medicine.Quantity)
      {
         if (medicine.Quantity < minQuantityMedicine.Quantity)
         {
            minQuantityMedicine = medicine;
         }
      }

      PillsFfile.close();

      cout << "The medicine with the least amount:" << endl;
      cout << minQuantityMedicine.Name << " " << minQuantityMedicine.Quantity;
   }

   void StockMost()
   {

      // function for withdrawal of the medicine with the largest amount in stock

      ifstream PillsFfile("pills.txt");

      if(!PillsFile){
         cerr << "Failed to open pills.txt" << endl;
         return;
      }

      Pill maxQuantityMedicine, medicine;
      maxQuantityMedicine.Quantity = numeric_limits<int>::min();

      while (PillsFfile >> medicine.Name >> medicine.Price >> medicine.Quantity)
      {
         if (medicine.Quantity > maxQuantityMedicine.Quantity)
         {
            maxQuantityMedicine = medicine;
         }
      }
      PillsFfile.close();

      cout << "The medicine with the most amount:" << endl;
      cout << maxQuantityMedicine.Name << " " << maxQuantityMedicine.Quantity;
   }

   void StockZero()
   {

      // a function for the output of a medicine whose quantity is 0
      cout << "Medicine with an amount equal to 0: \n";
      ifstream PillsFile("pills.txt");

      if(!PillsFile){
         cerr << "Failed to open pills.txt" << endl;
         return;
      }

      Pill medicine;
      while (PillsFile >> medicine.Name >> medicine.Price >> medicine.Quantity)
      {
         if (medicine.Quantity == 0)
         {
            cout << medicine.Name << endl;
         }
      }
      PillsFile.close();
   }

   void StockAmount()
{
   // function for displaying the total number of medications 

   ifstream PillsFile("pills.txt");

   if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

   Pill medicine;
   int amount = 0;
   while (PillsFile >> medicine.Name >> medicine.Price >> medicine.Quantity)
   {
      amount += medicine.Quantity;
   }
   PillsFile.close();

   cout << "All amounts of the medicine: " << amount;
}

void Search()
{
   // drug search function

   cout << "Enter a search query: \n";
   string line, medicineName;
   cin >> medicineName;
   bool found = false;
   ifstream PillsFile("pills.txt");

   if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

   while (getline(PillsFile, line))
   {
      if (line.find(medicineName) != string ::npos)
      {
         cout << "Result: \n"<< line << endl;
         found = true;
      }
   }

   if (!found)
   {
      cout << "The medication was not found \n";
   }
   PillsFile.close();
}

void ChangePrice()
{
   // function for changing the price of medicines

   vector<Pill> pillsVector;
   Pill medicine;
   string pillName;
   int newPrice;
   bool found = false;

   cout << "Enter the name of the medicine whose price you want to change: ";
   cin >> pillName;
   cout << "Enter a new price: ";
   cin >> newPrice;

   ifstream file("pills.txt");

   if(!file){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

   while (file >> medicine.Name >> medicine.Price >> medicine.Quantity)
   {
      pillsVector.push_back(medicine);
   }
   file.close();

   for (auto &medicine : pillsVector)
   {
      if (medicine.Name == pillName)
      {
         medicine.Price = newPrice;
         found = true;
         break;
      }
   }

   ofstream outfile("pills.txt");
   for (const auto &medicine : pillsVector)
   {
      outfile << medicine.Name << " " << medicine.Price << " " << medicine.Quantity << endl;
   }
   outfile.close();
   if (!found)
   {
      cout << "The medication you were looking for was not found";
   }
   else
   {
      cout << "The price of the medicine has been successfully changed" << endl;
   }
}

void Order(){
   //function for ordering medicines

   Pill medicine;
   cout << "Write the name of the medicine: ";
   cin >> medicine.Name;
   cout << "Write the quantity for the order: ";
   cin >> medicine.Quantity;

   ofstream orderFile("supply_new.txt", ios::app);
   orderFile << endl << medicine.Name << " " << medicine.Quantity;
   orderFile.close();

   cout << "The information was successfully added to the file";
}

void Sell()
{
   // function for selling medicines

   string medicineName;
   int quantity;
   char discountChoice;
   double discount;
   char sellMoreChoice;
   do{

      cout << "Specify the name of the medicine for sale: ";
      cin >> medicineName;
      cout << "Specify the quantity: ";
      cin >> quantity;
      cout << "Is there a discount?(Y/N)";
      cin >> discountChoice;
      if (discountChoice == 'Y' || discountChoice == 'y')
      {
         cout << "Enter the discount percentage: ";
         cin >> discount;
      }
      else
      {
         discount = 0.0;
      }

      Pill medicine;
      bool found = false;
      ifstream PillsFile("pills.txt");

      if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

      while(PillsFile >> medicine.Name >> medicine.Price >> medicine.Quantity){
         if(medicine.Name == medicineName){
            found = true;
            if(medicine.Quantity < quantity){
               cerr << "Insufficient stock for " << medicineName << endl;
               PillsFile.close();
               return;
            }
            break;   
         }
      }
      PillsFile.close();

      if(!found){
         cerr << "Medicine not found: " << medicineName << endl;
         return;
      }

      Pill soldMedicine;
      ifstream PillsFile("pills.txt");

      if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
      }

      ofstream tempFile("temp.txt");
      while (PillsFile >> soldMedicine.Name >> soldMedicine.Price >> soldMedicine.Quantity)
      {
         if(soldMedicine.Name == medicineName){
            soldMedicine.Quantity -= quantity;
         }
         tempFile << soldMedicine.Name << " " << soldMedicine.Price << " " << soldMedicine.Quantity << endl;
      }

      PillsFile.close();
      tempFile.close();

      string pillsFileName = "pills.txt";
      string tempFileName = "temp.txt";
      remove(pillsFileName.c_str());
      rename(tempFileName.c_str(), pillsFileName.c_str());

      if(remove(pillsFileName.c_str()) != 0){
         cerr << "Failed to delete " << pillsFileName << endl;
         return;
      }

      if(rename(tempFileName.c_str(), pillsFileName.c_str()) != 0){
         cerr << "Failed to rename " << tempFileName << " to " << pillsFileName << endl;
         return;
      }
      
      ofstream SalesFile("sales.txt");

      time_t now = time(0);
      tm* localTime = localtime(&now);
      char dateTime[50];
      strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %h:%M:%S", localTime);

      double totalCost = (medicine.Price * quantity) * (1 - discount);
      SalesFile << medicine.Name << " " << medicine.Price << " " << quantity << " " << fixed << setprecision(2) << totalCost << " " << dateTime << endl;

      SalesFile.close();

      cout << "Medicine sold successfully!" << endl << "Sell more medicine? (Y/N): ";
      cin >> sellMoreChoice;

   }while(sellMoreChoice == 'Y' || sellMoreChoice == 'y');
}

void MedicineForDelivery(){
   // function for displaying a list of medicines for delivery

   Pill Medicine;
   ifstream PillsFile("pills.txt");

   if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
   }

   cout << "Ьedicines with zero quantity value in stock: \n";
   while(PillsFile >> Medicine.Name >> Medicine.Price >> Medicine.Quantity){
      if(Medicine.Quantity == 0){
         cout << Medicine.Name << endl;
      }
   }
   PillsFile.close();

   ifstream SupplyNewFile("supply_new.txt");

   if(!SupplyNewFile){
      cerr << "Failed to open supply_new.txt" << endl;
      return;
   }

   string Pills;
   while (getline(SupplyNewFile, Pills))
   {
      cout << Pills << endl;
   }
   SupplyNewFile.close();
}

void DeliveredMedicines(){
   // function for displaying a list of delivered medicines

   ifstream DeliveredMedicinesFile("delivered_farm.txt");

   if(!DeliveredMedicinesFile){
      cerr << "Failed to open delivered_farm.txt" << endl;
      return;
   }

   string Pills;
   while (getline(DeliveredMedicinesFile, Pills))
   {
      cout << Pills << endl;
   }
   DeliveredMedicinesFile.close();
}

void DeliverMedicine(){ 
   // function for drug delivery

   char deliverMoreChoice;
   do{
      string medicineName;
      int quantity;
      bool found = false;
      cout << "Please enter the name of the medicine to be delivered: \n";
      cin >> medicineName;
      cout << " Please write the quantity to be delivered: ";
      cin >> quantity;

      time_t now = time(0);
      tm* localTime = localtime(&now);
      char dateTime[50];
      strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", localTime);

      ofstream DeliverFile("delivered_farm.txt", ios::app);
      DeliverFile << medicineName << " " << quantity << " " << dateTime << endl;
      DeliverFile.close();

      Pill Medicine;
      ifstream PillsFile("pills.txt");

      if(!PillsFile){
      cerr << "Failed to open pills.txt" << endl;
      return;
      }

      ofstream TempFile("temp.txt");
      while(PillsFile >> Medicine.Name >> Medicine.Price >> Medicine.Quantity){
         if(Medicine.Name == medicineName){
            found = true;
            Medicine.Quantity += quantity;
         }
         TempFile << Medicine.Name << " " << Medicine.Price << " " << Medicine.Quantity << endl;
      }
      PillsFile.close();
      TempFile.close();

      string PillsFileName = "pills.txt", TempFileName = "temp.txt";
      remove(PillsFileName.c_str());
      rename(TempFileName.c_str(), PillsFileName.c_str());

      if(remove(PillsFileName.c_str()) != 0){
         cerr << "Failed to delete " << PillsFileName << endl;
         return;
      }

      if(rename(TempFileName.c_str(), PillsFileName.c_str()) != 0){
         cerr << "Failed to rename " << TempFileName << " to " << PillsFileName << endl;
         return;
      }

      if(!found){
         cout << "The desired medicine was not found \n";
         break;
      }
      cout << "Successfully delivered! \n Deliver more medicines?(Y/N): ";
      cin >> deliverMoreChoice;
   }while(deliverMoreChoice == 'y' || deliverMoreChoice == 'Y');
}

void Information(){
   // function for displaying general information about the program

   cout << R"(
      "Pharmacy automation".

The pharmacy automation program, to help pharmaceutical company employees and those who work in these companies, is designed to improve conditions for pharmacy workers, suppliers and customers. The program performs automatic calculations and calculations, automatically determines the shortage of a particular drug in the pharmacy. 

The users of the program are a pharmacist, a supplier. To access the program, you need to log in to your account using your username and password.

Note:
- In the files, the information is given in the format "Name of the medicine, price, quantity, time".
   )";
}


void Logout(){

   // function to exit the program

   cout << "The program is completed, we will be glad to see you back! \n";
}


int main()
{
   Login();
   int OperationSelection;
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

         0. Exit
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
         case 0:
            break;
         default:
            cout << "Please choose from the options provided.";
            break;
         }
      }
      else
      { // AccountType is Supplier
         cout << R"(
            Greetings dear Supplier! Please dial the menu number to work with the program, if finished, then dial 6:

         1. Show a list of the entire list of medicines from pharmacies
         2. Show the medicine required for delivery
         3. Deliver the medicine
         4. Show the delivered medicines
         5. Show information about the program

         0. Exit
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
         case 0:
            break;
         default:
            cout << "Please choose from the options provided.";
            break;
         }
      }
   } while (OperationSelection != 0);

   Logout();
   return 0;
}