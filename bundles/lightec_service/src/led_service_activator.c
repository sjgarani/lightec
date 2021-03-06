#include <stdlib.h>
#include <celix_api.h>
#include "led_service_impl.h"
#include "remote_constants.h"

struct activator {
    led_t *led;
    led_service_t led_service;
    long svcId;
    celix_log_helper_t *log_helper;
};

celix_status_t lightec_bnd_start(struct activator *act, celix_bundle_context_t *ctx) {
    act->svcId = -1L;
    act->led = led_create();
    if (act->led != NULL) {
        act->led->log_helper = celix_logHelper_create(ctx, "led");
        act->led_service.handle = act->led;
        act->led_service.setState = (void*)led_set_state;

        celix_properties_t *properties = celix_properties_create();
        celix_properties_set(properties, OSGI_RSA_SERVICE_EXPORTED_INTERFACES, LED_SERVICE);
        celix_properties_set(properties, OSGI_RSA_SERVICE_EXPORTED_CONFIGS, LASER_CONFIGURATION_TYPE);

        act->svcId = celix_bundleContext_registerService(ctx, &act->led_service, LED_SERVICE, properties);
    }
    return CELIX_SUCCESS;
}

celix_status_t lightec_bnd_stop(struct activator *act, celix_bundle_context_t *ctx) {
    celix_bundleContext_unregisterService(ctx, act->svcId);
    if (act->led != NULL) {
        led_destroy(act->led);
    }
    return CELIX_SUCCESS;
}

CELIX_GEN_BUNDLE_ACTIVATOR(struct activator, lightec_bnd_start, lightec_bnd_stop);