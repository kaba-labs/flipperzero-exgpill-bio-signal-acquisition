#pragma once

#include "furi_hal.h"

#define RX_BUF_SIZE (2048)

typedef struct BioAmpEXGPillUart BioAmpEXGPillUart;

void bioamp_exg_pill_uart_set_handle_rx_data_cb(
    BioAmpEXGPillUart* uart,
    void (*handle_rx_data_cb)(uint8_t* buf, size_t len, void* context));
void bioamp_exg_pill_uart_set_handle_rx_pcap_cb(
    BioAmpEXGPillUart* uart,
    void (*handle_rx_pcap_cb)(uint8_t* buf, size_t len, void* context));
void bioamp_exg_pill_uart_tx(BioAmpEXGPillUart* uart, uint8_t* data, size_t len);
BioAmpEXGPillUart* bioamp_exg_pill_usart_init(BioAmpEXGPillApp* app);
void bioamp_exg_pill_uart_free(BioAmpEXGPillUart* uart);
