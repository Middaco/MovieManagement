//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_MOVIE_H
#define A45_CLION_MOVIE_H

#include <string>

class Movie {

private:
    std::string title;
    std::string genre;
    int year_of_release;
    int numb_of_likes;
    std::string trailer;

public:
    //constructor of the class
    Movie(std::string title, std::string genre, int year_of_release, int numb_of_likes, std::string trailer);
    ~Movie() = default;
    Movie() = default;

    void set_title(std::string title);
    void set_genre(std::string genre);
    void set_year_of_release(int year_of_release);
    void set_numb_of_likes(int numb_of_likes);
    void set_trailer(std::string trailer);


    //returns the title of the movie
    std::string get_title();

    //returns the genre of the movie
    std::string get_genre();

    //returns the year of release of the movie
    int get_release();

    //returns the number of likes of the movie
    int get_likes();

    //returns the link to the trailer of the movie
    std::string get_trailer();

    void increase_likes();

    bool operator==(Movie& other);

    Movie& operator=(Movie movie_to_be_assigned);
};


#endif //A45_CLION_MOVIE_H
