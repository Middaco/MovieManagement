cmake_minimum_required(VERSION 3.25)
project(a45_CLion)

set(CMAKE_CXX_STANDARD 11)

add_executable(a45_CLion "Start Application.cpp" UI/Console.cpp UI/Console.h Domain/Movie.cpp Domain/Movie.h Repositories/RepositoryForAdministrator.cpp Repositories/RepositoryForAdministrator.h Utils/DynamicArray.cpp Utils/DynamicArray.h Repositories/RepositoryForUser.cpp Repositories/RepositoryForUser.h Utils/ValidatorForMovie.cpp Utils/ValidatorForMovie.h Service/ServiceForMovies.cpp Service/ServiceForMovies.h Tests/Tests.cpp Tests/Tests.h Utils/Utilities.cpp Utils/Utilities.h)
