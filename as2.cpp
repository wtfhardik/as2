#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
class PHARMACY {
private:
 string addMed[50];
 int count;
public:
 PHARMACY() : count(0) {}
 void addingmedicine() {
 cout << "<===Welcome to Pharmacy Management===>" << endl;
 for (int i = 0; i < 50; i++) {
 cout << "Enter medicine's name which you want to add: ";
 getline(cin, addMed[i]);
 count++;
 cout << "Do you want to add more medicines? Enter 1 for yes, 0 for no:
";
 int choice;
 cin >> choice;
 cin.ignore(); // Clear input buffer
 if (choice == 0) {
 cout << "Terminating medicine addition process." << endl;
 break;
 }
 }
 cout << "Medicines added in the array are:" << endl;
 for (int i = 0; i < count; i++) {
 cout << addMed[i] << endl;
 }
 }
 void removingmed() {
 cout << "<===Welcome to Pharmacy Management===>" << endl;
 cout << "Do you want to remove the last added medicine? Enter 1 for yes and
0 for no: ";
 int rem;
 cin >> rem;
 if (rem == 1) {
 if (count > 0) {
 count--;
 cout << "Recently added medicine has been removed." << endl;
 } else {
 cout << "No medicines to remove." << endl;
 }
 }
 }
 void updateStockLevel() {
 cout << "<===Welcome to Pharmacy Management===>" << endl;
 cout << "Stock level updated successfully!" << endl;
 }
};
class ADMIN : public PHARMACY {
private:
 string details[3];
public:
 void addingpatientrecords() {
 cout << "<===Welcome to Admin Department===>" << endl;
 cout << "Enter the Name of the patient: ";
 getline(cin, details[0]);
 cout << "Enter the Blood group of the patient: ";
 getline(cin, details[1]);
 cout << "Enter the Age of the patient: ";
 getline(cin, details[2]);
 cout << "Patient details recorded successfully." << endl;
 }
};
class BILLING : public ADMIN {
private:
 int amountok[10];
 int rA;
 int count1;
 string items[15];
public:
 BILLING() : rA(0), count1(0) {}
 void generateBill() {
 cout << "<===Welcome to Billing Department===>" << endl;
 for (int i = 0; i < 15; i++) {
 cout << "Enter the item's name you want to add: ";
 getline(cin, items[count1]);
 count1++;
 cout << "Add another item? Enter 1 for yes and 0 for no: ";
 int choice1;
 cin >> choice1;
 cin.ignore(); // Clear input buffer
 if (choice1 == 0) {
 break;
 }
 }
 cout << "Generating bill:" << endl;
 int sum = 0;
 for (int i = 0; i < count1; i++) {
 int rand_int1 = rand() % 100;
 cout << "Item's name: " << items[i] << ", Item's price: " << rand_int1
<< endl;
 sum += rand_int1;
 }
 cout << "Total bill/price generated: " << sum << endl;
 amountok[rA] = sum;
 rA++;
 recordPayment();
 }
 void recordPayment() {
 cout << "Recorded payments:" << endl;
 for (int i = 0; i < rA; i++) {
 cout << "Payment " << (i + 1) << ": " << amountok[i] << endl;
 }
 }
};
class ResearchAndDevelopment {
public:
 void doingfasttest() {
 cout << "<===Welcome to Research And Development Management===>" << endl;
 string feverInput, coughInput, breathingInput;
 cout << "Please answer the following questions with 'yes' or 'no':" <<
endl;
 cout << "Do you have fever? ";
 getline(cin, feverInput);
 cout << "Do you have cough? ";
 getline(cin, coughInput);
 cout << "Do you have difficulty breathing? ";
 getline(cin, breathingInput);
 bool hasFever = feverInput == "yes";
 bool hasCough = coughInput == "yes";
 bool hasBreathingDifficulty = breathingInput == "yes";
 if (hasFever || hasCough || hasBreathingDifficulty) {
 cout << "You are advised to get tested for COVID-19." << endl;
 } else {
 cout << "Your symptoms do not indicate COVID-19." << endl;
 }
 cout << "Do you want to check the probability of the virus spreading? Enter
1 for YES or 0 for NO: ";
 int probability;
 cin >> probability;
 cin.ignore(); // Clear input buffer
 if (probability == 1) {
 calculateRiskProbability();
 }
 }
 void calculateRiskProbability() {
 cout << "Calculating risk probability..." << endl;
 int risk = rand() % 100;
 cout << "According to the checks, the risk of spreading the virus is: " <<
risk << "%" << endl;
 }
};
class ThirdPartyInsurance : public ResearchAndDevelopment {
public:
 void insuranceprocess() {
 cout << "<===Welcome to Third Party Insurance Management===>" << endl;
 verifyInsurance();
 cout << "If your ID gets approved, enter 1. If your ID gets rejected, enter
0: ";
 int ver;
 cin >> ver;
 if (ver == 1) {
 cout << "Your insurance claim has been approved." << endl;
 } else if (ver == 0) {
 cout << "Your insurance claiming process has been terminated because
your ID was rejected." << endl;
 } else {
 cout << "Invalid input." << endl;
 }
 }
 void verifyInsurance() {
 cout << "To check your insurance ID, enter your ID: ";
 string iD;
 getline(cin, iD);
 bool isIdApproved = rand() % 2;
 if (isIdApproved) {
 cout << "Your ID has been approved." << endl;
 } else {
 cout << "Your ID has been rejected." << endl;
 }
 }
};
int main() {
 srand(time(nullptr));
 bool continueLooping = true;
 while (continueLooping) {
 cout << "******************************************\n";
 cout << "* 𓆩WELCOME TO HP HOSPITAL SYSTEM 𓆩 *\n";
 cout << "* (COVID-19) *\n";
 cout << "******************************************\n";
 int choice;
 cout << "WHICH CLASS DO YOU WANT TO ACCESS? ENTER ITS SEQUENTIAL
NUMBER:" << endl;
 cout << "1. Inventory management (Pharmacy)" << endl;
 cout << "2. Hospital patient record management (Admin)" << endl;
 cout << "3. Billing departmentdepartment management (Billing)" << endl;
 cout << "4. COVID identification and probability (R&D)" << endl;
 cout << "5. Insurance management (Third party)" << endl;
 cout << "6. Exit" << endl;

 cout << "Which option do you want to choose? Enter the number: ";
 cin >> choice;
 cin.ignore(); // Clear input buffer

 switch (choice) {
 case 1: {
 PHARMACY pharmacy;
 pharmacy.addingmedicine();
 pharmacy.removingmed();
 pharmacy.updateStockLevel();
 break;
 }
 case 2: {
 ADMIN admin;
 admin.addingpatientrecords();
 break;
 }
 case 3: {
 BILLING billing;
 billing.generateBill();
 break;
 }
 case 4: {
 ResearchAndDevelopment rnd;
 rnd.doingfasttest();
 break;
 }
 case 5: {
 ThirdPartyInsurance tpi;
 tpi.insuranceprocess();
 break;
 }
 case 6: {
 continueLooping = false;
 cout << "Exiting the program. Goodbye!" << endl;
 break;
 }
 default: {
 cout << "Invalid choice. Please enter a number between 1 and 6." <<
endl;
 break;
 }
 }
 if (continueLooping) {
 cout << endl;
 cout << "Do you want to go to another department?" << endl;
 cout << "1. Yes" << endl;
 cout << "2. No, Exit the program" << endl;
 int option;
 cin >> option;
 cin.ignore(); // Clear input buffer
 if (option == 2) {
 continueLooping = false;
 cout << "Exiting the program. Goodbye!" << endl;
 }
 }
 }
 return 0;
}