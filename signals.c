#include "signals.h"


void close_window(void)
{
    puts("Close window!");
    gtk_main_quit();
}

void draw_graph(GtkWidget* window, cairo_t* cr, gpointer data)
{
    cairo_move_to(cr, 325, 0);
    cairo_line_to(cr, 325, 700);
    cairo_stroke(cr);
    cairo_move_to(cr, 0, 200);
    cairo_line_to(cr, 700, 200);
    cairo_stroke(cr);
}

//Амплитуда * синус(частота + фаза)

void draw_sin(GtkWidget* window, cairo_t* cr, gpointer data, GtkSpinButton *button1, GtkSpinButton *button2, GtkSpinButton *button3)
{   

    cairo_set_source_rgb(cr, 0, 0.4, 0.5);

    int frequency = gtk_spin_button_get_value(button1), amplitude = gtk_spin_button_get_value(button2), phase = gtk_spin_button_get_value(button3);

    for (float x = -8.0; x < 100.0; x += 0.001)
    {
        cairo_move_to(cr, 50 * x + 25, amplitude * sin(2 * PI * frequency * x + (phase * TO_RAD)) + 190);
        cairo_line_to(cr, 50 * x + 26, amplitude * sin(2 * PI * frequency * x + (phase * TO_RAD))  + 191);
    }

    cairo_stroke(cr);
}


void button_change(GtkWidget *window, gpointer data)
{
    puts("Change!");
    gtk_widget_queue_draw(data);
}
