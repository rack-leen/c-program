#include <stdlib.h>
#include <gtk/gtk.h>


int main (int argc, char *argv[])
{
  /**
    gtkAlinment 容器构件控制了他的子构件的对齐方式与大小
  */

  GtkWidget *window ;
  GtkWidget *ok ;
  GtkWidget *close ;
  GtkWidget *vbox ;
  GtkWidget *hbox ;
  GtkWidget *halign ;
  GtkWidget *valign ;


  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "gtkAlignment") ;

  gtk_container_set_border_width(GTK_CONTAINER(window) , 10) ;

  vbox = gtk_vbox_new(FALSE , 5) ;
  //y向下对齐

  //x(-1表示向左,1表示向右)
  valign = gtk_alignment_new(0,1,0,0) ;
  //将对齐方式放入垂直布局中,使得垂直对齐方式不能控制垂直布局，而控制垂直布局中的控件
  //vbox的对齐方式是垂直对齐
  gtk_container_add(GTK_CONTAINER(vbox) , valign) ;
  //再将垂直布局放入主窗口
  gtk_container_add(GTK_CONTAINER(window) , vbox) ;

  //创建水平布局方式
  hbox = gtk_hbox_new(TRUE , 3) ;
  ok = gtk_button_new_with_label("OK") ;
  gtk_widget_set_size_request(ok , 70 ,30) ;
  //将ok按钮放入水平布局方式中
  gtk_container_add(GTK_CONTAINER(hbox) , ok) ;
  close = gtk_button_new_with_label("Close") ;
  gtk_widget_set_size_request(close , 70 ,30) ;
  gtk_container_add(GTK_CONTAINER(hbox) , close) ;

  //x向右对齐,y不变
  halign = gtk_alignment_new(1,0,0,0) ;
  //将水平布局方式放入水平对齐，使得放置在水平布局中的控件随着对齐方式改变位置
  gtk_container_add(GTK_CONTAINER(halign) , hbox) ;

  gtk_box_pack_start(GTK_BOX(vbox) , halign , FALSE , FALSE , 0) ;

  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , G_OBJECT(window)) ;

  gtk_widget_show_all(window) ;
  gtk_main() ;

  return 0;
}
