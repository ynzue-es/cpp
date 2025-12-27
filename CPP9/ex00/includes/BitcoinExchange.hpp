#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _exchangeRates;

    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & src);
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        ~BitcoinExchange();

        void loadDatabase(std::string const & filename);
        void processInputFile(std::string const & filename);
};

#endif