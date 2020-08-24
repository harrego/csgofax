#ifndef DBUS_H
#define DBUS_H

#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>

typedef struct DBus {
    GError *error;
    GDBusConnection *bus;
} DBus;

typedef struct song {
    char *title;
    char *artist;
} song;

struct song *get_current_song(DBus *dbus);
char *song_now_playing_str(struct song *current_song);

#endif