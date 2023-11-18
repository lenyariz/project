#include "signals.h"


GtkSpinButton *button1, *button2, *button3;


gboolean on_draw(GtkWidget* window, cairo_t* cr, gpointer data)
{
    draw_graph(window, cr, data);
    draw_sin(window, cr, data, button1, button2, button3);
    return TRUE;
}


int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkBuilder *builder;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file(builder, "work.glade", NULL);

    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Window"));

    button1 = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "SpinButton1"));
    button2 = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "SpinButton2"));
    button3 = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "SpinButton3"));

    gtk_spin_button_set_range(button1, 0.0, 50.0);
    gtk_spin_button_set_range(button2, 0.0, 50.0);
    gtk_spin_button_set_range(button3, 0.0, 50.0);

    g_object_unref(builder);

    gtk_widget_show(window);

    gtk_main();

    return 0;

}