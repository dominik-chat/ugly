/*
 * Copyright 2022 Dominik Chat
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _UGLY_H_
#define _UGLY_H_

/********************************** DEFINES ***********************************/
#define UGLY_MAIN_WIN	0

/******************************* STRUCTS, ENUMS *******************************/
struct win_ctx;

/****************************** PUBLIC FUNCTIONS ******************************/

int ugly_init(const char *main_win_name, struct win_ctx **main_win_ctx);

int ugly_stop(void);

#endif /* _UGLY_H_ */
