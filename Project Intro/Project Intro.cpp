// Project Intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
string character = "e";    //global deceleration as we will use it in the whole program
void input(string ID[50], double price[50]) {
    cout << "Please enter 'e' in the ID if you want to exit " << endl;
    for (int counter = 0; counter < 50; counter++) { 
        if (!ID[counter].empty()) {             //to continue on the old array if we used the function more than one time
            continue;
        }
        cout << "Enter the item's ID ";
        cin >> ID[counter];
        if (ID[counter] == character) {        //if the user entered "e" 
            ID[counter].clear();               //we delete the "e" from the array
            break;
        }
        cout << "Enter the item's price ";
        cin >> price[counter];
        cout << endl << endl;
    }
}
void retrieve(string ID[50], double price[50]) {
    double x = 0;
    string z = "t";             //intializing a value of z to enter the while condition
    while (z != character) {
        cout << "Enter the item's ID ";
        cin >> z;
        if (ID[0].empty()) {            //if the array is empty apply a message 
            cout << "Nothing to retrieve ";
        }
        for (int j = 0; j < 50; j++) {
            if (z == character) {           //if the user enters "e" then he wants to exit the function
                break;
            }
            else if (ID[j] == z) {          //searching for the index of the crray that equals his input
                x = price[j];
                cout << "The price of your item is " << x;
            }
        }
        cout << endl << endl;
    }
}
void display(string ID[50], double price[50]) {
    double x, y;
    cout << "Enter your item's Price range ";
    cin >> x >> y;
    for (int counter = 0; counter < 50; counter++) {
        if (ID[counter].empty()) {                  //if the array is empty at the index(counter) of the array don't continue
            break;                                  //because if the index is empty the rest of the array will be empty
        }
        if (price[counter] >= x && price[counter] <= y) {   //to check if the index of the array is between the range
            cout << "The ID of the item is " << ID[counter] << endl;
            cout << "The price of the item is " << price[counter] << endl << endl;
        }
    }
}
void Delete(string ID[50], double price[50]) {
    string s;
    cout << "Which item you want to delete ? ";
    cin >> s;
    for (int i = 0; i < 50; i++) {
        if (ID[i] == s)                 //we are searching for the index of the array that equals the input
        {
            for (int j = i; j < 50; j++) {
                if (ID[j].empty()) {           //if the array is empty do not continue
                    break;
                }
                ID[j] = ID[j + 1];            //We are shifting the data in the array
                price[j] = price[j + 1];
            }
        }
    }
    cout << "The New Array is:" << endl;
    for (int i = 0; i < 50; i++) {
        if (ID[i].empty()) {
            break;                      //if the array is empty do not continue
        }
        cout << ID[i] << "\t";
        cout << price[i] << endl;
    }
}
void displayall(string ID[50], double price[50]) {
    string min_ID;
    double min_price;
    for (int j = 0; j < 50; j++) {
        if (ID[j].empty()) {            //if the array is empty do not continue
            break;
        }

        for (int k = j + 1; k < 50; k++) {
            if (ID[k].empty()) {            //if the array is empty do not continue
                break;
            }
            min_ID = ID[j];                 //using a new variable for swaping to sort the array
            min_price = price[j];
            if (min_price > price[k]) {     //if the price is greater than the following price 
                ID[j] = ID[k];              //swap them to display it in an ascending order
                ID[k] = min_ID;
                price[j] = price[k];
                price[k] = min_price;
            }
        }
    }
    for (int counter = 0; counter < 50; counter++) {
        if (ID[counter].empty()) {          ////if the array is empty do not continue
            break;
        }
        cout << "The ID of the item is " << ID[counter] << endl;
        cout << "The price of the item is " << price[counter] << endl << endl;
    }
}
void Deleteall(string ID[50], double price[50]) {
    for (int i = 0; i < 50; i++) {
        ID[i].clear();          //we use clear() delete the items in the array
    }
    cout << "All items deleted successfully " << endl;
}
int main()
{
    string ID[50];
    double price[50];
    char choice;
    cout << "Enter 1 If you want to Enter an item ID and price " << endl;
    cout << "Enter 2 If you want to Retrieve the price of a specific item " << endl;
    cout << "Enter 3 If you want to Display all items within a specific range of prices " << endl;
    cout << "Enter 4 If you want to Delete an item " << endl;
    cout << "Enter 5 If you want to Display all items " << endl;
    cout << "Enter 6 If you want to Delete all items " << endl;
    cout << "Enter \"e\" to exit " << endl;
    cin >> choice;
    //while (choice >= 1 && choice <= 6) {
    while(choice != 'e') {
        if (choice == 1) {
            input(ID, price);
        }
        else if (choice == 2) {
            retrieve(ID, price);
        }
        else if (choice == 3) {
            display(ID, price);
        }
        else if (choice == 4) {
            Delete(ID, price);
        }
        else if (choice == 5) {
            displayall(ID, price);
            if (ID[0].empty()) {            //if the array is empty we will apply a message
                cout << "There is no item to display " << endl;
            }
        }
        else if (choice == 6) {
            Deleteall(ID, price);
        }
        else {
            cout << "Please Enter one of the number between 1 and 6 or Enetr 0 to exit ";
            cin >> choice;
        }
        cout << "Would you like to enter another thing ? ";
        cin >> choice;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
