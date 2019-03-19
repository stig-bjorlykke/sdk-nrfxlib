/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

/**
 * @file bsd_os.h
 * @brief OS specific definitions.
 *
 * @defgroup bsd_os
 * @{
 */
#ifndef BSD_OS_H__
#define BSD_OS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TODO: add documentation in this file */

void bsd_os_init(void);

/* @brief Put a thread to a sleep for a specific time or until an event occurs.
 *
 * @param[in]      context   A unique identifier assigned by the library to identify the context.
 * @param[in, out] p_timeout A pointer to the timeout value, in milliseconds. -1 for infinite
 *                           timeout. Contains timeout value as input, remainig time to sleep
 *                           as output.
 *
 * @retval  0 If the procedure succeeded - it was either interrupted or an timeout occured.
 *            To identify which one took place, verify the content of the variable pointed
 *            by p_timeout (0 means that timeout occured).
 * @retval -1 If the procedure failed.
 */
int32_t bsd_os_timedwait(uint32_t context, int32_t * p_timeout);

void bsd_os_errno_set(int errno_val);

void bsd_os_application_irq_clear(void);

void bsd_os_application_irq_set(void);

void bsd_os_trace_irq_set(void);

void bsd_os_trace_irq_clear(void);

int32_t bsd_os_trace_put(const uint8_t * const p_buffer, uint32_t buf_len);

/* Need extern to not generate mock in testing. */
extern void bsd_os_application_irq_handler(void);

/* Need extern to not generate mock in testing. */
extern void bsd_os_trace_irq_handler(void);

#ifdef __cplusplus
}
#endif

#endif /* BSD_OS_H__ */

/** @} */
