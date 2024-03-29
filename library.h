/**
 * @file library.h
 * @author Kimble Culley
 * @date 2024-03-28
 * @brief idk
 * 
 * idk
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>

class Library {
private:
    struct Movie {
        std::string title;
        std::string directorName;
        int runtime;
        std::string format;
        float price;
        int year;
    };

    std::list<Movie> movieList;

public:
    // Constructor
    Library();

    // Methods
    void loadFromFile(std::string filename);
    void storeToFile(std::string filename);
    void insertSorted(Movie movie);
    void pushFront(Movie movie);
    void pushBack(Movie movie);
    void findMovie(std::string query);
    void directorSearch(std::string directorName);
    void remove(std::string title);
    void displayAll();
};

#endif // LIBRARY_H
