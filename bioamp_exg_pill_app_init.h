#pragma once

#include "bioamp_exg_pill_app.h"
#include "bioamp_exg_pill_uart.h"

#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/scene_manager.h>
#include <gui/modules/text_box.h>
#include <gui/modules/submenu.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/widget.h>

#include <storage/storage.h>
#include <lib/toolbox/path.h>
#include <dialogs/dialogs.h>

#define NUM_MENU_ITEMS (24)

#define BioAmpEXGPill_TEXT_BOX_STORE_SIZE (4096)
#define BioAmpEXGPill_TEXT_INPUT_STORE_SIZE (512)

#define BioAmpEXGPill_APP_FOLDER_USER "apps_data/bioamp_exg_pill"
#define BioAmpEXGPill_APP_FOLDER EXT_PATH(BioAmpEXGPill_APP_FOLDER_USER)
#define BioAmpEXGPill_APP_FOLDER_LOGS BioAmpEXGPill_APP_FOLDER "/logs"

typedef enum BioAmpEXGPillUserInputType {
    BioAmpEXGPillUserInputTypeString,
    BioAmpEXGPillUserInputTypeNumber,
    BioAmpEXGPillUserInputTypeFileName
} BioAmpEXGPillUserInputType;

struct BioAmpEXGPillApp {
    Gui* gui;
    // ViewDispatcher* view_dispatcher;
    // SceneManager* scene_manager;

    FuriString* text_box_store;
    bool need_to_prompt_settings_init;
    int which_prompt;
    DialogsApp* dialogs;
    BioAmpEXGPillUart* uart;
    const char* selected_tx_string;
    bool is_command;
    bool is_custom_tx_string;

};

typedef enum {
    BioAmpEXGPillAppViewVarItemList,
    BioAmpEXGPillAppViewConsoleOutput,
    BioAmpEXGPillAppViewTextInput,
    BioAmpEXGPillAppViewWidget,
    BioAmpEXGPillAppViewSubmenu,
} BioAmpEXGPillAppView;
