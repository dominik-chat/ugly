/*
 * Copyright 2022 Dominik Chat
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <ugly.h>

int main(int argc, char** argv)
{
	struct win_ctx *ctx;

	ugly_init("Ugly name", &ctx);

	ugly_stop();
}
