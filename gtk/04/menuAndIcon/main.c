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

  //创建一个新的accel组
  accel_group = gtk_accel_group_new() ;

  //将accel增加入window
  gtk_window_add_accel_group(GTK_WINDOW(window) , accel_group) ;

  //点击alt会在file下面添加下划线
  //采用gtk_button_new_with_label生成的button不会响应ATL键，也不会将“_”解释为添加下划线。要实现下划线和响应ATL的功能，需要使用gtk_button_new_with_mnemonic函数
  file = gtk_menu_item_new_with_mnemonic("_File") ;

  //生成两个带有图像的菜单选项
  new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW , NULL) ; //NULL达到的效果是自动生成accelerators快捷键，和为菜单选项分别提供图像和文字
  open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN , NULL) ;

  //菜单选项中的分隔符
  sep = gtk_separator_menu_item_new() ;

  quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT , accel_group) ;

  //gtk_widget_add_accelerator(quit , "activate" , accel_group , GDK_q , GDK_CONTROL_MASK , GTK_ACCEL_VISIBLE) ;


  //将file标签作为文件菜单
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file) , filemenu) ;
  //gtk_menu_item_set_submenu(GTK_MENU_ITEM(quit) , filemenu) ;

  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu) , new) ;
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu) , open) ;
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu) , sep) ;
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
