#include <stdlib.h>
#include <gtk/gtk.h>

/**
  拖放一个没有边框的窗口
*/

//点击按钮
void on_button_press(GtkWidget *widget , GdkEventButton *event , GdkWindowEdge edge)
{
  //如果事件类型是压住按钮
  if(event->type == GDK_BUTTON_PRESS)
  {
    if(event->button == 1)
    {

      gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)) , event->button , event->x_root , event->y_root , event->time) ;
    }
  }

  return FALSE ;
}
int main (int argc, char *argv[])
{

  GtkWidget *window ;

  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "drag and drop") ;
  gtk_window_set_decorated(GTK_WINDOW(window) , FALSE) ;


  gtk_main ();
  return 0;
}
