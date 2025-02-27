#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iptc/data.h>
#include <cJSON.h>

// Функция для получения IPTC метаданных из файла
char* get_iptc_json(const char* filename) {
    
    IptcData *iptc_data = iptc_data_new_from_file(filename, NULL);
    if (!iptc_data) return NULL;


    cJSON *root = cJSON_CreateObject();
    cJSON *file_obj = cJSON_CreateObject();
    cJSON_AddItemToObject(root, filename, file_obj);


    cJSON *iptc_metadata = cJSON_CreateObject();
    cJSON_AddItemToObject(file_obj, "IPTC_Metadata", iptc_metadata);

    
    for (int i = 0; i < iptc_data->record_count; i++) {
        IptcRecord *record = iptc_data->records[i];
        for (int j = 0; j < record->dataset_count; j++) {
            IptcDataset *dataset = record->datasets[j];
            if (!dataset || !dataset->value) continue;

          
            char tag_name[128];
            snprintf(tag_name, sizeof(tag_name), "Record%02d.Dataset%02d",
                     record->num, dataset->num);

            
            cJSON_AddStringToObject(iptc_metadata, tag_name, (char*)dataset->value);
        }
    }

    
    char *json_result = cJSON_Print(root);

    
    cJSON_Delete(root);
    iptc_data_free(iptc_data);

    return json_result;
}


void process_images_in_directory(const char* directory, const char* output_file) {
    DIR *dir = opendir(directory);
    if (!dir) {
        fprintf(stderr, "Не удалось открыть директорию: %s\n", directory);
        return;
    }

    cJSON *root = cJSON_CreateObject();
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
        if (strstr(entry->d_name, ".jpg") == NULL && strstr(entry->d_name, ".jpeg") == NULL) continue;

        
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

      
        char *iptc_json = get_iptc_json(full_path);
        if (iptc_json) {
            cJSON *file_obj = cJSON_Parse(iptc_json);
            if (file_obj) {
                cJSON_AddItemToObject(root, entry->d_name, file_obj);
            }
            free(iptc_json);
        }
    }

    closedir(dir);

    // Записываем результат в JSON файл
    char *output_json = cJSON_Print(root);
    FILE *file = fopen(output_file, "w");
    if (file) {
        fputs(output_json, file);
        fclose(file);
        printf("Данные успешно записаны в %s.\n", output_file);
    } else {
        fprintf(stderr, "Не удалось создать файл: %s\n", output_file);
    }

    cJSON_Delete(root);
    free(output_json);
}

/*
int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <directory> <output_json>\n", argv[0]);
        return 1;
    }

    const char* directory = argv[1];
    const char* output_file = argv[2];

    process_images_in_directory(directory, output_file);

    return 0;
}
*/
