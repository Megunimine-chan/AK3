#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *helpOption = "Options:\n"
    "-h or --help\n"
    "-v or --version\n"
    "-i[<val1>,...]\n";
    
    static struct option longOptions[] = {
        {"help",    no_argument,       0, 'h'}, 
        {"version", no_argument,       0, 'v'},
        {"input",    required_argument, 0, 'i'},
        {0, 0, 0, 0},
    };
    
    const char *shortOptions = "hvi:";
    
    bool h, v, i = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
         case 'v': {
                if (!v) {
                    v = true;
                    printf("The newest version\n");
                }
                break;
            }
          
            case 'i': {
                if (!i) {
                    char *args;
                    printf("Option list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    i = true;
                }
                break;
            }
              case 'h': {
                if (!h) {
                    h = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
           
            default: {
                printf("Error!\n");
                return 0;
            }
        }
    }
    return 0;
}
