/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:59:40 by cagonzal          #+#    #+#             */
/*   Updated: 2025/11/28 21:59:19 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>

/**
 * @brief Parse and initialize a BitcoinExchange object from a single input line.
 *
 * Initializes member fields, stores the original input string and attempts to
 * split it into exactly two segments (date and value) using the provided
 * delimiter. If the input does not split into two segments, an error message
 * is recorded in _error_detected and no further parsing is performed.
 *
 * The parsed date segment is trimmed of surrounding whitespace and passed to
 * set_date(...). The parsed value segment is trimmed and passed to
 * set_bit_value(..., arch_type). The arch_type parameter is forwarded to
 * set_bit_value and is otherwise unused within the constructor.
 *
 * Error handling: malformed input is not reported via exceptions; instead the
 * member _error_detected is set to "Error: bad input => <input>".
 *
 * @param str        Input line to parse (also stored in _origin).
 * @param del        Delimiter character used to separate date and value.
 * @param arch_type  Architecture/type flag forwarded to set_bit_value.
 *
 * @note Leading and trailing whitespace characters are removed from both
 *       segments using trim(...). Token count validation is performed with
 *       get_origin_size(...).
 *
 * @complexity O(n) where n is the length of the input string (tokenization and trimming).
 */
BitcoinExchange::BitcoinExchange( std::string str , char del, int arch_type) : _origin(str) , _unix_date(0), _bit_value(0), _error_detected("") 
{
    (void)arch_type;
    std::stringstream 	test(str);
    std::string 		segment;

    if (this->get_origin_size(str, del) != 2)
        this->_error_detected = "Error: bad input => "+ str;
    else
    {
        std::getline(test,segment,del);
        this->set_date(this->trim(segment, " \n\r\t\f\v"));
        std::getline(test,segment,del);
        this->set_bit_value(this->trim(segment, " \n\r\t\f\v"), arch_type);
    }
    return ; 
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &tmp) {

    this->_origin = tmp.get_origin();
    this->_bit_value = tmp.get_bit_value();
    this->_date.tm_year = tmp.get_date().tm_year;
    this->_date.tm_mon = tmp.get_date().tm_mon;
    this->_date.tm_mday = tmp.get_date().tm_mday;
    this->_error_detected = tmp.get_error();
    this->_unix_date = tmp.get_unix_date();
    this->_exchange_rates = tmp._exchange_rates; // Copy the map
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const BitcoinExchange &tmp) {

    if (tmp.get_error() != "")
        os << tmp.get_error() << std::endl;
    else
        os <<"Date : "<< tmp.get_string_date() << " == " << tmp.get_unix_date() << " - Value : " << tmp.get_bit_value() << std::endl;
    return (os);
}

std::string BitcoinExchange::trim(std::string str , std::string to_trim)
{
    //Trim from left
    for (int x = 0; x < (int)str.length(); x++)
    {
        if (to_trim.find(str[x]) == std::string::npos)
        {  
            str.erase(0 , x);
            break;
        }      
    }
    //Trim from right
    for (int x = (int)str.length() - 1; x >= 0; x--)
    {
        if (to_trim.find(str[x]) == std::string::npos)
        {  
            str.erase(x + 1);
            break;
        }  
    }
    return (str);
}

std::string BitcoinExchange::get_string_date(void) const
{
    std::string date = "";
    
    if (this->get_error() == "")
    {
        // C++98 compatible string conversion
        std::stringstream ss;
        ss << (this->_date.tm_year + 1900) << "-" << (this->_date.tm_mon + 1) << "-" << this->_date.tm_mday;
        date = ss.str();
    }
    else
        date = "Error Date";
    return (date);
}

void BitcoinExchange::set_bit_value (std::string str , int  arch_type)
{
    char * e;
    
    this->_bit_value = std::strtod(str.c_str(), &e);
    
    if (arch_type == 1 && (this->_bit_value < 0))	
        this->_error_detected = "Error: not a positive number.";
    if (arch_type == 1 && (this->_bit_value > 1000))	
        this->_error_detected = "Error: too large a number.";
    if (this->_bit_value < 0 && this->_error_detected == "" )
        this->_error_detected = "Error: not a positive number.";
}

void BitcoinExchange::set_date (std::string str)
{
    std::memset(&this->_date, 0, sizeof(this->_date));
    
    std::stringstream ss(str);
    std::string year_str, month_str, day_str;
    
    if (std::getline(ss, year_str, '-') && 
        std::getline(ss, month_str, '-') && 
        std::getline(ss, day_str))
    {
        int year = std::atoi(year_str.c_str());
        int month = std::atoi(month_str.c_str());
        int day = std::atoi(day_str.c_str());
        
        if (year > 1900 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
        {
            this->_date.tm_year = year - 1900;
            this->_date.tm_mon = month - 1;
            this->_date.tm_mday = day;
            
            std::time_t time_unix = std::mktime(&this->_date);
            this->_unix_date = time_unix;
        }
        else
            this->_error_detected = "Error: bad date provided.";
    }
    else
        this->_error_detected = "Error: bad date provided.";
}

int BitcoinExchange::get_origin_size(std::string str, char del)
{
    std::stringstream 	test(str);
    std::string 		segment;
    int                 x;

    x = 0;
    while (std::getline(test, segment, del))
        x++;
    return (x);
}

void BitcoinExchange::init_with_database(const std::string& db_filename)
{
    this->load_database(db_filename);
}

void BitcoinExchange::load_database(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    
    if (!file.is_open()) {
        this->_error_detected = "Error: could not open database file.";
        return;
    }
    
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        BitcoinExchange temp_entry(line, ',', 0); // 0 for database entries
        if (temp_entry.get_error() == "") {
            this->_exchange_rates[temp_entry.get_unix_date()] = temp_entry.get_bit_value();
        }
    }
    file.close();
}

double BitcoinExchange::find_closest_rate(std::time_t date) const
{
    if (this->_exchange_rates.empty()) {
        return 0.0;
    }
    
    std::map<std::time_t, double>::const_iterator it = this->_exchange_rates.lower_bound(date);
    
    // If exact date found
    if (it != this->_exchange_rates.end() && it->first == date) {
        return it->second;
    }
    
    // If date is before first entry, use first entry
    if (it == this->_exchange_rates.begin()) {
        return it->second;
    }
    
    // Use previous date (closest earlier date)
    --it;
    return it->second;
}

double BitcoinExchange::calculate_value(double amount) const
{
    if (this->_error_detected != "") {
        return 0.0;
    }
    
    double rate = this->find_closest_rate(this->_unix_date);
    return amount * rate;
}