#ifndef SIST2_ELASTIC_H
#define SIST2_ELASTIC_H

#include "src/sist.h"

typedef struct es_bulk_line {
    struct es_bulk_line *next;
    char uuid_str[UUID_STR_LEN];
    char line[0];
} es_bulk_line_t;

/**
 * Note: indexer is *not* thread safe
 */
typedef struct es_indexer es_indexer_t;

void elastic_index_line(es_bulk_line_t *line);

void elastic_flush();

void print_json(cJSON *document, const char uuid_str[UUID_STR_LEN]);

void index_json(cJSON *document, const char uuid_str[UUID_STR_LEN]);

es_indexer_t *create_indexer(const char* es_url);

void destroy_indexer(char *script, char index_id[UUID_STR_LEN]);

void elastic_init(int force_reset);

cJSON *elastic_get_document(const char *uuid_str);

char *elastic_get_status();

void execute_update_script(const char *script, const char index_id[UUID_STR_LEN]);

#endif
