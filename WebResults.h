//
// Created by Owner on 8/8/2022.
//

#ifndef WEBRESULTS_WEBRESULTS_H
#define WEBRESULTS_WEBRESULTS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char* buffer;
    size_t bufferSize;
} StyleElement;

typedef struct {
    StyleElement* elements;
    size_t currentIndex;
    size_t resultCount;
} WebResults;

inline WebResults CreateWebResults(size_t expectedResultCount) {
    WebResults wr;
    wr.currentIndex = 0;
    wr.resultCount = expectedResultCount;
    wr.elements = (StyleElement*)malloc(sizeof(StyleElement) * wr.resultCount);
    return wr;
}

inline void AddNewResult(WebResults* results, const char* text, size_t stringLength) {
    size_t index = (*results).currentIndex++;
    StyleElement elem = {.buffer = text, .bufferSize = stringLength};
    results->elements[index] = elem;
    (*results).resultCount++;
}

inline void WriteWebResults(WebResults* results, const char* path) {
    FILE* file;
    fopen_s(&file, path, "w");

    const char* boilerPlateStart = "<!DOCTYPE html>\n"
                                   "<html>\n"
                                   "<body style=\"margin: 20px;\">\n"
                                   "\n";


#ifdef __cplusplus
    const char* langGen = "C++";
#else
    const char* langGen = "C";
#endif
    char generationDataBuffer[512];
    sprintf(generationDataBuffer, "<h2> Generated With %s </h2>\n", langGen);


    const char* boilerPlateEnd = "\n</body>\n"
                                 "</html>";

    fputs(boilerPlateStart, file);
    fputs(generationDataBuffer, file);

    fputs("<div style=\"border: black solid 2px;\">", file);

    for (size_t i = 0; i < (*results).currentIndex; i++) {
        char buffer[512];
        sprintf(buffer, "<h3> &emsp; %s </h3>\n", (*results).elements[i].buffer);
        fputs(buffer, file);
        printf("(%zi/%zi) Got: %s\n", i+1, results->currentIndex, buffer);
    }

    fputs("</div>\n", file);
    fputs(boilerPlateEnd, file);
    fclose(file);
}



#endif //WEBRESULTS_WEBRESULTS_H
