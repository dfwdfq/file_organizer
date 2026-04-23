#include "include.h"


#define MAX_EXT_CHAR 10
#define MAX_FOLDER_CHAR 20
struct Mapping defaults[] = {
    // Documents 
    {"pdf", "Documents"},
    {"docx", "Documents"},
    {"doc", "Documents"},
    {"txt", "Documents"},
    {"pptx", "Documents"},
    {"ppt", "Documents"},
    {"xlsx", "Documents"},
    {"xls", "Documents"},
    {"csv", "Documents"},
    {"json", "Documents"},
    {"yaml", "Documents"},
    {"xml", "Documents"},
    {"epub", "Documents"},
    {"mobi", "Documents"},
    {"ttf", "Documents"},
    {"woff", "Documents"},
    {"otf", "Documents"},

    // Images  
    {"jpg", "Images"},
    {"jpeg", "Images"},
    {"png", "Images"},
    {"gif", "Images"},
    {"svg", "Images"},
    {"webp", "Images"},
    {"bmp", "Images"},
    {"ico", "Images"},
    {"tiff", "Images"},
    {"tif", "Images"},
    {"eps", "Images"},

    // Videos 
    {"mp4", "Videos"},
    {"mkv", "Videos"},
    {"avi", "Videos"},
    {"mov", "Videos"},
    {"wmv", "Videos"},
    {"flv", "Videos"},
    {"webm", "Videos"},
    {"m4v", "Videos"},

    // Music 
    {"mp3", "Music"},
    {"wav", "Music"},
    {"flac", "Music"},
    {"m4a", "Music"},
    {"ogg", "Music"},
    {"aac", "Music"},
    {"wma", "Music"},

    // Code
    {"c", "Code"},
    {"cpp", "Code"},
    {"h", "Code"},
    {"py", "Code"},
    {"js", "Code"},
    {"ts", "Code"},
    {"java", "Code"},
    {"go", "Code"},
    {"rs", "Code"},
    {"php", "Code"},
    {"html", "Code"},
    {"css", "Code"},
    {"sql", "Code"},

    // Archives (Includes Disk Images)
    {"zip", "Archives"},
    {"tar", "Archives"},
    {"rar", "Archives"},
    {"7z", "Archives"},
    {"gz", "Archives"},
    {"bz2", "Archives"},
    {"iso", "Archives"},
    {"dmg", "Archives"},

    // Executables
    {"exe", "Executables"},
    {"sh", "Executables"},
    {"bat", "Executables"},
    {"msi", "Executables"}
};