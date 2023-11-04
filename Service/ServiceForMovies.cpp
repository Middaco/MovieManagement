//
// Created by Asus on 23.06.2023.
//

#include "ServiceForMovies.h"
#include <stdexcept>
#include "../Utils/ValidatorForMovie.h"

ServiceForMovies::ServiceForMovies(RepositoryForAdministrator& repository, RepositoryForUser& watchlist) : repository{ repository }, watchlist{watchlist} {
}

Movie ServiceForMovies::create_movie(std::string title, std::string genre, int release, int number_of_likes, std::string trailer) {
    ValidatorForMovie::validate_movie(title, genre, release, number_of_likes, trailer);
    return Movie{ title, genre, release, number_of_likes, trailer };
}

int ServiceForMovies::count_movies_from_database() {
    return this->repository.count_movies_from_database();
}

void ServiceForMovies::add_movie_to_database(std::string title, std::string genre, int release, int number_of_likes, std::string trailer)
{
    Movie elem = create_movie(title, genre, release, number_of_likes, trailer);
    repository.add_movie_to_database(elem);
}

DynamicArray<Movie> ServiceForMovies::get_copy_of_movies_from_database()
{
    return repository.repo_get_copy_of_movies();
}

void ServiceForMovies::update_movie_in_database(std::string title, int release_year, std::string new_title, std::string new_genre, int new_release_year, int new_number_of_likes, std::string new_link_for_trailer)
{
    Movie movie_to_be_updated = create_movie(title, new_genre, release_year, new_number_of_likes, new_link_for_trailer);
    if( !repository.search_movie_in_database(movie_to_be_updated)){
        throw std::runtime_error("\tMovie not existing!\n\n");
    }
    Movie updated_movie = create_movie(new_title, new_genre, new_release_year, new_number_of_likes, new_link_for_trailer);
    repository.remove_movie_from_database(movie_to_be_updated);
    repository.add_movie_to_database(updated_movie);
}

bool ServiceForMovies::remove_movie_from_database(std::string title, int release_year)
{
    Movie movie_to_be_removed(title, "action", release_year, 0, "");
    return repository.remove_movie_from_database(movie_to_be_removed);
}

DynamicArray<Movie> ServiceForMovies::filter_movies_by_genre(std::string searched_genre)
{
    return repository.filter_movies_by_genre(searched_genre);
}

int ServiceForMovies::count_movies_from_watchlist()
{
    return watchlist.count_movies_from_watchlist();
}

void ServiceForMovies::add_movie_to_watchlist(Movie movie_to_be_added)
{
    watchlist.add_movie_to_watchlist(movie_to_be_added);
}

DynamicArray<Movie> ServiceForMovies::get_copy_of_movies_from_watchlist()
{
    return watchlist.copy_movies_from_watchlist();
}

void ServiceForMovies::remove_movie_from_watchlist(Movie movie_to_be_removed)
{
    watchlist.remove_movie_from_watchlist(movie_to_be_removed);
}

bool ServiceForMovies::increase_likes_for_one_movie(Movie movie_to_be_liked)
{
    return repository.increase_likes_for_one_movie(movie_to_be_liked);
}

DynamicArray<std::string> ServiceForMovies::filter_genres_by_likes(int desired_number_of_likes)
{
    return repository.filter_genres_by_likes(desired_number_of_likes);
}
