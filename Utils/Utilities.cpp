#include "Utilities.h"
#include <cstring>

Utilities::Utilities(ServiceForMovies& serv) :service{serv} {
}

void Utilities::add_ten_entities()
{
    std::string title, genre, link;

    title = "Terminator";
    genre = "action";
    link =  "https://www.youtube.com/watch?v=k64P4l2Wmeg";
    service.add_movie_to_database(title, genre, 1984, 0, link);

    title = "Avengers";
    genre = "sf";
    link =  "https://www.youtube.com/watch?v=eOrNdBpGMv8";
    service.add_movie_to_database(title, genre, 2012, 1, link);

    title = "Godfather";;
    genre = "action";
    link =  "https://www.youtube.com/watch?v=sY1S34973zA";
    service.add_movie_to_database(title, genre, 1972, 2, link);

    title = "Dark Knight";
    genre = "sf";
    link =  "https://www.youtube.com/watch?v=EXeTwQWrcwY";
    service.add_movie_to_database(title, genre, 2008, 3, link);

    title = "Schindler's List";
    genre = "drama";
    link =  "https://www.youtube.com/watch?v=gG22XNhtnoY";
    service.add_movie_to_database(title, genre, 1993, 4, link);

    title = "Lord Of The Rings";
    genre = "sf";
    link =  "https://www.youtube.com/watch?v=V75dMMIW2B4";
    service.add_movie_to_database(title, genre, 2001, 5, link);

    title = "Pulp Fiction";
    genre = "action";
    link =  "https://www.youtube.com/watch?v=s7EdQ4FqbhY";
    service.add_movie_to_database(title, genre, 1994, 6, link);

    title = "Fight Club";
    genre = "action";
    link =  "https://www.youtube.com/watch?v=qtRKdVHc-cE";
    service.add_movie_to_database(title, genre, 1999, 7, link);

    title = "Forrest Gump";
    genre = "adventure";
    link =  "https://www.youtube.com/watch?v=uPIEn0M8su0";
    service.add_movie_to_database(title, genre, 1994, 8, link);

    title = "Inception";
    genre = "sf";
    link =  "https://www.youtube.com/watch?v=YoHD9XEInc0";
    service.add_movie_to_database(title, genre, 2010, 9, link);

}