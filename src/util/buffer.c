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

#include <util/buffer.h>
#include <stdlib.h>
#include <stdio.h>

input_buffer_t* input_buffer_new(){
    input_buffer_t* buffer = (input_buffer_t*)malloc(sizeof(input_buffer_t));
    // this will let getline allocate the memory for the buffer
    buffer->buffer = NULL;
    buffer->length = 0;
    buffer->capacity = 0;
    return buffer;
}

char* input_buffer_get_data(input_buffer_t* buffer){
    // just a simple wrapper for the buffer
    return buffer->buffer;
}

void input_buffer_free(input_buffer_t* buffer){
    if (buffer->buffer != NULL){
        free(buffer->buffer);
    }
    free(buffer);
}

void input_buffer_read(input_buffer_t* buffer){
    ssize_t bytes_read = getline(&buffer->buffer, &buffer->capacity, stdin);

    if (bytes_read == -1){
        fprintf(stderr, "Error: Failed to read input\n");
        exit(EXIT_FAILURE);
    }

    // remove the trailing newline
    buffer->length = bytes_read - 1;
    buffer->buffer[buffer->length] = '\0';
}