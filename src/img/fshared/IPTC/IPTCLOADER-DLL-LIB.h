#pragma-once 

#ifdef IPTCLOADER_EXPORTS

    #define IPTCLOADER_API __declspec(dllexport)
  
  #else

    #define IPTCLOADER_API __declspec(dllexport)

#endif 


extern "C" EXIFLOADER_API char* get_iptc_json(const char* filename);
