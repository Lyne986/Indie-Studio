/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** GlobalArchitecture
*/

#ifndef GLOBALARCHITECTURE_HPP_
    #define GLOBALARCHITECTURE_HPP_

    #include <vector>
    #include <string>
    #include <sstream>
    #include <fstream>

namespace Indie {
    class MySockets;
    class Character;
    class Client;

    namespace Utils {
        class FileManager;
    };

    enum TYPE {
        EMPTY,
        PLAYER,
        AI
    };

    enum IA_TYPE {
        EASY,
        MEDIUM,
        HARD
    };


    typedef struct player_s {
        TYPE type;
        std::string model;
        int controller_id;
        IA_TYPE ia_type;
    } player_t;
}

#endif /* !GLOBALARCHITECTURE_HPP_ */
