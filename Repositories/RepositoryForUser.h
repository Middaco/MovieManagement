//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_REPOSITORYFORUSER_H
#define A45_CLION_REPOSITORYFORUSER_H


#include "../Domain/Movie.h"
#include "../Utils/DynamicArray.h"

class RepositoryForUser {
private:
    DynamicArray<Movie> watchlist;

public:
    RepositoryForUser() = default;
    void add_movie_to_watchlist(Movie movie_to_be_added);
    DynamicArray<Movie> copy_movies_from_watchlist();
    bool remove_movie_from_watchlist(Movie movie_to_be_removed);
    int count_movies_from_watchlist();
};


#endif //A45_CLION_REPOSITORYFORUSER_H
