#include "_cgo_export.h"
#include "watcher-c.h"


int main(int argc, char *argv[]){
    void *watcher = wtr_watcher_open("/go/src/app", handle_event, (void *)data);
    return 0;
}

void handle_event(struct wtr_watcher_event event, void *data) {
  // do nothing
}

uintptr_t start_new_watcher(char const *const path, uintptr_t data) {
  void *watcher = wtr_watcher_open(path, handle_event, (void *)data);
  if (watcher == NULL) {
    return 0;
  }
  return (uintptr_t)watcher;
}

int stop_watcher(uintptr_t watcher) {
  if (!wtr_watcher_close((void *)watcher)) {
    return 0;
  }
  return 1;
}
