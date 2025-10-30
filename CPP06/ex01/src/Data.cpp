/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:29:18 by cagonzal          #+#    #+#             */
/*   Updated: 2025/10/30 12:04:58 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(std::string name) : _name(name)
{
    return;
}
Data::~Data()
{
    return;
}
/**
 * @brief Convert a Data pointer into an integer representation.
 *
 * Reinterprets the pointer value as a uintptr_t so the pointer can be stored or
 * passed around as an integer. This is intended to be used together with a
 * matching deserialize function that converts the uintptr_t back to a Data*.
 *
 * @param ptr Pointer to a Data object to serialize. May be nullptr.
 * @return uintptr_t Integer containing the pointer's bit pattern. If ptr is
 *         nullptr the function returns 0. The result is meaningful only within
 *         the same process/address space and the same binary; it must not be
 *         used for persistent storage or to communicate pointer values between
 *         different processes or programs.
 *
 * @note No memory is allocated or freed and there are no side effects.
 *       The conversion preserves the underlying bit pattern of the pointer,
 *       but exact representation details are implementation-defined.
 */
uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
/**
 * @brief Reinterpret an integer as a pointer to Data.
 *
 * Reconstructs a Data* from an integer representation using reinterpret_cast.
 * This function is intended to be the inverse of a corresponding serialize()
 * function that converted a Data* into a uintptr_t.
 *
 * @param raw Integer representation (uintptr_t) of a Data* as produced by serialize().
 *            A value of 0 will be converted to a null pointer.
 *
 * @return Pointer to Data corresponding to the provided integer. No ownership is
 *         transferred or altered by this function; the caller remains responsible
 *         for the object's lifetime and deletion, if applicable.
 *
 * @note Passing a value that was not produced by serialize(), or a value that
 *       does not represent a valid, properly aligned Data* leads to undefined behavior.
 *       The returned pointer must not be dereferenced unless it is known to be valid.
 */
Data *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
