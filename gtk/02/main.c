#include <stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window ;
    GtkWidget *vbox ;

    GtkWidget *menubar ;
    GtkWidget *fileMenu ;
    GtkWidget *fileMi ; //文件选项
    GtkWidget *quitMi ; //退出选项

    GtkWidget *importMenu ;
    GtkWidget *importMi ;
    GtkWidget *feedMi ;
    GtkWidget *bookMi ;
    GtkWidget *mailMi ;

    GtkWidget *seq ;

    GtkWidget *editMenu ;
    GtkWidget *editMi ;
    GtkWidget *undoMi ;
    GtkWidget *redoMi ;
    GtkWidget *pasteMi ;

    gtk_init(&argc , &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),500,300);
    gtk_window_set_title(GTK_WINDOW(window),"Simple Menu");

    vbox = gtk_vbox_new(FALSE,0); //创建一个垂直布局
    gtk_container_add(GTK_WINDOW(window),vbox); //将垂直布局加入window

    menubar = gtk_menu_bar_new(); //创建一个菜单栏
    fileMenu = gtk_menu_new(); //创建一个文件菜单

    fileMi = gtk_menu_item_new_with_label("File"); //创建文件标签
    quitMi = gtk_menu_item_new_with_label("Quit");  //创建退出标签

    importMenu = gtk_menu_new();
    importMi = gtk_menu_item_new_with_label("Import");
    feedMi = gtk_menu_item_new_with_label("Import news feed ...");
    bookMi = gtk_menu_item_new_with_label("Import bookmarks ...");
    mailMi = gtk_menu_item_new_with_label("Import mail ...");

    editMenu = gtk_menu_new();
    editMi = gtk_menu_item_new_with_label("Edit");
    undoMi = gtk_menu_item_new_with_label("Undo");
    redoMi = gtk_menu_item_new_with_label("Redo");
    pasteMi = gtk_menu_item_new_with_label("Paste");
    seq = gtk_separator_menu_item_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi),fileMenu); //将文件标签设置为文件菜单
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),fileMi); //将文件菜单项增加到菜单栏

    gtk_menu_item_set_submenu(GTK_MENU(importMi),importMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(importMenu),feedMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(importMenu),bookMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(importMenu),mailMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),importMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),seq);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),quitMi); //将退出标签增加到文件菜单项

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(editMi),editMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),undoMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),redoMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),pasteMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),editMi);

    gtk_box_pack_start(GTK_BOX(vbox),menubar,FALSE,FALSE,0);

    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL); //调用quit信号销毁窗口（窗口不会自动调用销毁函数销毁窗口）
    g_signal_connect(G_OBJECT(quitMi),"activate",G_CALLBACK(gtk_main_quit),NULL);//选择退出按钮，终止程序


    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
