#ifndef PROVINCE_HPP
#define PROVINCE_HPP

#include <string>

class Province
{
private:
    std::string name;

public:
    Province();
    void set_name(std::string name);
    std::string get_name() const;
};

#endif // PROVINCE_HPP
