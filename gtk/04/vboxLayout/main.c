#include <stdlib.h>
#include <gtk/gtk.h>


int main (int argc, char *argv[])
{
  /**
    GtkVBox 是一种用于垂直布局的容器构件，他把放置在其中的子构件放置在单独的列中
  */

  GtkWidget *window ;
  GtkWidget *vbox ;

  GtkWidget *settings ;
  GtkWidget *accounts ;
  GtkWidget *loans ;
  GtkWidget *crash ;
  GtkWidget *debts ;


  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "GtkVBox") ;

  //设置边界，按钮距离容器边界距离
  gtk_container_set_border_width(GTK_CONTAINER(window) , 150) ;

  vbox = gtk_vbox_new(TRUE , 1) ; //1表示按钮之间的像素
  gtk_container_add(GTK_CONTAINER(window) , vbox) ;

  settings = gtk_button_new_with_label("Settings") ;
  gtk_container_set_border_width(GTK_CONTAINER(settings) , 20) ;
  accounts = gtk_button_new_with_label("Accounts") ;
  gtk_container_set_border_width(GTK_CONTAINER(accounts) , 20) ;
  loans = gtk_button_new_with_label("Loans") ;
  gtk_container_set_border_width(GTK_CONTAINER(loans) , 20) ;
  crash = gtk_button_new_with_label("Crash") ;
  gtk_container_set_border_width(GTK_CONTAINER(crash) , 20) ;
  debts = gtk_button_new_with_label("Debts") ;
  gtk_container_set_border_width(GTK_CONTAINER(debts) , 20) ;

  //将各个按钮打包放在box中
  gtk_box_pack_start(GTK_BOX(vbox) , settings , TRUE , TRUE , 0) ;
  gtk_box_pack_start(GTK_BOX(vbox) , accounts , TRUE , TRUE , 0) ;
  gtk_box_pack_start(GTK_BOX(vbox) , loans , TRUE , TRUE , 0) ;
  gtk_box_pack_start(GTK_BOX(vbox) , crash , TRUE , TRUE , 0) ;
  gtk_box_pack_start(GTK_BOX(vbox) , debts , TRUE , TRUE , 0) ;

  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , G_OBJECT(window)) ;


  gtk_widget_show_all(window) ;

  gtk_main ();
  return 0;
}
