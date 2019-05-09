#include <stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *vbox ;
  GtkWidget *menubar ; //菜单栏
  GtkWidget *filemenu ;//文件菜单
  GtkWidget *file ; //文件菜单名
  GtkWidget *new ; //文件菜单下的新建
  GtkWidget *open ; //文件菜单下的打开
  GtkWidget *quit ;
  GtkWidget *sep ;
  GtkAccelGroup *accel_group = NULL ;

  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  //设置默认尺寸
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "menubar test") ;

  //创建一个垂直布局的盒子
  vbox = gtk_vbox_new(FALSE , 0) ;
  //将盒子包含进window主窗口中
  gtk_container_add(GTK_CONTAINER(window) , vbox) ;
  //创建一个菜单栏
  menubar = gtk_menu_bar_new() ;
  //创建一个文件菜单
  filemenu = gtk_menu_new() ;

  accel_group = gtk_accel_group_new() ;

  gtk_window_add_accel_group(GTK_WINDOW(window) , accel_group) ;


  //创建一个文件标签
  file = gtk_menu_item_new_with_label("File") ;
  //创建一个退出标签
  quit = gtk_menu_item_new_with_label("Quit") ;
  //将file标签作为文件菜单
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file) , filemenu) ;
  //gtk_menu_item_set_submenu(GTK_MENU_ITEM(quit) , filemenu) ;
  //将qiut标签追加到文件菜单中
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu) , quit) ;
  //将file添加到菜单栏中
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar) , file) ;
  gtk_box_pack_start(GTK_BOX(vbox) , menubar , FALSE , FALSE , 3) ;
  g_signal_connect(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;
  g_signal_connect(G_OBJECT(quit) , "activate" , G_CALLBACK(gtk_main_quit) , NULL) ;

  gtk_widget_show_all(window) ;

  gtk_main() ;
  return 0;
}
