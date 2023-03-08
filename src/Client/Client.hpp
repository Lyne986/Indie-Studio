/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** MySockets
*/

#ifndef _CLIENT_HPP_
    #define _CLIENT_HPP_
    #ifndef _WIN32_WINNT
        #define _WIN32_WINNT 0x0501
    #endif

    #include <sstream>
    #include <iostream>
    #include "../GlobalArchitecture.hpp"
    #include <iostream>
    #include <istream>
    #include <ostream>
    #include <string>
    #include <boost/asio.hpp>
    #include <boost/bind.hpp>

class Indie::Client {
    public:
        Client(){};
        ~Client(){};
        void test();

    protected:
    private:
};

#endif /* !_CLIENT_HPP_ */
