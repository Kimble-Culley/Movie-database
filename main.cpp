/**
 * @file main.cpp
 * @author Kimble Culley
 * @date 2024-03-28
 * @brief idk
 * 
 * idk
 */

#include "library.h"
#include <iostream>

using namespace std;

int main() {
  
  Library movieList;



  int choice = 0;

  string filename, directorName, movieName;


  cout << "Welcome to your movie database! Please enter the name of the file you would like to open: ";
  cin >> filename;

  movieList.loadFromFile(filename);

  while(true){
    cout << "Now chose from the following options: " << endl;
    cout << "(1) Read Movies from file " << endl;
    cout << "(2) Write Movies to file " << endl;
    cout << "(3) Display all movies " << endl;
    cout << "(4) Search for title of movie " << endl;
    cout << "(5) Search for director of movie " << endl;
    cout << "(6) Remove movie entry " << endl;
    cout << "(7) Exit this program " << endl;
    cout << "Please enter your choice now: ";

    cin >> choice;
    cout << endl;

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
    else{
      cout << "Invalid choice, please enter a number 1-7: ";
    }

    cout << endl;
    
  }
  return 0;
}
