/**
 * @file main.cpp
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-03-28
 * @brief manages the movie database
 * 
 * 
 */

#include "library.h"
#include <iostream>

using namespace std;

int main() {
  
  Library movieList; //Library class that manages the database 



  int choice = 0; // the users menu choice

  string filename, directorName, movieName;

  //welcome message and loads the data from a file 
  cout << "Welcome to your movie database! Please enter the name of the file you would like to open: ";
  cin >> filename;

  movieList.loadFromFile(filename);

  //this is the menu and all the options for the user
  while(true){
    cout << "Now chose from the following options: " << endl;//user enters the number
    //associated with the option they want to select
    cout << "(1) Read Movies from file " << endl;
    cout << "(2) Write Movies to file " << endl;
    cout << "(3) Display all movies " << endl;
    cout << "(4) Search for title of movie " << endl;
    cout << "(5) Search for director of movie " << endl;
    cout << "(6) Remove movie entry " << endl;
    cout << "(7) Exit this program " << endl;
    cout << "Please enter your choice now: ";

    //takes user input for the choice 
    cin >> choice;
    cout << endl;

    //based on user choice methods below are documented in library.h file
    //after a choice is made, a statement then follows for a user to answer for input 
    if(choice == 1){
      cout << endl;
      cout << "Enter the file name to read from (Ex. test.txt): ";
      cin >> filename;
      movieList.loadFromFile(filename);
    }
    else if(choice == 2){
      cout << "Enter the file name to write to: ";
      cin >> filename;
      movieList.storeToFile(filename);
    }
    else if(choice == 3){
      cout << "====== Movie List ======" << endl;
      movieList.displayAll();
    }
    else if(choice == 4){
      cout << "Please enter name of movie: ";
      cin.ignore();
      getline(cin, movieName);
      movieList.findMovie(movieName);
    }
    else if(choice == 5){
      cout << "Please enter name of director (capitalization matters): ";
      cin.ignore();
      getline(cin, directorName);
      movieList.directorSearch(directorName);
      cout << endl;
    }
    else if(choice == 6){
      cout << "Please enter name of movie to remove: ";
      cin.ignore();
      getline(cin, movieName);
      movieList.remove(movieName);
    }
    else if(choice == 7){
      cout << "Exiting program. " << endl;
      break;
    }
    // prints if user does not input a number 1-7 
    else{
      cout << "Invalid choice, please enter a number 1-7: ";
    }

    cout << endl;
    
  }
  return 0;
}
