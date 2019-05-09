#include <stdlib.h>
#include <gtk/gtk.h>

gint count = 0 ;
char buf[5] ;

void increase(GtkWidget *widget , gpointer label)
{
  count++ ;
  //讲count值输出到buf中
  sprintf(buf , "%d" , count);
  //在标签上设置文本，将buf中的值放在label中
  gtk_label_set_text(label , buf);
}


void decrease(GtkWidget *widget , gpointer label)
{
  count-- ;
  sprintf(buf , "%d" , count) ;
  gtk_label_set_text(label , buf) ;
}

int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *label ;
  GtkWidget *frame ;
  GtkWidget *plus ;
  GtkWidget *minus ;

  gtk_init(&argc , &argv) ;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;

  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER);

  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;

  gtk_window_set_title(GTK_WINDOW(window) , "学生信息管理系统") ;


  //在主窗口中创建一个子窗frame
  frame = gtk_fixed_new() ;
  //将子窗口包含在主窗口中
  gtk_container_add(GTK_CONTAINER(window) , frame) ;
  //用label创建一个新的按钮plus
  plus = gtk_button_new_with_label("+") ;
  //设置按钮尺寸
  gtk_widget_set_size_request(plus , 80 , 35) ;
  //将按钮固定在frame窗口里面的50,20位置
  gtk_fixed_put(GTK_FIXED(frame) , plus , 50 , 20) ;

  minus = gtk_button_new_with_label("-") ;
  gtk_widget_set_size_request(minus , 80 , 35) ;
  gtk_fixed_put(GTK_FIXED(frame) , minus , 50 , 80) ;

  //创建一个新的label标签，初始值为0
  label = gtk_label_new("0") ;
  //将被固定的label放在frame框架里面的190，58位置
  gtk_fixed_put(GTK_FIXED(frame) , label , 190 , 58) ;
  gtk_widget_show_all(window) ;

  g_signal_connect(window , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;
  g_signal_connect(plus , "clicked" , G_CALLBACK(increase) , label) ;//点击plus按钮，通过回调函数，触发label标签，使其变化
  g_signal_connect(minus , "clicked" , G_CALLBACK(decrease) , label) ;

  gtk_main() ;

  return 0;
}
