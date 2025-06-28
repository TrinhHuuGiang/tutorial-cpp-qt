#include <stdio.h>
#include <ctype.h>  // isspace()

int main(int argc, char *argv[])
{	
    if (argc < 2) {
        fprintf(stderr, "No input file\n");
        return 1;
    }

    const char* arg_in = argv[1];
    FILE* fp_in = fopen(arg_in, "r");

    if (!fp_in) {
        fprintf(stderr, "Can't open [%s]\n", arg_in);
        return 2;
    }

    FILE* fp_out = fopen("./_trimmed_space.txt", "w");
    if (!fp_out) {
        fprintf(stderr, "Can't open output file\n");
        fclose(fp_in);
        return 3;
    }

    int c;  // fgetc return or EOF
    while ((c = fgetc(fp_in)) != EOF) {
        if (!isspace(c)) {
            fputc(c, fp_out);
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
