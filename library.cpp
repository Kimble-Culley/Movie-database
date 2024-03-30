/**
 * @file library.cpp
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-03-28
 * @brief Implementation of Library Class
 * 
 * This file handles the loading, storing, and manipulation of the movie data. 
 */

#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library(){
}




void Library::loadFromFile(string filename){
  //opens file for reading 
  ifstream file(filename);
  // checks if file opened correctly
  if(!file.is_open()){
    cerr << "Error: unable to open file: " << filename << endl;
    return;
  }

  cout << "File opened!" << endl;
  // stores movie details read from the file 
  string title, directorName, format, line;
  int runtime, year;
  float price;

  // reads the details until end of file 
  while(getline(file, title) && getline(file, directorName) && file >> runtime && getline(file >> ws, format) && file >> price && file >> year){
    file.ignore();
    // creates Movie object with the movie details that were read 
    Movie movie = {title, directorName, runtime, format, price, year};
    // inserts movie into library in order by title 
    insertSorted(movie);
  }
  file.close();
}



void Library::insertSorted(Movie movie){
  list<Movie>::iterator it = movieList.begin();
  // goes through movie list until end or a movie with a title that is greater(ascii) than input is found
  while (it != movieList.end() && it -> title < movie.title){
    it++;//moves to next movie 
  }
  //inserts input movie 
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
    // checks if movie is directed by the same director
    if(it -> directorName == directorName){
      //shows movie details
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
  bool found = false; // shows if there is a movie that matches the query 
  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++) {
    // checks if movie includes query string
    if(it -> title.find(query) != string::npos){
      found = true;
      // shows movie details
      cout << "Title: " << it -> title << endl;
      cout << "Director: " << it -> directorName << endl;
      cout << "Runtime; " << it -> runtime << " minutes" << endl;
      cout << "format: " << it -> format << endl;
      cout << "Price: $" << it -> price << endl;
      cout << "Year: " << it -> year << endl << endl;
    }
  }
  // if no movie is found that matches the query
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
  //opens the file for writing 
  ofstream file(filename);
  //makes sure file opened correctly 
  if(!file.is_open()){
    cerr << "Error Unable to open file: " << filename << " for writing" << endl;
    return;
  }
  //goes through movie list using an iterator 
  for(list<Movie>::iterator it = movieList.begin(); it != movieList.end(); it++){
    //writes movie details to file
    file << it -> title << endl;
    file << it -> directorName << endl;
    file << it -> runtime << endl;
    file << it -> format << endl;
    file << it -> price << endl;
    file << it -> year << endl;
  }
  
  file.close();

}
