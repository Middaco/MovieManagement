//
// Created by Asus on 23.06.2023.
//

#include "ValidatorForMovie.h"
#include <stdexcept>

void ValidatorForMovie::valid_genre(const std::string& genre_to_validate) {
    std::string genres[4] = { "action", "adventure", "sf", "drama" };
    bool found = false;
    for (const auto& current_genre : genres) {
        if (current_genre == genre_to_validate) {
            found = true;
            break;
        }
    }
    if (!found) {
        throw(std::runtime_error("\t!! GENRE is not an existing genres. Choose one from the list below: !!\naction\nadventure\nsf\n\n"));
    }
}

void ValidatorForMovie::valid_release(int release) {
    if (release < 1850) {
        throw(std::runtime_error("\t!! RELEASE YEAR cannot be < 1850 !!\n"));
    }
}

void ValidatorForMovie::valid_likes(int likes) {
    if (likes < 0) {
        throw(std::runtime_error("\t!! Number of LIKES cannot be < 0 !!\n"));
    }
}

void ValidatorForMovie::validate_movie(const std::string& title,
                                       const std::string& genre,
                                       int release,
                                       int likes,
                                       const std::string& link)
{
    valid_genre(genre);
    valid_release(release);
    valid_likes(likes);
}
