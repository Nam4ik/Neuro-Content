#pragma-once 


#ifdef EXIFLOADER_EXPORTS
 
    #define EXIFLOADER_API __declspec(dllexport)

  #else 
    
    #define EXIFLOADER_API __declspec(dllexport)

#endif

#define EXIFLOADER_EXPORTS
#include <cjson/cJSON.h>

#ifdef __cplusplus
  extern "C" EXIFLOADER_API char* process_files(const char** filenames, int count);
  extern "C" EXIFLOADER_API void free_json_result(char* json);
#else 
  EXIFLOADER_API char* process_files(const char** filenames, int count);
  EXIFLOADER_API void free_json_result(char* json);
#endif
