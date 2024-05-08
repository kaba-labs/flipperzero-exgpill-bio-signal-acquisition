#include "bioamp_exg_pill_app_i.h"

#include <furi_hal_power.h>
#include <furi.h>
#include <furi_hal.h>
#include <expansion/expansion.h>

static bool bioamp_exg_pill_app_custom_event_callback(void* context, uint32_t event) {
    furi_assert(context);
    BioAmpEXGPillApp* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, event);
}

static bool bioamp_exg_pill_app_back_event_callback(void* context) {
    furi_assert(context);
    BioAmpEXGPillApp* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

static void bioamp_exg_pill_app_tick_event_callback(void* context) {
    furi_assert(context);
    BioAmpEXGPillApp* app = context;
    scene_manager_handle_tick_event(app->scene_manager);
}

BioAmpEXGPillApp* bioamp_exg_pill_app_alloc() {
    BioAmpEXGPillApp* app = malloc(sizeof(BioAmpEXGPillApp));

    return app;
}

void bioamp_exg_pill_app_free(BioAmpEXGPillApp* app) {
    furi_assert(app);

    bioamp_exg_pill_uart_free(app->uart);

    free(app);
}

int32_t bioamp_exg_pill_app(void* p) {
    UNUSED(p);
    // Disable expansion protocol to avoid interference with UART Handle
    Expansion* expansion = furi_record_open(RECORD_EXPANSION);
    expansion_disable(expansion);

    uint8_t attempts = 0;
    bool otg_was_enabled = furi_hal_power_is_otg_enabled();
    while(!furi_hal_power_is_otg_enabled() && attempts++ < 5) {
        furi_hal_power_enable_otg();
        furi_delay_ms(10);
    }
    furi_delay_ms(200);

    BioAmpEXGPillApp* bioamp_exg_pill_app = bioamp_exg_pill_app_alloc();

    bioamp_exg_pill_app->uart = bioamp_exg_pill_usart_init(bioamp_exg_pill_app);

    view_dispatcher_run(bioamp_exg_pill_app->view_dispatcher);

    bioamp_exg_pill_app_free(bioamp_exg_pill_app);

    if(furi_hal_power_is_otg_enabled() && !otg_was_enabled) {
        furi_hal_power_disable_otg();
    }

    expansion_enable(expansion);
    furi_record_close(RECORD_EXPANSION);

    return 0;
}
