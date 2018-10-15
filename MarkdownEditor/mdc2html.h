
#include<iostream>
#include<fstream>
#include "md2html.h"

#ifndef MDC2HTML_H
#define MDC2HTML_H

void Compileit(){

    FILE *in_fp, *out_fp;
    char input[8] = "test.md";
    char output[10] = "test.html";
    open_file(&in_fp, input);
    create_file(&out_fp, output);

    mdparser(out_fp, in_fp, 2);

    close_files(&in_fp, &out_fp);
}
#endif // MDC2HTML_H
