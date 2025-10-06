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
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <util/buffer.h>
#include <shell/command.h>
#include <shell/shell.h>
#include <compiler/statement.h>
#include <compiler/compiler.h>

#define SQLITE_SHELL_PROMPT "sqlite > "

// print the prompt
static void shell_print_prompt(){
    fprintf(stdout, SQLITE_SHELL_PROMPT);
}

static void shell_show_info() {
    fprintf(stdout, "SQLite core version 0.1\n");
    fprintf(stdout, "Enter \".help\" for usage hints.\n");
    fprintf(stdout, "Connected to a transient in-memory database.\n");
    fprintf(stdout, "Use \".open FILENAME\" to open a file database.\n");
    fprintf(stdout, "Use \".exit\" to quit\n");
}

// execute the command
static void shell_execute_command(input_buffer_t* buffer){
    const char* command = input_buffer_get_data(buffer);

    // execute the meta command
    if (command[0] == SQLITE_META_COMMAND){
        switch (shell_meta_command_execute(buffer)) {
            case SQLITE_META_COMMAND_SUCCESS:
                break;
            case SQLITE_META_COMMAND_UNRECOGNIZED:
                fprintf(stderr, "Unknown command: %s\n", command);
                break;
        }
    }
    // execute the sql statement
    else {
        statement_t statement;
        // parse the statement
        switch (parse_statement(command, &statement)) {
            case SQLITE_STATEMENT_SUCCESS:
                break;
            case SQLITE_STATEMENT_SYNTAX_ERROR:
                fprintf(stderr, "Syntax error: %s\n", command);
                break;
            case SQLITE_STATEMENT_UNRECOGNIZED:
                fprintf(stderr, "Unrecognized statement: %s\n", command);
                break;
        }
        // compile the statement

        // execute the statement
    }
}

/**
 * Simple REPL state machine implementation
 */
void shell_repl(){
    input_buffer_t* buffer = input_buffer_new();
    // show the info
    shell_show_info();

    // start the repl loop
    while (true) {
        // print the prompt
        shell_print_prompt();
        // read the input
        input_buffer_read(buffer);
        // execute the command
        shell_execute_command(buffer);
    }
}