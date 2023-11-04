//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_SERVICEFORMOVIES_H
#define A45_CLION_SERVICEFORMOVIES_H


#include "../Domain/Movie.h"
#include "../Utils/DynamicArray.h"
#include "../Repositories/RepositoryForAdministrator.h"
#include "../Repositories/RepositoryForUser.h"

class ServiceForMovies {
public:
    ServiceForMovies(RepositoryForAdministrator& repo, RepositoryForUser& watchlist);

    Movie create_movie(std::string title, std::string genre, int release, int number_of_likes, std::string trailer);

    int count_movies_from_database();

    void add_movie_to_database(std::string title, std::string genre, int release, int number_of_likes, std::string trailer);

    DynamicArray<Movie> get_copy_of_movies_from_database();

    void update_movie_in_database(std::string title, int release, std::string new_title, std::string new_genre, int new_release, int new_number_of_likes, std::string new_link_for_trailer);

    bool remove_movie_from_database(std::string title, int release_year);

    DynamicArray<Movie> filter_movies_by_genre(std::string genre);

    int count_movies_from_watchlist();

    void add_movie_to_watchlist(Movie movie_to_be_added);

    DynamicArray<Movie> get_copy_of_movies_from_watchlist();

    void remove_movie_from_watchlist(Movie movie_to_be_removed);

    bool increase_likes_for_one_movie(Movie movie_to_be_liked);

    DynamicArray<std::string> filter_genres_by_likes(int desired_number_of_likes);

private:
    RepositoryForAdministrator& repository;
    RepositoryForUser& watchlist;

};


#endif //A45_CLION_SERVICEFORMOVIES_H
