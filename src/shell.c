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

#include <shell.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <util/buffer.h>

static void shell_print_prompt(){
    fprintf(stdout, SQLITE_SHELL_PROMPT);
}

static void shell_execute_command(input_buffer_t* buffer){
    const char* command = input_buffer_get_data(buffer);

    if (strcmp(command, SQLITE_COMMAND_EXIT) == 0){
        input_buffer_free(buffer);
        exit(EXIT_SUCCESS);
    }else {
        fprintf(stderr, "Unknown command: %s\n", command);
    }
}

/**
 * Simple REPL state machine implementation
 */
void shell_repl(){
    input_buffer_t* buffer = input_buffer_new();

    while (true) {
        // print the prompt
        shell_print_prompt();
        // read the input
        input_buffer_read(buffer);
        // execute the command
        shell_execute_command(buffer);
    }
}