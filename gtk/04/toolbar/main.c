#include <stdlib.h>
#include <gtk/gtk.h>

/**
	工具栏
*/

//撤销和还原
void undo_redo(GtkWidget *widget , gpointer item)
{
	static int count = 2 ;
	const char *name = gtk_widget_get_name(widget) ;

	if(strcmp(name , "undo"))
	{
		count ++ ;
	}
	else
	{
		count -- ;
	}

	if(count < 0)
	{
		//是否告诉计算机是否需要激活一个工具按钮
		gtk_widget_set_sensitive(widget , FALSE) ;
		gtk_widget_set_sensitive(item , TRUE) ;
	}

	if(count > 5)
	{
		gtk_widget_set_sensitive(widget , FALSE) ;
		gtk_widget_set_sensitive(item , TRUE) ;
	}
}

int main (int argc, char *argv[])
{
	GtkWidget *window ;
	GtkWidget *vbox ;
	GtkWidget *toolbar ;
	GtkWidget *new ;
	GtkWidget *open ;
	GtkWidget *save ;

	GtkWidget *undo ;
	GtkWidget *redo ;

	GtkWidget *sep ;
	GtkWidget *exit ;

	gtk_init(&argc , &argv) ;

	//创建和设置主窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL) ;
	gtk_window_set_default_size(GTK_WINDOW(window) , 800 , 500) ;
	gtk_window_set_position(GTK_WINDOW(window) , GTK_WIN_POS_CENTER) ;
	gtk_window_set_title(GTK_WINDOW(window) , "toolbar") ;

	//设置布局
	vbox = gtk_vbox_new(FALSE , 0) ;
	gtk_container_add(GTK_CONTAINER(window) , vbox) ;

	//创建工具栏
	toolbar = gtk_toolbar_new() ;
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar) , GTK_TOOLBAR_ICONS) ;
	gtk_container_set_border_width(GTK_CONTAINER(toolbar) , 2) ;

	//创建爱你需要的工具栏元素
	new = gtk_tool_button_new_from_stock(GTK_STOCK_NEW) ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , new , -1) ;

	open = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN) ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , open , -1) ;

	save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE) ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , save , -1) ;

	sep = gtk_separator_tool_item_new() ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , sep , -1) ;

	undo = gtk_tool_button_new_from_stock(GTK_STOCK_UNDO) ;
	gtk_widget_set_name(GTK_WIDGET(undo) , "undo") ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , undo , -1) ;

	redo = gtk_tool_button_new_from_stock(GTK_STOCK_REDO) ;
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , redo , -1) ;

	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , sep , -1) ;

	exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
	gtk_toolbar_insert(GTK_TOOLBAR(toolbar) , exit , -1) ;


	//将工具栏放在布局的开始位置
	gtk_box_pack_start(GTK_BOX(vbox) , toolbar , FALSE , FALSE , 5) ;

	g_signal_connect(G_OBJECT(window) , "destroy" , G_CALLBACK(gtk_main_quit) , NULL) ;
	g_signal_connect(G_OBJECT(exit) , "clicked" , G_CALLBACK(gtk_main_quit) , NULL) ;
	g_signal_connect(G_OBJECT(undo) , "clicked" , G_CALLBACK(undo_redo) , undo) ;
	g_signal_connect(G_OBJECT(redo) , "clicked" , G_CALLBACK(undo_redo) , redo) ;

	gtk_widget_show_all(window) ;
	gtk_main() ;
	return 0 ;
}
