#include <algorithm>
#include <iostream>
#include <string>

void str2BEhex(std::string string) {
    printf("0x");
    for(long unsigned int i=0; i<string.length(); i++) {
        printf("%02x", string[i]);
    }
    printf("\n");
}

int main(int argc, char ** argv) {
    if (2 != argc) {
        printf("Invalid number of arguments! Requires 1 parameter.\n");
        return 0;
    }

    std::string str(argv[1]);
    if (NULL != std::getenv("ENDIANNESS")) {
        std::string endianness(std::getenv("ENDIANNESS"));
        if (0 == endianness.compare("LE")) {
            std::reverse(str.begin(), str.end());
        }
    }
    str2BEhex(str);
    return 0;
}
