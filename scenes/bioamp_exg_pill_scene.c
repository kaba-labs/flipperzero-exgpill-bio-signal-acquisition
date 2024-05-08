#include "bioamp_exg_pill_app_scene.h"

// Generate scene on_enter handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_enter,
void (*const bioamp_exg_pill_app_scene_on_enter_handlers[])(void*) = {
#include "bioamp_exg_pill_app_scene_config.h"
};
#undef ADD_SCENE

// Generate scene on_event handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_event,
bool (*const bioamp_exg_pill_app_scene_on_event_handlers[])(void* context, SceneManagerEvent event) = {
#include "bioamp_exg_pill_app_scene_config.h"
};
#undef ADD_SCENE

// Generate scene on_exit handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_exit,
void (*const bioamp_exg_pill_app_scene_on_exit_handlers[])(void* context) = {
#include "bioamp_exg_pill_app_scene_config.h"
};
#undef ADD_SCENE

// Initialize scene handlers configuration structure
const SceneManagerHandlers bioamp_exg_pill_app_scene_handlers = {
    .on_enter_handlers = bioamp_exg_pill_app_scene_on_enter_handlers,
    .on_event_handlers = bioamp_exg_pill_app_scene_on_event_handlers,
    .on_exit_handlers = bioamp_exg_pill_app_scene_on_exit_handlers,
    .scene_num = BioAmpEXGPillSceneNum,
};
