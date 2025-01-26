//
// Created by Nativ on 26/01/2025.
//

#ifndef INVALIDROOM_H
#define INVALIDROOM_H
#include <exception>


class invalidRoom : public std::exception {
    public:
    invalidRoom()=default;
    ~invalidRoom() noexcept override = default;
    const char *what() const noexcept override;
};



#endif //INVALIDROOM_H
