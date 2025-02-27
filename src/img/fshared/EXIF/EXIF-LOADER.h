#pragma-once 

#ifndef EXIFLOADER_EXPORTS
#define EXIFLOADER_EXPORTS 
#endif /* ifndef EXIFLOADER_EXPORTS */


void process_images_in_directory(const char* directory, const char* output_file);
char* get_iptc_json(const char* filename);
