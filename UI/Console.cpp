//
// Created by Asus on 23.06.2023.
//

#include "Console.h"
#include <iostream>
#include "Console.h"
#include <cstdio>
#include <stdexcept>
#include <cstdlib>
#include <windows.h>
#include "../Utils/DynamicArray.cpp"
#include <limits>

using namespace std;

#define ADMIN_MODE 1
#define USER_MODE 2
#define EXIT_MODE 3
//admin
#define ADD_MOVIE_CASE 1
#define REMOVE_MOVIE_CASE 2
#define UPDATE_MOVIE_CASE 3
#define PRINT_MOVIES_CASE 4
#define FILTER_BY_LIKES_CASE 5
#define EXIT_ADMIN_CASE 6
//user
#define LOOP_THROUGH_MOVIES_CASE 1
#define REMOVE_MOVIE_FROM_WATCHLIST_CASE 2
#define PRINT_WATCHLIST_CASE 3
#define EXIT_USER_CASE 4

Console::Console(ServiceForMovies& serv) : service_for_movies{serv } {
}

void Console::choose_access_mode() {
    cout << "\t\tChoose one option:\n";
    cout << "\t1. Admin mode\n";
    cout << "\t2. User mode\n";
    cout << "\t3. Exit\n";
}

void Console::admin_menu() {
    cout << "\t\tYou are in the admin mode\n\n";
    cout << "\t1. Add movie\n";
    cout << "\t2. Remove movie\n";
    cout << "\t3. Update movie\n";
    cout << "\t4. See the stored movies\n";
    cout << "\t5. See the genres that have at least k likes\n";
    cout << "\t6. Exit admin mode\n";
}

void Console::add_movie_to_database() {
    std::string title, genre, trailer;
    int release, likes;
    char whitespace;
    cout << "\tTitle: ";
    cin.get(whitespace);
    std::getline(std::cin, title);
    cout << "\tGenre: ";
    std::getline(std::cin, genre);
    cout << "\tRelease: ";
    cin >> release;
    if(!cin.good()){
        throw runtime_error("\t!!! Release year should be a number !!!\n");
    }
    cout << "\tLikes: ";
    cin >> likes;
    if(!cin.good()){
        throw runtime_error("\t!!! Number of likes should be a number !!!\n");
    }
    cout << "\tTrailer: ";
    cin >> trailer;
    service_for_movies.add_movie_to_database(title, genre, release, likes, trailer);
    cout << "\n\tMovie successfully added!\n\n";
}

void Console::remove_movie_from_database() {
    std::string title;
    int release;
    char whitespace;
    cout << "\tTitle: ";
    cin.get(whitespace);
    std::getline(std::cin, title);
    cout << "\tRelease: ";
    cin >> release;
    if(!cin.good()){
        throw runtime_error("\t!!! Release year should be a number !!!\n");
    }
    if(service_for_movies.remove_movie_from_database(title, release)){
        cout << "\n\tMovie successfully removed!\n\n";
    }else{
        cout << "\n\tThis movie does not exist!\n\n";
    }
}

void Console::update_movie_in_database() {
    std::string title, new_title, new_genre, new_link_for_trailer;
    int release_year, new_release_year, new_number_of_likes;
    char whitespace;
    cout << "\tTitle: ";
    cin.get(whitespace);
    std::getline(std::cin, title);
    cout << "\tRelease: ";
    cin >> release_year;
    if(!cin.good()){
        throw runtime_error("\t!!! Release year should be a number !!!\n");
    }
    cout << "\tNew Title: ";
    cin.get(whitespace);
    std::getline(std::cin, new_title);
    cout << "\tNew Genre: ";
    cin >> new_genre;
    cout << "\tNew Release : ";
    cin >> new_release_year;
    if(!cin.good()){
        throw runtime_error("\t!!! Release year should be a number !!!\n");
    }
    cout << "\tNew Likes: ";
    cin >> new_number_of_likes;
    if(!cin.good()){
        throw runtime_error("\t!!! Number of likes should be a number !!!\n");
    }
    cout << "\tNew Trailer: ";
    cin >> new_link_for_trailer;
    service_for_movies.update_movie_in_database(title, release_year, new_title, new_genre, new_release_year, new_number_of_likes, new_link_for_trailer);
    cout << "\n\tMovie successfully updated!\n\n";
}

