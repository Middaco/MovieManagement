#include "Movie.h"

Movie::Movie(std::string title, std::string genre, int year_of_release, int numb_of_likes, std::string trailer):
year_of_release{year_of_release}, numb_of_likes{numb_of_likes}
{
    this->title = title;
    this->genre = genre;
    this->trailer = trailer;
}

void Movie::set_title(std::string title)
{
    this->title = title;
}

void Movie::set_genre(std::string genre)
{
    this->genre = genre;
}

void Movie::set_year_of_release(int year_of_release)
{
    this->year_of_release = year_of_release;
}

void Movie::set_numb_of_likes(int numb_of_likes)
{
    this->numb_of_likes = numb_of_likes;
}

void Movie::set_trailer(std::string trailer)
{
    this->trailer = trailer;
}

std::string Movie::get_title()
{
    return this->title;
}

std::string Movie::get_genre()
{
    return this->genre;
}

int Movie::get_release()
{
    return this->year_of_release;
}

int Movie::get_likes()
{
    return this->numb_of_likes;
}

std::string Movie::get_trailer()
{
    return this->trailer;
}

void Movie::increase_likes()
{
    this->numb_of_likes++;
}

bool Movie::operator==(Movie& movie_to_be_compared_with)
{
    if (this->title == movie_to_be_compared_with.get_title()) {
        if (this->year_of_release == movie_to_be_compared_with.get_release()) {
            return true;
        }
    }
    return false;
}

Movie& Movie::operator=(Movie movie_to_be_assigned)
{
    this->set_genre(movie_to_be_assigned.get_genre());
    this->set_numb_of_likes(movie_to_be_assigned.get_likes());
    this->set_title(movie_to_be_assigned.get_title());
    this->set_trailer(movie_to_be_assigned.get_trailer());
    this->set_year_of_release(movie_to_be_assigned.get_release());
    return *this;
}
