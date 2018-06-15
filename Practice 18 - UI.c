//Lorraine Bichara Assad
//A01193063
//Alert box code from: https://github.com/steshaw/gtk-examples/blob/master/ch11.color.font/dialog.c

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <ctype.h>
#include <string.h>

int iCantAgentes = 0;
GtkWidget *entryNombre, *entryApellido, *entryID, *entryCodigo, *entryEdad, *entryGenero, *entryMision;

struct agente {
	int iCode;
	char cName[21];
  char cLName[21];
  char cAgentID[16];
  char cAsset[35];
  int iContAssets;
  int iAge;
  char cGender;
  char cMission[13];
  int iContMisiones;
};

typedef struct agente agente;
agente agentesArr[10];
agente agent;

void CloseDialog (GtkWidget *widget, gpointer data)
{

    /* --- Remove grab --- */
    gtk_grab_remove (GTK_WIDGET (data));

    /* --- Close it. --- */
    gtk_widget_destroy (GTK_WIDGET (data));

}

void Popup (char *szMessage)
{
    static GtkWidget *label;
    GtkWidget *button;
    GtkWidget *dialog_window;

    /* --- Create a dialog window --- */
    dialog_window = gtk_dialog_new ();

    /* --- Trap the destroy button --- */
    gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
	                GTK_SIGNAL_FUNC(gtk_widget_destroyed),
	                &dialog_window);

    /* --- Add a title to the window --- */
    gtk_window_set_title (GTK_WINDOW (dialog_window), "Popup");

    /* --- Create a small border --- */
    gtk_container_border_width (GTK_CONTAINER (dialog_window), 5);

    /*
     * --- Create the message
     */

    /* --- Create the message in a label --- */
    label = gtk_label_new (szMessage);

    /* --- Put some room around the label --- */
    gtk_misc_set_padding (GTK_MISC (label), 10, 10);

    /* --- Add the label to the dialog --- */
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
                        label, TRUE, TRUE, 0);

    /* --- Make the label visible --- */
    gtk_widget_show (label);

    /* 
     * --- "ok" button
     */ 

    /* --- Create the "ok" button --- */
    button = gtk_button_new_with_label ("Ok");

    /* --- Need to close the window if they press "ok" --- */
    gtk_signal_connect (GTK_OBJECT (button), "clicked",
	                GTK_SIGNAL_FUNC (CloseDialog),
	                dialog_window);

    /* --- Allow it to be the default button --- */
    GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);

    /* --- Add the button to the dialog --- */
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
			  button, TRUE, TRUE, 0);

    /* --- Make the button the default button --- */
    gtk_widget_grab_default (button);

    /* --- Make the button visible --- */
    gtk_widget_show (button);

    /* --- Make the dialog visible --- */
    gtk_widget_show (dialog_window);

    gtk_grab_add (dialog_window);
}


static void terminar(GtkWidget *widget, gpointer data) {
	gtk_main_quit ();
}

static void agregarAgentes(GtkWidget *btnTerminar, GtkWidget **entry) {

	GtkWidget *entry_nom = entry[0];
	GtkWidget *entry_ap = entry[1];
	GtkWidget *entry_ed = entry[2];
	GtkWidget *entry_gen = entry[3];
	GtkWidget *entry_id = entry[4];
	GtkWidget *entry_cod = entry[5];
	GtkWidget *entry_mis = entry[6];

	const gchar *nombre;
	nombre = gtk_entry_get_text (GTK_ENTRY(entry_nom));
	strcpy(agent.cName, nombre);
	g_print("%s\n", nombre);

	const gchar *apellido;
	apellido = gtk_entry_get_text (GTK_ENTRY(entry_ap));
	strcpy(agent.cLName, apellido);
	g_print("%s\n", apellido);
	
	const gchar *edad;
	edad = gtk_entry_get_text (GTK_ENTRY(entry_ed));
	agent.iAge = atoi(edad);
	g_print("%s\n", edad);
    	
	const gchar *genero;
	genero = gtk_entry_get_text (GTK_ENTRY(entry_gen));
	agent.cGender = genero;
	g_print("%s\n", genero);

	const gchar *id;
	id = gtk_entry_get_text (GTK_ENTRY(entry_id));
	strcpy(agent.cAgentID, id);
	g_print("%s\n", id);

	const gchar *codigoAsset;
	codigoAsset = gtk_entry_get_text (GTK_ENTRY(entry_cod));
	strcpy(agent.cAsset, codigoAsset);
	g_print("%s\n", codigoAsset);

	const gchar *mision;
	mision = gtk_entry_get_text (GTK_ENTRY(entry_mis));
	strcpy(agent.cMission, mision);
	g_print("%s\n", mision); 

 	Popup ("Agente guardado exitosamente.");
}

