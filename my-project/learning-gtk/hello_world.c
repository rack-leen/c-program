/*************************************************************************
* > File Name: hello_world.c
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月05日 星期二 09时40分36秒
**************************************************************************/

/*************************************************************************
* > 头文件
**************************************************************************/

#include <gtk/gtk.h>

static void hello(GtkWidget *widget , gpointer data)
{
    g_print("Hello World!\n");
}

static gboolean delete_even(GtkWidget *widget , GdkEvent *event , gpointer data)
{
    g_print("delete_even occured!\n");
    return TRUE ;
}

static void destroy(GtkWidget *widget , gpointer data)
{
    gtk_main_quit();
}

int main(int argc , char *argv[])
{
    GtkWidget *window ;
    GtkWidget *button ;

    gtk_init(&argc , &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window , "delete_even" , G_CALLBACK(delete_even) , NULL);

    gtk_widget_show(window);

    g_signal_connect(window , "destroy" , G_CALLBACK(destroy) , NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window) , 10);
    gtk_main();

    return 0 ;
}
