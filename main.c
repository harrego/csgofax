#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <xdo.h>

#include "dbus.h"
#include "xdo.h"

int main() {
    // Setting up dbus
    struct DBus *dbus = malloc(sizeof(struct DBus));
    memset(dbus, 0, sizeof(struct DBus));

    dbus->error = NULL;
    dbus->bus = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &dbus->error);
    if (!dbus->bus) {
        g_error_free(dbus->error);
        printf("Failed to create dbus\n");

        free(dbus);
        return 1;
    }

    // Setting up XDO
    xdo_t *xdo = xdo_new(NULL);

    // Getting current song
    struct song *current_song = get_current_song(dbus);
    if (current_song == NULL) {
        printf("Failed to get current song\n");

        xdo_free(xdo);
        free(current_song);
        free(dbus);
        return 1;
    }

    char *now_playing_str = song_now_playing_str(current_song);
    printf("%s\n", now_playing_str);
    free(now_playing_str);

    free(current_song);
    free(dbus);

    xdo_free(xdo);

    return 0;
}