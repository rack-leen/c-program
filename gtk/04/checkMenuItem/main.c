#include <stdlib.h>
#include <gtk/gtk.h>

//浮动状态栏
void toggle_statusbar(GtkWidget *widget , gpointer statusbar)
{
  //如果激活了状态栏
  if(gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget)))
  {
    //显示
    gtk_widget_show(statusbar) ;
  }
  else
  {
    //隐藏
    gtk_widget_hide(statusbar) ;
  }
}


int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *vbox ;
  GtkWidget *menubar ;
  GtkWidget *viewmenu ;
  GtkWidget *view ;
  GtkWidget *tog_stat ;
  GtkWidget *statusbar ;

  gtk_init(&argc , &argv) ;

  //创建和设置主窗口
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "view statusbar") ;

  //创建垂直布局方式
  vbox = gtk_vbox_new(FALSE , 0) ;
  //将垂直布局加入主窗口
  gtk_container_add(GTK_CONTAINER(window) , vbox) ;

  //创建菜单栏
  menubar = gtk_menu_bar_new() ;
  //创建view菜单
  viewmenu = gtk_menu_new() ;
  //创建view菜单的元素
  view = gtk_menu_item_new_with_label("View") ;

  //创建选择标签
  tog_stat = gtk_check_menu_item_new_with_label("View StatusBar") ;

  //激活选择标签
  gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(tog_stat) , TRUE) ;
  //将view元素设置为viewmenu子菜单
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(view) , viewmenu) ;
  //将tog_stat加入view子菜单
  gtk_menu_shell_append(GTK_MENU_SHELL(viewmenu) , tog_stat) ;
  //将view子菜单加入menbar菜单栏
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar) , view) ;
  //将菜单栏设置到vbox的顶部，padding为3
  gtk_box_pack_start(GTK_BOX(vbox) , menubar , FALSE , FALSE , 3) ;
  //创建状态栏
  statusbar = gtk_statusbar_new() ;
  //将状态栏设置到vbox的底部，padding为1
  gtk_box_pack_end(GTK_BOX(vbox) , statusbar , FALSE , TRUE , 1) ;
  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;
  g_signal_connect(G_OBJECT(tog_stat) , "activate" , G_CALLBACK(toggle_statusbar) , statusbar) ;
  gtk_widget_show_all(window) ;

  gtk_main() ;

  return 0;
}
