/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:59:40 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/05 12:41:54 by cagonzal         ###   ########.fr       */
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

/**
 * @brief Assignment operator for BitcoinExchange.
 *
 * Performs a deep copy of all member variables from the source object to this
 * object. This includes the origin string, bitcoin value, date components,
 * error message, unix timestamp, and the complete exchange rates map.
 *
 * @param tmp The source BitcoinExchange object to copy from.
 * @return Reference to this object after assignment.
 *
 * @complexity O(n) where n is the size of the exchange rates map.
 */
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

/**
 * @brief Stream insertion operator for BitcoinExchange.
 *
 * Outputs the BitcoinExchange object to the given output stream. If an error
 * has been detected during parsing or validation, outputs the error message.
 * Otherwise, outputs the formatted date (both string and unix timestamp) along
 * with the bitcoin value.
 *
 * @param os  The output stream to write to.
 * @param tmp The BitcoinExchange object to output.
 * @return Reference to the output stream for chaining.
 *
 * @note Format with error: "<error_message>"
 * @note Format without error: "Date : YYYY-MM-DD == <unix_timestamp> - Value : <value>"
 */
std::ostream &operator<<(std::ostream& os, const BitcoinExchange &tmp) {

	if (tmp.get_error() != "")
		os << tmp.get_error() << std::endl;
	else
		os <<"Date : "<< tmp.get_string_date() << " == " << tmp.get_unix_date() << " - Value : " << tmp.get_bit_value() << std::endl;
	return (os);
}

/**
 * @brief Trim specified characters from both ends of a string.
 *
 * Removes all leading and trailing characters that appear in the to_trim
 * string. The function first removes characters from the left side, then
 * from the right side of the input string.
 *
 * @param str      The string to be trimmed.
 * @param to_trim  String containing characters to remove from both ends.
 * @return A new string with specified characters removed from both ends.
 *
 * @note Common usage: trim(input, " \n\r\t\f\v") to remove whitespace.
 * @complexity O(n) where n is the length of the input string.
 */
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

/**
 * @brief Get the date as a formatted string.
 *
 * Converts the internal date representation (struct tm) to a human-readable
 * string in the format "YYYY-MM-DD". If an error has been detected, returns
 * "Error Date" instead.
 *
 * @return Formatted date string "YYYY-MM-DD" or "Error Date" if invalid.
 *
 * @note The tm_year field is offset by 1900 and tm_mon by 1 for correct formatting.
 * @note Uses C++98 compatible string conversion via stringstream.
 */
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

/**
 * @brief Parse and validate a bitcoin value from a string.
 *
 * Converts the input string to a double value using strtod and performs
 * validation based on the arch_type parameter. Sets appropriate error
 * messages if validation fails.
 *
 * @param str       String representation of the bitcoin value.
 * @param arch_type Validation mode:
 *                  - 1: Enforce range [0, 1000] (for input validation)
 *                  - 0: Only enforce non-negative (for database entries)
 *
 * @note Sets _error_detected if:
 *       - Value is negative (always)
 *       - Value exceeds 1000 (when arch_type == 1)
 */
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

/**
 * @brief Parse and validate a date string in YYYY-MM-DD format.
 *
 * Parses a date string and initializes the internal _date struct (tm) and
 * _unix_date timestamp. The date must be in format "YYYY-MM-DD" with valid
 * ranges for each component.
 *
 * @param str Date string in format "YYYY-MM-DD".
 *
 * @note Valid ranges:
 *       - Year: > 1900
 *       - Month: 1-12
 *       - Day: 1-31
 * @note Sets _error_detected to "Error: bad date provided." if:
 *       - Format is incorrect
 *       - Values are out of valid range
 * @note The struct tm fields are adjusted: tm_year = year - 1900, tm_mon = month - 1
 */
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

/**
 * @brief Count the number of segments in a delimited string.
 *
 * Splits the input string by the specified delimiter and returns the count
 * of resulting segments. Used to validate that input lines contain exactly
 * two parts (date and value).
 *
 * @param str String to analyze.
 * @param del Delimiter character to split on.
 * @return Number of segments found in the string.
 *
 * @note Empty segments are counted.
 * @complexity O(n) where n is the length of the string.
 */
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

/**
 * @brief Initialize the exchange rates from a database file.
 *
 * Loads historical bitcoin exchange rates from the specified CSV database
 * file. This is a convenience wrapper around load_database.
 *
 * @param db_filename Path to the CSV database file containing exchange rates.
 *
 * @see load_database(const std::string&)
 */
void BitcoinExchange::init_with_database(const std::string& db_filename)
{
	this->load_database(db_filename);
}

/**
 * @brief Load exchange rate data from a CSV file into the internal map.
 *
 * Opens and parses a CSV file containing historical bitcoin exchange rates.
 * The file format should be: date,exchange_rate with a header line that is
 * skipped. Each valid entry is stored in the _exchange_rates map with the
 * unix timestamp as the key and the rate as the value.
 *
 * @param filename Path to the CSV database file.
 *
 * @note Sets _error_detected to "Error: could not open database file." if file
 *       cannot be opened.
 * @note The first line (header) is always skipped.
 * @note Invalid entries (with parsing errors) are silently skipped.
 * @note Uses comma ',' as delimiter and arch_type 0 for parsing.
 */
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

/**
 * @brief Find the exchange rate for a given date or the closest earlier date.
 *
 * Searches the exchange rates map for the given date. If an exact match is
 * found, returns that rate. Otherwise, returns the rate from the closest
 * earlier date. If the requested date is before all entries, returns the
 * earliest available rate.
 *
 * @param date Unix timestamp of the date to look up.
 * @return Exchange rate for the date or closest earlier date, or 0.0 if map is empty.
 *
 * @note Uses std::map::lower_bound for efficient O(log n) lookup.
 * @note Always returns a valid rate unless the database is empty.
 * @complexity O(log n) where n is the number of entries in the exchange rates map.
 */
double BitcoinExchange::find_closest_rate(std::time_t date) const
{
	if (this->_exchange_rates.empty())
		return 0.0;
	
	std::map<std::time_t, double>::const_iterator it = this->_exchange_rates.lower_bound(date);
	
	// If exact date found
	if (it != this->_exchange_rates.end() && it->first == date)
		return it->second;
	
	// If date is before first entry, use first entry
	if (it == this->_exchange_rates.begin())
		return it->second;
	
	// Use previous date (closest earlier date)
	--it;
	return it->second;
}

/**
 * @brief Calculate the value of bitcoins at the stored date.
 *
 * Multiplies the given bitcoin amount by the exchange rate for this object's
 * date (or the closest earlier date if exact match not found). Returns 0.0
 * if any error has been detected during parsing or validation.
 *
 * @param amount Number of bitcoins to value.
 * @return Total value in the currency of the exchange rate, or 0.0 if error detected.
 *
 * @note Returns 0.0 if _error_detected is not empty.
 * @see find_closest_rate(std::time_t) for rate lookup logic.
 */
double BitcoinExchange::calculate_value(double amount) const
{
	if (this->_error_detected != "") {
		return 0.0;
	}
	
	double rate = this->find_closest_rate(this->_unix_date);
	return amount * rate;
}