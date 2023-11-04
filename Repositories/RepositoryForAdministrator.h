//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_REPOSITORYFORADMINISTRATOR_H
#define A45_CLION_REPOSITORYFORADMINISTRATOR_H


#include "../Domain/Movie.h"
#include "../Utils/DynamicArray.h"

class RepositoryForAdministrator {
private:
    DynamicArray<Movie> movies;

public:
    RepositoryForAdministrator() = default;
    void add_movie_to_database(Movie movie_to_be_added);
    int count_movies_from_database();
    DynamicArray<Movie> repo_get_copy_of_movies();
    bool search_movie_in_database(Movie movie_to_be_searched);
    bool remove_movie_from_database(Movie movie_to_be_removed);
    /*
     * Iterates through the current list of movies
     * Compares the given std::string with every movie's genre
     * Returns a DynamicArray of movies with the provided genre
     * Returns a copy of the current list of movies is std::string is empty
     */
    DynamicArray<Movie> filter_movies_by_genre(std::string searched_genre);
    bool increase_likes_for_one_movie(Movie movie_to_be_liked);
    /*
     * Calculates the total number of likes of every genre using a
     * DynamicArray<std::pair<std::string, int>>, the string being a genre and
     * the integer the total number of likes of that genre. Iterates through
     * the new created DynamicArray and returns another DynamicArray, this time
     * only containing std::string, with the genres that have the total number
     * of likes greater or equal to the desired_number_of_likes
     */
    DynamicArray<std::string> filter_genres_by_likes(int desired_number_of_likes);

};


#endif //A45_CLION_REPOSITORYFORADMINISTRATOR_H
