#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;


static void main_window_load(Window *window){
  //Create child layers
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  s_time_layer = text_layer_create(GRect(0, 52, bounds.size.w, bounds.size.h)); //GRect(OriginX, OriginY, width, height)
}
static void main_window_unload(Window *window){
  //Destroy child layers
  text_layer_destroy(s_time_layer);
}

static void init(){
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers){
    .load = main_window_load,
    .unload = main_window_unload,
  });
  //window_set_fullscreen(s_main_window, true); //Doesn't show the status bar(only applicable to apps)
  window_stack_push(s_main_window, true); //What to push to top(show on screen)? (window, animated?)
}

static void deinit(){
  window_destroy(s_main_window);
  
}

int main(void){
  init();
  app_event_loop();
  deinit();
}