//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_TESTS_H
#define A45_CLION_TESTS_H

#include "../Service/ServiceForMovies.h"

class Tests {
private:
    //Service* service_for_movies;
public:
    //Tests(Service* service_for_movies);
    Tests() = default;
    void start_all_tests();
    void test_user_mode();
    void test_admin_mode();

    void test_filter_movies(ServiceForMovies& service_for_tests);
    void test_add_to_watchlist(ServiceForMovies& service_for_tests);
    void test_remove_from_watchlist(ServiceForMovies& service_for_tests);

    void test_create_movie();
    void test_add_movie();
    void test_update_movie();
    void test_delete_movie();
};


#endif //A45_CLION_TESTS_H
