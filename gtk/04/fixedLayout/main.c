#include <stdlib.h>
#include <gtk/gtk.h>
/**
  容器构件gtkfixed用于布置子构件在一个固定的位置和设定固定的大小
  这种构件并不是属于自动的布局关系器
  我们设计大多数应用程序中，不怎么使用gtkFixed
  用的最多的死游戏、含绘图功能的专用软件，那些需要移动和调整大小的软件以及一些小型的教育用途软件
*/
int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *fixed ;
  GtkWidget *button1 ;
  GtkWidget *button2 ;
  GtkWidget *button3 ;

  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_title(GTK_WINDOW(window) , "Gtk Fixed") ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;


  //创建固定布局
  fixed = gtk_fixed_new() ;
  gtk_container_add(GTK_CONTAINER(window) , fixed) ;

  //创建按钮
  button1 = gtk_button_new_with_label("Button") ;
  //将按钮设置到固定位置
  gtk_fixed_put(GTK_FIXED(fixed) , button1 , 150,50) ;
  //设置按钮的大小
  gtk_widget_set_size_request(button1 , 80 , 35) ;

  button2 = gtk_button_new_with_label("Button") ;
  gtk_fixed_put(GTK_FIXED(fixed) , button2 , 15 , 15) ;
  gtk_widget_set_size_request(button2 , 80 , 35) ;

  button3 = gtk_button_new_with_label("Button") ;
  gtk_fixed_put(GTK_FIXED(fixed) , button3 , 100,100) ;
  gtk_widget_set_size_request(button3 , 80 ,35) ;

  g_signal_connect(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;
  gtk_widget_show_all(window) ;

  gtk_main() ;

  return 0;
}
