#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/*O nome deste programa*/
const char *program_name;

void print_usage(FILE *stream, int exit_code){
        fprintf(stream,"Uso: %s opções[ arquivo de entrada...]\n",program_name);
        fprintf(stream,
                        "-h --help      Mostra esta informação de uso.\n"
                        "-o --help      Escreve no arquivo.\n"
                        "-v --verbose   Imprime Mensagens.\n");
        exit (exit_code);

}

int main(int argc, char* argv[]){
        int next_option;
        const char *short_options="ho:v";
        const struct option long_options[]={
                {"help",        0,      NULL,   'h'},
                {"output",      1,      NULL,   '0'},
                {"verbose",     0,      NULL,   'v'},
                {NULL,          0,      NULL,   0}};
        const char *output_filename=NULL;
        int verbose = 0;
        program_name= argv[0];

        do{
                next_option = getopt_long(argc, argv,short_options,long_options,NULL);
                switch(next_option){
                        case 'h':
                                print_usage(stdout,0);
                        case 'o':
                                output_filename = optarg;
                                break;
                        case 'v':
                                verbose=1;
                                break;
                        case '?':
                                print_usage(stderr,1);
                        case -1:
                                break;
                        default:
                                abort();


                }

        }while(next_option != -1);

        if (verbose){
                int i;
                for(i=optind;i<argc;++i)
                        printf("Argumento: %s\n",argv[i]);

        }
        return 0;
}

