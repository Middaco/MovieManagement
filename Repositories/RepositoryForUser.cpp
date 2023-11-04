//
// Created by Asus on 23.06.2023.
//

#include "RepositoryForUser.h"
#include <stdexcept>
#include "../Utils/DynamicArray.cpp"

void RepositoryForUser::add_movie_to_watchlist(Movie movie_to_be_added)
{
    if (this->watchlist.search_element(movie_to_be_added)) {
        throw std::runtime_error("\t!! The given movie is already existing in Watch List !!\n");
    }
    this->watchlist.add(movie_to_be_added);
}

DynamicArray<Movie> RepositoryForUser::copy_movies_from_watchlist()
{
    DynamicArray<Movie> copied_watchlist(this->watchlist);
    return copied_watchlist;
}

bool RepositoryForUser::remove_movie_from_watchlist(Movie movie_to_be_removed)
{
    return this->watchlist.remove(movie_to_be_removed);
}

int RepositoryForUser::count_movies_from_watchlist()
{
    return this->watchlist.get_length();
}
