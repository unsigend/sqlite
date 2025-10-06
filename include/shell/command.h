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

// shell command definitions
#define SQLITE_COMMAND_EXIT ".exit"
#define SQLITE_COMMAND_HELP ".help"
#define SQLITE_COMMAND_OPEN ".open"


// shell command declarations

/**
 * @brief Exit the shell
 * @details This function exits the shell.
 */
extern void shell_command_exit();

#endif