/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** FileManager.hpp
*/

#ifndef __FILE_MANAGER_HPP_
    #define __FILE_MANAGER_HPP_

    #include "../GlobalArchitecture.hpp"

class Indie::Utils::FileManager {
    private:
        std::string content;

    public:
        FileManager(std::string filename);
        FileManager();
        ~FileManager();
        std::vector<std::string> splitByDelim(std::string str, char delim);
        std::string getContent() const;
        void write(std::string filename, std::string content);
        std::string read(std::string filename);
};

#endif