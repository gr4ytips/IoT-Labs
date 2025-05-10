
#include "validate.h"
#include <ctype.h>

int validate_answer(const char *input, const char *target) {
    while (*input && *target) {
        if (tolower((unsigned char)*input) != tolower((unsigned char)*target))
            return 1;
        input++;
        target++;
    }
    return (*target == '\0') ? 0 : 1;
}
