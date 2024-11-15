#ifndef BITCOINEXCHANGE.HPP
# define BITCOINEXCHANGE.HPP

#include <iostream>
#include <map>

class Bitcoin{
    private:
        Bitcoin();

        std::map<std::string, double> pair;
        std::string startDate;
        void    getData(const std::string &file);
    public:
        Bitcoin(const std::string &file);
        Bitcoin(const Bitcoin &other);
        Bitcoin &operator=(const Bitcoin &other);
        ~Bitcoin();
        double  getRate(const std::string &date);
        void    Input(const std::string &file);
};

#endif