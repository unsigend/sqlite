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
#include <stdlib.h>
#include <shell/command.h>

typedef struct {
    const char * name;
    const char * description;
} shell_command_t;

// shell commands constant table
static shell_command_t shell_commands[] = {
    {SQLITE_COMMAND_EXIT, "Exit the shell"},
    {SQLITE_COMMAND_HELP, "Show help"},
    {SQLITE_COMMAND_OPEN, "Open a database"},
};

void shell_command_exit() {
    exit(EXIT_SUCCESS);
}

void shell_command_help() {

}