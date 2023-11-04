//
// Created by Asus on 23.06.2023.
//

#include "Tests.h"
#include <assert.h>
#include <string>
#include <stdexcept>
#include "../Utils/DynamicArray.cpp"

//Tests::Tests(ServiceForMovies* service_for_movies) {
//	this->service_for_movies = service_for_movies;
//}

void Tests::test_create_movie() {
    std::string title, genre, link;

    RepositoryForAdministrator repository_movies_for_tests;
    RepositoryForUser watchlist_for_tests;
    ServiceForMovies service_for_tests(repository_movies_for_tests, watchlist_for_tests);

    //create a valid movie
    title = "Terminator";
    genre = "action";
    link = "https://www.youtube.com/watch?v=k64P4l2Wmeg";

    Movie movie = service_for_tests.create_movie(title, genre, 1984, 0, link);

    assert(movie.get_title() == "Terminator");
    assert(movie.get_genre() == "action");
    assert(movie.get_release() == 1984);
    assert(movie.get_likes() == 0);
    assert(movie.get_trailer() == "https://www.youtube.com/watch?v=k64P4l2Wmeg");

    //try to create non-valid movies
    genre = "a";
    try {
        service_for_tests.create_movie(title, genre, 1984, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }
    genre = "action";

    try {
        service_for_tests.create_movie(title, genre, 1, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }

    try {
        service_for_tests.create_movie(title, genre, 1984, -1, link);
    }
    catch (std::exception&) {
        assert(true);
    }
}

void Tests::test_add_movie() {
    RepositoryForAdministrator repository_movies_for_tests;
    RepositoryForUser watchlist_for_tests;
    ServiceForMovies service_for_tests(repository_movies_for_tests, watchlist_for_tests);

    std::string title, genre, link;

    title = "Terminator";
    genre = "action";
    link = "https://www.youtube.com/watch?v=k64P4l2Wmeg";

    assert(service_for_tests.count_movies_from_database() == 0);

    service_for_tests.add_movie_to_database(title, genre, 1984, 0, link);

    assert(service_for_tests.count_movies_from_database() == 1);

    //try to add the same movie
    try {
        service_for_tests.add_movie_to_database(title, genre, 1984, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }

    //add more movies to test the resize of the DynamicArray
    for (int i = 2001; i < 2027; i++) {
        service_for_tests.add_movie_to_database(title, genre, i, 0, link);
    }
    assert(service_for_tests.count_movies_from_database() == 27);
}

void Tests::test_update_movie() {
    RepositoryForAdministrator repository_movies_for_tests;
    RepositoryForUser watchlist_for_tests;
    ServiceForMovies service_for_tests(repository_movies_for_tests, watchlist_for_tests);

    assert(service_for_tests.count_movies_from_database() == 0);

    std::string title, genre, link;

    title = "Terminator";
    genre = "action";
    link = "https://www.youtube.com/watch?v=k64P4l2Wmeg";

    service_for_tests.add_movie_to_database(title, genre, 1980, 0, link);

    assert(service_for_tests.count_movies_from_database() == 1);

    DynamicArray<Movie> movies = service_for_tests.get_copy_of_movies_from_database();

    assert(movies[0].get_title() == "Terminator");
    assert(movies[0].get_genre() == "action");
    assert(movies[0].get_trailer() == link);
    assert(movies[0].get_release() == 1980);
    assert(movies[0].get_likes() == 0);

    //try and update a movie that's not stored
    title = "A";
    try {
        service_for_tests.update_movie_in_database(title, 1980, title, genre, 1980, 0, link);
    }
    catch (std::runtime_error&) {
        assert(true);
    }
    title = "Terminator";
    try {
        service_for_tests.update_movie_in_database(title, 1900, title, genre, 1980, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }


    //update the stored movie with unvalid fields
    genre = "a";
    try {
        service_for_tests.update_movie_in_database(title, 1980, title, genre, 1980, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }
    genre = "action";
    try {
        service_for_tests.update_movie_in_database(title, 1980, title, genre, 19, 0, link);
    }
    catch (std::exception&) {
        assert(true);
    }
    try {
        service_for_tests.update_movie_in_database(title, 1980, title, genre, 1980, -1, link);
    }
    catch (std::exception&) {
        assert(true);
    }

    //update the movie
    std::string new_title, new_genre;
    new_title = "A";
    new_genre = "adventure";
    service_for_tests.update_movie_in_database(title, 1980, new_title, new_genre, 2000, 15, link);

    movies = service_for_tests.get_copy_of_movies_from_database();

    assert(movies[0].get_title() == "A");
    assert(movies[0].get_genre() == "adventure");
    assert(movies[0].get_trailer() == link);
    assert(movies[0].get_release() == 2000);
    assert(movies[0].get_likes() == 15);
}

void Tests::test_delete_movie() {

    RepositoryForAdministrator repository_movies_for_tests;
    RepositoryForUser watchlist_for_tests;
    ServiceForMovies service_for_tests(repository_movies_for_tests, watchlist_for_tests);

    assert(service_for_tests.count_movies_from_database() == 0);

    std::string title, link, genre;

    title = "Terminator";
    genre = "action";
    link = "https://www.youtube.com/watch?v=k64P4l2Wmeg";

    //create 10 movies
    for (int i = 2000; i < 2010; i++) {
        service_for_tests.add_movie_to_database(title, genre, i, 1, link);
    }

    assert(service_for_tests.count_movies_from_database() == 10);

    //try to delete movies that are not valid
    try {
        service_for_tests.remove_movie_from_database(title, 1);
    }
    catch (std::exception&) {
        assert(true);
    }

    //delete all movies
    service_for_tests.remove_movie_from_database(title, 2000);
    assert(service_for_tests.count_movies_from_database() == 9);
    service_for_tests.remove_movie_from_database(title, 2001);
    assert(service_for_tests.count_movies_from_database() == 8);
    service_for_tests.remove_movie_from_database(title, 2002);
    assert(service_for_tests.count_movies_from_database() == 7);
    service_for_tests.remove_movie_from_database(title, 2003);
    assert(service_for_tests.count_movies_from_database() == 6);
    service_for_tests.remove_movie_from_database(title, 2004);
    assert(service_for_tests.count_movies_from_database() == 5);
    service_for_tests.remove_movie_from_database(title, 2005);
    assert(service_for_tests.count_movies_from_database() == 4);
    service_for_tests.remove_movie_from_database(title, 2006);
    assert(service_for_tests.count_movies_from_database() == 3);
    service_for_tests.remove_movie_from_database(title, 2007);
    assert(service_for_tests.count_movies_from_database() == 2);
    service_for_tests.remove_movie_from_database(title, 2008);
    assert(service_for_tests.count_movies_from_database() == 1);
    service_for_tests.remove_movie_from_database(title, 2009);
    assert(service_for_tests.count_movies_from_database() == 0);
}

void Tests::test_admin_mode() {
    test_create_movie();
    test_add_movie();
    test_update_movie();
    test_delete_movie();
}

void Tests::test_filter_movies(ServiceForMovies& service_for_tests) {
    std::string title, genre, link;
    DynamicArray<Movie> movies;

    title = "Terminator";
    genre = "action";
    link = "https://www.youtube.com/watch?v=k64P4l2Wmeg";

    int release_year = 2000;
    //int likes = 2;

    service_for_tests.add_movie_to_database(title, genre, release_year, 1, link);

    title =  "Terminator2";
    service_for_tests.add_movie_to_database(title, genre, release_year, 2, link);

    title =  "Terminator3";
    service_for_tests.add_movie_to_database(title, genre, release_year, 3, link);

    title =  "Star";
    genre =  "sf";
    service_for_tests.add_movie_to_database(title, genre, release_year, 4, link);
    title =  "Star2";
    service_for_tests.add_movie_to_database(title, genre, release_year, 3, link);
    title =  "Star3";
    service_for_tests.add_movie_to_database(title, genre, release_year, 1, link);

    title =  "Finn";
    genre =  "adventure";
    service_for_tests.add_movie_to_database(title, genre, release_year, 1, link);
    title =  "Finn2";
    service_for_tests.add_movie_to_database(title, genre, release_year, 0, link);
    title =  "Finn3";
    service_for_tests.add_movie_to_database(title, genre, release_year, 1, link);



    //try to filter after a genre that is not stored
    try {
        service_for_tests.filter_movies_by_genre("romance");
    }
    catch (std::exception) {
        assert(true);
    }

    DynamicArray<Movie> action_movies = service_for_tests.filter_movies_by_genre("action");
    DynamicArray<Movie> adventure_movies = service_for_tests.filter_movies_by_genre("adventure");
    DynamicArray<Movie> sf_movies = service_for_tests.filter_movies_by_genre("sf");
    DynamicArray<Movie> all_movies = service_for_tests.filter_movies_by_genre("");

    assert(action_movies.get_length() == adventure_movies.get_length()
           && adventure_movies.get_length() == sf_movies.get_length()
           && sf_movies.get_length() == 3);
    assert(all_movies.get_length() == 9);

    assert(action_movies[0].get_title() == "Terminator");
    assert(action_movies[0].get_genre() ==  "action");

    assert(action_movies[1].get_title() ==  "Terminator2");
    assert(action_movies[1].get_genre() ==  "action");

    assert(action_movies[2].get_title() ==  "Terminator3");
    assert(action_movies[2].get_genre() ==  "action");

    assert(adventure_movies[0].get_title() ==  "Finn");
    assert(adventure_movies[0].get_genre() ==  "adventure");

    assert(adventure_movies[1].get_title() ==  "Finn2");
    assert(adventure_movies[1].get_genre() ==  "adventure");

    assert(adventure_movies[2].get_title() ==  "Finn3");
    assert(adventure_movies[2].get_genre() ==  "adventure");

    assert(sf_movies[0].get_title() ==  "Star");
    assert(sf_movies[0].get_genre() ==  "sf");

    assert(sf_movies[1].get_title() ==  "Star2");
    assert(sf_movies[1].get_genre() ==  "sf");

    assert(sf_movies[2].get_title() ==  "Star3");
    assert(sf_movies[2].get_genre() ==  "sf");

    DynamicArray<std::string> filtered_genres = service_for_tests.filter_genres_by_likes(0);

    assert(filtered_genres.search_element("action") == true);
    assert(filtered_genres.search_element("adventure") == true);
    assert(filtered_genres.search_element("sf") == true);
    assert(filtered_genres.get_length() == 3);

    filtered_genres = service_for_tests.filter_genres_by_likes(3);
    assert(filtered_genres.search_element("action") == true);
    assert(filtered_genres.search_element("sf") == true);
    assert(filtered_genres.get_length() == 2);

    filtered_genres = service_for_tests.filter_genres_by_likes(7);
    assert(filtered_genres.search_element("sf") == true);
    assert(filtered_genres.get_length() == 1);

    filtered_genres = service_for_tests.filter_genres_by_likes(41);
    assert(filtered_genres.get_length() == 0);

}

void Tests::test_add_to_watchlist(ServiceForMovies& service_for_tests) {

    assert(service_for_tests.count_movies_from_watchlist() == 0);

    service_for_tests.add_movie_to_watchlist(service_for_tests.get_copy_of_movies_from_database()[0]);

    assert(service_for_tests.count_movies_from_watchlist() == 1);

    try {
        service_for_tests.add_movie_to_watchlist(service_for_tests.get_copy_of_movies_from_database()[0]);
    }
    catch (std::exception) {
        assert(true);
    }

    DynamicArray<Movie> watchlist = service_for_tests.get_copy_of_movies_from_watchlist();

    assert(watchlist[0].get_title() == "Terminator");
    assert(watchlist[0].get_genre() == "action");
    assert(watchlist[0].get_trailer() == "https://www.youtube.com/watch?v=k64P4l2Wmeg");
    assert(watchlist[0].get_release() == 2000);
    assert(watchlist[0].get_likes() == 1);

    service_for_tests.add_movie_to_watchlist(service_for_tests.get_copy_of_movies_from_database()[5]);

    watchlist = service_for_tests.get_copy_of_movies_from_watchlist();

    assert(watchlist[0].get_title() == "Terminator");
    assert(watchlist[0].get_genre() == "action");
    assert(watchlist[0].get_trailer() == "https://www.youtube.com/watch?v=k64P4l2Wmeg");
    assert(watchlist[0].get_release() == 2000);
    assert(watchlist[0].get_likes() == 1);

    assert(watchlist[1].get_title() == "Star3");
    assert(watchlist[1].get_genre() == "sf");
    assert(watchlist[1].get_trailer() == "https://www.youtube.com/watch?v=k64P4l2Wmeg");
    assert(watchlist[1].get_release() == 2000);
    assert(watchlist[1].get_likes() == 1);
}

void Tests::test_remove_from_watchlist(ServiceForMovies& service_for_tests) {

    assert(service_for_tests.count_movies_from_watchlist() == 2);

    DynamicArray<Movie> watchlist = service_for_tests.get_copy_of_movies_from_watchlist();

    //try to increase the number of likes of a non-existing movie
    assert(service_for_tests.increase_likes_for_one_movie(service_for_tests.create_movie("Fake Movie", "action", 1900, 0, "")) == false);

    assert(service_for_tests.increase_likes_for_one_movie(watchlist[0]) == true);
    service_for_tests.remove_movie_from_watchlist(watchlist[0]);

    watchlist = service_for_tests.get_copy_of_movies_from_watchlist();

    assert(service_for_tests.count_movies_from_watchlist() == 1);

    assert(watchlist[0].get_title() == "Star3");
    assert(watchlist[0].get_genre() == "sf");
    assert(watchlist[0].get_trailer() == "https://www.youtube.com/watch?v=k64P4l2Wmeg");
    assert(watchlist[0].get_release() == 2000);
    assert(watchlist[0].get_likes() == 1);

    service_for_tests.remove_movie_from_watchlist(watchlist[0]);
    assert(service_for_tests.count_movies_from_watchlist() == 0);
}

void Tests::test_user_mode() {
    RepositoryForAdministrator repository_movies_for_tests;
    RepositoryForUser watchlist_for_tests;
    ServiceForMovies service_for_tests(repository_movies_for_tests, watchlist_for_tests);


    test_filter_movies(service_for_tests);
    test_add_to_watchlist(service_for_tests);
    test_remove_from_watchlist(service_for_tests);
}

void Tests::start_all_tests() {
    test_admin_mode();
    test_user_mode();
}


