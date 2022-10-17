#include <stdlib.h>

int ms1_test_1() {
    int length = 4, locations = 2, gaps = 16;
    for (int i = 0; i < 10; i++) {
        const char *command = sprintf("./spatter -pMS1:%d:%d:%d", length);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        length *= 2;
        locations *= 2;
        gaps *= 2;
    }
    return EXIT_SUCCESS;
}

int ms1_test_2() {
    int length = 4, length2 = 1, locations = 2, locations2 = 16;
    for (int i = 0; i < 10; i++) {
        const char *command = sprintf("./spatter -pMS1:%d:%d,%d:%d", length, length2, locations, locations2);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        length *= 2;
        length2 *= 2;
        locations *= 2;
        locations2 *= 2;
    }
    return EXIT_SUCCESS;
}

int ms1_test_3() {
    int length = 4, length2 = 1, locations = 2, locations2 = 16, gaps = 11;
    for (int i = 0; i < 10; i++) {
        const char *command = sprintf("./spatter -pMS1:%d:%d,%d:%d,%d", length, length2, locations, locations2, gaps);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
        length *= 2;
        length2 *= 2;
        locations *= 2;
        locations2 *= 2;
        gaps *= 2;
    }
    return EXIT_SUCCESS;
}

int ms1_test_delta1() {
    for (int delta = 1; delta < 100; delta*=2) {
        const char *command = sprintf("./spatter -pMS1:8:4:32 -d%d", delta);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int ms1_test_delta2() {
    for (int delta = 1; delta < 100; delta*=2) {
        const char *command = sprintf("./spatter -pMS1:8:2,3:20 -d%d", delta);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int ms1_test_delta3() {
    for (int delta = 1; delta < 100; delta*=2) {
        const char *command = sprintf("./spatter -pMS1:8:2,3:20,22 -d%d", delta);
        if (system(command) == EXIT_FAILURE) {
            printf("Test failure on %s", command);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (ms1_test_1() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if (ms1_test_2() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if (ms1_test_3() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if (ms1_test_delta1() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if (ms1_test_delta2() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if (ms1_test_delta3() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}