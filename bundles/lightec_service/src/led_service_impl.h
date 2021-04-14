#ifndef LED_SERVICE_IMPL_H_
#define LED_SERVICE_IMPL_H_

#include "led_service.h"
#include "log_helper.h"

typedef struct led {
    log_helper_t *log_helper;
    int state;
} led_t;

led_t* led_create(void);
void led_destroy(led_t *led);

int led_set_state(led_t *led, int input);
int led_get_state(led_t *led, int *output);

#endif /* LED_SERVICE_IMPL_H_ */