void Console::print_all_movies_from_database() {
    DynamicArray<Movie> movies = service_for_movies.get_copy_of_movies_from_database();
    int i;
    for (i = 0; i < movies.get_length(); i++) {
        cout << "\tTitle: " << movies[i].get_title() << " || Genre: " << movies[i].get_genre() << " || Release: " << movies[i].get_release() << " || Likes: " << movies[i].get_likes() << " || Trailer: " << movies[i].get_trailer() << "\n";
    }
}

void Console::start_admin_mode() {
    while (true) {
        admin_menu();
        int admin_choice;
        cout << ">>>";
        cin >> admin_choice;
        switch (admin_choice)
        {
            case ADD_MOVIE_CASE:
                try {
                    add_movie_to_database();
                }
                catch (exception &current_error) {
                    cout << current_error.what();
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            case REMOVE_MOVIE_CASE:
                try {
                    remove_movie_from_database();
                }
                catch (exception& just_caught_exception) {
                    cout << just_caught_exception.what();
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            case UPDATE_MOVIE_CASE:
                try {
                    update_movie_in_database();
                }
                catch (exception& just_caught_exception) {
                    cout << just_caught_exception.what();
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case PRINT_MOVIES_CASE:
                print_all_movies_from_database();
                break;

            case FILTER_BY_LIKES_CASE:
                try{
                    filter_likes();
                }catch(exception& just_caught_exception){
                    cout << just_caught_exception.what();
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case EXIT_ADMIN_CASE:
                return;
            default:
                cout<<"\t!! Invalid command !!\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

void Console::user_menu() {
    cout << "\t\tYou are in the user mode\n\n";
    cout << "\t1. Cycle through movies\n";
    cout << "\t2. Remove movie from Watch List\n";
    cout << "\t3. See the Watch List\n";
    cout << "\t4. Exit user mode\n";
}

void Console::print_all_movies_from_watchlist() {
    DynamicArray<Movie> movies = service_for_movies.get_copy_of_movies_from_watchlist();
    for (int i = 0; i < movies.get_length(); i++) {
        cout << "\tTitle: " << movies[i].get_title() << "|| Genre: " << movies[i].get_genre() << "|| Release: " << movies[i].get_release() << "|| Likes: " << movies[i].get_likes()<<"\n";
    }
}

void Console::remove_movie_from_watchlist() {
    DynamicArray<Movie> watchlist = service_for_movies.get_copy_of_movies_from_watchlist();
    if (watchlist.get_length() == 0) {
        throw runtime_error("\t!!! The watchlist is empty !!!\n");
    }
    for (int i = 0; i < watchlist.get_length(); i++) {
        cout << "\t" << i << ". Title: " << watchlist[i].get_title() << " || Release: " << watchlist[i].get_release() << "\n";
    }
    while (true) {
        int choice;
        cout << "\tIndex of the movie you want to delete: ";
        cin >> choice;
        if(!cin.good()){
            throw runtime_error("\t!!! Index of movie should be a number !!!\n");
        }
        if (choice > watchlist.get_length() || choice < 0) {
            cout << "\t!! Invalid command !!\n\n";
        }
        else {
            cout << "\tDid you like this movie?(yes/no)";
            string liked_movie_or_not;
            cin >> liked_movie_or_not;
            if (liked_movie_or_not == "yes") {
                service_for_movies.increase_likes_for_one_movie(watchlist[choice]);
                cout << "\n\tYou liked this movie!\n\n";
            }
            cout << "\n\tYou disliked this movie!\n\n";
            service_for_movies.remove_movie_from_watchlist(watchlist[choice]);
            cout << "\n\tMovie successfully removed!\n\n";
            break;
        }
    }
}

void Console::cycle_through_movies() {
    std::string genre;
    char whitespace;
    cout << "\n\tEnter the genre you want or leave the field empty to display all the movies\n\tAvaliable genres: action, adventure, sf, drama\n";
    cout << "\tGenre: ";
    cin.get(whitespace);
    std::getline(std::cin, genre);
    DynamicArray<Movie> filtered_movies_by_genre;
    if (genre.empty()) {
        filtered_movies_by_genre = service_for_movies.get_copy_of_movies_from_database();
    }
    else {
        filtered_movies_by_genre = service_for_movies.filter_movies_by_genre(genre);
    }
    for (int i = 0; i < filtered_movies_by_genre.get_length(); i++) {
        cout << "\tTitle: " << filtered_movies_by_genre[i].get_title() << "|| Genre: " << filtered_movies_by_genre[i].get_genre() << "|| Release: " << filtered_movies_by_genre[i].get_release() << "|| Likes: " << filtered_movies_by_genre[i].get_likes()<<"\n";
        ShellExecuteA(nullptr, "open", filtered_movies_by_genre[i].get_trailer().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
        cout << "\tAdd " << filtered_movies_by_genre[i].get_title() << " to the WatchList?(yes/no/stop)";
        std::string choice;
        while (true) {
            cin >> choice;
            if (choice == "yes") {
                service_for_movies.add_movie_to_watchlist(filtered_movies_by_genre[i]);
                cout << "\n\tMovie successfully added!\n\n";
                break;
            }
            else if (choice == "no") {
                break;
            }
            else if (choice == "stop") {
                return;
            }
            else {
                cout << "\t!! Invalid command !!\n\n";
            }
        }
        if (i == filtered_movies_by_genre.get_length() - 1) {
            i = -1;
        }
    }
}

void Console::filter_likes() {
    cout << "\tNumber of likes: ";
    int desired_number_of_likes;
    cin >> desired_number_of_likes;
    if(!cin.good()){
        throw runtime_error("\t!!! Number of likes should be a number !!!\n");
    }
    DynamicArray< std::string>  filtered_genres = service_for_movies.filter_genres_by_likes(desired_number_of_likes);
    for (int i = 0; i < filtered_genres.get_length(); i++) {
        cout << "\t" << filtered_genres[i] << "\n";
    }
}

void Console::start_user_mode() {
    while (true) {
        user_menu();
        int user_choice;
        cout << ">>>";
        cin >> user_choice;
        switch (user_choice) {
            case LOOP_THROUGH_MOVIES_CASE:
                try {
                    cycle_through_movies();
                }
                catch (exception& msg) {
                    cout << msg.what();
                }
                break;

            case REMOVE_MOVIE_FROM_WATCHLIST_CASE:
                try {
                    remove_movie_from_watchlist();
                }
                catch (exception& msg) {
                    cout << msg.what();
                }
                break;

            case PRINT_WATCHLIST_CASE:
                print_all_movies_from_watchlist();
                break;

            case EXIT_USER_CASE:
                return;

            default:
                cout << "\t!! Invalid command !!\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

void Console::start() {
    while (true){
        choose_access_mode();
        int choice;
        cout << "Choice:";
        if(cin >> choice){
            if (choice == ADMIN_MODE) {
                //admin mode
                start_admin_mode();
            }
            else if (choice == USER_MODE) {
                //user mode
                start_user_mode();
            }
            else if (choice == EXIT_MODE) {
                cout << "\tGoodbye!\n";
                exit(0);
            }
            else {
                cout << "\t!! Invalid command !!\n\n";
            }
        }else{
            cout << "\t!! Please provide an integer !!\n\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}