/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-bastien.boymond
** File description:
** FileManager.cpp
*/

#include "FileManager.hpp"

namespace Indie::Utils {
    FileManager::FileManager(std::string filename)
    {
        std::ifstream s(filename);
        std::stringstream buffer;

        buffer << s.rdbuf();
        this->content = buffer.str();
    }

    FileManager::FileManager()
    {

    }

    FileManager::~FileManager()
    {

    }

    std::vector<std::string> FileManager::splitByDelim(std::string str, char delim)
    {
        std::stringstream ss(str);
        std::string tmp;
        std::vector<std::string> words;

        while(getline(ss, tmp, delim)){
            words.push_back(tmp);
        }
        return words;
    }

    std::string FileManager::getContent() const
    {
        return this->content;
    }

    void FileManager::write(std::string filename, std::string content)
    {
        std::ofstream s(filename);
        s << content;
    }

    std::string FileManager::read(std::string filename)
    {
        std::ifstream s(filename);
        std::stringstream buffer;

        buffer << s.rdbuf();
        this->content = buffer.str();
        return (this->content);
    }

}