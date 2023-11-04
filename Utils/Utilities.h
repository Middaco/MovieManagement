//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_UTILITIES_H
#define A45_CLION_UTILITIES_H

#include "../Service/ServiceForMovies.h"

class Utilities
{
private:
    ServiceForMovies& service;

public:
    Utilities(ServiceForMovies& service);
    void add_ten_entities();
};


#endif //A45_CLION_UTILITIES_H
