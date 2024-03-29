/**
 * @file library.cpp
 * @author Kimble Culley
 * @date 2024-03-28
 * @brief idk
 * 
 * idk
 */

#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library(){
}


void Library::loadFromFile(string filename){
  ifstream file(filename);
  if(!file.is_open()){
    cerr << "Error: unable to open file: " << filename << endl;
    return;
  }

  cout << "File opened!" << endl;
  string title, directorName, format, line;
  int runtime, year;
  float price;

  while(getline(file, title) && getline(file, directorName) && file >> runtime && getline(file >> ws, format) && file >> price && file >> year){
    file.ignore();
    Movie movie = {title, directorName, runtime, format, price, year};
    insertSorted(movie);
  }
  file.close();
}

void Library::insertSorted(Movie movie){
  list<Movie>::iterator it = movieList.begin();
  while (it != movieList.end() && it -> title < movie.title){
    it++;
  }
  movieList.insert(it,movie);
}

void Library::displayAll(){
  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++){
    cout << "Title: " << it -> title << endl;
    cout << "Director: " << it -> directorName << endl;
    cout << "Runtime; " << it -> runtime << " minutes" << endl;
    cout << "format: " << it -> format << endl;
    cout << "Price: $" << it -> price << endl;
    cout << "Year: " << it -> year << endl << endl;
  }
}

void Library::directorSearch(string directorName){
  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++){
    if(it -> directorName == directorName){
      cout << "Title: " << it -> title << endl;
      cout << "Director: " << it -> directorName << endl;
      cout << "Runtime; " << it -> runtime << " minutes" << endl;
      cout << "format: " << it -> format << endl;
      cout << "Price: $" << it -> price << endl;
      cout << "Year: " << it -> year << endl << endl;
    }
  }
}
void Library::remove(string title){
  movieList.remove_if([&title](Movie& movie){return movie.title == title; });
}

void Library::findMovie(string query){
  bool found = false;
  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++) {
    if(it -> title.find(query) != string::npos){
      found = true;
      cout << "Title: " << it -> title << endl;
      cout << "Director: " << it -> directorName << endl;
      cout << "Runtime; " << it -> runtime << " minutes" << endl;
      cout << "format: " << it -> format << endl;
      cout << "Price: $" << it -> price << endl;
      cout << "Year: " << it -> year << endl << endl;
    }
  }
  if(!found){
    cout << "No movie found, please check spelling." << endl;
    return;
  }
}

void Library::pushFront(Movie movie){
  movieList.push_front(movie);
}

void Library::pushBack(Movie movie){
  movieList.push_back(movie);
}

void Library::storeToFile(string filename){
  ofstream file(filename);
  if(!file.is_open()){
    cerr << "Error Unable to open file: " << filename << " for writing" << endl;
    return;
  }

  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++){
    file << it -> title << endl;
    file << it -> directorName << endl;
    file << it -> runtime << endl;
    file << it -> format << endl;
    file << it -> price << endl;
    file << it -> year << endl;
  }
  
  file.close();

}
