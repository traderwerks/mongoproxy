/*
 * file   : buf.h
 * author : ning
 * date   : 2012-09-25 00:24:41
 */

#ifndef _BUF_H_
#define _BUF_H_

typedef struct buffer_s {
    char *ptr;

    size_t used;
    size_t size;
} buffer_t;

buffer_t *buffer_new(size_t len);
void buffer_free(buffer_t * b);
void buffer_reset(buffer_t * b);

int buffer_prepare_copy(buffer_t * b, size_t size);
int buffer_prepare_append(buffer_t * b, size_t size);

int buffer_append_memory(buffer_t * b, const void *s, size_t s_len);
int buffer_copy_memory(buffer_t * b, const void *s, size_t s_len);

int buffer_is_empty(buffer_t * b);
int buffer_is_equal(buffer_t * a, buffer_t * b);

int buffer_append_raw_int32(buffer_t * b, int32_t arg);
int buffer_append_raw_int64(buffer_t * b, int64_t arg);

int buffer_append_printf(buffer_t * b, char *fmt, ...);
int buffer_append_trailing_null(buffer_t * b);
#endif
