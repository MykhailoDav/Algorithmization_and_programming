#include <stdio.h>

#ifdef OPTION1
#define OPTION1_MESSAGE "Option 1 is enabled."
#else
#define OPTION1_MESSAGE "Option 1 is disabled."
#endif

#ifdef OPTION2
#define OPTION2_MESSAGE "Option 2 is enabled."
#else
#define OPTION2_MESSAGE "Option 2 is disabled."
#endif

int main() {
    // Перевірка опцій компілятора
#if defined(OPTION1) || defined(OPTION2)
    printf("Compiler options are set correctly:\n%s\n%s\n", OPTION1_MESSAGE, OPTION2_MESSAGE);
#else
    printf("No compiler options detected.\n");
#endif

    return 0;
}
