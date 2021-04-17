#include <stdlib.h>
#include "led_service_impl.h"

led_t* led_create(void) {
    struct led *tmp = calloc(1, sizeof(*tmp));
    tmp->state = 0;
    return tmp;
}

void led_destroy(led_t *led) {
    free(led);
}

int led_set_state(led_t *led, int input, int *output) {
    int status = CELIX_SUCCESS;

    *output = led->state;
    led->state = input;
    celix_logHelper_info(led->log_helper, "Set Led State: %i", led->state);

    return status;
}
