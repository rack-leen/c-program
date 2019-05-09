#include <stdlib.h>
#include <gtk/gtk.h>

/**
  鼠标进入信号
    当鼠标移动到我们所绑定的那个构件上时就会发出“鼠标进入信号”
*/

void enter_button(GtkWidget *widget, gpointer data)
{
    GdkColor color ;
    color.red = 27000 ;
    color.green = 30325 ;
    color.blue = 34181 ;

    gtk_widget_modify_bg(widget, GTK_STATE_PRELIGHT, &color) ;
}

int main (int argc, char *argv[])
{
    GtkWidget *window ;
    GtkWidget *fixed ;
    GtkWidget *button ;

    gtk_init(&argc, &argv) ;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
    gtk_window_set_default_size(GTK_WINDOW(window), 800,500) ;
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER) ;
    gtk_window_set_title(GTK_WINDOW(window), "enter signal") ;

    fixed = gtk_fixed_new() ;
    gtk_container_add(GTK_CONTAINER(window), fixed) ;

    button = gtk_button_new_with_label("button") ;
    gtk_widget_set_size_request(button, 80, 35) ;
    gtk_fixed_put(GTK_FIXED(fixed), button, 50,50) ;

    g_signal_connect(G_OBJECT(button), "enter", G_CALLBACK(enter_button), NULL) ;
    g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL) ;

    gtk_widget_show_all(window) ;
    gtk_main ();
    return 0;
}
