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

#ifndef SQLITE_COMPILER_H
#define SQLITE_COMPILER_H

#include <compiler/statement.h>

/**
 * @brief Statement result
 * @details This enum is used to store the result of the statement.
 */
enum statement_result {
    SQLITE_STATEMENT_SUCCESS,
    SQLITE_STATEMENT_SYNTAX_ERROR,
    SQLITE_STATEMENT_UNRECOGNIZED,
};

/**
 * @brief Parse the statement
 * @details This function parses the statement.
 * @param source The source code
 * @param statement The statement
 * @return The result of the statement
 */
extern enum statement_result 
    parse_statement(const char* source, statement_t* statement);

#endif