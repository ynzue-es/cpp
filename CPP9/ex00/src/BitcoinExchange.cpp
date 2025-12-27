#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _exchangeRates(src._exchangeRates) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    if (this != &rhs) {
        _exchangeRates = rhs._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(std::string const & filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    if (!file)
        throw std::runtime_error("Error: could not open database.");
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        if(!std::getline(ss, date, ',') ||
           !std::getline(ss, rate))
		   continue;
		_exchangeRates[date] = std::atof(rate.c_str());
    }
}

void BitcoinExchange::processInputFile(std::string const & filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    if (!file) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        double value = std::atof(valueStr.c_str());
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
		if (_exchangeRates.empty()) {
			std::cout << "Error: database empty." << std::endl;
			return;
		}
        std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);
		// if we don't move and date is not exact (only case we don't have value)
        if (it == _exchangeRates.begin() && it->first != date) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (it == _exchangeRates.end() || it->first != date)
            --it;
        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}