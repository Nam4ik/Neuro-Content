#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libexif/exif-data.h>
#include <cjson/cJSON.h>

#define MAX_TAG_VALUE 256

cJSON* get_exif_data(const char* filename) {
    ExifData* exif_data = exif_data_new_from_file(filename);
    if (!exif_data) return NULL;

    cJSON* png_metadata = cJSON_CreateObject();
    
    // Основные теги для извлечения
    struct ExifTagMapping {
        ExifTag tag;
        const char* json_name;
    } tag_mappings[] = {
        {EXIF_TAG_ARTIST, "Author"},
        {EXIF_TAG_IMAGE_DESCRIPTION, "Description"},
        {EXIF_TAG_COPYRIGHT, "Copyright"},
        {EXIF_TAG_SOFTWARE, "Software"},
        {EXIF_TAG_DATETIME, "DateTime"}
    };

    for (int i = 0; i < sizeof(tag_mappings)/sizeof(tag_mappings[0]); i++) {
        ExifEntry* entry = exif_content_get_entry(
            exif_data->ifd[EXIF_IFD_0],
            tag_mappings[i].tag
        );

        if (entry) {
            char value[MAX_TAG_VALUE];
            exif_entry_get_value(entry, value, sizeof(value));
            cJSON_AddStringToObject(png_metadata, tag_mappings[i].json_name, value);
        }
    }

    exif_data_unref(exif_data);
    return png_metadata;
}

cJSON* process_file(const char* filename) {
    cJSON* file_entry = cJSON_CreateObject();
    cJSON* metadata = get_exif_data(filename);
    
    if (metadata) {
        cJSON_AddItemToObject(file_entry, "PNG_Metadata", metadata);
    }
    
    return file_entry;
}

char* generate_json(cJSON* root) {
    char* json = cJSON_Print(root);
    cJSON_Delete(root);
    return json;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file1> [file2 ...]\n", argv[0]);
        return 1;
    }

    cJSON* root = cJSON_CreateObject();

    for (int i = 1; i < argc; i++) {
        cJSON* file_entry = process_file(argv[i]);
        if (file_entry) {
            cJSON_AddItemToObject(root, argv[i], file_entry);
        }
    }

    char* json = generate_json(root);
    printf("%s\n", json);
    free(json);

    return 0;
}
