#ifndef RENDERER_H
#define RENDERER_H

#include "microui.h"

#ifdef SDL3_RENDERER
#  include <SDL3/SDL.h>

#  define R_EV_QUIT            SDL_EVENT_QUIT
#  define R_EV_KEYUP           SDL_EVENT_KEY_UP
#  define R_EV_KEYDOWN         SDL_EVENT_KEY_DOWN
#  define R_EV_MOUSEMOTION     SDL_EVENT_MOUSE_MOTION
#  define R_EV_MOUSEBUTTONUP   SDL_EVENT_MOUSE_BUTTON_UP
#  define R_EV_MOUSEBUTTONDOWN SDL_EVENT_MOUSE_BUTTON_DOWN
#  define R_EV_MOUSEWHEEL      SDL_EVENT_MOUSE_WHEEL
#  define R_EV_TEXTINPUT       SDL_EVENT_TEXT_INPUT

  static const char r_key_map[256] = {
    [ SDL_SCANCODE_LSHIFT ]    = MU_KEY_SHIFT,
    [ SDL_SCANCODE_RSHIFT ]    = MU_KEY_SHIFT,
    [ SDL_SCANCODE_LCTRL ]     = MU_KEY_CTRL,
    [ SDL_SCANCODE_RCTRL ]     = MU_KEY_CTRL,
    [ SDL_SCANCODE_LALT ]      = MU_KEY_ALT,
    [ SDL_SCANCODE_RALT ]      = MU_KEY_ALT,
    [ SDL_SCANCODE_RETURN ]    = MU_KEY_RETURN,
    [ SDL_SCANCODE_BACKSPACE ] = MU_KEY_BACKSPACE,
  };
#else
#  include <SDL2/SDL.h>

#  define R_EV_QUIT            SDL_QUIT
#  define R_EV_KEYUP           SDL_KEYUP
#  define R_EV_KEYDOWN         SDL_KEYDOWN
#  define R_EV_MOUSEMOTION     SDL_MOUSEMOTION
#  define R_EV_MOUSEBUTTONUP   SDL_MOUSEBUTTONUP
#  define R_EV_MOUSEBUTTONDOWN SDL_MOUSEBUTTONDOWN
#  define R_EV_MOUSEWHEEL      SDL_MOUSEWHEEL
#  define R_EV_TEXTINPUT       SDL_TEXTINPUT

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

static const char r_button_map[256] = {
  [ SDL_BUTTON_LEFT   & 0xff ] =  MU_MOUSE_LEFT,
  [ SDL_BUTTON_RIGHT  & 0xff ] =  MU_MOUSE_RIGHT,
  [ SDL_BUTTON_MIDDLE & 0xff ] =  MU_MOUSE_MIDDLE,
};

#define r_PollEvent(E) SDL_PollEvent(E)
typedef SDL_Event      r_Event;


void r_init(void);
void r_draw_rect(mu_Rect rect, mu_Color color);
void r_draw_text(const char *text, mu_Vec2 pos, mu_Color color);
void r_draw_icon(int id, mu_Rect rect, mu_Color color);
 int r_get_event_key_modifier(r_Event event);
 int r_get_text_width(const char *text, int len);
 int r_get_text_height(void);
void r_set_clip_rect(mu_Rect rect);
void r_clear(mu_Color color);
void r_present(void);


#endif

