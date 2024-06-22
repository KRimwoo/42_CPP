#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _exchange = other._exchange;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(std::string date) const {
    
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (int i = 0; i < 4; i++) {
        if (!std::isdigit(yearStr[i])) {
            return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (!std::isdigit(monthStr[i]) || !std::isdigit(dayStr[i])) {
            return false;
        }
    }

    std::tm inputTime = {};
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    inputTime.tm_year = year - 1900;
    inputTime.tm_mon = month - 1;
    inputTime.tm_mday = day;

    std::time_t convertedTime = std::mktime(&inputTime);
    std::tm *outputTime = std::localtime(&convertedTime);

    return (year - 1900) == outputTime->tm_year &&
           (month - 1) == outputTime->tm_mon &&
           (day) == outputTime->tm_mday;
}


void BitcoinExchange::init(std::string data) {
    std::ifstream dataBase(data.c_str());

    if (!dataBase.is_open())
        throw std::runtime_error("Error: Data file not found");
    
    std::string line;
    std::getline(dataBase, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Invalid file format");
    
    while (std::getline(dataBase, line)) {
        if (line.find(',') == std::string::npos)
            throw std::runtime_error("Invalid data file format");
        std::string dateKey = line.substr(0, line.find(','));
        std::string priceValue = line.substr(line.find(',') + 1);
        if (line.find(',', line.find(',') + 1) != std::string::npos)
            throw std::runtime_error("Invalid data file format");
        if (!isValidDate(dateKey))
            throw std::runtime_error("Invalid date format in data file");
        char *end = NULL;
        float price = std::strtof(priceValue.c_str(), &end);
        if (*end != '\0' || errno == ERANGE)
            throw std::runtime_error("Invalid price format");
        _exchange.insert(std::make_pair(dateKey, price));
    }
    dataBase.close();
}

void BitcoinExchange::exchange(std::string input) {
    std::fstream inputFile(input.c_str());

    if (!inputFile.is_open()) {
        printError("could not open file.");
        return ;
    }
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value") {
        printError("invalid file format");
        return ;
    }
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string data;
        int index = 0;
        std::string date;
        float value;
        while (std::getline(ss, data, ' ')) {
            if (index == 0) {
                if (!isValidDate(data)) {
                    printError("bad input => " + data);
                    break ;
                }
                date = data;
            }
            else if (index == 1) {
                if (data != "|")
                {
                    printError("wrong separator");
                    break ;
                }
            }
            else if (index == 2) {
                if (data == "") {
                    printError("no value");
                    break ;
                }
                char *end = NULL;
                value = std::strtof(data.c_str(), &end);
                if (*end != '\0' || errno == ERANGE) {
                    printError("not a float number");
                    break ;
                }
                if (value < 0) {
                    printError("not a positive number");
                    break ;
                }
                if (value > 1000) {
                    printError("too large a number");
                    break ;
                }
                printExchange(date, value);
            }
            else {
                printError("too many arguments");
                break ;
            }
            index++;
        }
        
    }
    
}

void BitcoinExchange::printError(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
}

void BitcoinExchange::printExchange(std::string date, float value) {
    std::map<std::string, float>::iterator it;
    it = _exchange.find(date);
    if (it != _exchange.end()) {
        std::cout << date << " => " << value << " = " << it->second *value << std::endl;
    }
    else {
        it = _exchange.lower_bound(date);
        if (it == _exchange.begin()) {
            printError("bad input => " + date);
        }
        else {
            it--;
            std::cout << date << " => " << value << " = " << it->second * value << std::endl;
        }
    }
}