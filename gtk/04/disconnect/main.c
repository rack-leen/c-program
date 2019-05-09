#include <stdlib.h>
#include <gtk/gtk.h>

/**
  disconnenct 回调函数解除绑定
*/



int handle_id ;

void button_click(GtkWidget *widget , gpointer data)
{
  g_print("clicked\n") ;
}

//widget表示复选框，window表示按钮，按钮作为指针指向复选框
void toggle_button(GtkWidget *widget , gpointer window)
{
  //如果复选框被激活
  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
  {
    //点击按钮，调用button_click函数，在终端打印clicked
    //这里重新使用这个信号，是为了当主函数中的信号函数被打断后，如果复选框重新被激活，能够重新开始信号
    handle_id = g_signal_connect(G_OBJECT(window) , "clicked" , G_CALLBACK(button_click) , NULL) ;
  }
  else
  {
    //解除按钮与唯一标示的函数返回值的绑定
    g_signal_handler_disconnect(window , handle_id) ;
  }
}
int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *fixed ;
  GtkWidget *button ;
  GtkWidget *check ;


  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_title(GTK_WINDOW(window) , "Disconnect") ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;

  fixed = gtk_fixed_new() ;
  gtk_container_add(GTK_CONTAINER(window) , fixed) ;

  button = gtk_button_new_with_label("Click") ;
  gtk_widget_set_size_request(button , 80 , 30) ;
  gtk_fixed_put(GTK_FIXED(fixed) , button , 30 , 50) ;

  check = gtk_check_button_new_with_label("connect") ;
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check) , TRUE) ;
  gtk_fixed_put(GTK_FIXED(fixed) , check , 130,50) ;

  //点击button调用button_click函数（在终端输出clicked） 函数执行后会返回一个id数据，这就实现了对回调函数的唯一标示
  //初始化按钮点击信号,被打断之后就不能重新使用这个信号了
  handle_id = g_signal_connect(G_OBJECT(button) , "clicked" , G_CALLBACK(button_click) , NULL) ;

  //点击复选框，调用toggle_button回调函数 (gpointer)可以不需要
  g_signal_connect(G_OBJECT(check) , "clicked" , G_CALLBACK(toggle_button) , (gpointer)button) ;

  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;

  gtk_widget_show_all(window) ;

  gtk_main ();
  return 0;
}
