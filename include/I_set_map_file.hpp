#ifndef I_SET_MAP_FILE_HPP
#define I_SET_MAP_FILE_HPP

#include "I_open_file.hpp"
#include <string>
#include <list>
#include <map>

class I_set_map_file:public I_open_file
{
    public:
    virtual ~I_set_map_file() = default;
    virtual void set_m_file(std::map<std::string,std::list<std::string>>) = 0;
};

#endif // I_SET_MAP_FILE_HPP