#include <stdlib.h>
#include <gtk/gtk.h>


int main (int argc, char *argv[])
{

  GtkWidget *window ;
  GtkWidget *table ;
  GtkWidget *title ;
  GtkWidget *activate ;
  GtkWidget *halign1 ;
  GtkWidget *halign2 ;
  GtkWidget *valign ;
  GtkWidget *close ;
  GtkWidget *wins ;
  GtkWidget *help ;
  GtkWidget *ok ;

  //创建主窗口和初始化主窗口设置
  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  //设置主窗口尺寸
  gtk_widget_set_size_request(GTK_WINDOW(window) , 300 , 250) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  //使得主窗口只能保持原来的尺寸
  gtk_window_set_resizable(GTK_WINDOW(window) , FALSE) ;
  gtk_window_set_title(GTK_WINDOW(window) , "windows") ;

  gtk_container_set_border_width(GTK_CONTAINER(window) , 15) ;

  //设置8行4列的表
  table = gtk_table_new(8,4,FALSE) ;

  //每一列之间的间距都是3
  gtk_table_set_col_spacings(GTK_TABLE(table) , 3) ;
  title = gtk_label_new("windows") ;

  //创建水平对齐
  halign1 = gtk_alignment_new(0,0,0,0) ;
  //将文本框标题放入水平对齐中
  gtk_container_add(GTK_CONTAINER(halign1) , title) ;

  //将第一个水平对齐构件放在表的第一行，并将第一行x,y都填满
  gtk_table_attach(GTK_TABLE(table),halign1 , 0 , 1 , 0 , 1 , GTK_FILL , GTK_FILL , 0 , 0) ;

  //文本框
  wins = gtk_text_view_new() ;
  //设置不可编辑
  gtk_text_view_set_editable(GTK_TEXT_VIEW(wins) , FALSE) ;
  //设置鼠标指针隐藏
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(wins) , FALSE) ;
  //将wins窗口放在左边，占2行2列，并将行列填满并且能够扩展 ， 每行列的x,y方向文本与行列之间的间隔都为1
  gtk_table_attach(GTK_TABLE(table) , wins , 0 , 2 , 1 , 3 , GTK_FILL|GTK_EXPAND , GTK_FILL|GTK_EXPAND , 1 , 1) ;



  activate = gtk_button_new_with_label("Activate") ;
  gtk_widget_set_size_request(GTK_WIDGET(activate) , 50 ,30);
  //将activate放置在wins的右边，第一行的下面，占1行1列
  gtk_table_attach(GTK_TABLE(table) , activate , 3 , 4 , 1 , 2 , GTK_FILL , GTK_SHRINK , 1 , 1) ;

  //创建垂直对齐，将close放置在垂直对齐中
  valign = gtk_alignment_new(0 , 0 , 0 , 0) ;
  close = gtk_button_new_with_label("Close") ;
  gtk_widget_set_size_request(GTK_WIDGET(close) , 70 , 30) ;
  gtk_container_add(GTK_CONTAINER(valign) , close) ;
  gtk_table_set_row_spacing(GTK_TABLE(table) , 1 , 3) ;
  gtk_table_attach(GTK_TABLE(table) , valign , 3,4,2,3 , GTK_FILL , GTK_FILL|GTK_EXPAND , 1 , 1) ;

  //将help和ok都放在水平对齐中，并将水平对齐放置在最低端
  halign2 = gtk_alignment_new(0,1,0,0) ;
  help = gtk_button_new_with_label("Help") ;
  gtk_container_add(GTK_CONTAINER(halign2) , help) ;
  gtk_widget_set_size_request(GTK_WIDGET(help) , 70 , 30) ;
  gtk_table_set_row_spacing(GTK_TABLE(table) , 3 , 6) ;
  gtk_table_attach(GTK_TABLE(table) , halign2 , 0 , 1 , 4 , 5 , GTK_FILL , GTK_FILL , 0 , 0) ;

  ok = gtk_button_new_with_label("OK") ;
  gtk_widget_set_size_request(ok , 70 ,30) ;
  gtk_table_attach(GTK_TABLE(table) , ok , 3 , 4 ,4 ,5 , GTK_FILL , GTK_FILL , 0, 0) ;

  gtk_container_add(GTK_CONTAINER(window) , table) ;

  //与g_sgnal_connect区别是,当触发信号时，其回调函数使用 data 作为参数，而不是 g_signal_connect() 所采用的默认参数。
  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , G_OBJECT(window)) ;

  gtk_widget_show_all(window) ;
  gtk_main() ;


  return 0;
}
