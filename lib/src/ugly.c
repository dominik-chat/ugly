/*
 * Copyright 2022 Dominik Chat
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <errno.h>

/********************************** DEFINES ***********************************/
#define SDL_LOG_ERR(msg)	fprintf(stderr, msg); \
				fprintf(stderr, " (%s)\n", SDL_GetError())
#define SDL_LOG_INF(msg)	fprintf(stdout, msg); \
				fprintf(stdout, " (%s)\n", SDL_GetError())

#define LOG_ERR(msg)		fprintf(stderr, msg); \
				fprintf(stderr, "\n")
#define LOG_INF(msg)		fprintf(stdout, msg); \
				fprintf(stderr, "\n")

/******************************* STRUCTS, ENUMS *******************************/
struct win_ctx {
	SDL_Window *win;
	SDL_Renderer *rndr;
};

/****************************** STATIC VARIABLES ******************************/

/****************************** STATIC FUNCTIONS ******************************/

/****************************** PUBLIC FUNCTIONS ******************************/
int ugly_init(const char *main_name, struct win_ctx **main_win_ctx)
{
	int err;
	struct win_ctx *ctx;
	char default_name[] = "Oopsie someone forgot to name this window";

	if (NULL == main_name) {
		main_name = default_name;
	}

	if (NULL == main_win_ctx) {
		LOG_ERR("main_win_ctx is null");
		return EINVAL;
	}

	err = SDL_Init(SDL_INIT_VIDEO);
	if (err) {
		SDL_LOG_ERR("SDL_Init failed");
		return err;
	}

	*main_win_ctx = malloc(sizeof(**main_win_ctx));
	if (NULL == *main_win_ctx) {
		LOG_ERR("Main window context allocation failed");
		return -ENOMEM;
	}
	ctx = *main_win_ctx;

	SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
	ctx->win = SDL_CreateWindow(main_name,
					   SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED,
					   640,
					   480,
					   0
	);
	if (NULL == ctx->win) {
		SDL_LOG_ERR("SDL_CreateWindow failed");
	}

	ctx->rndr = SDL_CreateRenderer(ctx->win, -1,
					      SDL_RENDERER_ACCELERATED);
	if (NULL == ctx->win) {
		SDL_LOG_INF("SDL_RENDERER_ACCELERATED unavailable");
		ctx->rndr = SDL_CreateRenderer(ctx->win, -1,
						      SDL_RENDERER_SOFTWARE);
	}
	if (NULL == ctx->win) {
		SDL_LOG_INF("SDL_CreateRenderer failed");
	}

	SDL_SetRenderDrawColor(ctx->rndr, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(ctx->rndr);
	SDL_RenderPresent(ctx->rndr);

	SDL_Delay(2000);

	return 0;
}

int ugly_stop(void)
{
//	SDL_DestroyWindow(ctx->win);
	SDL_Quit();

	return 0;
}
