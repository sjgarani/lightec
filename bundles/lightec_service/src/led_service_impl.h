#ifndef LED_SERVICE_IMPL_H_
#define LED_SERVICE_IMPL_H_

#include "led_service.h"
#include "celix_log_helper.h"

typedef struct led {
    celix_log_helper_t *log_helper;
    int state;
} led_t;

led_t* led_create(void);
void led_destroy(led_t *led);

int led_set_state(led_t *led, int input, int *output);

#endif /* LED_SERVICE_IMPL_H_ */