#pragma once

#include "bioamp_exg_pill_app.h"
#include "scenes/bioamp_exg_pill_scene.h"
#include "bioamp_exg_pill_custom_event.h"
#include "bioamp_exg_pill_uart.h"

#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/scene_manager.h>
#include <gui/modules/text_box.h>
#include <gui/modules/text_input.h>
#include <gui/modules/submenu.h>
#include <gui/modules/variable_item_list.h>

#include <storage/storage.h>
#include <lib/toolbox/path.h>
#include <dialogs/dialogs.h>

#define UART_CH (FuriHalSerialIdUsart)

#define NUM_MENU_ITEMS (11)

#define bioamp_exg_pill_TEXT_BOX_STORE_SIZE (4096)
#define bioamp_exg_pill_TEXT_INPUT_STORE_SIZE (512)

#define bioamp_exg_pill_APP_FOLDER_USER "apps_data/bioamp_exg_pill"
#define bioamp_exg_pill_APP_FOLDER EXT_PATH(bioamp_exg_pill_APP_FOLDER_USER)
#define bioamp_exg_pill_APP_FOLDER_LOGS bioamp_exg_pill_APP_FOLDER "/logs"

struct BioAmpEXGPillApp {
    Gui* gui;
    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;

    BioAmpEXGPillUart* uart;

    char text_input_store[bioamp_exg_pill_TEXT_INPUT_STORE_SIZE + 1];
    FuriString* text_box_store;
    size_t text_box_store_strlen;
    TextBox* text_box;
    TextInput* text_input;

    VariableItemList* var_item_list;

    int selected_menu_index;
    int selected_option_index[NUM_MENU_ITEMS];
    const char* selected_tx_string;
    bool is_command;
    bool is_custom_tx_string;
    bool focus_console_start;
    bool show_stopscan_tip;
};

typedef enum {
    BioAmpEXGPillAppViewVarItemList,
    BioAmpEXGPillAppViewConsoleOutput,
    BioAmpEXGPillAppViewTextInput,
    BioAmpEXGPillAppViewWidget,
    BioAmpEXGPillAppViewSubmenu,
} BioAmpEXGPillAppView;
