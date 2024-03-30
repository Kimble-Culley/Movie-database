/**
 * @file library.h
 * @author Kimble Culley and Sydney Marshall
 * @date 2024-03-28
 * @brief contains Library class that manages the collection of movies
 * 
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>


/**
 * movie struct for the info on a movie
 *
 * @class Library library.h "Movie-database/library.h" 
 *
 */
class Library {
private:
  struct Movie { //includes all the different kinds of info about a movie 
        std::string title;
        std::string directorName;
        int runtime;
        std::string format;
        float price;
        int year;
    };

  std::list<Movie> movieList; //list to store the movies

public:
    // Constructor
    Library();

    // Methods  


/**
 * this will load the movie data from a file and put it into the library
 *
 * @param std::string filename  
 * @return void 
 * @post adds to the library
 * 
 */
    void loadFromFile(std::string filename);

/**
 * stores movie data from the library into a file 
 *
 * @param std::string filename 
 * @return void 
 * @post writes data of movies in the library to a file
 * 
 */
    void storeToFile(std::string filename);

/**
 * inserts a movie into the library based on alphabetical order by title
 *
 * @param Movie movie  
 * @return void 
 * @post adds movie to library
 * 
 */
    void insertSorted(Movie movie);


/**
 * inserts a movie at the beginning of the library
 *
 * @param Movie movie  
 * @return void 
 * @post adds movie to front of library
 * 
 */
    void pushFront(Movie movie);

/**
 * inserts a movie at the end of the library
 *
 * @param Movie movie  
 * @return void 
 * @post adds movie to the end of library
 * 
 */
    void pushBack(Movie movie);

/**
 * searches for movies based on a string in the title and prints its data
 *
 * @param std::string query 
 * @pre 
 * @return void 
 * @post prints info of movie
 * 
 */
    void findMovie(std::string query);

/**
 * searches for movies based on director then prints their data 
 *
 * @param std::string directorName  
 * @return void 
 * @post prints data of movie made by the given director
 * 
 */
    void directorSearch(std::string directorName);

/**
 * removes movie from the library based on its title 
 *
 * @param std::string title  
 * @return void 
 * @post deletes movie
 * 
 */
    void remove(std::string title);

/**
 * shows all of the movies that are in the library
 * 
 * @return void 
 * @post prints library
 * 
 */
    void displayAll();
};

#endif // LIBRARY_H
