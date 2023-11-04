//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_CONSOLE_H
#define A45_CLION_CONSOLE_H

#include "../Service/ServiceForMovies.h"

class Console {
private:
     ServiceForMovies& service_for_movies;

     void filter_likes();
     static void choose_access_mode();
     static void admin_menu();
     void add_movie_to_database();
     void remove_movie_from_database();
     void update_movie_in_database();
     void print_all_movies_from_database();
     void start_admin_mode();
     static void user_menu();
     void print_all_movies_from_watchlist();
     void remove_movie_from_watchlist();
     void cycle_through_movies();
     void start_user_mode();

public:
     Console(ServiceForMovies& service);
     void start();
};


#endif //A45_CLION_CONSOLE_H
