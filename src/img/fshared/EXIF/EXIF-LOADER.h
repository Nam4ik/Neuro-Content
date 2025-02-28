#pragma-once 

#ifndef EXIF_PARSER_H
#define EXIF_PARSER_H

#include <cjson/cJSON.h>

#ifdef __cplusplus
extern "C" {
#endif
char* process_files(const char** filenames, int count);
void free_json_result(char* json);
#ifdef __cplusplus
}
#endif

#endif // EXIF_PARSER_H
