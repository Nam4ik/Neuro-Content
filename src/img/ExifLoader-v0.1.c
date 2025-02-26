#include <stdio.h>
#include <libexif/exif-data.h>

void read_all_exif_tags(const char *filename) {
    ExifData *exif_data = exif_data_new_from_file(filename);
    if (!exif_data) return;

    ExifByteOrder byte_order = exif_data_get_byte_order(exif_data);

    for (int ifd = 0; ifd < EXIF_IFD_COUNT; ifd++) {
        ExifContent *content = exif_data->ifd[ifd];
        if (!content) continue;

        for (unsigned int i = 0; i < content->count; i++) {
            ExifEntry *entry = content->entries[i];
            char value[1024];
            exif_entry_get_value(entry, value, sizeof(value));

          
            const char *tag_name = exif_tag_get_name(entry->tag);
            if (!tag_name) {
              
                printf("[%s] Unknown tag 0x%04X: %s\n", 
                       exif_ifd_get_name((ExifIfd)ifd),
                       entry->tag, value);
            } else {
                printf("[%s] %s: %s\n", 
                       exif_ifd_get_name((ExifIfd)ifd),
                       tag_name, value);
            }
        }
    }

    exif_data_unref(exif_data);
}
