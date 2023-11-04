//
// Created by Asus on 23.06.2023.
//

#include "RepositoryForAdministrator.h"
#include <stdexcept>
#include <cstring>
#include "../Utils/DynamicArray.cpp"

void RepositoryForAdministrator::add_movie_to_database(Movie movie_to_be_added)
{
    if (this->movies.search_element(movie_to_be_added)) {
        throw(std::runtime_error("\t!! The given movie is already existing !!\n"));
    }
    this->movies.add(movie_to_be_added);
}

int RepositoryForAdministrator::count_movies_from_database()
{
    return this->movies.get_length();
}

DynamicArray<Movie> RepositoryForAdministrator::repo_get_copy_of_movies()
{
    DynamicArray<Movie> copy_of_movies(this->movies);
    return copy_of_movies;
}

bool RepositoryForAdministrator::search_movie_in_database(Movie movie_to_be_searched)
{
    return this->movies.search_element(movie_to_be_searched);
}

bool RepositoryForAdministrator::remove_movie_from_database(Movie movie_to_be_removed)
{
    return this->movies.remove(movie_to_be_removed);
}

DynamicArray<Movie> RepositoryForAdministrator::filter_movies_by_genre(std::string searched_genre)
{
    if (searched_genre.empty()) {
        return this->movies;
    }
    DynamicArray<Movie> movies_filtered_by_genre;
    int i;
    for (i = 0; i < this->movies.get_length(); i++) {
        if (this->movies[i].get_genre() == searched_genre) {
            movies_filtered_by_genre.add(movies[i]);
        }
    }
    if (movies_filtered_by_genre.get_length() == 0) {
        throw(std::runtime_error("\t!! Genre not found !!\n"));
    }
    return movies_filtered_by_genre;
}

bool RepositoryForAdministrator::increase_likes_for_one_movie(Movie movie_to_be_liked)
{
    for (int i = 0; i < this->movies.get_length(); i++) {
        if (this->movies[i] == movie_to_be_liked) {
            this->movies[i].increase_likes();
            return true;
        }
    }
    return false;
}

DynamicArray<std::string> RepositoryForAdministrator::filter_genres_by_likes(int desired_number_of_likes)
{
    DynamicArray<std::pair<std::string, int>> available_genres_and_their_total_number_of_likes;
    DynamicArray<std::string> filtered_genres;
    for (int i = 0; i < this->movies.get_length(); i++) {
        bool found = false;
        for (int j = 0; j < available_genres_and_their_total_number_of_likes.get_length(); j++) {
            if (available_genres_and_their_total_number_of_likes[j].first == movies[i].get_genre()) {
                found = true;
                available_genres_and_their_total_number_of_likes[j].second += movies[i].get_likes();
                break;
            }
        }
        if (!found) {
            available_genres_and_their_total_number_of_likes.add({ movies[i].get_genre(), movies[i].get_likes()});
        }
    }
    for (int i = 0; i < available_genres_and_their_total_number_of_likes.get_length(); i++) {
        if (available_genres_and_their_total_number_of_likes[i].second >= desired_number_of_likes) {
            filtered_genres.add(available_genres_and_their_total_number_of_likes[i].first);
        }
    }

    return filtered_genres;
}
