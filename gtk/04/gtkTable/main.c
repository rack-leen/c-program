#include <stdlib.h>
#include <gtk/gtk.h>

/**
  GtkTable 布局构件既可以按照行也可以按照列来布局子构件
*/
int main (int argc, char *argv[])
{
  GtkWidget *window ;
  GtkWidget *table ;
  GtkWidget *button ;

  //从上倒下，从左往右，显示的按钮名称
  char *values[16] = {"7","8","9","\\","4","5","6","*","1","2","3","-","0",".","=","+"};

  gtk_init(&argc , &argv) ;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
  gtk_window_set_default_size(GTK_WINDOW(window) , 300 , 300) ;
  gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
  gtk_window_set_title(GTK_WINDOW(window) , "Calculator") ;

  gtk_container_set_border_width(GTK_CONTAINER(window) , 6) ;

  table = gtk_table_new(4,4,TRUE) ;
  //每行每列之间的间距都为2
  gtk_table_set_row_spacings(GTK_TABLE(table) , 2) ;
  gtk_table_set_col_spacings(GTK_TABLE(table) , 2) ;

  int i=0 , j = 0 , pos = 0 ;

  //i,j将创建的按钮按照4行4列排列
  for(i=0 ; i<4 ; i++)
  {
    for(j=0 ; j<4 ; j++)
    {
      button = gtk_button_new_with_label(values[pos]);
      /*
           第1个：   * 1
                    1
            第2个:
                  0 * 2
                    1
      */
      gtk_table_attach_defaults(GTK_TABLE(table) , button , j , j+1 , i , i+1) ;
      pos++ ;
    }
  }

  gtk_container_add(GTK_WINDOW(window) , table) ;
  g_signal_connect_swapped(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , G_OBJECT(window)) ;

  gtk_widget_show_all(window) ;
  gtk_main() ;
  return 0;
}