//propiedades de la ventana
static void initialize_window(GtkWidget* window)
{
  gtk_window_set_title(GTK_WINDOW(window),"AGENT MANAGEMENT SYSTEM"); //Set window title
  gtk_window_set_default_size (GTK_WINDOW (window), 100, 600); //Set default size for the window
  g_signal_connect (window, "destroy", G_CALLBACK (terminar), NULL); //End application when close button clicked
  gtk_container_set_border_width (GTK_CONTAINER (window), 20);
}

int main (int argc, char *argv[])
{
  //GtkWidget *window,*table,*label,*entry;
  GtkWidget *window, *table, *lbNombre, *lbApellido, *lbID, *lbCodigo, *lbEdad, *lbGenero, *lbMision;
 
  GtkWidget *fixed;

  gtk_init(&argc, &argv);

  //Main Window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  initialize_window(window);

   //Table
  table = gtk_table_new (7, 2, TRUE);
  gtk_container_add (GTK_CONTAINER (window), table);

  //Labels
  lbNombre = gtk_label_new ("Nombre:" );
  lbApellido = gtk_label_new ("Apellido:" );
  lbID = gtk_label_new ("ID:" );
  lbCodigo = gtk_label_new ("Codigo de Asset:" );
  lbEdad = gtk_label_new ("Edad:" );
  lbGenero = gtk_label_new ("Genero (H/M):" );
  lbMision = gtk_label_new ("Mision:" );

  gtk_table_set_homogeneous(GTK_TABLE (table), TRUE);
  gtk_table_attach_defaults (GTK_TABLE (table), lbNombre, 0, 1, 0, 1);
  gtk_table_attach_defaults (GTK_TABLE (table), lbApellido, 0, 1, 0, 2);
  gtk_table_attach_defaults (GTK_TABLE (table), lbID, 0, 1, 0, 3);
  gtk_table_attach_defaults (GTK_TABLE (table), lbCodigo, 0, 1, 0, 4);
  gtk_table_attach_defaults (GTK_TABLE (table), lbEdad, 0, 1, 0, 5);
  gtk_table_attach_defaults (GTK_TABLE (table), lbGenero, 0, 1, 0, 6);
  gtk_table_attach_defaults (GTK_TABLE (table), lbMision, 0, 1, 0, 7);

  //Text boxes
  entryNombre = gtk_entry_new ();
  entryApellido = gtk_entry_new ();
  entryID = gtk_entry_new ();
  entryCodigo = gtk_entry_new ();
  entryEdad = gtk_entry_new ();
  entryGenero = gtk_entry_new ();
  entryMision = gtk_entry_new ();

  gtk_entry_set_max_length (GTK_ENTRY (entryNombre),0);
  gtk_entry_set_max_length (GTK_ENTRY (entryApellido),0);
  gtk_entry_set_max_length (GTK_ENTRY (entryID),15);
  gtk_entry_set_max_length (GTK_ENTRY (entryEdad),3);
  gtk_entry_set_max_length (GTK_ENTRY (entryGenero),1);
  gtk_entry_set_max_length (GTK_ENTRY (entryMision),12);
  gtk_entry_set_max_length (GTK_ENTRY (entryCodigo),35);

  gtk_table_attach_defaults (GTK_TABLE (table), entryNombre, 1, 2, 0, 1);
  gtk_table_attach_defaults (GTK_TABLE (table), entryApellido, 1, 2, 0, 2);
  gtk_table_attach_defaults (GTK_TABLE (table), entryID, 1, 2, 0, 3);
  gtk_table_attach_defaults (GTK_TABLE (table), entryCodigo, 1, 2, 0, 4);
  gtk_table_attach_defaults (GTK_TABLE (table), entryEdad, 1, 2, 0, 5);
  gtk_table_attach_defaults (GTK_TABLE (table), entryGenero, 1, 2, 0, 6);
  gtk_table_attach_defaults (GTK_TABLE (table), entryMision, 1, 2, 0, 7);

	GtkWidget **entry;
  entry = malloc(7 * sizeof(GtkWidget));
  entry[0] = entryNombre;
  entry[1] = entryApellido;
  entry[2] = entryEdad;
  entry[3] = entryGenero;
  entry[4] = entryID;
  entry[5] = entryCodigo;
  entry[6] = entryMision;

  //Button
  GtkWidget *button, *btnTerminar;
  button = gtk_button_new_with_label ("Guardar agente");
  btnTerminar = gtk_button_new_with_label ("Terminar");
  
  gtk_table_attach (GTK_TABLE (table), button, 0, 2, 2, 6, GTK_FILL, GTK_SHRINK, 10, 10);
 
  gtk_table_attach (GTK_TABLE (table), btnTerminar, 0, 2, 2, 7, GTK_FILL, GTK_SHRINK, 10, 10);

  g_signal_connect(button, "clicked", G_CALLBACK (agregarAgentes), entry);
  
  g_signal_connect(G_OBJECT(btnTerminar), "clicked", G_CALLBACK (terminar), (gpointer) "button 1");


  gtk_widget_show_all(window);

  gtk_main ();
  return 0;
}
