#include <string.h>
#include "include.h"


int main(int argc , char** argv) {
    if(argc == 1){
        printf("Target Folder Path not Provided\n");
        return EXIT_FAILURE;
    }
    if(argc != 2){
        printf("Usage ./organize {Folder path to organize}\n");
        return EXIT_FAILURE;
    }

    //read config
    char* config_path = expand_config_path("~/.config/file_organizer/config.ini");
    if(access(config_path, F_OK | R_OK) == 0)
      {
	//read config, otherwise use default mapping
      }


    char* path = argv[1];
    // build the extension to folder hashmap
    enum RETURN ret = build_extension_folder_hashmap();
    switch(ret){
        case SUCCESS : printf("HashMap Build Success\n");break;
        case FAIL : printf("Failure While building HashMap\n");return EXIT_FAILURE;
        case SOMETHING_WRONG: printf("Something is wrong with hash format / config file\n");return EXIT_FAILURE;
        default: printf("Unknown Return Code\n");return EXIT_FAILURE;
    }
    // pick every file and move it into respective folders
    organize(path);
    return EXIT_SUCCESS;
}
