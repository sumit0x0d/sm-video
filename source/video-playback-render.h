#ifndef VIDEO_PLAYBACK_RENDER_H
#define VIDEO_PLAYBACK_RENDER_H

#include <stdint.h>

#include <video-playback.h>

typedef uint32_t xcb_window_t;

struct SM_VideoPlayback_render_create_config {
	union {
		struct {
			struct wl_display *wl_display;
			struct wl_surface *wl_surface;
		};
		struct {
			struct xcb_connection_t *xcb_connnection;
			xcb_window_t xcb_window;
		};
	};
};

struct SM_VideoPlayback_render_interface {
	void *(*create)(const struct SM_VideoPlayback_create_config *create_config, const struct SM_VideoPlayback_render_create_config *render_create_config);
	void (*destroy)(void *backend);
	void (*dispatch)(void *backend, void *buffer);
};

struct SM_VideoPlaybackRender {
	void *backend;
	struct SM_VideoPlayback_render_interface interface;
};

struct SM_VideoPlaybackRender *SM_VideoPlaybackRender_Create(const struct SM_VideoPlaybackCreateConfig *create_config, const struct SM_VideoPlaybackRenderCreateConfig *render_create_config);

void SM_VideoPlayback_render_destroy(struct SM_VideoPlayback_render *SM_VideoPlayback);

void SM_VideoPlayback_render_dispatch(struct SM_VideoPlayback_render *SM_VideoPlayback, void *buffer);

#endif
