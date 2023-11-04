//movies
#include "Tests/Tests.h"
#include "Repositories/RepositoryForAdministrator.h"
#include "Repositories/RepositoryForUser.h"
#include "UI/Console.h"
#include "Utils/Utilities.h"

using namespace std;

int main() {
    Tests testing;
    testing.start_all_tests();

    RepositoryForAdministrator repository_movies_for_administrator;
    RepositoryForUser watchlist_with_movies_for_users;
    ServiceForMovies main_service_for_movies (repository_movies_for_administrator, watchlist_with_movies_for_users);
    Console console(main_service_for_movies);
    Utilities utils(main_service_for_movies);

    utils.add_ten_entities();
    console.start();
    return 0;
}