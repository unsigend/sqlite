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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <util/buffer.h>
#include <shell/command.h>

#define SQLITE_SPACE_ALIGNMENT 16

// shell meta command table
shell_meta_command_t shell_meta_command_table[] = {
    {SQLITE_META_COMMAND_EXIT, "Exit the shell", shell_meta_command_exit},
    {SQLITE_META_COMMAND_HELP, "Show help", shell_meta_command_help},
    {SQLITE_META_COMMAND_OPEN, "Open a database", shell_meta_command_open},
};

// shell meta command table size
size_t shell_meta_command_table_size = sizeof(shell_meta_command_table) 
    / sizeof(shell_meta_command_table[0]);

// exit meta command function
enum shell_meta_command_result shell_meta_command_exit(input_buffer_t* buffer) {
    // free the buffer
    input_buffer_free(buffer);
    // exit the shell
    exit(EXIT_SUCCESS);
    return SQLITE_META_COMMAND_SUCCESS;
}

// help meta command function
enum shell_meta_command_result shell_meta_command_help(input_buffer_t* buffer) {
    // print the help message with right space alignment
    for (size_t i = 0; i < shell_meta_command_table_size; i++) {
        shell_meta_command_t meta_command = shell_meta_command_table[i];
        fprintf(stdout, "%-*s %s\n", SQLITE_SPACE_ALIGNMENT, meta_command.name, meta_command.description);
    }
    
    return SQLITE_META_COMMAND_SUCCESS;
}

// open meta command function
enum shell_meta_command_result shell_meta_command_open(input_buffer_t* buffer) {
    return SQLITE_META_COMMAND_SUCCESS;
}

enum shell_meta_command_result 
    shell_meta_command_execute(input_buffer_t* buffer) {
    const char* command = input_buffer_get_data(buffer);

    for (size_t i = 0; i < shell_meta_command_table_size; i++) {
        shell_meta_command_t meta_command = shell_meta_command_table[i];
        if (strcmp(command, meta_command.name) == 0) {
            return meta_command.function(buffer);
        }
    }

    return SQLITE_META_COMMAND_UNRECOGNIZED;
}