#include <stdlib.h>
#include <gtk/gtk.h>

void frame_callback(GtkWidget *window , GdkEvent *event , gpointer data)
{
	int x , y ;
	char buf[10] ;
	//捕获当前鼠标所在坐标
	x = event->configure.x ;
	y = event->configure.y ;

	//打印捕获的坐标,并存入buf中
	sprintf(buf , "%d,%d",x,y) ;

	gtk_window_set_title(GTK_WINDOW(window) , buf) ;
}

int main (int argc, char *argv[])
{
	GtkWidget *window ;

	gtk_init(&argc , &argv) ;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
	gtk_window_set_default_size(GTK_WINDOW(window) , 800 ,500) ;
	gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ; //GTK_WIN_POS_CENTER包含了所有的大小、位置和用于存储事件次序的栈结构

	gtk_window_set_title(GTK_WINDOW(window) , "Simple") ;

	gtk_widget_add_events(GTK_WIDGET(window) , GDK_CONFIGURE) ;

	g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , G_OBJECT(window)) ;
	g_signal_connect(G_OBJECT(window) , "configure-event" , G_CALLBACK(frame_callback) , NULL) ;

	gtk_widget_show_all(window) ;
	gtk_main() ;

	return 0;
}
