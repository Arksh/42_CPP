/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:59:16 by cagonzal          #+#    #+#             */
/*   Updated: 2025/12/05 13:20:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <string>
# include <iostream>
# include <ctime>
# include <map>
# include <fstream>

/**
 * @class BitcoinExchange
 * @brief A class for managing Bitcoin exchange rates and calculating Bitcoin values based on dates.
 * 
 * This class handles the storage and retrieval of historical Bitcoin exchange rates from a database file.
 * It allows parsing of dates and Bitcoin amounts, finding the closest exchange rate for a given date,
 * and calculating the value of a Bitcoin amount based on historical rates.
 * 
 * @note The class uses std::map to store exchange rates indexed by Unix timestamps for efficient
 *       lookup of historical rates.
 */
class	BitcoinExchange {

    private:
        std::string _origin;
        std::tm 	_date;
        std::time_t	_unix_date;
        double		_bit_value;
        std::string _error_detected;
        std::map<std::time_t, double> _exchange_rates; // Container for storing rates
        
        int get_origin_size			(std::string str, char del);
        void set_bit_value			(std::string str, int  arch_type);
        void set_date				(std::string str);
        std::string trim			(std::string str , std::string to_trim);
        void load_database			(const std::string& filename);
        double find_closest_rate	(std::time_t date) const;
    
    public:

        BitcoinExchange				( void ) :_origin("") , _unix_date(0), _bit_value(0), _error_detected("") {};
        BitcoinExchange 			( std::string str , char del , int arch_type );
        BitcoinExchange 			( const BitcoinExchange & var ) { *this = var;  };
        ~BitcoinExchange			( void ) {};
        BitcoinExchange &operator=	(const BitcoinExchange &tmp);

        // Add method to initialize with database
        void init_with_database		(const std::string& db_filename);
        
        std::string get_origin		(void)	const	{ return(this->_origin); };
        double 		get_bit_value	(void)	const	{ return(this->_bit_value); };
        std::tm		get_date		(void)	const 	{ return(this->_date); };
        std::string	get_error		(void)	const 	{ return(this->_error_detected); };
        std::time_t get_unix_date 	(void)	const	{ return(this->_unix_date); };
        std::string get_string_date	(void)	const;
        
        // Method to calculate value based on stored rates
        double calculate_value		(double amount) const;
};
std::ostream &operator<<(std::ostream& os, const BitcoinExchange &tmp);

#endif