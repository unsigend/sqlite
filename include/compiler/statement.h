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

#ifndef SQLITE_STATEMENT_H
#define SQLITE_STATEMENT_H

/**
 * @brief Statement type
 * @details This enum is used to store the type of the statement.
 */
enum statement_type {
    SQLITE_STATEMENT_INSERT,
    SQLITE_STATEMENT_SELECT,
};

/**
 * @brief Statement structure
 * @details This structure is used to store the statement.
 */
typedef struct {
    enum statement_type type;
} statement_t;


#endif