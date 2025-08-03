#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "microui.h"

void r_init(void);
void r_draw_rect(mu_Rect rect, mu_Color color);
void r_draw_text(const char *text, mu_Vec2 pos, mu_Color color);
void r_draw_icon(int id, mu_Rect rect, mu_Color color);
 int r_get_text_width(const char *text, int len);
 int r_get_text_height(void);
void r_set_clip_rect(mu_Rect rect);
void r_clear(mu_Color color);
void r_present(void);


typedef SDL_Event r_Event;

#define r_PollEvent(X)       SDL_PollEvent(X)
#define R_EV_QUIT            SDL_QUIT
#define R_EV_KEYUP           SDL_KEYUP
#define R_EV_KEYDOWN         SDL_KEYDOWN
#define R_EV_MOUSEMOTION     SDL_MOUSEMOTION
#define R_EV_MOUSEBUTTONUP   SDL_MOUSEBUTTONUP
#define R_EV_MOUSEBUTTONDOWN SDL_MOUSEBUTTONDOWN
#define R_EV_MOUSEWHEEL      SDL_MOUSEWHEEL
#define R_EV_TEXTINPUT       SDL_TEXTINPUT


static const char r_button_map[256] = {
  [ SDL_BUTTON_LEFT   & 0xff ] =  MU_MOUSE_LEFT,
  [ SDL_BUTTON_RIGHT  & 0xff ] =  MU_MOUSE_RIGHT,
  [ SDL_BUTTON_MIDDLE & 0xff ] =  MU_MOUSE_MIDDLE,
};

static const char r_key_map[256] = {
  [ SDLK_LSHIFT       & 0xff ] = MU_KEY_SHIFT,
  [ SDLK_RSHIFT       & 0xff ] = MU_KEY_SHIFT,
  [ SDLK_LCTRL        & 0xff ] = MU_KEY_CTRL,
  [ SDLK_RCTRL        & 0xff ] = MU_KEY_CTRL,
  [ SDLK_LALT         & 0xff ] = MU_KEY_ALT,
  [ SDLK_RALT         & 0xff ] = MU_KEY_ALT,
  [ SDLK_RETURN       & 0xff ] = MU_KEY_RETURN,
  [ SDLK_BACKSPACE    & 0xff ] = MU_KEY_BACKSPACE,
};


#endif

