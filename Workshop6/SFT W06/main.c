#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "log4c.h"

int main(void)
{
    struct Log4cStruct logInstance = l4cOpen("log.txt", 0);
    char errorMessage[L4C_ERROR_MSG_MAX + 1];

    if (l4cCheck(&logInstance, errorMessage) != 0) {
        l4cError(&logInstance, errorMessage);
        return 1;
    }

    char testStr[] = "This is a\nstring with embedded newline characters\nand 12345 numbers inside it as well 67890";
    assert(testStr != NULL);

    struct StringIndex strIndex = indexString(testStr);

    char Message[100];
    snprintf(Message, sizeof(Message), "Index created. Number of lines: %d, Number of words: %d, Number of numbers: %d",
        getNumberLines(&strIndex), getNumberWords(&strIndex), getNumberNumbers(&strIndex));
    l4cInfo(&logInstance, Message);

    printf("LINES\n");
    for (int line = 0; line < strIndex.numLines; line++) {
        printUntil(strIndex.str, strIndex.lineStarts[line], '\n');
        printf("\n");
    }

    printf("\nWORDS\n");
    for (int word = 0; word < strIndex.numWords; word++) {
        printUntilSpace(strIndex.str, strIndex.wordStarts[word]);
        printf("\n");
    }

    printf("\nNUMBERS\n");
    for (int number = 0; number < strIndex.numNumbers; number++) {
        printUntilSpace(strIndex.str, strIndex.numberStarts[number]);
        printf("\n");
    }

    assert(getNumberLines(&strIndex) == 3);
    assert(getNumberWords(&strIndex) == 14);
    assert(getNumberNumbers(&strIndex) == 2);

    l4cClose(&logInstance);

    return 0;
}
