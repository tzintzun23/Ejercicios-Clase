//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//



//Nombre: Hernández Tzintzun Daniel
//Práctica: 2
//Versión VS: 2017
//Instrucciones: se muestran las letras CGDH con distinta degradación de color



#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar

	//Letra C en color verde degradado diagonalmente hacia la derecha
	glBegin(GL_QUADS);
		glColor3f(0.172, 0.368, 0.011);
		glVertex3f(-14.0f, -5.0f, 0.0f);
		glColor3f(0.470, 0.972, 0.070);
		glVertex3f(-8.0f, -5.0f, 0.0f);
		glColor3f(0.517f, 0.949f, 0.313f);
		glVertex3f(-8.0f, -3.0f, 0.0f);
		glColor3f(0.470, 0.972, 0.070);
		glVertex3f(-12.0f, -3.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.172, 0.368, 0.011);
		glVertex3f(-14.0f, -5.0f, 0.0f);
		glColor3f(0.470, 0.972, 0.070);
		glVertex3f(-12.0f, -3.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-12.0f, 3.0f, 0.0f);
		glColor3f(0.470, 0.972, 0.070);
		glVertex3f(-14.0f, 5.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-12.0f, 3.0f, 0.0f);
		glColor3f(0.694, 0.984, 0.454);
		glVertex3f(-8.0f, 3.0f, 0.0f);
		glColor3f(0.694, 0.984, 0.454);
		glVertex3f(-8.0f, 5.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-14.0f, 5.0f, 0.0f);
	glEnd();

	//Letra G en color azul degradado diagonalmente hacia la izquierda
	glBegin(GL_QUADS);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-7.0f, -5.0f, 0.0f);
		glVertex3f(-5.0f, -3.0f, 0.0f);
		glColor3f(0.698, 0.713, 0.980);
		glVertex3f(-5.0f, 3.0f, 0.0f);
		glVertex3f(-7.0f, 5.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-7.0f, -5.0f, 0.0f);
		glColor3f(0.027, 0.058, 0.615);
		glVertex3f(-1.0f, -5.0f, 0.0f);
		glVertex3f(-1.0f, -3.0f, 0.0f);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-5.0f, -3.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-5.0f, 3.0f, 0.0f);
		glVertex3f(-1.0f, 3.0f, 0.0f);
		glVertex3f(-1.0f, 5.0f, 0.0f);
		glColor3f(0.698, 0.713, 0.980);
		glVertex3f(-7.0f, 5.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.027, 0.058, 0.615);
		glVertex3f(-3.0f, -3.0f, 0.0f);
		glVertex3f(-1.0f, -3.0f, 0.0f);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-3.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.262, 0.298, 0.898);
		glVertex3f(-4.0f, -1.0f, 0.0f);
		//glColor3f(0.235, 0.341, 0.905);
		glVertex3f(-3.0f, -1.0f, 0.0f);
		//glColor3f(0.235, 0.341, 0.905);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		//glColor3f(0.235, 0.341, 0.905);
		glVertex3f(-4.0f, 1.0f, 0.0f);
	glEnd();

	//Letra D en color amarillo degradado horizontalmente
	glBegin(GL_QUADS);
		glColor3f(0.909f, 0.905f, 0.427f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(7.0f, 1.0f, 0.0f);
		glColor3f(0.996f, 0.996f, 0.862f);
		glVertex3f(7.0f, -5.0f, 0.0f);
		glVertex3f(1.0f, -5.0f, 0.0f);
		
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(3.0f, -3.0f, 0.0f);
		glVertex3f(5.0f, -3.0f, 0.0f);
		glVertex3f(5.0f, -1.0f, 0.0f);
		glVertex3f(3.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.917f, 0.890f, 0.380f);
		glVertex3f(5.0f, 1.0f, 0.0f);
		glVertex3f(7.0f, 1.0f, 0.0f);
		glColor3f(0.945f, 0.901f, 0.117f);
		glVertex3f(7.0f, 5.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, 0.0f);
	glEnd();

	//Letra H en color rojo degradado verticalmente
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(8.0f, -5.0f, 0.0f);
		glVertex3f(8.0f, 5.0f, 0.0f);
		glColor3f(0.929f, 0.368f, 0.388f);
		glVertex3f(10.0f, 5.0f, 0.0f);
		glVertex3f(10.0f, -5.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.905f, 0.454f, 0.470f);
		glVertex3f(10.0f, -1.0f, 0.0f);
		glVertex3f(12.0f, -1.0f, 0.0f);
		glVertex3f(12.0f, 1.0f, 0.0f);
		glVertex3f(10.0f, 1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.949f, 0.631f, 0.639f);
		glVertex3f(12.0f, -5.0f, 0.0f);
		glVertex3f(12.0f, 5.0f, 0.0f);
		glColor3f(0.984f, 0.815f, 0.823f);
		glVertex3f(14.0f, 5.0f, 0.0f);
		glVertex3f(14.0f, -5.0f, 0.0f);
	glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-17,17,-9,9,-1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

