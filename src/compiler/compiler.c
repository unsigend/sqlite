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

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <compiler/compiler.h>

#define INSERT "INSERT"
#define SELECT "SELECT"
#define INSERT_LEN 6
#define SELECT_LEN 6

#define SQLITE_STATEMENT_MATH(SOURCE, TYPE) \
    (strncmp(SOURCE, TYPE, TYPE##_LEN) == 0)

enum statement_result parse_statement(const char* source, statement_t* statement) {
    // convert the source to uppercase
    char* source_upper = strdup(source);
    for (size_t i = 0; i < strlen(source_upper); i++) {
        source_upper[i] = toupper(source_upper[i]);
    }
    // parse the statement
    if (SQLITE_STATEMENT_MATH(source_upper, INSERT)){
        statement->type = SQLITE_STATEMENT_INSERT;
        return SQLITE_STATEMENT_SUCCESS;
    }
    else if (SQLITE_STATEMENT_MATH(source_upper, SELECT)) {
        statement->type = SQLITE_STATEMENT_SELECT;
        return SQLITE_STATEMENT_SUCCESS;
    }

    // free the source_upper
    free(source_upper);

    return SQLITE_STATEMENT_UNRECOGNIZED;
}

