/* sqlite - A rebuild of sqlite core features
 * Copyright (C) 2025 Yixiang Qiu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SQLITE_BUFFER_H
#define SQLITE_BUFFER_H

#include <stddef.h>

/**
 * @brief Input buffer structure
 * @details This structure is used to store the input buffer for the sqlite
 *          command line interface.
 */
typedef struct {
    char * buffer;
    size_t length;
    size_t capacity;
} input_buffer_t;

/**
 * @brief Create a new input buffer
 * @details This function creates a new input buffer.
 * @return The new input buffer
 */
extern input_buffer_t* input_buffer_new();

/**
 * @brief Get the data from the input buffer
 * @details This function gets the data from the input buffer.
 * @param buffer The input buffer
 * @return The data from the input buffer
 */
extern char* input_buffer_get_data(input_buffer_t* buffer);

/**
 * @brief Free the input buffer
 * @details This function frees the input buffer.
 * @param buffer The input buffer
 */
extern void input_buffer_free(input_buffer_t* buffer);

/**
 * @brief Read the input buffer
 * @details This function reads the input buffer.
 * @param buffer The input buffer
 */
extern void input_buffer_read(input_buffer_t* buffer);

#endif