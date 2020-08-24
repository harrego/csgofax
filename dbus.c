#include "dbus.h"

struct song *get_current_song(DBus *dbus) {
    GVariant *result = g_dbus_connection_call_sync(dbus->bus, "org.mpris.MediaPlayer2.rhythmbox", "/org/mpris/MediaPlayer2", "org.freedesktop.DBus.Properties", "Get", g_variant_new("(ss)", "org.mpris.MediaPlayer2.Player", "Metadata"), G_VARIANT_TYPE("(v)"), G_DBUS_CALL_FLAGS_NONE, -1, NULL, &dbus->error);

    if (dbus->error) {
        printf("Error getting dbus song: %s\n", dbus->error->message);
        g_error_free(dbus->error);
        return NULL;
    }

    GVariant *props = NULL;
    g_variant_get(result, "(v)", &props);

    char *song_title = NULL;
    char *song_artist = NULL;
    char **song_artists = NULL;    

    g_variant_lookup(props, "xesam:title", "s", &song_title);
    g_variant_lookup(props, "xesam:artist", "^as", &song_artists);

    if (song_title == NULL) {
        song_title = "Unknown Song";
    }

    if (song_artists != NULL) {
        song_artist = song_artists[0];
    } else {
        song_artist = "Unknown Artist";
    }

    struct song *current_song = malloc(sizeof(struct song));
    memset(current_song, 0, sizeof(struct song));

    current_song->title = song_title;
    current_song->artist = song_artist;

    return current_song;
}

char *song_now_playing_str(struct song *current_song) {
    size_t now_playing_str_len = 20 + strlen(current_song->title) + strlen(current_song->artist);
    char *now_playing_str = malloc(now_playing_str_len * sizeof(char));
    snprintf(now_playing_str, now_playing_str_len, "Now playing: %s by %s", current_song->title, current_song->artist);

    return now_playing_str;
}