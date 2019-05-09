#include <stdlib.h>
#include <gtk/gtk.h>

//创建图标
GdkPixbuf *create_pixbuf(const gchar *filename)
{
  GdkPixbuf *pixbuf ;
  GError *error = NULL ;

  //从文件中得到一个新的图标
  pixbuf = gdk_pixbuf_new_from_file(filename , &error) ;

  if(!pixbuf)
  {
    //打印错误信息
    fprintf(stderr , "%s\n" , error->message) ;
    //释放指针
    g_error_free(error);

  }
  return pixbuf ;
}

int main (int argc, char *argv[])
{
  GtkWidget *window ;
  //初始化
  gtk_init(&argc , &argv);

  //创建一个新的主窗口
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  //设置标题
  gtk_window_set_title(GTK_WINDOW(window),"学生信息管理系统");
  //设置图标
  //gtk_window_set_icon(GTK_WINDOW(window),"icon");
  //设置默认尺寸
  gtk_window_set_default_size(GTK_WINDOW(window),800,500);
  //设置开始窗口位置
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
  //设置图标
  gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("kate.svg")) ;
  //将主窗口显示
  gtk_widget_show(window);

  //窗口销毁信号,可以点击x关闭窗口
  g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

  //运行主程序
  gtk_main() ;
  return 0;
}
