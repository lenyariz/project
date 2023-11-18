#pragma once

#ifndef _SIGNALS_
#define _SIGNALS_
#define PI 3.14
#define TO_RAD 3.1415 / 180

#include <gtk/gtk.h>
#include <cairo.h>
#include <stdio.h>
#include <math.h>

void close_window(void);

void draw_graph(GtkWidget*, cairo_t*, gpointer);

void draw_sin(GtkWidget*, cairo_t*, gpointer, GtkSpinButton*, GtkSpinButton*, GtkSpinButton*);

void button_change(GtkWidget*, gpointer);

#endif
