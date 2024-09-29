#include "watcher-c.h"
#include <stdio.h>

void handle_event(struct wtr_watcher_event event, void *data) {
  // do nothing
}

// the watcher is started and immediately stopped
int main(int argc, char *argv[]){
  uintptr_t data = 0;
  void *watcher = wtr_watcher_open("/go/src/app", handle_event, (void *)data);

  // wtr_watcher_close returns true
  if (wtr_watcher_close((void *)watcher)) {
    printf("success\n");
    return 0;
  }
  // wtr_watcher_close returns false
  printf("failure\n");
  return 1;
}
