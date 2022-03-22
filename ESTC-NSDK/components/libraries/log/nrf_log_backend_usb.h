/**
 * Copyright 2021 Evgeniy Morozov
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE
*/

#ifndef LOG_BACKEND_USB_H
#define LOG_BACKEND_USB_H

#include "nrf_log_backend_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const nrf_log_backend_api_t log_backend_usb_api;

typedef struct
{
    nrf_log_backend_t backend;
} log_backend_usb_t;

#define LOG_BACKEND_USB_DEF(_name) \
    NRF_LOG_BACKEND_DEF(_name, log_backend_usb_api, NULL)

void log_backend_usb_init(void);

#if LOG_BACKEND_USB_INIT_STACK
void log_backend_usb_process(void);
#define LOG_BACKEND_USB_PROCESS() log_backend_usb_process()
#else
#define LOG_BACKEND_USB_PROCESS()
#endif    /* LOG_BACKEND_USB_INIT_STACK */

#ifdef __cplusplus
}
#endif

#endif //LOG_BACKEND_USB_H
