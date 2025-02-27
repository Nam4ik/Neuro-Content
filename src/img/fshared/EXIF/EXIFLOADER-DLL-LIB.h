#pragma-once 


#ifdef EXIFLOADER_EXPORTS
 
    #define EXIFLOADER_API __declspec(dllexport)

  #else 
    
    #define EXIFLOADER_API __declspec(dllexport)

#endif

#define EXIFLOADER_EXPORTS

extern "C" EXIFLOADER_API char* get_exif_json(const char* filename);

