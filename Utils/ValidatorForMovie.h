//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_VALIDATORFORMOVIE_H
#define A45_CLION_VALIDATORFORMOVIE_H


#include <string>

class ValidatorForMovie {
private:
    static void valid_genre(const std::string& genre_to_validate);

    static void valid_release(int release);

    static void valid_likes(int likes);

public:
    static void validate_movie(const std::string& title,
                               const std::string& genre,
                               int release,
                               int likes,
                               const std::string& link);

};


#endif //A45_CLION_VALIDATORFORMOVIE_H
