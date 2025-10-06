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

#ifndef SQLITE_SHELL_COMMAND_H
#define SQLITE_SHELL_COMMAND_H

// shell command structure
enum shell_meta_command_result {
    SQLITE_META_COMMAND_SUCCESS,
    SQLITE_META_COMMAND_UNRECOGNIZED,
};

// shell meta command function type
typedef enum shell_meta_command_result (*shell_meta_command_function_t)(input_buffer_t* buffer);
// shell meta command structure
typedef struct {
    const char * name;
    const char * description;
    shell_meta_command_function_t function;
} shell_meta_command_t;

// shell meta command table
extern shell_meta_command_t shell_meta_command_table[];
// shell meta command table size
extern size_t shell_meta_command_table_size;

// shell meta command definitions
#define SQLITE_META_COMMAND      '.'
#define SQLITE_META_COMMAND_EXIT ".exit"
#define SQLITE_META_COMMAND_HELP ".help"
#define SQLITE_META_COMMAND_OPEN ".open"


// shell meta command function declarations
/**
 * @brief Execute the meta command
 * @details This function executes the meta command.
 * @param buffer The input buffer
 * @return The result of the meta command
 */
extern enum shell_meta_command_result 
    shell_meta_command_execute(input_buffer_t* buffer);

// shell meta command function declarations
extern enum shell_meta_command_result shell_meta_command_exit(input_buffer_t* buffer);
extern enum shell_meta_command_result shell_meta_command_help(input_buffer_t* buffer);
extern enum shell_meta_command_result shell_meta_command_open(input_buffer_t* buffer);


#endif